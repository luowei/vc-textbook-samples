// MyThreadView.h : interface of the CMyThreadView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTHREADVIEW_H__CBBACF3B_B41E_4EEF_8376_6BDB60DB1A01__INCLUDED_)
#define AFX_MYTHREADVIEW_H__CBBACF3B_B41E_4EEF_8376_6BDB60DB1A01__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_THREADENDED  (WM_USER+100)   //定义用户消息

class CMyThreadView : public CView
{
protected: // create from serialization only
	CMyThreadView();
	DECLARE_DYNCREATE(CMyThreadView)

// Attributes
public:
	CMyThreadDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyThreadView)
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
	virtual ~CMyThreadView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyThreadView)
	afx_msg void OnStartThread();
	afx_msg void OnStopThread();
	afx_msg LONG OnThreadEnded(WPARAM wParam,LPARAM lParam); //消息映射函数
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyThreadView.cpp
inline CMyThreadDoc* CMyThreadView::GetDocument()
   { return (CMyThreadDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTHREADVIEW_H__CBBACF3B_B41E_4EEF_8376_6BDB60DB1A01__INCLUDED_)
