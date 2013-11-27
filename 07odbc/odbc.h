// odbc.h : main header file for the ODBC application
//

#if !defined(AFX_ODBC_H__B75732A5_8DDF_4C6F_A591_C1738DAC44D2__INCLUDED_)
#define AFX_ODBC_H__B75732A5_8DDF_4C6F_A591_C1738DAC44D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COdbcApp:
// See odbc.cpp for the implementation of this class
//

class COdbcApp : public CWinApp
{
public:
	COdbcApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COdbcApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(COdbcApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBC_H__B75732A5_8DDF_4C6F_A591_C1738DAC44D2__INCLUDED_)
