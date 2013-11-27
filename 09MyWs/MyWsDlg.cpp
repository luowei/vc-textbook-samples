// MyWsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyWs.h"
#include "MyWsDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyWsDlg dialog

CMyWsDlg::CMyWsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyWsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyWsDlg)
	m_server_port = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_clientSocket=NULL;
	m_listenSocket=NULL;
}

void CMyWsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyWsDlg)
	DDX_Control(pDX, IDC_RECEIVED_INFO, m_ctlRecvd);
	DDX_Control(pDX, IDC_LIST_INLINE, m_inLine);
	DDX_Text(pDX, IDC_SERVER_PORT, m_server_port);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyWsDlg, CDialog)
	//{{AFX_MSG_MAP(CMyWsDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, OnBnClickedStart)
	ON_BN_CLICKED(IDC_CLOSE, OnBnClickedClose)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyWsDlg message handlers

BOOL CMyWsDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyWsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMyWsDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMyWsDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyWsDlg::AcceptClient()
{
	m_clientSocket=new CRWSock(this);
	if(!m_listenSocket->Accept(*m_clientSocket))
	{
		AfxMessageBox("请求连接失败");
		delete m_clientSocket;
		m_clientSocket=NULL;
		return;
	}
	m_list.AddTail(m_clientSocket);
}

void CMyWsDlg::SendSocketMessage(CRWSock *socket, _DATA *buf) //发送消息
{
	POSITION pos=m_list.GetHeadPosition();
	while(pos!=NULL)
	{
		CRWSock* client=(CRWSock*)m_list.GetNext(pos);
		if(client==socket)continue;
		client->Send(&m_Dat,sizeof(m_Dat));
	}
}



void CMyWsDlg::displayInLine(char *name)
{
	CString cName;
	CString delName=(CString)name;
	POSITION pos=m_list.GetHeadPosition();
	m_inLine.ResetContent();
	while(pos!=NULL)
	{
		CRWSock* client=(CRWSock*)m_list.GetNext(pos);
		cName=(CString)client->m_Dat.m_strName;
		if(delName!=cName)m_inLine.AddString(cName);
	}
}

void CMyWsDlg::OnBnClickedStart() //启动程序
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	m_listenSocket=new CLSock(this);
	if(!m_listenSocket->Create(m_server_port))
	{
		MessageBox(_T("创建Socket失败！"));
		delete m_listenSocket;
		m_listenSocket=NULL;
		return;
	}
	if(!m_listenSocket->Listen())
	{
		MessageBox(_T("端口设置失败！"),_T("网络信息"),MB_OK);
		delete m_listenSocket;
		m_listenSocket=NULL;
		return;
	}
	//处理控件的状态更新
	GetDlgItem(IDC_START)->EnableWindow(false);
	GetDlgItem(IDC_CLOSE)->EnableWindow(true);
	GetDlgItem(IDC_SERVER_PORT)->EnableWindow(false);
}

void CMyWsDlg::OnBnClickedClose() 
{
	// TODO: Add your control notification handler code here
	POSITION pos=m_list.GetHeadPosition();
	while(pos!=NULL)
	{
		CRWSock* client=(CRWSock*)m_list.GetNext(pos);
		delete client;
	}
	if(m_listenSocket!=NULL)
	{
		m_listenSocket->Close();
		delete m_listenSocket;
	}
	GetDlgItem(IDC_START)->EnableWindow(true);
	GetDlgItem(IDC_CLOSE)->EnableWindow(false);
	GetDlgItem(IDC_SERVER_PORT)->EnableWindow(true);
}
