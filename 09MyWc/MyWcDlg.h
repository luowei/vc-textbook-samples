// MyWcDlg.h : header file
//

#if !defined(AFX_MYWCDLG_H__198CBBF1_B3C5_486C_A883_9DD08B2B720A__INCLUDED_)
#define AFX_MYWCDLG_H__198CBBF1_B3C5_486C_A883_9DD08B2B720A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "WCSocket.h"
/////////////////////////////////////////////////////////////////////////////
// CMyWcDlg dialog

class CMyWcDlg : public CDialog
{
// Construction
public:
	CMyWcDlg(CWnd* pParent = NULL);	// standard constructor
	_DATA m_Dat;
	CWCSocket sockClient;

	//声明用户消息响应函数
	LRESULT OnMyReceive(WPARAM wParam,LPARAM lParam);

// Dialog Data
	//{{AFX_DATA(CMyWcDlg)
	enum { IDD = IDD_MYWC_DIALOG };
	CListBox	m_ctlName;
	CListBox	m_ctlRecvd;
	CString	m_client_name;
	CString	m_server_name;
	int		m_nPort;
	CString	m_send_info;
	CString	m_systemTime;
	BOOL	m_talk;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyWcDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyWcDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnClickedConnect();
	afx_msg void OnBnClickedClose();
	afx_msg void OnBnClickedSend();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnBnClickedCheck1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYWCDLG_H__198CBBF1_B3C5_486C_A883_9DD08B2B720A__INCLUDED_)
