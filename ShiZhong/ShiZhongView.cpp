// ShiZhongView.cpp : implementation of the CShiZhongView class
//

#include "stdafx.h"
#include "ShiZhong.h"

#include "ShiZhongDoc.h"
#include "ShiZhongView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShiZhongView

IMPLEMENT_DYNCREATE(CShiZhongView, CFormView)

BEGIN_MESSAGE_MAP(CShiZhongView, CFormView)
	//{{AFX_MSG_MAP(CShiZhongView)
	ON_COMMAND(ID_TIME_START, OnTimeStart)
	ON_COMMAND(ID_TIME_STOP, OnTimeStop)
	ON_WM_TIMER()
	ON_WM_CANCELMODE()
	ON_UPDATE_COMMAND_UI(ID_TIME_START, OnUpdateTimeStart)
	ON_UPDATE_COMMAND_UI(ID_TIME_STOP, OnUpdateTimeStop)
	ON_COMMAND(ID_TIME_CURRENT, OnTimeCurrent)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShiZhongView construction/destruction

CShiZhongView::CShiZhongView()
	: CFormView(CShiZhongView::IDD)
	,m_strTime(_T(""))
	,m_timer(0)
	,m_btimer(true)
	,h(0)
	,m(0)
	,s(0)
	,ms(0)
{
	//{{AFX_DATA_INIT(CShiZhongView)
	m_strTime = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	
}

CShiZhongView::~CShiZhongView()
{
}

void CShiZhongView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShiZhongView)
	DDX_Text(pDX, IDC_TIME, m_strTime);
	//}}AFX_DATA_MAP
}

BOOL CShiZhongView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CShiZhongView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

}

/////////////////////////////////////////////////////////////////////////////
// CShiZhongView printing

BOOL CShiZhongView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CShiZhongView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CShiZhongView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CShiZhongView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CShiZhongView diagnostics

#ifdef _DEBUG
void CShiZhongView::AssertValid() const
{
	CFormView::AssertValid();
}

void CShiZhongView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CShiZhongDoc* CShiZhongView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CShiZhongDoc)));
	return (CShiZhongDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShiZhongView message handlers

void CShiZhongView::OnTimeStart() 
{
	// TODO: Add your command handler code here
	m_timer=SetTimer(1,100,NULL);//设置定时器
	m_btimer=FALSE;
}

void CShiZhongView::OnTimeStop() 
{
	// TODO: Add your command handler code here
	KillTimer(m_timer);//销毁定时器
	m_btimer=TRUE;
}

void CShiZhongView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	m_strTime.Format("%d:%d:%d.%d ",h,m,s,ms);
	UpdateData(FALSE);//刷新控件显示
	ms++;
	if(ms==10){ms=0;s++;}
	if(s==60){s=0;m++;}
	if(m==60){m=0;h++;}
	CFormView::OnTimer(nIDEvent);
}

void CShiZhongView::OnCancelMode() 
{
	CFormView::OnCancelMode();
	
	// TODO: Add your message handler code here
	
}

void CShiZhongView::OnUpdateTimeStart(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(!m_btimer)
		pCmdUI->Enable(FALSE);
}

void CShiZhongView::OnUpdateTimeStop(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	if(m_btimer)
		pCmdUI->Enable(FALSE);
}



void CShiZhongView::OnTimeCurrent() 
{
	// TODO: Add your command handler code here
	OnTimeStop();
	CTime t=CTime::GetCurrentTime();
	CString str;
	str.Format("Current Time is %02d:%02d:%02d",t.GetHour(),t.GetMinute(),t.GetSecond());
	MessageBox(str,NULL,MB_OK);
	h=m=s=ms=0;
	m_strTime.Format("%02d:%02d:%02d.%01d",h,m,s,ms);
	UpdateData(FALSE);
}
