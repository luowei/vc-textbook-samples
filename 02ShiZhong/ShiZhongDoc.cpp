// ShiZhongDoc.cpp : implementation of the CShiZhongDoc class
//

#include "stdafx.h"
#include "ShiZhong.h"

#include "ShiZhongDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShiZhongDoc

IMPLEMENT_DYNCREATE(CShiZhongDoc, CDocument)

BEGIN_MESSAGE_MAP(CShiZhongDoc, CDocument)
	//{{AFX_MSG_MAP(CShiZhongDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShiZhongDoc construction/destruction

CShiZhongDoc::CShiZhongDoc()
{
	// TODO: add one-time construction code here

}

CShiZhongDoc::~CShiZhongDoc()
{
}

BOOL CShiZhongDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CShiZhongDoc serialization

void CShiZhongDoc::Serialize(CArchive& ar)
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
// CShiZhongDoc diagnostics

#ifdef _DEBUG
void CShiZhongDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CShiZhongDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CShiZhongDoc commands
