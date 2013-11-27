========================================================================
       MICROSOFT FOUNDATION CLASS LIBRARY : MyDraw
========================================================================


AppWizard has created this MyDraw application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your MyDraw application.

MyDraw.dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

MyDraw.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    CMyDrawApp application class.

MyDraw.cpp
    This is the main application source file that contains the application
    class CMyDrawApp.

MyDraw.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Visual C++.

MyDraw.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

res\MyDraw.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file MyDraw.rc.

res\MyDraw.rc2
    This file contains resources that are not edited by Microsoft 
	Visual C++.  You should place all resources not editable by
	the resource editor in this file.



/////////////////////////////////////////////////////////////////////////////

For the main frame window:

MainFrm.h, MainFrm.cpp
    These files contain the frame class CMainFrame, which is derived from
    CFrameWnd and controls all SDI frame features.

res\Toolbar.bmp
    This bitmap file is used to create tiled images for the toolbar.
    The initial toolbar and status bar are constructed in the CMainFrame
    class. Edit this toolbar bitmap using the resource editor, and
    update the IDR_MAINFRAME TOOLBAR array in MyDraw.rc to add
    toolbar buttons.
/////////////////////////////////////////////////////////////////////////////

AppWizard creates one document type and one view:

MyDrawDoc.h, MyDrawDoc.cpp - the document
    These files contain your CMyDrawDoc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via CMyDrawDoc::Serialize).

MyDrawView.h, MyDrawView.cpp - the view of the document
    These files contain your CMyDrawView class.
    CMyDrawView objects are used to view CMyDrawDoc objects.



/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named MyDraw.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, and your application is 
in a language other than the operating system's current language, you
will need to copy the corresponding localized resources MFC42XXX.DLL
from the Microsoft Visual C++ CD-ROM onto the system or system32 directory,
and rename it to be MFCLOC.DLL.  ("XXX" stands for the language abbreviation.
For example, MFC42DEU.DLL contains resources translated to German.)  If you
don't do this, some of the UI elements of your application will remain in the
language of the operating system.

/////////////////////////////////////////////////////////////////////////////
��Ļ��ͼ��
	CDC����л�ͼ��
	1.����ͼ���OnDraw()�����л�ͼ
	���裺
		1.ѡ���ͼ����
			����pDC->SelectObject(LTGRAY_BRUSH);
		2.����ͼ��
			��1�����ƾ���
				1.�������
				CRect rect(10,10,200,70);
				2.��һ������
				pDC->Rectangle(rect);
			��2�������ı�
				pDC->TextOut(100,80,"Hello,VC++���");
	2.����ͼ���һ�㺯���л�ͼ
		��1�֣����ڶ�ջ�Ϲ�����󣬹���Ķ���ᱻ�Զ�ɾ����
			����
			void CMyHelloView::OnLbuttonDown(UINT nFlags,CPoint point)
			{
				CDC dc(this);			//�������dc
				CRect rect(0,0,100,100)	//����һ������
				dc.Rectang(rect);		//��ͼ
			}	//dc�Զ��ر��ͷ�
		��2�֣�����GetDC()���������ʾ�豸������ָ��pDC���л�ͼ������ͼ��Ϻ�
		�������ReleaseDC()�������ͷ�����
			����
			void CMyHelloView::OnLbuttonDown(UINT nFlags,CPoint point)
			{
				CDC* pDC=GetDC();  //��ȡ�豸������ָ��
				CRect rect;			//��ͼ����
				pDC->Rectang(rect);
				ReleaseDC(pDC);		//�ͷ�pDC
			}

	CPaintDC����л�ͼ��
	Ӧ���ڶԻ�����������Դ�������Windows��WM_PAINT��Ϣ������ͨ������OnPaint��Ϣ��Ӧ������ʹ�á�
		����
		void MyTestDlg::OnPaint()
		{
		//1.����һ��CPaintDC��Ķ���
			CPaintDC dc(this);
		//2.����CPaintDC��ĺ������л�ͼ
			dc.MoveTo(10,10);	//����MoveTo()��������λ����(10,10)
			dc.LineTo(100,100);	//����LineTo()���������ߵ���(100,100)
			dc.Ellipse(120,120,160,160);	//���û���Բ����Ellipse()
			CDialog::OnPaint();
		}

	CClientDC����л�ͼ��
	CClientDC�������Ҫ�����Զ�������������ڵĿͻ�����������豸�������е��ú��ͷš���CClientDC�����
	����ʱ�Զ�����GetDC(),�ڳ���ʱ���Զ�����ReleaseDC()��
		����
		void CMyHelloView::OnLbuttonDown(UINT nFlags,CPoint point)
		{
			CClientDC dc(this);
			CRect rect;
			GetClientRect(&rect);
			dc.MoveTo(rect.left,rect.Top);		//��λ���ͻ�������������Ͻ�
			dc.LineTo(rect.right,rect.bottom);	//���ߵ��ͻ�������������½�
			Cview::OnLbuttonDown(nFlags,point);
		}

	��ͼ���ߣ�
		CPen(������)��
			1.����ͳ�ʼ�������ڴ������Ĺ��캯����һ�����
				CPen newPen(PS_SOLID,2,RGB(2,255,0));
			2.����ͳ�ʼ����������ɣ������ɲ��������Ĺ��캯����ɣ�����ʼ���ɳ�ʼ������ɡ�
				CPen newPen;
				newPen.CreatePen(PS_SOLID,2,RGB(0,255,0));
		CBrush(��ˢ��):
			1.����ͳ�ʼ�������ڴ������Ĺ��캯����һ�����
				CBrush newBrush(RGB(0,0,255));
			2.����ͳ�ʼ����������ɣ������ɲ��������Ĺ��캯����ɣ�����ʼ���ɳ�ʼ������ɡ�
				CBrush newBrush;
				newBrush.CreateSolidBrush(RGB(0,255,0));
		CFont(������)�������������������
			1.����һ��CFont��Ķ���Ӧ�ÿ�ܻ���ù��캯��
				CFont myFont;
			2.����CFont��Ĵ������庯�����������CFont�������Windows��ĳ�����������
				myFont.CreateFont(...);
				����,CreateFont()ԭ��Ϊ��
				BOOL CreateFont(
					int nHeight,		//����߶�
					int nWidth,			//�ַ�ƽ�����
					int nEscapement,	//�ı��нǶ�
					int nOrientation,	//�ַ��Ƕ�
					int nWeight,		//�ַ���ϸ��
					BYTE bItalic,		//б��
					BYTE bUnderline,	//�»���
					BYTE cStrikeOut,	//ɾ����
					BYTE nCharSet,		//�ַ���
					BYTE nOutPrecison,	//������������Ҫ���ƥ��̶�
					BYTE nClipPrecison,	//��βü����ڲü���֮����ַ�
					BYTE nQuality,		//��������ƥ��ľ�ȷ�̶�
					BYTE nPitchAnFamily,//������������
					BYTE lpszFacename	//��������
				);
