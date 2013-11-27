// AdoRWAccess.h : main header file for the ADORWACCESS application
//

#if !defined(AFX_ADORWACCESS_H__653EAA37_D960_4115_8AA7_3B5DCF462847__INCLUDED_)
#define AFX_ADORWACCESS_H__653EAA37_D960_4115_8AA7_3B5DCF462847__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

#import "msado15.dll" no_namespace rename("EOF","adoEOF")

/////////////////////////////////////////////////////////////////////////////
// CAdoRWAccessApp:
// See AdoRWAccess.cpp for the implementation of this class
//

class CAdoRWAccessApp : public CWinApp
{
public:
	CAdoRWAccessApp();
	_ConnectionPtr m_pConnection;	//连接对象指针
	_RecordsetPtr m_pRecordset;		//记录集指针

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdoRWAccessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAdoRWAccessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADORWACCESS_H__653EAA37_D960_4115_8AA7_3B5DCF462847__INCLUDED_)
