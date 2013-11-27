//MCIClass.h


class CMCIClass
{
	protected:
		CString m_strMediumAlias;	//�豸����
		HWND m_hWndCallback;		//�ص����ھ��
		BOOL m_bMediumOpen;			//ý��򿪱��
	public:
		CMCIClass(HWND hWnd=NULL);
		virtual ~CMCIClass();
		LONG Open(LPCSTR strMedium,LPCSTR strMediumType,LPCSTR strStyle="",HWND hWnd=NULL);		//��
		LONG Close();	//�ر�
		LONG Play(LPCSTR strStyle="",LPCSTR strFlag="");  //����
		LONG Stop();	//ֹͣ
		LONG SetTimeFormat(LPCSTR strTimeFormat="ms");
		LONG GetLength();
		CString GetTimeFormat();
		LONG GetPosition(LPSTR strPos);
		LONG GetStartPosition(LPSTR strPos);
		BOOL IsMediumOpen();
		BOOL IsMediumPresent();
		LONG Execute(LPCSTR strCmd,LPSTR lpstrReturn=NULL,
			BOOL bShowError=FALSE);		//ִ��MCI����
};