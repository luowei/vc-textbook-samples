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
	m_server_name = _T("localhost");	//手工修改为本机名
	m_nPort = 800;			//手工修改为默认值800
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
	DDV_MaxChars(pDX,m_client_name,20);				//限制变量最大字符长度20
	DDX_Text(pDX, IDC_SERVER_NAME, m_server_name);
	DDV_MaxChars(pDX,m_server_name,30);				//限制变量最大字符长度30
	DDX_Text(pDX, IDC_SERVER_PORT, m_nPort);
	DDV_MinMaxInt(pDX,m_nPort,0,1024);				//限制变量范围
	DDX_Text(pDX, IDC_SEND_INFO, m_send_info);
	DDV_MaxChars(pDX,m_send_info,500);				//限制变量最大字符长度500
	DDX_Text(pDX, IDC_EDIT_TIME, m_systemTime);
	DDV_MaxChars(pDX,m_systemTime,100);				//限制变量最大字符长度100
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
	ON_MESSAGE(RE_RECEIVED,OnMyReceive)		//自定义消息映射
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
	//添加对保存在线客户列表框的初始化语句
	m_ctlName.InsertString(0,"所有人");
	m_ctlName.SetCurSel(0);
	UpdateData(false);
	
	SetTimer(1,100,NULL);	//安装定时器
	//控件状态更新
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

void CMyWcDlg::OnBnClickedConnect() //连接服务器进入聊天室(上线)
{
	// TODO: Add your control notification handler code here
	//1.更新关联变量，如服务器名、端口号
	UpdateData(true);
	CString cName=m_client_name;
	if(!cName.Compare(_T("")))
	{
		AfxMessageBox(_T("Client's name can not be full"));
		return;
	}

	//2.创建套接字，建立与服务器的连接
	if(!sockClient.Create())
	{
		AfxMessageBox(_T("create WC socket failed"));
		PostQuitMessage(0);
	}
	if(!sockClient.Connect(m_server_name,m_nPort))
	{
		if(sockClient!=NULL) sockClient.Close();
		MessageBox(_T("连接失败！"));
		return;
	}

	//3.向服务器发送客户资料，如用户名
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
	//1.向服务器报告下线信息
	memset(m_Dat.m_type,0,255);
	memcpy(m_Dat.m_type,"CLOSE",sizeof("CLOSE"));
	sockClient.Send(&m_Dat,sizeof(m_Dat));

	//2.断开与服务顺手连接
	sockClient.Close();

	//3.退出系统
	exit(0);
}

void CMyWcDlg::OnBnClickedSend() //实现聊天信息的发送
{
	// TODO: Add your control notification handler code here
	//1.更新关联变量，如要发送的信息
	UpdateData(true);
	CString talkingName;
	m_ctlName.GetText(m_ctlName.GetCurSel(),talkingName);

	//2.对聊天类型进行判断，填写数据包各个字段的数据
	if(talkingName!="所有人")
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

	//3.发送消息
	int iSent=sockClient.Send(&m_Dat,sizeof(m_Dat));

	//4.将发送的消息显示在聊天室一键列表框中
	if(iSent!=SOCKET_ERROR)
	{
		m_ctlRecvd.AddString(m_client_name+_T("说：(")+m_systemTime+_T(")"));
		m_ctlRecvd.AddString(_T(" ")+m_send_info);
		m_send_info="";
		UpdateData(false);
	}
}


void CMyWcDlg::OnTimer(UINT nIDEvent) //定时器消息响应函数
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
	//处理收到的数据
	_DATA *dat;
	dat=new _DATA;
	memcpy(dat,(_DATA*)wparam,sizeof(_DATA));

	int count=0;
	CString type=(CString)dat->m_type;			//提取类型
	CString name=(CString)dat->m_strName;		//提取客户名
	if(!type.Compare(_T("CLIENT")))				//通知原有的在线客户
	{
		m_ctlName.InsertString(count,name);
		count++;
	}
	else if(!type.Compare(_T("CONNECTION")))	//通知客户上线
	{
		m_ctlName.InsertString(count,name);
		count++;
	}
	else if(!type.Compare(_T("CLOSE")))			//通知客户下线
	{
		int i=1;
		CString closeName;
		m_ctlName.GetText(i,closeName);
		while(1)								//从客户列表中删除下线客户
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
	else if(!type.Compare(_T("PRIVATE")))		//对悄悄话的处理
	{
		CString str1=name;
		str1+=_T("对你说：(")+m_systemTime+_T(")");
		m_ctlRecvd.AddString(str1);
		str1=_T(" ");
		str1+=dat->m_dbData;
		m_ctlRecvd.AddString(str1);
	}
	else										//公众消息
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

void CMyWcDlg::OnBnClickedCheck1() //实现私人聊天功能
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
