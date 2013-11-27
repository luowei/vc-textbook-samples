// MySyn1View.cpp : implementation of the CMySyn1View class
//

#include "stdafx.h"
#include "MySyn1.h"

#include "MySyn1Doc.h"
#include "MySyn1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


#include "afxmt.h"

//全局变量
int count=0;
CCriticalSection critical;

UINT NosynFunction(LPVOID param)	//非同步线程控制函数
{
	int Data[5],i;
	for(i=0;i<3;i++)
	{
		count++;
		::Sleep(50);
		Data[i]=count;
	}
	TCHAR str[50];
	str[0]=0;
	for(i=0;i<3;i++)
	{
		int len=lstrlen((LPTSTR)str);
		wsprintf((LPTSTR)&str[len],_T("%d"),Data[i]);
	}
	::MessageBox((HWND)param,str,_T("Nonsyn Thread"),MB_OK);
	return 0;
}

//使用临界区对象进行线程同步
UINT SynchroFunction(LPVOID param)		//同步线程控制函数
{
	int Data[5],i;
	critical.Lock();		//保护临界区数据
	for(i=0;i<3;i++)
	{
		count++;
		::Sleep(50);
		Data[i]=count;
	}
	TCHAR str[50];
	str[0]=0;
	for(i=0;i<3;i++)
	{
		int len=lstrlen((LPTSTR)str);
		wsprintf((LPTSTR)&str[len],_T("%d"),Data[i]);
	}
	critical.Unlock();		//释放该线程对临界区的控制权
	::MessageBox((HWND)param,str,_T("synchro Thread"),MB_OK);
	return 0;
}

//使用互斥对象进行线程同步
CMutex mutex;
UINT SynchroFunction1(LPVOID param)	//同步线程控制函数
{
	CSingleLock singleLock(&mutex);	//用互斥对象保护数据
	singleLock.Lock();
	int Data[5],i;
	//critical.Lock();
	for(i=0;i<3;i++)
	{
		count++;
		::Sleep(50);
		Data[i]=count;
	}
	TCHAR str[50];
	str[0]=0;
	for(i=0;i<3;i++)
	{
		int len=lstrlen((LPTSTR)str);
		wsprintf((LPTSTR)&str[len],_T("%d"),Data[i]);
	}
	singleLock.Unlock();
	//critical.Unlock();		//释放该线程对临界区的控制权
	::MessageBox((HWND)param,str,_T("synchro Thread"),MB_OK);
	return 0;
}

//使用信号量对象进行线程同步
CSemaphore *sema=new CSemaphore(2,2);

UINT SynchroFunction2(LPVOID param)
{
	int Data[5],i;
	CSingleLock singleLock(sema);
	singleLock.Lock();
	for(i=0;i<3;i++)
	{
		count++;
		::Sleep(50);
		Data[i]=count;
	}
	TCHAR str[50];
	str[0]=0;
	for(i=0;i<3;i++)
	{
		int len=lstrlen((LPTSTR)str);
		wsprintf((LPTSTR)&str[len],_T("%d"),Data[i]);
	}
	::Sleep(5000);
	singleLock.Unlock();
	::MessageBox((HWND)param,str,_T("synchro Thread"),MB_OK);
	return 0;
}


/////////////////////////////////////////////////////////////////////////////
// CMySyn1View

IMPLEMENT_DYNCREATE(CMySyn1View, CView)

BEGIN_MESSAGE_MAP(CMySyn1View, CView)
	//{{AFX_MSG_MAP(CMySyn1View)
	ON_COMMAND(ID_SYNCHRO, OnSynchro)
	ON_COMMAND(ID_NOSYN, OnNosyn)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMySyn1View construction/destruction

CMySyn1View::CMySyn1View()
{
	// TODO: add construction code here

}

CMySyn1View::~CMySyn1View()
{
}

BOOL CMySyn1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMySyn1View drawing

void CMySyn1View::OnDraw(CDC* pDC)
{
	CMySyn1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CMySyn1View printing

BOOL CMySyn1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMySyn1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMySyn1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMySyn1View diagnostics

#ifdef _DEBUG
void CMySyn1View::AssertValid() const
{
	CView::AssertValid();
}

void CMySyn1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMySyn1Doc* CMySyn1View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySyn1Doc)));
	return (CMySyn1Doc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMySyn1View message handlers

void CMySyn1View::OnSynchro() //同步方式启动3个线程
{
	// TODO: Add your command handler code here
	count=0;
	HWND hWnd=GetSafeHwnd();

	//使用临界区对象进行线程同步
//	AfxBeginThread(SynchroFunction,hWnd);
//	AfxBeginThread(SynchroFunction,hWnd);
//	AfxBeginThread(SynchroFunction,hWnd);

	//使用互斥对象进行线程同步
//	AfxBeginThread(SynchroFunction1,hWnd);
//	AfxBeginThread(SynchroFunction1,hWnd);
//	AfxBeginThread(SynchroFunction1,hWnd);

	//使用信号量对象进行线程同步
	AfxBeginThread(SynchroFunction2,hWnd);
	AfxBeginThread(SynchroFunction2,hWnd);
	AfxBeginThread(SynchroFunction2,hWnd);
}



void CMySyn1View::OnNosyn() //非同步方式启动3个线程
{
	// TODO: Add your command handler code here
	count=0;
	HWND hWnd=GetSafeHwnd();
	AfxBeginThread(NosynFunction,hWnd);
	AfxBeginThread(NosynFunction,hWnd);
	AfxBeginThread(NosynFunction,hWnd);
}
