// odbcDoc.h : interface of the COdbcDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBCDOC_H__FD2B7A56_F9C5_4592_BBB6_949086D055F2__INCLUDED_)
#define AFX_ODBCDOC_H__FD2B7A56_F9C5_4592_BBB6_949086D055F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "odbcSet.h"


class COdbcDoc : public CDocument
{
protected: // create from serialization only
	COdbcDoc();
	DECLARE_DYNCREATE(COdbcDoc)

// Attributes
public:
	COdbcSet m_odbcSet;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COdbcDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~COdbcDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(COdbcDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDOC_H__FD2B7A56_F9C5_4592_BBB6_949086D055F2__INCLUDED_)
