// MySdiView.cpp : implementation of the CMySdiView class
//

#include "stdafx.h"
#include "MySdi.h"

#include "MySdiDoc.h"
#include "MySdiView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMySdiView

IMPLEMENT_DYNCREATE(CMySdiView, CFormView)

BEGIN_MESSAGE_MAP(CMySdiView, CFormView)
	//{{AFX_MSG_MAP(CMySdiView)
	ON_CBN_SELCHANGE(IDC_COMBO, OnSelchangeCombo)
	ON_EN_CHANGE(IDC_EDIT_NAME, OnChangeEditName)
	ON_EN_CHANGE(IDC_EDIT_AGE, OnChangeEditAge)
	ON_EN_CHANGE(IDC_EDIT_SCHOOL, OnChangeEditSchool)
	ON_EN_CHANGE(IDC_EDIT_SEX, OnChangeEditSex)
	ON_EN_CHANGE(IDC_EDIT_TEL, OnChangeEditTel)
	ON_COMMAND(ID_FILE_MYOPEN, OnFileMyopen)
	ON_COMMAND(ID_FILE_MYSAVE, OnFileMysave)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CFormView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CFormView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMySdiView construction/destruction

CMySdiView::CMySdiView()
	: CFormView(CMySdiView::IDD)
{
	//{{AFX_DATA_INIT(CMySdiView)
	m_name = _T("");
	m_age = 0;
	m_school = _T("");
	m_sex = _T("");
	m_tel = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here
	m_nCurrentNo=0;
}

CMySdiView::~CMySdiView()
{
}

void CMySdiView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMySdiView)
	DDX_Control(pDX, IDC_COMBO, m_noList);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_AGE, m_age);
	DDX_Text(pDX, IDC_EDIT_SCHOOL, m_school);
	DDX_Text(pDX, IDC_EDIT_SEX, m_sex);
	DDX_Text(pDX, IDC_EDIT_TEL, m_tel);
	//}}AFX_DATA_MAP
}

BOOL CMySdiView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CFormView::PreCreateWindow(cs);
}

void CMySdiView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	char temp[10];
	CString k;
	for(int i=0;i<40;i++)
	{
		if(i<10)k="2000";
		else k="200";
		m_noList.InsertString(i,k+itoa(i,temp,10));
	}
	CMySdiDoc * pDoc=GetDocument();
	m_noList.SetCurSel(0);
	m_name=pDoc->m_student[0].name;
	m_age=pDoc->m_student[0].age;
	m_school=pDoc->m_student[0].school;
	m_sex=pDoc->m_student[0].sex;
	m_tel=pDoc->m_student[0].tel;
	UpdateData(false);
}

/////////////////////////////////////////////////////////////////////////////
// CMySdiView printing

BOOL CMySdiView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMySdiView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMySdiView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMySdiView::OnPrint(CDC* pDC, CPrintInfo* /*pInfo*/)
{
	// TODO: add customized printing code here
}

/////////////////////////////////////////////////////////////////////////////
// CMySdiView diagnostics

#ifdef _DEBUG
void CMySdiView::AssertValid() const
{
	CFormView::AssertValid();
}

void CMySdiView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CMySdiDoc* CMySdiView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMySdiDoc)));
	return (CMySdiDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMySdiView message handlers

void CMySdiView::OnSelchangeCombo() 
{
	// TODO: Add your control notification handler code here
	CMySdiDoc * pDoc=GetDocument();
	m_nCurrentNo=m_noList.GetCurSel();
	m_name=pDoc->m_student[m_nCurrentNo].name;
	m_age=pDoc->m_student[m_nCurrentNo].age;
	m_school=pDoc->m_student[m_nCurrentNo].school;
	m_sex=pDoc->m_student[m_nCurrentNo].sex;
	m_tel=pDoc->m_student[m_nCurrentNo].tel;
	UpdateData(false);
}

void CMySdiView::OnChangeEditName() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CMySdiDoc * pDoc=GetDocument(); //获取文档对象指针
	UpdateData(true);	//将name控件中的数据存入变量
	if(strcmp(pDoc->m_student[m_nCurrentNo].name,m_name)) //比较
	{
		strcpy(pDoc->m_student[m_nCurrentNo].name,m_name);
		pDoc->SetModifiedFlag();
	}
}

