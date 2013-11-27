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

UINT ThreadProc(LPVOID param) //�߳̿��ƺ���
{
	int i=0;
	double r=35.0;
	double alpha=3.14/30.0;	//����һ���߶�����ת�Ļ�����
	int cx,cy;				//�����Բ��

	//�����������8���߳�
	if(ThreadCount>=8)
	{
		MessageBeep((WORD)-1);
		return 0;
	}
	//ȷ���������Բ�ĵ�����
	cx=50+(ThreadCount%4)*120;
	if(ThreadCount<4) cy=60;
	else cy=200;

	ThreadCount++;	//�߳�������
	CClientDC dc(((CFrameWnd*)(AfxGetApp()->m_pMainWnd))->GetActiveView());
	dc.SetROP2(R2_NOT);
	dc.MoveTo(cx,cy);
	dc.LineTo(int(cx+r*cos(i*alpha)),int(cy+r*sin(i*alpha)));

	for(;;)	//����ѭ����ʹ���벻ͣ����ת
	{
		//����ȫ�ֱ��� ThreadFlag,��ֵΪ������ֹ�߳�
		if(ThreadFlag==0) break;

		dc.LineTo(cx,cy);	//ɾ����һ����ʾ�����ֱ��
		//��һ������ֱ��
		dc.LineTo(int(cx+r*cos(i*alpha)),int(cy+r*sin(i*alpha)));
		i++;
		if(i==60)
			i=0;
		::Sleep(500);	//�ӳ�500 us
	}
	//������Ϣ WM_THREADENDED
	::PostMessage((HWND)param,WM_THREADENDED,0,0);
	return 0;
}

void CMyThreadView::OnStartThread() //�����߳�
{
	// TODO: Add your command handler code here
	HWND hWnd=GetSafeHwnd();
	AfxBeginThread(ThreadProc,hWnd);
	ThreadFlag=1;
}

void CMyThreadView::OnStopThread() //ֹͣ�߳�
{
	// TODO: Add your command handler code here
	ThreadFlag=0;	//�����̱߳��Ϊ��ֹ
}

LONG CMyThreadView::OnThreadEnded(WPARAM wParam,LPARAM lParam)
{
	CString str;
	str.Format(_T("%s %d %s"),_T("��"),ThreadCount--,_T("���߳���ֹ"));
	MessageBox(str);
	return 0;
}