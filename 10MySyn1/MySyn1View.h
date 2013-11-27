// MySyn1View.h : interface of the CMySyn1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSYN1VIEW_H__8AE7713C_3797_4815_9324_4D34434150D2__INCLUDED_)
#define AFX_MYSYN1VIEW_H__8AE7713C_3797_4815_9324_4D34434150D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMySyn1View : public CView
{
protected: // create from serialization only
	CMySyn1View();
	DECLARE_DYNCREATE(CMySyn1View)

// Attributes
public:
	CMySyn1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySyn1View)
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
	virtual ~CMySyn1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMySyn1View)
	afx_msg void OnSynchro();
	afx_msg void OnNosyn();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MySyn1View.cpp
inline CMySyn1Doc* CMySyn1View::GetDocument()
   { return (CMySyn1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSYN1VIEW_H__8AE7713C_3797_4815_9324_4D34434150D2__INCLUDED_)
