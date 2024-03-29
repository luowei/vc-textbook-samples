; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMyDrawView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyDraw.h"
LastPage=0

ClassCount=5
Class1=CMyDrawApp
Class2=CMyDrawDoc
Class3=CMyDrawView
Class4=CMainFrame

ResourceCount=3
Resource1=IDR_MAINFRAME
Class5=CAboutDlg
Resource2=IDR_POPUP_MENU
Resource3=IDD_ABOUTBOX

[CLS:CMyDrawApp]
Type=0
HeaderFile=MyDraw.h
ImplementationFile=MyDraw.cpp
Filter=N

[CLS:CMyDrawDoc]
Type=0
HeaderFile=MyDrawDoc.h
ImplementationFile=MyDrawDoc.cpp
Filter=N

[CLS:CMyDrawView]
Type=0
HeaderFile=MyDrawView.h
ImplementationFile=MyDrawView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_WIDTH3


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_WIDTH1
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=MyDraw.cpp
ImplementationFile=MyDraw.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_LINE
Command15=ID_RECT
Command16=ID_ELLIRECT
Command17=ID_ELLIPSE
Command18=ID_WIDTH1
Command19=ID_WIDTH2
Command20=ID_WIDTH3
Command21=ID_COLOR
Command22=ID_VIEW_TOOLBAR
Command23=ID_VIEW_STATUS_BAR
Command24=ID_APP_ABOUT
Command25=ID_SHOWBITMAP
Command26=ID_Dbmp
CommandCount=26

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_ELLIRECT
Command3=ID_ELLIPSE
Command4=ID_ELLIPSE
Command5=ID_LINE
Command6=ID_FILE_NEW
Command7=ID_FILE_OPEN
Command8=ID_FILE_PRINT
Command9=ID_RECT
Command10=ID_FILE_SAVE
Command11=ID_EDIT_PASTE
Command12=ID_EDIT_UNDO
Command13=ID_EDIT_CUT
Command14=ID_NEXT_PANE
Command15=ID_PREV_PANE
Command16=ID_EDIT_COPY
Command17=ID_EDIT_PASTE
Command18=ID_EDIT_CUT
Command19=ID_EDIT_UNDO
CommandCount=19

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
Command9=ID_COLOR
Command10=ID_LINE
Command11=ID_RECT
Command12=ID_ELLIRECT
Command13=ID_ELLIPSE
Command14=ID_WIDTH1
Command15=ID_WIDTH2
Command16=ID_WIDTH3
CommandCount=16

[MNU:IDR_POPUP_MENU]
Type=1
Class=?
Command1=ID_LINE
Command2=ID_RECT
Command3=ID_ELLIRECT
Command4=ID_ELLIPSE
CommandCount=4

