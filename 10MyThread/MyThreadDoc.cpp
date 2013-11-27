// MyThreadDoc.cpp : implementation of the CMyThreadDoc class
//

#include "stdafx.h"
#include "MyThread.h"

#include "MyThreadDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyThreadDoc

IMPLEMENT_DYNCREATE(CMyThreadDoc, CDocument)

BEGIN_MESSAGE_MAP(CMyThreadDoc, CDocument)
	//{{AFX_MSG_MAP(CMyThreadDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyThreadDoc construction/destruction

CMyThreadDoc::CMyThreadDoc()
{
	// TODO: add one-time construction code here

}

CMyThreadDoc::~CMyThreadDoc()
{
}

BOOL CMyThreadDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMyThreadDoc serialization

void CMyThreadDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMyThreadDoc diagnostics

#ifdef _DEBUG
void CMyThreadDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMyThreadDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMyThreadDoc commands
