//MCIClass.h


class CMCIClass
{
	protected:
		CString m_strMediumAlias;	//设备别名
		HWND m_hWndCallback;		//回调窗口句柄
		BOOL m_bMediumOpen;			//媒体打开标记
	public:
		CMCIClass(HWND hWnd=NULL);
		virtual ~CMCIClass();
		LONG Open(LPCSTR strMedium,LPCSTR strMediumType,LPCSTR strStyle="",HWND hWnd=NULL);		//打开
		LONG Close();	//关闭
		LONG Play(LPCSTR strStyle="",LPCSTR strFlag="");  //播放
		LONG Stop();	//停止
		LONG SetTimeFormat(LPCSTR strTimeFormat="ms");
		LONG GetLength();
		CString GetTimeFormat();
		LONG GetPosition(LPSTR strPos);
		LONG GetStartPosition(LPSTR strPos);
		BOOL IsMediumOpen();
		BOOL IsMediumPresent();
		LONG Execute(LPCSTR strCmd,LPSTR lpstrReturn=NULL,
			BOOL bShowError=FALSE);		//执行MCI命令
};