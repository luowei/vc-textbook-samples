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

//ȫ�ֱ���
int count=0;
CCriticalSection critical;

UINT NosynFunction(LPVOID param)	//��ͬ���߳̿��ƺ���
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

//ʹ���ٽ�����������߳�ͬ��
UINT SynchroFunction(LPVOID param)		//ͬ���߳̿��ƺ���
{
	int Data[5],i;
	critical.Lock();		//�����ٽ�������
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
	critical.Unlock();		//�ͷŸ��̶߳��ٽ����Ŀ���Ȩ
	::MessageBox((HWND)param,str,_T("synchro Thread"),MB_OK);
	return 0;
}

//ʹ�û����������߳�ͬ��
CMutex mutex;
UINT SynchroFunction1(LPVOID param)	//ͬ���߳̿��ƺ���
{
	CSingleLock singleLock(&mutex);	//�û�����󱣻�����
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
	//critical.Unlock();		//�ͷŸ��̶߳��ٽ����Ŀ���Ȩ
	::MessageBox((HWND)param,str,_T("synchro Thread"),MB_OK);
	return 0;
}

//ʹ���ź�����������߳�ͬ��
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

void CMySyn1View::OnSynchro() //ͬ����ʽ����3���߳�
{
	// TODO: Add your command handler code here
	count=0;
	HWND hWnd=GetSafeHwnd();

	//ʹ���ٽ�����������߳�ͬ��
//	AfxBeginThread(SynchroFunction,hWnd);
//	AfxBeginThread(SynchroFunction,hWnd);
//	AfxBeginThread(SynchroFunction,hWnd);

	//ʹ�û����������߳�ͬ��
//	AfxBeginThread(SynchroFunction1,hWnd);
//	AfxBeginThread(SynchroFunction1,hWnd);
//	AfxBeginThread(SynchroFunction1,hWnd);

	//ʹ���ź�����������߳�ͬ��
	AfxBeginThread(SynchroFunction2,hWnd);
	AfxBeginThread(SynchroFunction2,hWnd);
	AfxBeginThread(SynchroFunction2,hWnd);
}



void CMySyn1View::OnNosyn() //��ͬ����ʽ����3���߳�
{
	// TODO: Add your command handler code here
	count=0;
	HWND hWnd=GetSafeHwnd();
	AfxBeginThread(NosynFunction,hWnd);
	AfxBeginThread(NosynFunction,hWnd);
	AfxBeginThread(NosynFunction,hWnd);
}
