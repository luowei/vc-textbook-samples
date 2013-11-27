// WCSocket.cpp : implementation file
//

#include "stdafx.h"
#include "MyWc.h"
#include "WCSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWCSocket

CWCSocket::CWCSocket()
{
}

CWCSocket::~CWCSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CWCSocket, CSocket)
	//{{AFX_MSG_MAP(CWCSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CWCSocket member functions

void CWCSocket::OnReceive(int nErrorCode) //处理收到的消息
{
	// TODO: Add your specialized code here and/or call the base class
	if(Receive(&m_Dat,sizeof(m_Dat))==sizeof(m_Dat))
	{
		::PostMessage(::AfxGetApp()->m_pMainWnd->m_hWnd,RE_RECEIVED,(WPARAM)&m_Dat,0);
	}
	CSocket::OnReceive(nErrorCode);
}
