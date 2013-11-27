// odbcDoc.cpp : implementation of the COdbcDoc class
//

#include "stdafx.h"
#include "odbc.h"

#include "odbcSet.h"
#include "odbcDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COdbcDoc

IMPLEMENT_DYNCREATE(COdbcDoc, CDocument)

BEGIN_MESSAGE_MAP(COdbcDoc, CDocument)
	//{{AFX_MSG_MAP(COdbcDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COdbcDoc construction/destruction

COdbcDoc::COdbcDoc()
{
	// TODO: add one-time construction code here

}

COdbcDoc::~COdbcDoc()
{
}

BOOL COdbcDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// COdbcDoc diagnostics

#ifdef _DEBUG
void COdbcDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void COdbcDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COdbcDoc commands
