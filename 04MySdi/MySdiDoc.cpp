// MySdiDoc.cpp : implementation of the CMySdiDoc class
//

#include "stdafx.h"
#include "MySdi.h"

#include "MySdiDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySdiDoc

IMPLEMENT_DYNCREATE(CMySdiDoc, CDocument)

BEGIN_MESSAGE_MAP(CMySdiDoc, CDocument)
	//{{AFX_MSG_MAP(CMySdiDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMySdiDoc construction/destruction

CMySdiDoc::CMySdiDoc()
{
	// TODO: add one-time construction code here
	for(int i=0;i<40;i++)
	{
		m_student[i].name[0]=NULL;
		m_student[i].sex[0]=NULL;
		m_student[i].age=0;
		m_student[i].tel[0]=NULL;
		m_student[i].school[0]=NULL;
	}
}

CMySdiDoc::~CMySdiDoc()
{
}

BOOL CMySdiDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMySdiDoc serialization

void CMySdiDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring()) //保存数据
	{
		// TODO: add storing code here
		for(int i=0;i<40;i++)
		{
			ar.Write(m_student[i].name,10);
			ar.Write(m_student[i].sex,3);
			//ar.Write(&(m_student[i].age),sizeof(int));
			ar<<m_student[i].age; //利用类似于流的输入输出方式写入文件(输出)
			ar.Write(m_student[i].tel,14);
			ar.Write(m_student[i].school,30);
		}
	}
	else
	{
		// TODO: add loading code here
		for(int i=0;i<40;i++)
		{
			ar.Read(m_student[i].name,10);
			ar.Read(m_student[i].sex,3);
			//ar.Read(&(m_student[i].age),sizeof(int));
			ar>>m_student[i].age;	//利用类似于流的输入输出方式读取文件(输入)
			ar.Read(m_student[i].tel,14);
			ar.Read(m_student[i].school,30);
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMySdiDoc diagnostics

#ifdef _DEBUG
void CMySdiDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMySdiDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMySdiDoc commands
