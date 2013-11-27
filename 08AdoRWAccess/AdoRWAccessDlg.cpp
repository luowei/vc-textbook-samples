// AdoRWAccessDlg.cpp : implementation file
//

#include "stdafx.h"
#include "AdoRWAccess.h"
#include "AdoRWAccessDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CAdoRWAccessApp theApp;	//引入外部定义的程序对象

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
// CAdoRWAccessDlg dialog

CAdoRWAccessDlg::CAdoRWAccessDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAdoRWAccessDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdoRWAccessDlg)
	m_address = _T("");
	m_name = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAdoRWAccessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdoRWAccessDlg)
	DDX_Control(pDX, IDC_MODIFY, m_modify);
	DDX_Control(pDX, IDC_LISTDATABASE, m_listdatabase);
	DDX_Control(pDX, IDC_EXITSYS, m_exit);
	DDX_Control(pDX, IDC_DELETE, m_delete);
	DDX_Control(pDX, IDC_ADD, m_add);
	DDX_Control(pDX, IDC_LISTALL, m_listall);
	DDX_Text(pDX, IDC_ADDRESS, m_address);
	DDX_Text(pDX, IDC_NAME, m_name);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAdoRWAccessDlg, CDialog)
	//{{AFX_MSG_MAP(CAdoRWAccessDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LISTALL, OnListall)
	ON_BN_CLICKED(IDC_ADD, OnBnClickedAdd)
	ON_LBN_SELCHANGE(IDC_LISTDATABASE, OnLbnSelchangeListdatabase)
	ON_BN_CLICKED(IDC_DELETE, OnBnClickedDelete)
	ON_BN_CLICKED(IDC_MODIFY, OnBnClickedModify)
	ON_BN_CLICKED(IDC_EXITSYS, OnBnClickedExitsys)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdoRWAccessDlg message handlers

BOOL CAdoRWAccessDlg::OnInitDialog()
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
	m_pRecordset.CreateInstance(_uuidof(Recordset));
	//在ADO操作中建议用try...catch()语句来捕获意想不到的错误信息
	try
	{
		m_pRecordset->Open("SELECT * FROM Table1",	//查询Table1表中的所有字段
			theApp.m_pConnection.GetInterfacePtr(),	//获取链接库的IDispatch指针
			adOpenDynamic,
			adLockOptimistic,
			adCmdText);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CAdoRWAccessDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CAdoRWAccessDlg::OnPaint() 
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
HCURSOR CAdoRWAccessDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAdoRWAccessDlg::OnListall() 
{
	// TODO: Add your control notification handler code here
	_variant_t var;
	CString strName,strAddress;
	//清空列表框
	m_listdatabase.ResetContent();	//每次读取内容前先清空listbox内容
	strName=strAddress="";
	try
	{
		if(!m_pRecordset->BOF)m_pRecordset->MoveFirst();
		else
		{
			AfxMessageBox("表内数据为空");
			return;
		}
		//读入库中各字段并将其加入列表框中
		while(!m_pRecordset->adoEOF)
		{
			var=m_pRecordset->GetCollect("name");
			if(var.vt!=VT_NULL)
				strName=(LPCSTR)_bstr_t(var);
			var=m_pRecordset->GetCollect("address");
			if(var.vt!=VT_NULL)
				strAddress=(LPCSTR)_bstr_t(var);
			m_listdatabase.AddString(strName+"	"+strAddress);
			m_pRecordset->MoveNext();
			
		}
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void CAdoRWAccessDlg::OnBnClickedAdd() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_name==""||m_address=="")
	{
		AfxMessageBox("姓名和籍贯信息不能为空！");
		return;
	}
	try
	{
		//写入呼字段值
		m_pRecordset->AddNew();
		m_pRecordset->PutCollect("name",_variant_t(m_name));
		m_pRecordset->PutCollect("address",_variant_t(m_address));
		m_pRecordset->Update();
		//更新并显示其库中的内容
		int nCurSel=m_listdatabase.GetCurSel();
		OnListall();
		m_listdatabase.SetCurSel(nCurSel);
		OnLbnSelchangeListdatabase();
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void CAdoRWAccessDlg::OnLbnSelchangeListdatabase() 
{
	// TODO: Add your control notification handler code here
	int curSel=m_listdatabase.GetCurSel();
	if(curSel<0) return;
	_variant_t var;
	try
	{
		//先将指针移向第1条记录，然后就可以相对第1条记录来随意移动记录指针
		m_pRecordset->MoveFirst();
		m_pRecordset->Move(long(curSel));
		var=m_pRecordset->GetCollect("name");
		if(var.vt!=VT_NULL)
			m_name=(LPCSTR)_bstr_t(var);
		var=m_pRecordset->GetCollect("address");
		if(var.vt!=VT_NULL)
			m_address=(LPCSTR)_bstr_t(var);
		UpdateData(false);
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void CAdoRWAccessDlg::OnBnClickedDelete() 
{
	// TODO: Add your control notification handler code here
	if(m_listdatabase.GetCount()==0) return;
	else if(m_listdatabase.GetCurSel()<0 || 
		m_listdatabase.GetCurSel()>m_listdatabase.GetCount())
		m_listdatabase.SetCurSel(0);
	try
	{
		m_pRecordset->Delete(adAffectCurrent);
		m_pRecordset->Update();
		int nCurSel=m_listdatabase.GetCurSel();
		m_listdatabase.DeleteString(nCurSel);
		if(nCurSel-0 && (m_listdatabase.GetCount()!=0))
			m_listdatabase.SetCurSel(nCurSel);
		else if(m_listdatabase.GetCount()!=0)
			m_listdatabase.SetCurSel(nCurSel-1);
		OnLbnSelchangeListdatabase();
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void CAdoRWAccessDlg::OnBnClickedModify() 
{
	// TODO: Add your control notification handler code here
	UpdateData();
	if(m_listdatabase.GetCount()==0||m_name==""||m_address=="")
	{
		AfxMessageBox("表中的记录数为空或姓名和籍贯信息没有设置！");
		return;
	}
	else if(m_listdatabase.GetCurSel()<0||
		m_listdatabase.GetCurSel()>m_listdatabase.GetCount())
		m_listdatabase.SetCurSel(0);
	try
	{
		//修改当前记录的字段值
		m_pRecordset->PutCollect("name",_variant_t(m_name));
		m_pRecordset->PutCollect("address",_variant_t(m_address));
		m_pRecordset->Update();
		//重新读入库中的记录，以更新显示
		int nCurSel=m_listdatabase.GetCurSel();
		OnListall();
		m_listdatabase.SetCurSel(nCurSel);
		//移动记录指针到新的位置
		OnLbnSelchangeListdatabase();
	}
	catch(_com_error *e)
	{
		AfxMessageBox(e->ErrorMessage());
	}
}

void CAdoRWAccessDlg::OnBnClickedExitsys() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnOK();
}
