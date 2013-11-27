; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMySdiView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MySdi.h"
LastPage=0

ClassCount=5
Class1=CMySdiApp
Class2=CMySdiDoc
Class3=CMySdiView
Class4=CMainFrame

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Resource3=IDD_MYSDI_FORM

[CLS:CMySdiApp]
Type=0
HeaderFile=MySdi.h
ImplementationFile=MySdi.cpp
Filter=N

[CLS:CMySdiDoc]
Type=0
HeaderFile=MySdiDoc.h
ImplementationFile=MySdiDoc.cpp
Filter=N

[CLS:CMySdiView]
Type=0
HeaderFile=MySdiView.h
ImplementationFile=MySdiView.cpp
Filter=D
BaseClass=CFormView
VirtualFilter=VWC
LastObject=IDC_EDIT_NAME


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=ID_FILE_MYSAVE




[CLS:CAboutDlg]
Type=0
HeaderFile=MySdi.cpp
ImplementationFile=MySdi.cpp
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
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_FILE_MYOPEN
Command18=ID_FILE_MYSAVE
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[DLG:IDD_MYSDI_FORM]
Type=1
Class=CMySdiView
ControlCount=13
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308352
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_EDIT_NAME,edit,1350631552
Control7=IDC_EDIT_SEX,edit,1350631552
Control8=IDC_EDIT_AGE,edit,1350631552
Control9=IDC_EDIT_TEL,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308353
Control12=IDC_EDIT_SCHOOL,edit,1350631552
Control13=IDC_COMBO,combobox,1344340226

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
Command9=ID_FILE_MYOPEN
Command10=ID_FILE_MYSAVE
CommandCount=10

