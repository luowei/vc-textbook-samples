// CalculatorDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Calculator.h"
#include "CalculatorDlg.h"
#include "Math.h"

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
// CCalculatorDlg dialog

CCalculatorDlg::CCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCalculatorDlg::IDD, pParent)
	,m_display(_T("0.0"))
	,m_first(0.0)
	,m_second(0.0)
	,m_coff(1.0)
	,m_operator(_T("+"))
{
//	m_display=_T("0.0");
//	m_first=0.0;
//	m_second=0.0;
//	m_coff=1.0;
//	m_operator=_T("+");
	//{{AFX_DATA_INIT(CCalculatorDlg)
	m_display = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCalculatorDlg)
	DDX_Text(pDX, IDC_DISPLAY, m_display);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCalculatorDlg, CDialog)
	//{{AFX_MSG_MAP(CCalculatorDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_0, OnButton0)
	ON_BN_CLICKED(IDC_BUTTON_1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON_2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON_3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON_4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON_5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON_6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON_7, OnButton7)
	ON_BN_CLICKED(IDC_BUTTON_8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON_9, OnButton9)
	ON_BN_CLICKED(IDC_BUTTON_ADD, OnButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_CLEAR, OnButtonClear)
	ON_BN_CLICKED(IDC_BUTTON_DIV, OnButtonDiv)
	ON_BN_CLICKED(IDC_BUTTON_EQUAL, OnButtonEqual)
	ON_BN_CLICKED(IDC_BUTTON_MINUS, OnButtonMinus)
	ON_BN_CLICKED(IDC_BUTTON_MULTIPLY, OnButtonMultiply)
	ON_BN_CLICKED(IDC_BUTTON_POINT, OnButtonPoint)
	ON_BN_CLICKED(IDC_BUTTON_RECIPROCAL, OnButtonReciprocal)
	ON_BN_CLICKED(IDC_BUTTON_SIGN, OnButtonSign)
	ON_BN_CLICKED(IDC_BUTTON_SQRT, OnButtonSqrt)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg message handlers

BOOL CCalculatorDlg::OnInitDialog()
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

void CCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCalculatorDlg::OnPaint() 
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
HCURSOR CCalculatorDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


void CCalculatorDlg::OnButton0() 
{
	// TODO: Add your control notification handler code here
	if(1.0==m_coff)
	{
		m_second=m_second*10+0;
	}
	else
	{
		m_second=m_second;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	if(1.0==m_coff)
	{
		m_second=m_second*10+1;
	}
	else
	{
		m_second=m_second+1*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	if(1.0==m_coff)
	{
		m_second=m_second*10+2;
	}
	else
	{
		m_second=m_second+2*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	if(1.0==m_coff)
	{
		m_second=m_second*10+3;
	}
	else
	{
		m_second=m_second+3*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	if(1.0==m_coff)
	{
		m_second=m_second*10+4;
	}
	else
	{
		m_second=m_second+4*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
	if(1.0==m_coff)
	{
		m_second=m_second*10+5;
	}
	else
	{
		m_second=m_second+5*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	if(1.0==m_coff)
	{
		m_second=m_second*10+6;
	}
	else
	{
		m_second=m_second+6*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	if(1.0==m_coff)
	{
		m_second=m_second*10+7;
	}
	else
	{
		m_second=m_second+7*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButton8() 
{
	// TODO: Add your control notification handler code here
	if(1.0==m_coff)
	{
		m_second=m_second*10+8;
	}
	else
	{
		m_second=m_second+8*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButton9() 
{
	// TODO: Add your control notification handler code here
	if(1.0==m_coff)
	{
		m_second=m_second*10+9;
	}
	else
	{
		m_second=m_second+9*m_coff;
		m_coff*=0.1;
	}
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButtonAdd() 
{
	// TODO: Add your control notification handler code here
	Calculate();
	m_operator="+";
}

void CCalculatorDlg::OnButtonClear() 
{
	// TODO: Add your control notification handler code here
	m_second=0.0;
	m_operator="+";
	m_coff=1.0;
	UpdateDisplay(0.0);
}

void CCalculatorDlg::OnButtonDiv() 
{
	// TODO: Add your control notification handler code here
	Calculate();
	m_operator="/";
}

void CCalculatorDlg::OnButtonEqual()
{
	// TODO: Add your control notification handler code here
	Calculate();
	m_first=0.0;
	m_operator="+";
}

void CCalculatorDlg::OnButtonMinus() 
{
	// TODO: Add your control notification handler code here
	Calculate();
	m_operator="-";
}

void CCalculatorDlg::OnButtonMultiply() 
{
	// TODO: Add your control notification handler code here
	Calculate();
	m_operator="*";
}

void CCalculatorDlg::OnButtonPoint() 
{
	// TODO: Add your control notification handler code here
	m_coff=0.1;
}

void CCalculatorDlg::OnButtonReciprocal() 
{
	// TODO: Add your control notification handler code here
	if(fabs(m_second)<=0.000001)
	{
		m_display="除数不能等于0";
		UpdateData(false);
		return;
	}
	m_second=1.0/m_second;
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButtonSign() 
{
	// TODO: Add your control notification handler code here
	m_second=-m_second;
	UpdateDisplay(m_second);
}

void CCalculatorDlg::OnButtonSqrt() 
{
	// TODO: Add your control notification handler code here
	m_second=sqrt(m_second);
	UpdateDisplay(m_second);
}

void CCalculatorDlg::Calculate()
{
	switch(m_operator.GetAt(0))
	{
	case '+':
		m_first+=m_second;
		break;
	case '-':
		m_first-=m_second;
		break;
	case '*':
		m_first*=m_second;
		break;
	case'/':
		if(fabs(m_second)<=0.000001)
		{
			m_display="除数不能等于零";
			UpdateData(false);
			return;
		}
		m_first/=m_second;
		break;
	}
	m_second=0.0;
	m_coff=1.0;
	UpdateDisplay(m_first);
}

void CCalculatorDlg::UpdateDisplay(double lVal)
{
	m_display.Format(_T("%f"),lVal);
	int i=m_display.GetLength();
	while(m_display.GetAt(i-1)=='0')
	{
		m_display.Delete(i-1,1);
		i--;
	}
	UpdateData(false);
}

