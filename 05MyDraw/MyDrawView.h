// MyDrawView.h : interface of the CMyDrawView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYDRAWVIEW_H__421245B9_1C7F_4668_BCC5_75DCE23C3BB1__INCLUDED_)
#define AFX_MYDRAWVIEW_H__421245B9_1C7F_4668_BCC5_75DCE23C3BB1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyDrawView : public CView
{
protected: // create from serialization only
	CMyDrawView();
	DECLARE_DYNCREATE(CMyDrawView)

// Attributes
public:
	CMyDrawDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyDrawView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyDrawView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyDrawView)
	afx_msg void OnShowbitmap();
	afx_msg void OnDbmp();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnColor();
	afx_msg void OnLine();
	afx_msg void OnRect();
	afx_msg void OnEllirect();
	afx_msg void OnEllipse();
	afx_msg void OnWidth1();
	afx_msg void OnWidth2();
	afx_msg void OnWidth3();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnUpdateLine(CCmdUI* pCmdUI);
	afx_msg void OnUpdateRect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEllirect(CCmdUI* pCmdUI);
	afx_msg void OnUpdateEllipse(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWidth1(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWidth2(CCmdUI* pCmdUI);
	afx_msg void OnUpdateWidth3(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int m_type; //当前选择图形的类型
	COLORREF m_color; //当前画笔颜色
	int m_nmx;	//窗口横坐标最大值
	int m_nmy;	//窗口纵坐标最大值
	int m_width; //当前画笔宽度
	CBitmap* m_pbmp; //位图GDI对象
	CDC* m_pmdc;	//在于内存中的设备环境变量
	CPoint m_pold;	//光标原位置
	CPoint m_pnew;	//光标新位置
	BOOL m_bdoing; //标识当前是否在绘图
};

#ifndef _DEBUG  // debug version in MyDrawView.cpp
inline CMyDrawDoc* CMyDrawView::GetDocument()
   { return (CMyDrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDRAWVIEW_H__421245B9_1C7F_4668_BCC5_75DCE23C3BB1__INCLUDED_)
