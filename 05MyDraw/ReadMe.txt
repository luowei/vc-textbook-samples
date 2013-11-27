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
屏幕绘图：
	CDC类进行绘图：
	1.在视图类的OnDraw()函数中绘图
	步骤：
		1.选择绘图工具
			例：pDC->SelectObject(LTGRAY_BRUSH);
		2.绘制图像
			例1：绘制矩形
				1.定义矩形
				CRect rect(10,10,200,70);
				2.画一个矩形
				pDC->Rectangle(rect);
			例2：绘制文本
				pDC->TextOut(100,80,"Hello,VC++编程");
	2.在视图类的一般函数中绘图
		第1种：是在堆栈上构造对象，构造的对象会被自动删除。
			例：
			void CMyHelloView::OnLbuttonDown(UINT nFlags,CPoint point)
			{
				CDC dc(this);			//构造对象dc
				CRect rect(0,0,100,100)	//定义一个矩形
				dc.Rectang(rect);		//绘图
			}	//dc自动地被释放
		第2种：调用GetDC()函数获得显示设备环境的指针pDC进行绘图，但绘图完毕后，
		必须调用ReleaseDC()函数来释放它。
			例：
			void CMyHelloView::OnLbuttonDown(UINT nFlags,CPoint point)
			{
				CDC* pDC=GetDC();  //获取设备环境的指针
				CRect rect;			//绘图部分
				pDC->Rectang(rect);
				ReleaseDC(pDC);		//释放pDC
			}

	CPaintDC类进行绘图：
	应用于对话框程序，它可以处理来自Windows的WM_PAINT消息，所以通常是在OnPaint消息响应函数中使用。
		例：
		void MyTestDlg::OnPaint()
		{
		//1.创建一个CPaintDC类的对象
			CPaintDC dc(this);
		//2.调用CPaintDC类的函数进行绘图
			dc.MoveTo(10,10);	//调用MoveTo()函数，定位到点(10,10)
			dc.LineTo(100,100);	//调用LineTo()函数，画线到点(100,100)
			dc.Ellipse(120,120,160,160);	//调用画椭圆函数Ellipse()
			CDialog::OnPaint();
		}

	CClientDC类进行绘图：
	CClientDC类对象主要用来自动处理对描述窗口的客户程序区域的设备环境进行调用和释放。在CClientDC类对象
	创建时自动调用GetDC(),在撤销时将自动调用ReleaseDC()。
		例：
		void CMyHelloView::OnLbuttonDown(UINT nFlags,CPoint point)
		{
			CClientDC dc(this);
			CRect rect;
			GetClientRect(&rect);
			dc.MoveTo(rect.left,rect.Top);		//定位到客户程序区域的左上角
			dc.LineTo(rect.right,rect.bottom);	//画线到客户程序区域的右下角
			Cview::OnLbuttonDown(nFlags,point);
		}

	绘图工具：
		CPen(画笔类)：
			1.构造和初始化对象都在带参数的构造函数中一步完成
				CPen newPen(PS_SOLID,2,RGB(2,255,0));
			2.构造和初始化分两步完成，构造由不带参数的构造函数完成，而初始化由初始函数完成。
				CPen newPen;
				newPen.CreatePen(PS_SOLID,2,RGB(0,255,0));
		CBrush(画刷类):
			1.构造和初始化对象都在带参数的构造函数中一步完成
				CBrush newBrush(RGB(0,0,255));
			2.构造和初始化分两步完成，构造由不带参数的构造函数完成，而初始化由初始函数完成。
				CBrush newBrush;
				newBrush.CreateSolidBrush(RGB(0,255,0));
		CFont(字体类)：创建字体由两步完成
			1.定义一个CFont类的对象，应用框架会调用构造函数
				CFont myFont;
			2.调用CFont类的创建字体函数，将构造的CFont类对象与Windows的某种字体相关联
				myFont.CreateFont(...);
				其中,CreateFont()原型为：
				BOOL CreateFont(
					int nHeight,		//字体高度
					int nWidth,			//字符平均宽度
					int nEscapement,	//文本行角度
					int nOrientation,	//字符角度
					int nWeight,		//字符粗细度
					BYTE bItalic,		//斜体
					BYTE bUnderline,	//下划线
					BYTE cStrikeOut,	//删除线
					BYTE nCharSet,		//字符集
					BYTE nOutPrecison,	//字体输出结果和要求的匹配程度
					BYTE nClipPrecison,	//如何裁剪落于裁剪区之外的字符
					BYTE nQuality,		//字体属性匹配的精确程度
					BYTE nPitchAnFamily,//字体间距和字体簇
					BYTE lpszFacename	//字体名称
				);
