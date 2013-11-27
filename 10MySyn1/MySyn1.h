// MySyn1.h : main header file for the MYSYN1 application
//

#if !defined(AFX_MYSYN1_H__CE74894F_78FA_47E0_9C08_89C808A8CE64__INCLUDED_)
#define AFX_MYSYN1_H__CE74894F_78FA_47E0_9C08_89C808A8CE64__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMySyn1App:
// See MySyn1.cpp for the implementation of this class
//

class CMySyn1App : public CWinApp
{
public:
	CMySyn1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySyn1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMySyn1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSYN1_H__CE74894F_78FA_47E0_9C08_89C808A8CE64__INCLUDED_)
