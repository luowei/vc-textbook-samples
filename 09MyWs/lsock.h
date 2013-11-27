#if !defined(AFX_LSOCK_H__E0AC6130_C6E8_44C0_88B8_D2F573DD3865__INCLUDED_)
#define AFX_LSOCK_H__E0AC6130_C6E8_44C0_88B8_D2F573DD3865__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// LSock.h : header file
//

typedef struct
{
	char m_strName[255];		//客户名字
	char m_dbData[255];			//要发送的数据或信息
	char m_type[255];			//通信类型
	char m_talkingName[255];	//聊天客户名
}_DATA;

class CMyWsDlg;

/////////////////////////////////////////////////////////////////////////////
// CLSock command target

class CLSock : public CSocket
{
// Attributes
public:

// Operations
public:
	CLSock(CMyWsDlg * p);
	virtual ~CLSock();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLSock)
	public:
	virtual void OnAccept(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CLSock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
private:
	CMyWsDlg * m_p;
};

/////////////////////////////////////////////////////////////////////////////



/////////////////////////////////////////////////////////////////////////////
// CRWSock command target

class CRWSock : public CSocket
{
	CMyWsDlg * m_p;
// Attributes
public:
	_DATA m_Dat;
	
// Operations
public:
	CRWSock(CMyWsDlg *p);
	virtual ~CRWSock();
	void CRWSock::OnReceive(int nErrorCode);

// Overrides
public:
	void ReadMessage(CRWSock* sock);
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRWSock)
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CRWSock)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LSOCK_H__E0AC6130_C6E8_44C0_88B8_D2F573DD3865__INCLUDED_)
