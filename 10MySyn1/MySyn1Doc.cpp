// MySyn1Doc.cpp : implementation of the CMySyn1Doc class
//

#include "stdafx.h"
#include "MySyn1.h"

#include "MySyn1Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySyn1Doc

IMPLEMENT_DYNCREATE(CMySyn1Doc, CDocument)

BEGIN_MESSAGE_MAP(CMySyn1Doc, CDocument)
	//{{AFX_MSG_MAP(CMySyn1Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMySyn1Doc construction/destruction

CMySyn1Doc::CMySyn1Doc()
{
	// TODO: add one-time construction code here

}

CMySyn1Doc::~CMySyn1Doc()
{
}

BOOL CMySyn1Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMySyn1Doc serialization

void CMySyn1Doc::Serialize(CArchive& ar)
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
// CMySyn1Doc diagnostics

#ifdef _DEBUG
void CMySyn1Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMySyn1Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMySyn1Doc commands
