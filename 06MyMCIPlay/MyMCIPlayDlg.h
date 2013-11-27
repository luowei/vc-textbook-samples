// MyMCIPlayDlg.h : header file
//

#if !defined(AFX_MYMCIPLAYDLG_H__EEDB15CA_A82A_4189_AEDB_9F3E5A7794F0__INCLUDED_)
#define AFX_MYMCIPLAYDLG_H__EEDB15CA_A82A_4189_AEDB_9F3E5A7794F0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMyMCIPlayDlg dialog

class CMyMCIPlayDlg : public CDialog
{
// Construction
public:
	CMyMCIPlayDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMyMCIPlayDlg)
	enum { IDD = IDD_MYMCIPLAY_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMCIPlayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMyMCIPlayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMCIPLAYDLG_H__EEDB15CA_A82A_4189_AEDB_9F3E5A7794F0__INCLUDED_)
