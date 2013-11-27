// MyWsDlg.h : header file
//

#if !defined(AFX_MYWSDLG_H__314D9FA3_BCD0_4BA6_B044_6BF884A36CFF__INCLUDED_)
#define AFX_MYWSDLG_H__314D9FA3_BCD0_4BA6_B044_6BF884A36CFF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LSock.h"

/////////////////////////////////////////////////////////////////////////////
// CMyWsDlg dialog

class CMyWsDlg : public CDialog
{
private:
	CRWSock* m_clientSocket;
	CLSock *m_listenSocket;
	CPtrList m_list;

// Construction
public:
	void ReadMessage(CRWSock* sock);
	void displayInLine(char* name);
	void SendSocketMessage(CRWSock* socket,_DATA* buf);
	CMyWsDlg(CWnd* pParent = NULL);	// standard constructor
	_DATA m_Dat;
	void AcceptClient(void);

// Dialog Data
	//{{AFX_DATA(CMyWsDlg)
	enum { IDD = IDD_MYWS_DIALOG };
	CListBox	m_ctlRecvd;
	CListBox	m_inLine;
	UINT	m_server_port;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyWsDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWSDLG_H__314D9FA3_BCD0_4BA6_B044_6BF884A36CFF__INCLUDED_)
