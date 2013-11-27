// MyThreadView.cpp : implementation of the CMyThreadView class
//

#include "stdafx.h"
#include "MyThread.h"

#include "MyThreadDoc.h"
#include "MyThreadView.h"

#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

volatile int ThreadCount=0;
volatile int ThreadFlag;

/////////////////////////////////////////////////////////////////////////////
// CMyThreadView

IMPLEMENT_DYNCREATE(CMyThreadView, CView)

BEGIN_MESSAGE_MAP(CMyThreadView, CView)
	//{{AFX_MSG_MAP(CMyThreadView)
	ON_COMMAND(ID_START_THREAD, OnStartThread)
	ON_COMMAND(ID_STOP_THREAD, OnStopThread)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_MESSAGE(WM_THREADENDED,OnThreadEnded)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyThreadView construction/destruction

CMyThreadView::CMyThreadView()
{
	// TODO: add construction code here

}

CMyThreadView::~CMyThreadView()
{
}

BOOL CMyThreadView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyThreadView drawing

void CMyThreadView::OnDraw(CDC* pDC)
{
	CMyThreadDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMyThreadView printing

BOOL CMyThreadView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyThreadView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyThreadView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyThreadView diagnostics

#ifdef _DEBUG
void CMyThreadView::AssertValid() const
{
	CView::AssertValid();
}

void CMyThreadView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyThreadDoc* CMyThreadView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyThreadDoc)));
	return (CMyThreadDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyThreadView message handlers

UINT ThreadProc(LPVOID param) //线程控制函数
{
	int i=0;
	double r=35.0;
	double alpha=3.14/30.0;	//表针一次走动所旋转的弧度数
	int cx,cy;				//表针的圆心

	//限制最多启动8个线程
	if(ThreadCount>=8)
	{
		MessageBeep((WORD)-1);
		return 0;
	}
	//确定各表针的圆心的坐标
	cx=50+(ThreadCount%4)*120;
	if(ThreadCount<4) cy=60;
	else cy=200;

	ThreadCount++;	//线程数增加
	CClientDC dc(((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView());
	dc.SetROP2(R2_NOT);
	dc.MoveTo(cx,cy);
	dc.LineTo(int(cx+r*cos(i*alpha)),int(cy+r*sin(i*alpha)));

	for(;;)	//无限循环，使秒针不停地旋转
	{
		//监视全局变量 ThreadFlag,若值为零则终止线程
		if(ThreadFlag==0) break;

		dc.LineTo(cx,cy);	//删除上一条表示秒针的直线
		//画一条秒针直线
		dc.LineTo(int(cx+r*cos(i*alpha)),int(cy+r*sin(i*alpha)));
		i++;
		if(i==60)
			i=0;
		::Sleep(500);	//延迟500 us
	}
	//发送消息 WM_THREADENDED
	::PostMessage((HWND)param,WM_THREADENDED,0,0);
	return 0;
}

void CMyThreadView::OnStartThread() //启动线程
{
	// TODO: Add your command handler code here
	HWND hWnd=GetSafeHwnd();
	AfxBeginThread(ThreadProc,hWnd);
	ThreadFlag=1;
}

void CMyThreadView::OnStopThread() //停止线程
{
	// TODO: Add your command handler code here
	ThreadFlag=0;	//设置线程标记为终止
}

LONG CMyThreadView::OnThreadEnded(WPARAM wParam,LPARAM lParam)
{
	CString str;
	str.Format(_T("%s %d %s"),_T("第"),ThreadCount--,_T("个线程终止"));
	MessageBox(str);
	return 0;
}