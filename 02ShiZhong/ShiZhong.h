// ShiZhong.h : main header file for the SHIZHONG application
//

#if !defined(AFX_SHIZHONG_H__9CD84726_B52E_498A_8AFD_6C7E3DB42733__INCLUDED_)
#define AFX_SHIZHONG_H__9CD84726_B52E_498A_8AFD_6C7E3DB42733__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShiZhongApp:
// See ShiZhong.cpp for the implementation of this class
//

class CShiZhongApp : public CWinApp
{
public:
	CShiZhongApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShiZhongApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShiZhongApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHIZHONG_H__9CD84726_B52E_498A_8AFD_6C7E3DB42733__INCLUDED_)
