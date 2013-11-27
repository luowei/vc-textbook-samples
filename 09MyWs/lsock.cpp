// LSock.cpp : implementation file
//

#include "stdafx.h"
#include "MyWs.h"
#include "LSock.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include "MyWsDlg.h"
/////////////////////////////////////////////////////////////////////////////
// CLSock

CLSock::CLSock(CMyWsDlg* p)
{
	m_p=p;
}

CLSock::~CLSock()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CLSock, CSocket)
	//{{AFX_MSG_MAP(CLSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CLSock member functions
/////////////////////////////////////////////////////////////////////////////
// CRWSock

CRWSock::CRWSock(CMyWsDlg* p)
{
	m_p=p;
}

CRWSock::~CRWSock()
{
}

void CRWSock::OnReceive(int nErrorCode)
{
	m_p->ReadMessage(this);
	CSocket::OnReceive(nErrorCode);
}

// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CRWSock, CSocket)
	//{{AFX_MSG_MAP(CRWSock)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CRWSock member functions

void CLSock::OnAccept(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_p->AcceptClient();	//处理客户的连接请求
	
	CSocket::OnAccept(nErrorCode);
}

//DEL int CLSock::Receive(void* lpBuf, int nBufLen, int nFlags) 
//DEL {
//DEL 	// TODO: Add your specialized code here and/or call the base class
//DEL 	
//DEL 	return CSocket::Receive(lpBuf, nBufLen, nFlags);
//DEL }

void CMyWsDlg::ReadMessage(CRWSock *sock)
{
	int len=sock->Receive(&m_Dat,sizeof(m_Dat));
	sock->m_Dat=m_Dat;
	if(len!=sizeof(m_Dat)) return;
	_DATA* dat=&m_Dat;
	CString type=(CString)dat->m_type;
	if(!type.Compare(_T("CONNECTION")))
	{
		CString a;
		a=(CString)dat->m_strName;
		CString str1=_T("用户");
		str1+=_T("已经登录了！");
		m_ctlRecvd.AddString(a);	//添加上线客户
		memset(dat->m_dbData,0,255);
		memcpy(dat->m_dbData,str1,str1.GetLength());
		SendSocketMessage(sock,&m_Dat);	//通知其他在线用户
		//将在线用户通知连接用户
		POSITION pos=m_list.GetHeadPosition();
		while(pos!=NULL)
		{
			CRWSock* client=(CRWSock*)m_list.GetNext(pos);
			if(client==sock) continue;
			strcpy(client->m_Dat.m_type,"CLIENT");
			::Sleep(1000);
			sock->Send(&client->m_Dat,sizeof(client->m_Dat));
		}
	}
	else if(!type.Compare(_T("CLOSE")))
	{
		CString str2=_T("用户：");
		str2+=(CString)dat->m_strName;
		str2+=_T("已经断开了！");
		m_ctlRecvd.AddString(str2);
		SendSocketMessage(sock,&m_Dat);
		POSITION pos=m_list.GetHeadPosition();
		sock->Close();
		pos=m_list.Find(sock);
		m_list.RemoveAt(pos);
		if(sock!=NULL) delete sock;
		displayInLine(dat->m_strName);
	}
	else if(!type.Compare(_T("MSG")))
	{
		CString str=(CString)dat->m_strName;
		str+=_T(" 说：");
		str+=(CString)dat->m_dbData;
		m_ctlRecvd.AddString(str);
		SendSocketMessage(sock,&m_Dat);
	}
	else if(!type.Compare(_T("PRIVATE")))
	{
		CString talkingName=(CString)sock->m_Dat.m_talkingName;
		CString cName;
		POSITION pos=m_list.GetHeadPosition();
		while(pos!=NULL)
		{
			CRWSock* client=(CRWSock*)m_list.GetNext(pos);
			cName=client->m_Dat.m_strName;
			if(talkingName==cName)
				client->Send(&m_Dat,sizeof(m_Dat));
		}
	}
}


