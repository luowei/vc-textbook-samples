// MyDrawView.cpp : implementation of the CMyDrawView class
//

#include "stdafx.h"
#include "MyDraw.h"

#include "MyDrawDoc.h"
#include "MyDrawView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView

IMPLEMENT_DYNCREATE(CMyDrawView, CView)

BEGIN_MESSAGE_MAP(CMyDrawView, CView)
	//{{AFX_MSG_MAP(CMyDrawView)
	ON_COMMAND(ID_SHOWBITMAP, OnShowbitmap)
	ON_COMMAND(ID_Dbmp, OnDbmp)
	ON_WM_CREATE()
	ON_COMMAND(ID_COLOR, OnColor)
	ON_COMMAND(ID_LINE, OnLine)
	ON_COMMAND(ID_RECT, OnRect)
	ON_COMMAND(ID_ELLIRECT, OnEllirect)
	ON_COMMAND(ID_ELLIPSE, OnEllipse)
	ON_COMMAND(ID_WIDTH1, OnWidth1)
	ON_COMMAND(ID_WIDTH2, OnWidth2)
	ON_COMMAND(ID_WIDTH3, OnWidth3)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_UPDATE_COMMAND_UI(ID_LINE, OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_RECT, OnUpdateRect)
	ON_UPDATE_COMMAND_UI(ID_ELLIRECT, OnUpdateEllirect)
	ON_UPDATE_COMMAND_UI(ID_ELLIPSE, OnUpdateEllipse)
	ON_UPDATE_COMMAND_UI(ID_WIDTH1, OnUpdateWidth1)
	ON_UPDATE_COMMAND_UI(ID_WIDTH2, OnUpdateWidth2)
	ON_UPDATE_COMMAND_UI(ID_WIDTH3, OnUpdateWidth3)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView construction/destruction

CMyDrawView::CMyDrawView()
	:m_type(0)
	,m_nmx(0)
	,m_nmy(0)
	,m_width(0)
	,m_pold(0)
	,m_pnew(0)
	,m_bdoing(false)
{
	// TODO: add construction code here
	m_color=RGB(0,0,255);
	m_pmdc=new CDC;
	m_pbmp=new CBitmap;
}

CMyDrawView::~CMyDrawView()
{
	delete m_pmdc;
	delete m_pbmp;
}

BOOL CMyDrawView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView drawing

void CMyDrawView::OnDraw(CDC* pDC)
{
	CMyDrawDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	CBitmap* poldbmp=m_pmdc->SelectObject(m_pbmp);
	pDC->BitBlt(0,0,m_nmx,m_nmy,m_pmdc,0,0,SRCCOPY);
	m_pmdc->SelectObject(poldbmp);
}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView printing

BOOL CMyDrawView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMyDrawView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMyDrawView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView diagnostics

#ifdef _DEBUG
void CMyDrawView::AssertValid() const
{
	CView::AssertValid();
}

void CMyDrawView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMyDrawDoc* CMyDrawView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMyDrawDoc)));
	return (CMyDrawDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyDrawView message handlers

void CMyDrawView::OnShowbitmap()  //GDI位图的显示
{
	// TODO: Add your command handler code here
	CClientDC pDC(this);
	CRect rect;
	GetClientRect(rect);
	CBitmap MyBitmap;
	//调入位图参数
	if(MyBitmap.LoadBitmap(IDB_BITMAP1))
	{
		//获取位图参数
		BITMAP bm;
		MyBitmap.GetObject(sizeof(BITMAP),&bm);
		//定义并创建一个内存设备环境
		CDC memDC;
		memDC.CreateCompatibleDC(&pDC);
		//将位图选入内存设备环境
		CBitmap *pOldbmp=memDC.SelectObject(&MyBitmap);
		//将位图复制到蒲实际的设备环境当中
		pDC.StretchBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,bm.bmWidth,bm.bmHeight,SRCCOPY);
		//pDC.BitBlt(0,0,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
		//恢复原来的内存设备环境
		memDC.SelectObject(pOldbmp);
	}
}

void CMyDrawView::OnDbmp() //bmp文件的显示
{
	// TODO: Add your command handler code here
	CString strFilter="Dat Files(*.bmp)|*.bmp|All Files(*.*)|*.*||";
	//通用文件对话框
	CFileDialog FileDlg(true,NULL,NULL,OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,
		(LPCSTR)strFilter,this);
	if(FileDlg.DoModal()!=IDOK)	return;
	CClientDC pDC(this);
	HBITMAP bitmap;
	bitmap=(HBITMAP)LoadImage(AfxGetInstanceHandle(),FileDlg.GetPathName(),
		IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);
	HBITMAP oldbitmap;
	CDC MemDC;
	MemDC.CreateCompatibleDC(&pDC);
	CRect rect;
	GetClientRect(rect);
	oldbitmap=(HBITMAP)MemDC.SelectObject(bitmap);
	pDC.BitBlt(0,0,rect.Width(),rect.Height(),&MemDC,0,0,SRCCOPY);
	MemDC.SelectObject(oldbitmap);
}

