// MySdi.h : main header file for the MYSDI application
//

#if !defined(AFX_MYSDI_H__C03BF692_9AD7_4BD9_AA09_471A0FA22965__INCLUDED_)
#define AFX_MYSDI_H__C03BF692_9AD7_4BD9_AA09_471A0FA22965__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMySdiApp:
// See MySdi.cpp for the implementation of this class
//

class CMySdiApp : public CWinApp
{
public:
	CMySdiApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMySdiApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMySdiApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSDI_H__C03BF692_9AD7_4BD9_AA09_471A0FA22965__INCLUDED_)
