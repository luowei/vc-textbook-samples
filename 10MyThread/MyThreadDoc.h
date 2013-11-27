// MyThreadDoc.h : interface of the CMyThreadDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYTHREADDOC_H__06ED029D_BAE9_4905_AC47_020E8506AAEA__INCLUDED_)
#define AFX_MYTHREADDOC_H__06ED029D_BAE9_4905_AC47_020E8506AAEA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyThreadDoc : public CDocument
{
protected: // create from serialization only
	CMyThreadDoc();
	DECLARE_DYNCREATE(CMyThreadDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyThreadDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMyThreadDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyThreadDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTHREADDOC_H__06ED029D_BAE9_4905_AC47_020E8506AAEA__INCLUDED_)
