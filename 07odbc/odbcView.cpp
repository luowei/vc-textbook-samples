// odbcView.cpp : implementation of the COdbcView class
//

#include "stdafx.h"
#include "odbc.h"

#include "odbcSet.h"
#include "odbcDoc.h"
#include "odbcView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COdbcView

IMPLEMENT_DYNCREATE(COdbcView, CRecordView)

BEGIN_MESSAGE_MAP(COdbcView, CRecordView)
	//{{AFX_MSG_MAP(COdbcView)
	ON_COMMAND(ID_RECORD_FIRST, OnRecordFirst)
	ON_COMMAND(ID_RECORD_LAST, OnRecordLast)
	ON_COMMAND(ID_RECORD_NEXT, OnRecordNext)
	ON_COMMAND(ID_RECORD_PREV, OnRecordPrev)
	ON_BN_CLICKED(IDC_RECORD_ADD, OnRecordAdd)
	ON_BN_CLICKED(IDC_RECORD_DEL, OnRecordDel)
	ON_BN_CLICKED(IDC_RECORD_EDIT, OnRecordEdit)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CRecordView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CRecordView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COdbcView construction/destruction

COdbcView::COdbcView()
	: CRecordView(COdbcView::IDD)
{
	//{{AFX_DATA_INIT(COdbcView)
	m_pSet = NULL;
	m_ID = 0;
	m_name = _T("");
	m_position = _T("");
	m_singer = _T("");
	m_writer = _T("");
	//}}AFX_DATA_INIT
	// TODO: add construction code here

}

COdbcView::~COdbcView()
{
}

void COdbcView::DoDataExchange(CDataExchange* pDX)
{
	CRecordView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(COdbcView)
	DDX_Text(pDX, IDC_EDIT_ID, m_ID);
	DDX_Text(pDX, IDC_EDIT_NAME, m_name);
	DDX_Text(pDX, IDC_EDIT_POSITION, m_position);
	DDX_Text(pDX, IDC_EDIT_SINGER, m_singer);
	DDX_Text(pDX, IDC_EDIT_WRITER, m_writer);
	//}}AFX_DATA_MAP
}

BOOL COdbcView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CRecordView::PreCreateWindow(cs);
}

void COdbcView::OnInitialUpdate()
{
	m_pSet = &GetDocument()->m_odbcSet;
	CRecordView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();
	
	try
	{
		m_pSet=new COdbcSet();
		m_pSet->Open();
		MyUpdateData();
	}
	catch(CDBException* pe)
	{
		AfxMessageBox(pe->m_strError);
		pe->Delete();
	}
}

/////////////////////////////////////////////////////////////////////////////
// COdbcView printing

BOOL COdbcView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void COdbcView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void COdbcView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// COdbcView diagnostics

#ifdef _DEBUG
void COdbcView::AssertValid() const
{
	CRecordView::AssertValid();
}

void COdbcView::Dump(CDumpContext& dc) const
{
	CRecordView::Dump(dc);
}

COdbcDoc* COdbcView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(COdbcDoc)));
	return (COdbcDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COdbcView database support
CRecordset* COdbcView::OnGetRecordset()
{
	return m_pSet;
}


/////////////////////////////////////////////////////////////////////////////
// COdbcView message handlers

void COdbcView::OnRecordFirst() 
{
	// TODO: Add your command handler code here
	m_pSet->MoveFirst();	//�ƶ���¼��ָ������һ����¼��
	MyUpdateData();			//���¼�¼��ʾ
}

void COdbcView::OnRecordLast() 
{
	// TODO: Add your command handler code here
	m_pSet->MoveLast();	//�ƶ���¼��ָ�������һ����¼��
	MyUpdateData();			//���¼�¼��ʾ
}

void COdbcView::OnRecordNext() 
{
	// TODO: Add your command handler code here
	m_pSet->MoveNext();	//�ƶ���¼��ָ������һ����¼��
	MyUpdateData();			//���¼�¼��ʾ
}

void COdbcView::OnRecordPrev() 
{
	// TODO: Add your command handler code here
	m_pSet->MovePrev();	//�ƶ���¼��ָ������һ����¼��
	MyUpdateData();			//���¼�¼��ʾ
}

void COdbcView::OnRecordAdd() //��Ӽ�¼��ť��Ϣ��Ӧ
{
	// TODO: Add your control notification handler code here
	try
	{
		m_pSet->AddNew();
		//�����༭���е����ݴ��ݸ�����������
		UpdateData(true);
		//�����������ݸ����ݼ�ָ����ָ��¼�ĸ����ֶ�
		m_pSet->m_ID=m_ID;
		m_pSet->m_name=m_name;
		m_pSet->m_singer=m_singer;
		m_pSet->m_writer=m_writer;
		m_pSet->m_position=m_position;
		m_pSet->Update();
		m_pSet->Requery();
	}
	catch(CDBException* pe)
	{
		AfxMessageBox(pe->m_strError);
		pe->Delete();
	}
}

void COdbcView::OnRecordDel() //ɾ����¼��ť��Ϣ��Ӧ
{
	// TODO: Add your control notification handler code here
	try
	{
		m_pSet->Delete();
		m_pSet->Requery();
		MyUpdateData();
	}
	catch(CDBException* pe)
	{
		AfxMessageBox(pe->m_strError);
		pe->Delete();
	}
}

void COdbcView::OnRecordEdit() //�޸ļ�¼��ť��Ϣ��Ӧ
{
	// TODO: Add your control notification handler code here
	try
	{
		m_pSet->Edit();
		UpdateData(true);
		m_pSet->m_ID=m_ID;
		m_pSet->m_name=m_name;
		m_pSet->m_singer=m_singer;
		m_pSet->m_writer=m_writer;
		m_pSet->m_position=m_position;
		m_pSet->Update();
	}
	catch(CDBException* pe)
	{
		AfxMessageBox(pe->m_strError);
		pe->Delete();
	}
}

void COdbcView::MyUpdateData()
{
	m_name=m_pSet->m_name;
	m_ID=m_pSet->m_ID;
	m_singer=m_pSet->m_singer;
	m_writer=m_pSet->m_writer;
	m_position=m_pSet->m_position;
	UpdateData(false);
}
