// XiaoXiDoc.cpp : implementation of the CXiaoXiDoc class
//

#include "stdafx.h"
#include "XiaoXi.h"

#include "XiaoXiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CXiaoXiDoc

IMPLEMENT_DYNCREATE(CXiaoXiDoc, CDocument)

BEGIN_MESSAGE_MAP(CXiaoXiDoc, CDocument)
	//{{AFX_MSG_MAP(CXiaoXiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXiaoXiDoc construction/destruction

CXiaoXiDoc::CXiaoXiDoc()
{
	// TODO: add one-time construction code here

}

CXiaoXiDoc::~CXiaoXiDoc()
{
}

BOOL CXiaoXiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CXiaoXiDoc serialization

void CXiaoXiDoc::Serialize(CArchive& ar)
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
// CXiaoXiDoc diagnostics

#ifdef _DEBUG
void CXiaoXiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CXiaoXiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXiaoXiDoc commands
