// ShiZhongDoc.h : interface of the CShiZhongDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHIZHONGDOC_H__8904253A_C336_4B22_BFE8_63CB333D0EE1__INCLUDED_)
#define AFX_SHIZHONGDOC_H__8904253A_C336_4B22_BFE8_63CB333D0EE1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShiZhongDoc : public CDocument
{
protected: // create from serialization only
	CShiZhongDoc();
	DECLARE_DYNCREATE(CShiZhongDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShiZhongDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShiZhongDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShiZhongDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHIZHONGDOC_H__8904253A_C336_4B22_BFE8_63CB333D0EE1__INCLUDED_)
