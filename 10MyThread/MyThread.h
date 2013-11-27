// MyThread.h : main header file for the MYTHREAD application
//

#if !defined(AFX_MYTHREAD_H__FC361D9E_A12D_4485_BA89_BC00839BB3F2__INCLUDED_)
#define AFX_MYTHREAD_H__FC361D9E_A12D_4485_BA89_BC00839BB3F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyThreadApp:
// See MyThread.cpp for the implementation of this class
//

class CMyThreadApp : public CWinApp
{
public:
	CMyThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMyThreadApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYTHREAD_H__FC361D9E_A12D_4485_BA89_BC00839BB3F2__INCLUDED_)
