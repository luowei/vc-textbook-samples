// XiaoXiDoc.h : interface of the CXiaoXiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_XIAOXIDOC_H__E04DC336_D8A5_4AC7_A238_D2B9F21947CE__INCLUDED_)
#define AFX_XIAOXIDOC_H__E04DC336_D8A5_4AC7_A238_D2B9F21947CE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CXiaoXiDoc : public CDocument
{
protected: // create from serialization only
	CXiaoXiDoc();
	DECLARE_DYNCREATE(CXiaoXiDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXiaoXiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CXiaoXiDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CXiaoXiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XIAOXIDOC_H__E04DC336_D8A5_4AC7_A238_D2B9F21947CE__INCLUDED_)
