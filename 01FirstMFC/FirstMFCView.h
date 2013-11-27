// FirstMFCView.h : interface of the CFirstMFCView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FIRSTMFCVIEW_H__AC57D89D_24AE_449D_892D_E74A27413F28__INCLUDED_)
#define AFX_FIRSTMFCVIEW_H__AC57D89D_24AE_449D_892D_E74A27413F28__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "PasswordDialog.h"
class CFirstMFCView : public CFormView
{
protected: // create from serialization only
	CFirstMFCView();
	DECLARE_DYNCREATE(CFirstMFCView)

public:
	//{{AFX_DATA(CFirstMFCView)
	enum{ IDD = IDD_FIRSTMFC_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CFirstMFCDoc* GetDocument();
	//添加口令对话框成员指针
	CPasswordDialog * m_pModallessDlg;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFirstMFCView)
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
	virtual ~CFirstMFCView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CFirstMFCView)
	afx_msg void OnNomodalless();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FirstMFCView.cpp
inline CFirstMFCDoc* CFirstMFCView::GetDocument()
   { return (CFirstMFCDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FIRSTMFCVIEW_H__AC57D89D_24AE_449D_892D_E74A27413F28__INCLUDED_)
