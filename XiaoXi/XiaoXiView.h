// XiaoXiView.h : interface of the CXiaoXiView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_XIAOXIVIEW_H__DDD2346E_EE35_49C9_A08B_E1257EE2B869__INCLUDED_)
#define AFX_XIAOXIVIEW_H__DDD2346E_EE35_49C9_A08B_E1257EE2B869__INCLUDED_

#if _MSC_VER > 1000
#pragma once
const int WM_USERMSG=WM_USER+100;  //定义用户消息
#endif // _MSC_VER > 1000



class CXiaoXiView : public CView
{
protected: // create from serialization only
	CXiaoXiView();
	DECLARE_DYNCREATE(CXiaoXiView)
	CString m_sMousePoint;  //存储鼠标的方式和位置
	int m_nLine;			//存储按回车键的次数
	CString m_strDisplay;	//存储当前行输入的字符
// Attributes
public:
	CXiaoXiDoc* GetDocument();

// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXiaoXiView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CXiaoXiView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CXiaoXiView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnDestroy();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg LRESULT OnMyFunction(WPARAM wParam,LPARAM lParam);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);	//声名消息响应函数
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
//	CString m_sMousePoint;  //存储鼠标的方式和位置	
};

#ifndef _DEBUG  // debug version in XiaoXiView.cpp
inline CXiaoXiDoc* CXiaoXiView::GetDocument()
   { return (CXiaoXiDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_XIAOXIVIEW_H__DDD2346E_EE35_49C9_A08B_E1257EE2B869__INCLUDED_)
