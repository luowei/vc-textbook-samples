// odbcSet.cpp : implementation of the COdbcSet class
//

#include "stdafx.h"
#include "odbc.h"
#include "odbcSet.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COdbcSet implementation

IMPLEMENT_DYNAMIC(COdbcSet, CRecordset)

COdbcSet::COdbcSet(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(COdbcSet)
	m_ID = 0;
	m_name = _T("");
	m_singer = _T("");
	m_writer = _T("");
	m_position = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = dynaset;
}
///////////////////////////////////////////////////////
//与数据库连接
CString COdbcSet::GetDefaultConnect()
{
	return _T("ODBC;DSN=mysong");
}

CString COdbcSet::GetDefaultSQL()
{
	return _T("[Table1]");
}
///////////////////////////////////////////////////////
//当前记录与COdbcSet类成员变量的数据交互
void COdbcSet::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(COdbcSet)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Text(pFX, _T("[singer]"), m_singer);
	RFX_Text(pFX, _T("[writer]"), m_writer);
	RFX_Text(pFX, _T("[position]"), m_position);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// COdbcSet diagnostics

#ifdef _DEBUG
void COdbcSet::AssertValid() const
{
	CRecordset::AssertValid();
}

void COdbcSet::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
