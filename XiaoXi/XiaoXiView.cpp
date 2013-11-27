// XiaoXiView.cpp : implementation of the CXiaoXiView class
//

#include "stdafx.h"
#include "XiaoXi.h"

#include "XiaoXiDoc.h"
#include "XiaoXiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXiaoXiView

IMPLEMENT_DYNCREATE(CXiaoXiView, CView)

BEGIN_MESSAGE_MAP(CXiaoXiView, CView)
	//{{AFX_MSG_MAP(CXiaoXiView)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_CHAR()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_MESSAGE(WM_USERMSG,OnMyFunction)  //消息映射声明
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXiaoXiView construction/destruction

CXiaoXiView::CXiaoXiView()
{
	// TODO: add construction code here
	m_sMousePoint="";
	m_nLine=0;
}

CXiaoXiView::~CXiaoXiView()
{
}

BOOL CXiaoXiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CXiaoXiView drawing

void CXiaoXiView::OnDraw(CDC* pDC)
{
	CXiaoXiDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(300,200,m_sMousePoint);
	pDC->TextOut(0,m_nLine*20,m_strDisplay);
}

/////////////////////////////////////////////////////////////////////////////
// CXiaoXiView printing

BOOL CXiaoXiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CXiaoXiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CXiaoXiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CXiaoXiView diagnostics

#ifdef _DEBUG
void CXiaoXiView::AssertValid() const
{
	CView::AssertValid();
}

void CXiaoXiView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CXiaoXiDoc* CXiaoXiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CXiaoXiDoc)));
	return (CXiaoXiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXiaoXiView message handlers

void CXiaoXiView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_sMousePoint.Format("鼠标左键在点(%d,%d)按下",point.x,point.y);
	Invalidate();
	CView::OnLButtonDown(nFlags, point);
}

void CXiaoXiView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_sMousePoint.Format("鼠标左键被释放");
	Invalidate();
	
	CView::OnLButtonUp(nFlags, point);
}

void CXiaoXiView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	m_sMousePoint.Format("鼠标箭头指在点(%d,%d)",point.x,point.y);
	Invalidate();
	
	CView::OnMouseMove(nFlags, point);
}

void CXiaoXiView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(VK_RETURN==nChar)
	{
		m_strDisplay.Empty();
		m_nLine++;
	}
	else
	{
		m_strDisplay+=(TCHAR)nChar;
	}
	CClientDC dc(this);
	dc.TextOut(0,m_nLine*20,m_strDisplay);
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CXiaoXiView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();
	
	// TODO: Add your specialized code here and/or call the base class
	SetTimer(1,1000,NULL);	//安装定时器
}

void CXiaoXiView::OnDestroy() 
{
	CView::OnDestroy();
	
	// TODO: Add your message handler code here
	KillTimer(1);		//清除1号定时器
}

void CXiaoXiView::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	MessageBeep(-1);
	CView::OnTimer(nIDEvent);
}

LRESULT CXiaoXiView::OnMyFunction(WPARAM wParam,LPARAM lParam)
{
	AfxMessageBox("恭喜你，消息发送成功！");
	return NULL;
}

void CXiaoXiView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	HWND hWnd=GetSafeHwnd();
	if(VK_UP==nChar)
	{
		::PostMessage(hWnd,WM_USERMSG,0,0);
		return;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
