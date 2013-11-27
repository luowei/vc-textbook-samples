// MyWcDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MyWc.h"
#include "MyWcDlg.h"

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
// CMyWcDlg dialog

CMyWcDlg::CMyWcDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMyWcDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMyWcDlg)
	m_client_name = _T("");
	m_server_name = _T("localhost");	//�ֹ��޸�Ϊ������
	m_nPort = 800;			//�ֹ��޸�ΪĬ��ֵ800
	m_send_info = _T("");
	m_systemTime = _T("");
	m_talk = FALSE;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyWcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMyWcDlg)
	DDX_Control(pDX, IDC_LIST_NAME, m_ctlName);
	DDX_Control(pDX, IDC_RECEIVED_INFO, m_ctlRecvd);
	DDX_Text(pDX, IDC_CLIENT_NAME, m_client_name);
	DDV_MaxChars(pDX,m_client_name,20);				//���Ʊ�������ַ�����20
	DDX_Text(pDX, IDC_SERVER_NAME, m_server_name);
	DDV_MaxChars(pDX,m_server_name,30);				//���Ʊ�������ַ�����30
	DDX_Text(pDX, IDC_SERVER_PORT, m_nPort);
	DDV_MinMaxInt(pDX,m_nPort,0,1024);				//���Ʊ�����Χ
	DDX_Text(pDX, IDC_SEND_INFO, m_send_info);
	DDV_MaxChars(pDX,m_send_info,500);				//���Ʊ�������ַ�����500
	DDX_Text(pDX, IDC_EDIT_TIME, m_systemTime);
	DDV_MaxChars(pDX,m_systemTime,100);				//���Ʊ�������ַ�����100
	DDX_Check(pDX, IDC_CHECK1, m_talk);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CMyWcDlg, CDialog)
	//{{AFX_MSG_MAP(CMyWcDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnBnClickedConnect)
	ON_BN_CLICKED(IDC_CLOSE, OnBnClickedClose)
	ON_BN_CLICKED(IDC_SEND, OnBnClickedSend)
	ON_WM_TIMER()
	ON_MESSAGE(RE_RECEIVED,OnMyReceive)		//�Զ�����Ϣӳ��
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyWcDlg message handlers

BOOL CMyWcDlg::OnInitDialog()
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
	//��ӶԱ������߿ͻ��б��ĳ�ʼ�����
	m_ctlName.InsertString(0,"������");
	m_ctlName.SetCurSel(0);
	UpdateData(false);
	
	SetTimer(1,100,NULL);	//��װ��ʱ��
	//�ؼ�״̬����
	GetDlgItem(IDC_CONNECT)->EnableWindow(true);
	GetDlgItem(IDC_SEND)->EnableWindow(false);
	GetDlgItem(IDC_CLOSE)->EnableWindow(false);
	GetDlgItem(IDC_SERVER_PORT)->EnableWindow(true);
	GetDlgItem(IDC_CLIENT_NAME)->EnableWindow(true);
	GetDlgItem(IDC_SERVER_NAME)->EnableWindow(true);
	GetDlgItem(IDC_LIST_NAME)->EnableWindow(false);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMyWcDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyWcDlg::OnPaint() 
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
HCURSOR CMyWcDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CMyWcDlg::OnBnClickedConnect() //���ӷ���������������(����)
{
	// TODO: Add your control notification handler code here
	//1.���¹���������������������˿ں�
	UpdateData(true);
	CString cName=m_client_name;
	if(!cName.Compare(_T("")))
	{
		AfxMessageBox(_T("Client's name can not be full"));
		return;
	}

	//2.�����׽��֣������������������
	if(!sockClient.Create())
	{
		AfxMessageBox(_T("create WC socket failed"));
		PostQuitMessage(0);
	}
	if(!sockClient.Connect(m_server_name,m_nPort))
	{
		if(sockClient!=NULL) sockClient.Close();
		MessageBox(_T("����ʧ�ܣ�"));
		return;
	}

	//3.����������Ϳͻ����ϣ����û���
	memset(m_Dat.m_type,0,255);
	memset(m_Dat.m_strName,0,255);
	memcpy(m_Dat.m_type,"CONNECTION",sizeof("CONNECTION"));
	memcpy(m_Dat.m_strName,m_client_name,m_client_name.GetLength());
	sockClient.Send(&m_Dat,sizeof(m_Dat));

	GetDlgItem(IDC_CONNECT)->EnableWindow(false);
	GetDlgItem(IDC_SEND)->EnableWindow(true);
	GetDlgItem(IDC_CLOSE)->EnableWindow(true);
	GetDlgItem(IDC_SERVER_PORT)->EnableWindow(false);
	GetDlgItem(IDC_CLIENT_NAME)->EnableWindow(false);
	GetDlgItem(IDC_SERVER_NAME)->EnableWindow(false);
}

