// MySdiView.h : interface of the CMySdiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSDIVIEW_H__A66B4C77_2AC5_4810_8602_33B6FE94F63D__INCLUDED_)
#define AFX_MYSDIVIEW_H__A66B4C77_2AC5_4810_8602_33B6FE94F63D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMySdiView : public CFormView
{
	int m_nCurrentNo; //±Ì æ—ß∫≈
protected: // create from serialization only
	CMySdiView();
	DECLARE_DYNCREATE(CMySdiView)

public:
	//{{AFX_DATA(CMySdiView)
	enum { IDD = IDD_MYSDI_FORM };
	CComboBox	m_noList;
	CString	m_name;
	int		m_age;
	CString	m_school;
	CString	m_sex;
	CString	m_tel;
	//}}AFX_DATA

// Attributes
public:
	CMySdiDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySdiView)
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
	virtual ~CMySdiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMySdiView)
	afx_msg void OnSelchangeCombo();
	afx_msg void OnChangeEditName();
	afx_msg void OnChangeEditAge();
	afx_msg void OnChangeEditSchool();
	afx_msg void OnChangeEditSex();
	afx_msg void OnChangeEditTel();
	afx_msg void OnFileMyopen();
	afx_msg void OnFileMysave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MySdiView.cpp
inline CMySdiDoc* CMySdiView::GetDocument()
   { return (CMySdiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSDIVIEW_H__A66B4C77_2AC5_4810_8602_33B6FE94F63D__INCLUDED_)
