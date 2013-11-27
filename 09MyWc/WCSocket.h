#if !defined(AFX_WCSOCKET_H__1D7D7DB2_75A9_46C7_872E_085B742F1835__INCLUDED_)
#define AFX_WCSOCKET_H__1D7D7DB2_75A9_46C7_872E_085B742F1835__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WCSocket.h : header file
//

#define RE_RECEIVED WM_USER+1

typedef struct
{
	char m_strName[255];		//�ͻ�����
	char m_dbData[255];			//Ҫ���͵����ݻ���Ϣ
	char m_type[255];			//ͨ������
	char m_talkingName[255];	//����ͻ���
}_DATA;

/////////////////////////////////////////////////////////////////////////////
// CWCSocket command target

class CWCSocket : public CSocket
{
// Attributes
public:
	_DATA m_Dat;	//����_DATA���͵ĳ�Ա����m_Dat,���ڴ洢����
// Operations
public:
	CWCSocket();
	virtual ~CWCSocket();

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWCSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CWCSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WCSOCKET_H__1D7D7DB2_75A9_46C7_872E_085B742F1835__INCLUDED_)
