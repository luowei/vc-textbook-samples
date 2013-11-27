// MyMCIPlay.h : main header file for the MYMCIPLAY application
//

#if !defined(AFX_MYMCIPLAY_H__7F9F45A0_CDC1_4424_9C3F_281C43A9DD62__INCLUDED_)
#define AFX_MYMCIPLAY_H__7F9F45A0_CDC1_4424_9C3F_281C43A9DD62__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyMCIPlayApp:
// See MyMCIPlay.cpp for the implementation of this class
//

class CMyMCIPlayApp : public CWinApp
{
public:
	CMyMCIPlayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMCIPlayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyMCIPlayApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMCIPLAY_H__7F9F45A0_CDC1_4424_9C3F_281C43A9DD62__INCLUDED_)
