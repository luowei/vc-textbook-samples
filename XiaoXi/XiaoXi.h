// XiaoXi.h : main header file for the XIAOXI application
//

#if !defined(AFX_XIAOXI_H__B389A942_801A_434C_92C3_4F63F80EF360__INCLUDED_)
#define AFX_XIAOXI_H__B389A942_801A_434C_92C3_4F63F80EF360__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CXiaoXiApp:
// See XiaoXi.cpp for the implementation of this class
//

class CXiaoXiApp : public CWinApp
{
public:
	CXiaoXiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXiaoXiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CXiaoXiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XIAOXI_H__B389A942_801A_434C_92C3_4F63F80EF360__INCLUDED_)
