// odbcView.h : interface of the COdbcView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBCVIEW_H__21DC8FA9_20C6_4AE7_91E3_25EA13B6CF49__INCLUDED_)
#define AFX_ODBCVIEW_H__21DC8FA9_20C6_4AE7_91E3_25EA13B6CF49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COdbcSet;

class COdbcView : public CRecordView
{
protected: // create from serialization only
	COdbcView();
	DECLARE_DYNCREATE(COdbcView)

public:
	//{{AFX_DATA(COdbcView)
	enum { IDD = IDD_ODBC_FORM };
	COdbcSet* m_pSet;
	UINT	m_ID;
	CString	m_name;
	CString	m_position;
	CString	m_singer;
	CString	m_writer;
	//}}AFX_DATA

// Attributes
public:
	COdbcDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COdbcView)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void MyUpdateData(void);
	virtual ~COdbcView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COdbcView)
	afx_msg void OnRecordFirst();
	afx_msg void OnRecordLast();
	afx_msg void OnRecordNext();
	afx_msg void OnRecordPrev();
	afx_msg void OnRecordAdd();
	afx_msg void OnRecordDel();
	afx_msg void OnRecordEdit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in odbcView.cpp
inline COdbcDoc* COdbcView::GetDocument()
   { return (COdbcDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCVIEW_H__21DC8FA9_20C6_4AE7_91E3_25EA13B6CF49__INCLUDED_)
