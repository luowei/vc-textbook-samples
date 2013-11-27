// MyWs.h : main header file for the MYWS application
//

#if !defined(AFX_MYWS_H__90AE69A7_D444_437D_AF07_190C15695D6B__INCLUDED_)
#define AFX_MYWS_H__90AE69A7_D444_437D_AF07_190C15695D6B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyWsApp:
// See MyWs.cpp for the implementation of this class
//

class CMyWsApp : public CWinApp
{
public:
	CMyWsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyWsApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWS_H__90AE69A7_D444_437D_AF07_190C15695D6B__INCLUDED_)
