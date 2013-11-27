// CalculatorDlg.h : header file
//

#if !defined(AFX_CALCULATORDLG_H__6240C8ED_D85E_421F_BBCA_81BFC6E05029__INCLUDED_)
#define AFX_CALCULATORDLG_H__6240C8ED_D85E_421F_BBCA_81BFC6E05029__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCalculatorDlg dialog

class CCalculatorDlg : public CDialog
{
// Construction
public:
	
	CCalculatorDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCalculatorDlg)
	enum { IDD = IDD_CALCULATOR_DIALOG };
	CString	m_display;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCalculatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CString m_operator;
	double m_coff;
	double m_second;
	double m_first;

	HICON m_hIcon;
	void UpdateDisplay(double lVal);
	void Calculate(void);
	// Generated message map functions
	//{{AFX_MSG(CCalculatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton0();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	afx_msg void OnButton8();
	afx_msg void OnButton9();
	afx_msg void OnButtonAdd();
	afx_msg void OnButtonClear();
	afx_msg void OnButtonDiv();
	afx_msg void OnButtonEqual();
	afx_msg void OnButtonMinus();
	afx_msg void OnButtonMultiply();
	afx_msg void OnButtonPoint();
	afx_msg void OnButtonReciprocal();
	afx_msg void OnButtonSign();
	afx_msg void OnButtonSqrt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CALCULATORDLG_H__6240C8ED_D85E_421F_BBCA_81BFC6E05029__INCLUDED_)