int CMyDrawView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	m_nmx=GetSystemMetrics(SM_CXSCREEN);
	m_nmy=GetSystemMetrics(SM_CYSCREEN);
	CDC * pDC=GetDC();
	m_pmdc->CreateCompatibleDC(pDC);
	m_pbmp->CreateCompatibleBitmap(pDC,m_nmx,m_nmy);
	CBitmap * pOldbitmap=m_pmdc->SelectObject(m_pbmp);
	CBrush brush;
	brush.CreateStockObject(WHITE_BRUSH);
	CRect rect(-1,-1,m_nmx,m_nmy);
	m_pmdc->FillRect(rect,&brush);
	m_pmdc->SelectObject(pOldbitmap);
	ReleaseDC(pDC);

	return 0;
}

void CMyDrawView::OnColor() 
{
	// TODO: Add your command handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags|=CC_PREVENTFULLOPEN|CC_RGBINIT;
	dlg.m_cc.rgbResult=m_color;
	if(dlg.DoModal()==IDOK)
	{
		m_color=dlg.GetColor();
	}
}


void CMyDrawView::OnLine() 
{
	// TODO: Add your command handler code here
	m_type=1;
}

void CMyDrawView::OnRect() 
{
	// TODO: Add your command handler code here
	m_type=2;
}

void CMyDrawView::OnEllirect() 
{
	// TODO: Add your command handler code here
	m_type=3;
}

void CMyDrawView::OnEllipse() 
{
	// TODO: Add your command handler code here
	m_type=4;
}

void CMyDrawView::OnWidth1() 
{
	// TODO: Add your command handler code here
	m_width=1;
}

void CMyDrawView::OnWidth2() 
{
	// TODO: Add your command handler code here
	m_width=2;
}

void CMyDrawView::OnWidth3() 
{
	// TODO: Add your command handler code here
	m_width=3;
}

void CMyDrawView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_bdoing)return; //如果正在画图，则返回
	m_bdoing=true;	//画图标识
	m_pnew=point;	//将当前鼠标点赋给画图的起点m_pnew
	m_pold=point;	//将当前鼠标点赋给临时点m_pold
	//CView::OnLButtonDown(nFlags, point);
}

void CMyDrawView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_bdoing)return; //如果不是正画图，返回
	CDC* pDC=GetDC();	//获得显示设备环境的指针
	CBitmap* poldbmp=m_pmdc->SelectObject(m_pbmp);
	CPen pen;
	pen.CreatePen(PS_SOLID,m_width,m_color);
	CPen* poldPen=pDC->SelectObject(&pen);
	CBrush* poldbrush=(CBrush*)pDC->SelectStockObject(NULL_BRUSH);
	CRect rectold(m_pold,m_pnew);
	rectold.NormalizeRect();	//...
	rectold.InflateRect(m_width,m_width);	//...
	pDC->BitBlt(rectold.left,rectold.top,rectold.Width(),rectold.Height(),
		m_pmdc,rectold.left,rectold.top,SRCCOPY);
	CRect rectnew(m_pold,point);
	switch(m_type)
	{
	case 1:
		pDC->MoveTo(m_pold);
		pDC->LineTo(point);
		break;
	case 2:
		pDC->Rectangle(rectnew);
		break;
	case 3:
		pDC->RoundRect(m_pold.x,m_pold.y,point.x,point.y,10,10);
		break;
	case 4:
		pDC->Ellipse(rectnew);
		break;
	default:
		break;
	}
	m_pmdc->SelectObject(poldbmp);
	pDC->SelectObject(poldPen);
	pDC->SelectObject(poldbrush);
	ReleaseDC(pDC);
	m_pnew=point;
	//CView::OnMouseMove(nFlags, point);
}

void CMyDrawView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(!m_bdoing)return; //如果不是正画图，返回
	m_bdoing=FALSE;
	CBitmap* poldbmp=m_pmdc->SelectObject(m_pbmp);
	CPen pen;
	pen.CreatePen(PS_SOLID,m_width,m_color);
	CPen* poldPen=m_pmdc->SelectObject(&pen);
	CBrush* poldbrush=(CBrush*)m_pmdc->SelectStockObject(NULL_BRUSH);
	CRect rect(m_pnew,m_pold);
	switch(m_type)
	{
	case 1:
		m_pmdc->MoveTo(m_pold);
		m_pmdc->LineTo(point);
		break;
	case 2:
		m_pmdc->Rectangle(rect);
		break;
	case 3:
		m_pmdc->RoundRect(m_pnew.x,m_pnew.y,m_pold.x,m_pold.y,10,10);
		break;
	case 4:
		m_pmdc->Ellipse(rect);
		break;
	default:
		break;
	}
	Invalidate(FALSE);
	m_pmdc->SelectObject(poldbmp);
	m_pmdc->SelectObject(poldPen);
	m_pmdc->SelectObject(poldbrush);

	//CView::OnLButtonUp(nFlags, point);
}

void CMyDrawView::OnUpdateLine(CCmdUI* pCmdUI) //为直线菜单项作选中标记状态更新
{
	//菜单项的状态更新控制有两种方式
	//1.SetCheck方式：该方式在菜单项左边出现选中标记"√"
	//2.Enable/Disable方式：该方式使菜单项无效(呈灰色)或恢复使用。

		pCmdUI->SetCheck(m_type==1);

	
}

void CMyDrawView::OnUpdateRect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==2);
}

void CMyDrawView::OnUpdateEllirect(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==3);
}

void CMyDrawView::OnUpdateEllipse(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_type==4);
}

void CMyDrawView::OnUpdateWidth1(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_width==1);
}

void CMyDrawView::OnUpdateWidth2(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_width==2);
}

void CMyDrawView::OnUpdateWidth3(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_width==3);
}
