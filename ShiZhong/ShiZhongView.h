// ShiZhongView.h : interface of the CShiZhongView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHIZHONGVIEW_H__DF8952E0_8030_4C24_918B_B6BA1AAF7877__INCLUDED_)
#define AFX_SHIZHONGVIEW_H__DF8952E0_8030_4C24_918B_B6BA1AAF7877__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShiZhongView : public CFormView
{
protected: // create from serialization only
	CShiZhongView();
	DECLARE_DYNCREATE(CShiZhongView)

public:
	//{{AFX_DATA(CShiZhongView)
	enum { IDD = IDD_SHIZHONG_FORM };
	CString	m_strTime;
	//}}AFX_DATA

// Attributes
public:
	CShiZhongDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShiZhongView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	bool m_btimer;
	unsigned int m_timer;

	virtual ~CShiZhongView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShiZhongView)
	afx_msg void OnTimeStart();
	afx_msg void OnTimeStop();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnCancelMode();
	afx_msg void OnUpdateTimeStart(CCmdUI* pCmdUI);
	afx_msg void OnUpdateTimeStop(CCmdUI* pCmdUI);
	afx_msg void OnTimeCurrent();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	int h;
	int m;
	int s;
	int ms;
};

#ifndef _DEBUG  // debug version in ShiZhongView.cpp
inline CShiZhongDoc* CShiZhongView::GetDocument()
   { return (CShiZhongDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHIZHONGVIEW_H__DF8952E0_8030_4C24_918B_B6BA1AAF7877__INCLUDED_)
