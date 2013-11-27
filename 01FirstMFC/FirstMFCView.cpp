// FirstMFCView.cpp : implementation of the CFirstMFCView class
//

#include "stdafx.h"
#include "FirstMFC.h"

#include "FirstMFCDoc.h"
#include "FirstMFCView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCView

IMPLEMENT_DYNCREATE(CFirstMFCView, CFormView)

BEGIN_MESSAGE_MAP(CFirstMFCView, CFormView)
	//{{AFX_MSG_MAP(CFirstMFCView)
	ON_COMMAND(ID_NOMODALLESS, OnNomodalless)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCView construction/destruction

CFirstMFCView::CFirstMFCView()
	: CFormView(CFirstMFCView::IDD)
{
	//{{AFX_DATA_INIT(CFirstMFCView)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_pModallessDlg=NULL; //初始化指针
}

CFirstMFCView::~CFirstMFCView()
{
	if(m_pModallessDlg!=NULL)
		delete m_pModallessDlg;//释放空间
}

void CFirstMFCView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFirstMFCView)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BOOL CFirstMFCView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CFirstMFCView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCView printing

BOOL CFirstMFCView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CFirstMFCView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CFirstMFCView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CFirstMFCView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCView diagnostics

#ifdef _DEBUG
void CFirstMFCView::AssertValid() const
{
	CFormView::AssertValid();
}

void CFirstMFCView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CFirstMFCDoc* CFirstMFCView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFirstMFCDoc)));
	return (CFirstMFCDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFirstMFCView message handlers
//对非模式对话框菜单项响应，调用非模式对话框
void CFirstMFCView::OnNomodalless()  
{
	// TODO: Add your command handler code here
	if(m_pModallessDlg==NULL)//如果指针指向NULL,说明对话框还没有创建，动态创建
	{
		m_pModallessDlg=new CPasswordDialog;
		m_pModallessDlg->Create(IDD_PASSWORD_DIALOG,this);
	}
	m_pModallessDlg->ShowWindow(SW_SHOW);
}