void CMyWcDlg::OnBnClickedClose() 
{
	// TODO: Add your control notification handler code here
	//1.�����������������Ϣ
	memset(m_Dat.m_type,0,255);
	memcpy(m_Dat.m_type,"CLOSE",sizeof("CLOSE"));
	sockClient.Send(&m_Dat,sizeof(m_Dat));

	//2.�Ͽ������˳������
	sockClient.Close();

	//3.�˳�ϵͳ
	exit(0);
}

void CMyWcDlg::OnBnClickedSend() //ʵ��������Ϣ�ķ���
{
	// TODO: Add your control notification handler code here
	//1.���¹�����������Ҫ���͵���Ϣ
	UpdateData(true);
	CString talkingName;
	m_ctlName.GetText(m_ctlName.GetCurSel(),talkingName);

	//2.���������ͽ����жϣ���д���ݰ������ֶε�����
	if(talkingName!="������")
	{
		memset(m_Dat.m_type,0,255);
		memcpy(m_Dat.m_type,"PRIVATE",sizeof("PRIVATE"));
		//strcpy(m_Dat.m_type,"PRIVATE");
		memset(m_Dat.m_talkingName,0,255);
		memcpy(m_Dat.m_talkingName,talkingName,talkingName.GetLength());
		//strcpy(m_Dat.m_talkingName,talkingName);
	}
	else
	{
		//strcpy(m_Dat.m_type,"MSG");
		memset(m_Dat.m_type,0,255);
		memcpy(m_Dat.m_type,"MSG",sizeof("MSG"));
	}
	memset(m_Dat.m_dbData,0,255);
	memcpy(m_Dat.m_dbData,m_send_info,m_send_info.GetLength());
	memset(m_Dat.m_strName,0,255);
	memcpy(m_Dat.m_strName,m_client_name,m_client_name.GetLength());
	//strcpy(m_Dat.m_strName,m_client_name);

	//3.������Ϣ
	int iSent=sockClient.Send(&m_Dat,sizeof(m_Dat));

	//4.�����͵���Ϣ��ʾ��������һ���б����
	if(iSent!=SOCKET_ERROR)
	{
		m_ctlRecvd.AddString(m_client_name+_T("˵��(")+m_systemTime+_T(")"));
		m_ctlRecvd.AddString(_T(" ")+m_send_info);
		m_send_info="";
		UpdateData(false);
	}
}


void CMyWcDlg::OnTimer(UINT nIDEvent) //��ʱ����Ϣ��Ӧ����
{
	// TODO: Add your message handler code here and/or call default
	UpdateData(true);
	CTime sTime=CTime::GetCurrentTime();
	CString sTimeSting=sTime.Format("%H:%M:%S");
	m_systemTime=sTimeSting;
	UpdateData(FALSE);

	CDialog::OnTimer(nIDEvent);
}

LRESULT CMyWcDlg::OnMyReceive(WPARAM wparam,LPARAM lparam)
{
	//�����յ�������
	_DATA *dat;
	dat=new _DATA;
	memcpy(dat,(_DATA*)wparam,sizeof(_DATA));

	int count=0;
	CString type=(CString)dat->m_type;			//��ȡ����
	CString name=(CString)dat->m_strName;		//��ȡ�ͻ���
	if(!type.Compare(_T("CLIENT")))				//֪ͨԭ�е����߿ͻ�
	{
		m_ctlName.InsertString(count,name);
		count++;
	}
	else if(!type.Compare(_T("CONNECTION")))	//֪ͨ�ͻ�����
	{
		m_ctlName.InsertString(count,name);
		count++;
	}
	else if(!type.Compare(_T("CLOSE")))			//֪ͨ�ͻ�����
	{
		int i=1;
		CString closeName;
		m_ctlName.GetText(i,closeName);
		while(1)								//�ӿͻ��б���ɾ�����߿ͻ�
		{
			if(!name.Compare(closeName))
			{
				m_ctlName.DeleteString(i);
				count--;
				break;
			}
			if(closeName=="")
				break;
			i++;
			m_ctlName.GetText(i,closeName);
		}
	}
	else if(!type.Compare(_T("PRIVATE")))		//�����Ļ��Ĵ���
	{
		CString str1=name;
		str1+=_T("����˵��(")+m_systemTime+_T(")");
		m_ctlRecvd.AddString(str1);
		str1=_T(" ");
		str1+=dat->m_dbData;
		m_ctlRecvd.AddString(str1);
	}
	else										//������Ϣ
	{
		CString str=(CString)dat->m_strName;
		str+=_T(":(")+m_systemTime+_T(")");
		m_ctlRecvd.AddString(str);
		str=_T(" ");
		str+=dat->m_dbData;
		m_ctlRecvd.AddString(str);
	}
	UpdateData(false);
	delete dat;
	return 1;
}

void CMyWcDlg::OnBnClickedCheck1() //ʵ��˽�����칦��
{
	// TODO: Add your control notification handler code here
	if(m_talk==false)
		GetDlgItem(IDC_LIST_NAME)->EnableWindow(true);
	else
	{
		GetDlgItem(IDC_LIST_NAME)->EnableWindow(false);
		m_ctlName.SetCurSel(0);
	}
}
