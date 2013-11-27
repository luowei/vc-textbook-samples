; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CLSock
LastTemplate=CSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "MyWs.h"

ClassCount=4
Class1=CMyWsApp
Class2=CMyWsDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CLSock
Resource3=IDD_MYWS_DIALOG

[CLS:CMyWsApp]
Type=0
HeaderFile=MyWs.h
ImplementationFile=MyWs.cpp
Filter=N

[CLS:CMyWsDlg]
Type=0
HeaderFile=MyWsDlg.h
ImplementationFile=MyWsDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_SERVER_PORT

[CLS:CAboutDlg]
Type=0
HeaderFile=MyWsDlg.h
ImplementationFile=MyWsDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_MYWS_DIALOG]
Type=1
Class=CMyWsDlg
ControlCount=9
Control1=IDC_STATIC,button,1342177287
Control2=IDC_START,button,1342242816
Control3=IDC_CLOSE,button,1342242816
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_LIST_INLINE,listbox,1353777409
Control7=IDC_RECEIVED_INFO,listbox,1353777409
Control8=IDC_STATIC,static,1342308352
Control9=IDC_SERVER_PORT,edit,1350631552

[CLS:CLSock]
Type=0
HeaderFile=LSock.h
ImplementationFile=LSock.cpp
BaseClass=CSocket
Filter=N
VirtualFilter=uq

