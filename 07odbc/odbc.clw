; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=COdbcView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "odbc.h"
LastPage=0

ClassCount=6
Class1=COdbcApp
Class2=COdbcDoc
Class3=COdbcView
Class4=CMainFrame
Class6=CAboutDlg

ResourceCount=7
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=COdbcSet
Resource7=IDD_ODBC_FORM

[CLS:COdbcApp]
Type=0
HeaderFile=odbc.h
ImplementationFile=odbc.cpp
Filter=N

[CLS:COdbcDoc]
Type=0
HeaderFile=odbcDoc.h
ImplementationFile=odbcDoc.cpp
Filter=N

[CLS:COdbcView]
Type=0
HeaderFile=odbcView.h
ImplementationFile=odbcView.cpp
Filter=D
BaseClass=CRecordView
VirtualFilter=RVWC
LastObject=IDC_RECORD_EDIT


[CLS:COdbcSet]
Type=0
HeaderFile=odbcSet.h
ImplementationFile=odbcSet.cpp
Filter=N

[DB:COdbcSet]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[ID], 4, 4
Column2=[name], 12, 100
Column3=[singer], 12, 100
Column4=[writer], 12, 100
Column5=[position], 12, 100


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_RECORD_FIRST




[CLS:CAboutDlg]
Type=0
HeaderFile=odbc.cpp
ImplementationFile=odbc.cpp
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
Command1=ID_FILE_PRINT
Command2=ID_FILE_PRINT_PREVIEW
Command3=ID_FILE_PRINT_SETUP
Command4=ID_APP_EXIT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_RECORD_FIRST
Command10=ID_RECORD_PREV
Command11=ID_RECORD_NEXT
Command12=ID_RECORD_LAST
Command13=ID_VIEW_TOOLBAR
Command14=ID_VIEW_STATUS_BAR
Command15=ID_APP_ABOUT
CommandCount=15

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_PRINT
Command2=ID_EDIT_UNDO
Command3=ID_EDIT_CUT
Command4=ID_EDIT_COPY
Command5=ID_EDIT_PASTE
Command6=ID_EDIT_UNDO
Command7=ID_EDIT_CUT
Command8=ID_EDIT_COPY
Command9=ID_EDIT_PASTE
Command10=ID_NEXT_PANE
Command11=ID_PREV_PANE
CommandCount=11

[DLG:IDD_ODBC_FORM]
Type=1
Class=COdbcView
ControlCount=13
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_ID,edit,1350631552
Control7=IDC_EDIT_NAME,edit,1350631552
Control8=IDC_EDIT_SINGER,edit,1350631552
Control9=IDC_EDIT_WRITER,edit,1350631552
Control10=IDC_EDIT_POSITION,edit,1350631552
Control11=IDC_RECORD_ADD,button,1342242816
Control12=IDC_RECORD_DEL,button,1342242816
Control13=IDC_RECORD_EDIT,button,1342242816

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_EDIT_CUT
Command2=ID_EDIT_COPY
Command3=ID_EDIT_PASTE
Command4=ID_FILE_PRINT
Command5=ID_RECORD_FIRST
Command6=ID_RECORD_PREV
Command7=ID_RECORD_NEXT
Command8=ID_RECORD_LAST
Command9=ID_APP_ABOUT
CommandCount=9

