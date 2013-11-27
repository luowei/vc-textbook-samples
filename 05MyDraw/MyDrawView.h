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
	int m_type; //��ǰѡ��ͼ�ε�����
	COLORREF m_color; //��ǰ������ɫ
	int m_nmx;	//���ں��������ֵ
	int m_nmy;	//�������������ֵ
	int m_width; //��ǰ���ʿ��
	CBitmap* m_pbmp; //λͼGDI����
	CDC* m_pmdc;	//�����ڴ��е��豸��������
	CPoint m_pold;	//���ԭλ��
	CPoint m_pnew;	//�����λ��
	BOOL m_bdoing; //��ʶ��ǰ�Ƿ��ڻ�ͼ
};

#ifndef _DEBUG  // debug version in MyDrawView.cpp
inline CMyDrawDoc* CMyDrawView::GetDocument()
   { return (CMyDrawDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYDRAWVIEW_H__421245B9_1C7F_4668_BCC5_75DCE23C3BB1__INCLUDED_)
