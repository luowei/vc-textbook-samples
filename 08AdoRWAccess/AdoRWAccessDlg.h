// AdoRWAccessDlg.h : header file
//

#if !defined(AFX_ADORWACCESSDLG_H__15AB47C3_26F7_43FB_8BEB_1C5E518B16E5__INCLUDED_)
#define AFX_ADORWACCESSDLG_H__15AB47C3_26F7_43FB_8BEB_1C5E518B16E5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



/////////////////////////////////////////////////////////////////////////////
// CAdoRWAccessDlg dialog

class CAdoRWAccessDlg : public CDialog
{
// Construction
public:
	CAdoRWAccessDlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;	//定义连接指针
	_CommandPtr m_pCommand;			//定义命令指针
	_RecordsetPtr m_pRecordset;		//定义记录集指针

// Dialog Data
	//{{AFX_DATA(CAdoRWAccessDlg)
	enum { IDD = IDD_ADORWACCESS_DIALOG };
	CButton	m_modify;
	CListBox	m_listdatabase;
	CButton	m_exit;
	CButton	m_delete;
	CButton	m_add;
	CButton	m_listall;
	CString	m_address;
	CString	m_name;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdoRWAccessDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAdoRWAccessDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnListall();
	afx_msg void OnBnClickedAdd();
	afx_msg void OnLbnSelchangeListdatabase();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedModify();
	afx_msg void OnBnClickedExitsys();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADORWACCESSDLG_H__15AB47C3_26F7_43FB_8BEB_1C5E518B16E5__INCLUDED_)
