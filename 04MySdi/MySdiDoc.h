// MySdiDoc.h : interface of the CMySdiDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYSDIDOC_H__1B9816C1_A921_4858_A2F1_94BE7384889A__INCLUDED_)
#define AFX_MYSDIDOC_H__1B9816C1_A921_4858_A2F1_94BE7384889A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMySdiDoc : public CDocument
{
protected: // create from serialization only
	CMySdiDoc();
	DECLARE_DYNCREATE(CMySdiDoc)

// Attributes

// Operations
public:
	struct{   //修改CMySdiDoc类的定义
		char name[10];
		char sex[3];
		int age;
		char tel[14];
		char school[30];
	}m_student[40];
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySdiDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMySdiDoc();

#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMySdiDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSDIDOC_H__1B9816C1_A921_4858_A2F1_94BE7384889A__INCLUDED_)
