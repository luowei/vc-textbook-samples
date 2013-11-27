// odbcSet.h : interface of the COdbcSet class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBCSET_H__587DACE8_4623_428D_A18E_65A5D45CD0E5__INCLUDED_)
#define AFX_ODBCSET_H__587DACE8_4623_428D_A18E_65A5D45CD0E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class COdbcSet : public CRecordset
{
public:
	COdbcSet(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(COdbcSet)

// Field/Param Data
	//{{AFX_FIELD(COdbcSet, CRecordset)
	long	m_ID;
	CString	m_name;
	CString	m_singer;
	CString	m_writer;
	CString	m_position;
	//}}AFX_FIELD

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COdbcSet)
	public:
	virtual CString GetDefaultConnect();	// Default connection string
	virtual CString GetDefaultSQL(); 	// default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCSET_H__587DACE8_4623_428D_A18E_65A5D45CD0E5__INCLUDED_)