void CMySdiView::OnChangeEditAge() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CMySdiDoc * pDoc=GetDocument(); //获取文档对象指针
	UpdateData(true);	//将name控件中的数据存入变量
	if(pDoc->m_student[m_nCurrentNo].age!=m_age)
	{
		pDoc->m_student[m_nCurrentNo].age=m_age;
		pDoc->SetModifiedFlag();
	}
}

void CMySdiView::OnChangeEditSchool() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CMySdiDoc * pDoc=GetDocument(); //获取文档对象指针
	UpdateData(true);	//将name控件中的数据存入变量
	if(strcmp(pDoc->m_student[m_nCurrentNo].school,m_school)) //比较
	{
		strcpy(pDoc->m_student[m_nCurrentNo].school,m_school);
		pDoc->SetModifiedFlag();
	}
}

void CMySdiView::OnChangeEditSex() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CMySdiDoc * pDoc=GetDocument(); //获取文档对象指针
	UpdateData(true);	//将name控件中的数据存入变量
	if(strcmp(pDoc->m_student[m_nCurrentNo].sex,m_sex)) //比较
	{
		strcpy(pDoc->m_student[m_nCurrentNo].sex,m_sex);
		pDoc->SetModifiedFlag();
	}
}

void CMySdiView::OnChangeEditTel() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CFormView::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.
	
	// TODO: Add your control notification handler code here
	CMySdiDoc * pDoc=GetDocument(); //获取文档对象指针
	UpdateData(true);	//将name控件中的数据存入变量
	if(strcmp(pDoc->m_student[m_nCurrentNo].tel,m_tel)) //比较
	{
		strcpy(pDoc->m_student[m_nCurrentNo].tel,m_tel);
		pDoc->SetModifiedFlag();
	}
}

void CMySdiView::OnFileMyopen() //给'我的打开'菜单项添加响应代码
{
	// TODO: Add your command handler code here
	//响应我的打开菜单项
	CString strFilter="Dat Files(*.dat)|*.dat|All Files(*.*)|*.*||";
	//通用文件对话框
	CFileDialog FileDlg(true,NULL,NULL,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,(LPCSTR)strFilter,this);
	if(FileDlg.DoModal()!=IDOK) return;
	CString strFileName=FileDlg.GetPathName();
	CFile f;
	if(!f.Open(strFileName,CFile::modeRead))
	{
		AfxMessageBox("打开文件失败");
		return;
	}
	CMySdiDoc *pDoc=GetDocument();
	//读出文件中的数据，存放到文档的数据成员中
	f.Read(&m_nCurrentNo,sizeof(int));
	for(int i=0;i<40;i++)
	{
		f.Read(pDoc->m_student[i].name,10);
		f.Read(pDoc->m_student[i].sex,3);
		f.Read(&(pDoc->m_student[i].age),sizeof(int));
		f.Read(pDoc->m_student[i].tel,14);
		f.Read(pDoc->m_student[i].school,30);
	}
	f.Close();
	//将文档类的数据传递给视图类的数据成员，并显
	m_noList.SetCurSel(m_nCurrentNo);
	m_name=pDoc->m_student[m_nCurrentNo].name;
	m_age=pDoc->m_student[m_nCurrentNo].age;
	m_school=pDoc->m_student[m_nCurrentNo].school;
	m_sex=pDoc->m_student[m_nCurrentNo].sex;
	m_tel=pDoc->m_student[m_nCurrentNo].tel;
	UpdateData(false);
}

void CMySdiView::OnFileMysave() 
{
	// TODO: Add your command handler code here
	//响应我的打开菜单项
	CString strFilter="Dat Files(*.dat)|*.dat|All Files(*.*)|*.*||";
	//通用文件对话框
	CFileDialog FileDlg(false,NULL,NULL,
		OFN_HIDEREADONLY|OFN_OVERWRITEPROMPT,(LPCSTR)strFilter,this);
	if(FileDlg.DoModal()!=IDOK) return;
	CString strFileName=FileDlg.GetPathName();
	CFile f;
	if(!f.Open(strFileName,CFile::modeCreate|CFile::modeWrite))
	{
		AfxMessageBox("创建文件失败");
		return;
	}
	CMySdiDoc * pDoc=GetDocument();
	f.Write(&m_nCurrentNo,sizeof(int));
	for(int i=0;i<40;i++)
	{
		f.Write(pDoc->m_student[i].name,10);
		f.Write(pDoc->m_student[i].sex,3);
		f.Write(&(pDoc->m_student[i].age),sizeof(int));
		f.Write(pDoc->m_student[i].tel,14);
		f.Write(pDoc->m_student[i].school,30);
	}
	f.Close();
}

