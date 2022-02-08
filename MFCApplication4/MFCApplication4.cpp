﻿
// MFCApplication4.cpp: 定义应用程序的类行为。
//

#include "pch.h"
#include "framework.h"
#include "afxwinappex.h"
#include "afxdialogex.h"
#include "MFCApplication4.h"
#include "MainFrm.h"

#include "MFCApplication4Doc.h"
#include "MFCApplication4View.h"

#include"Man.h"
#include"LoginDLG.h"
#include "ScoreManageDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif



// CMFCApplication4App

BEGIN_MESSAGE_MAP(CMFCApplication4App, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, &CMFCApplication4App::OnAppAbout)
	// 基于文件的标准文档命令
	ON_COMMAND(ID_FILE_NEW, &CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, &CWinApp::OnFileOpen)
	// 标准打印设置命令
	ON_COMMAND(ID_FILE_PRINT_SETUP, &CWinApp::OnFilePrintSetup)
END_MESSAGE_MAP()


// CMFCApplication4App 构造

CMFCApplication4App::CMFCApplication4App() noexcept
{
	// 支持重新启动管理器
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_ALL_ASPECTS;
#ifdef _MANAGED
	// 如果应用程序是利用公共语言运行时支持(/clr)构建的，则: 
	//     1) 必须有此附加设置，“重新启动管理器”支持才能正常工作。
	//     2) 在您的项目中，您必须按照生成顺序向 System.Windows.Forms 添加引用。
	System::Windows::Forms::Application::SetUnhandledExceptionMode(System::Windows::Forms::UnhandledExceptionMode::ThrowException);
#endif

	// TODO: 将以下应用程序 ID 字符串替换为唯一的 ID 字符串；建议的字符串格式
	//为 CompanyName.ProductName.SubProduct.VersionInformation
	SetAppID(_T("MFCApplication4.AppID.NoVersion"));

	// TODO: 在此处添加构造代码，
	// 将所有重要的初始化放置在 InitInstance 中
}

// 唯一的 CMFCApplication4App 对象

CMFCApplication4App theApp;


// CMFCApplication4App 初始化

BOOL CMFCApplication4App::InitInstance()
{
	// 如果一个运行在 Windows XP 上的应用程序清单指定要
	// 使用 ComCtl32.dll 版本 6 或更高版本来启用可视化方式，
	//则需要 InitCommonControlsEx()。  否则，将无法创建窗口。
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// 将它设置为包括所有要在应用程序中使用的
	// 公共控件类。
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	///////////////////////////////////////////////////


    Read_Course();
	Read_Student();
	Read_Student_Course();
	Read_Teacher();
	Read_Login();

	LoginDLG login_dlg;
	login_dlg.DoModal();

	//Write_Course();
	//Write_Student();
	//Write_Student_Course();
	//Write_Teacher();
	//Write_Login();
	


	//CMenu* pMenu = AfxGetMainWnd()->GetMenu();
	//pMenu->EnableMenuItem(3, MF_BYPOSITION | MF_ENABLED);


	CWinApp::InitInstance();


	// 初始化 OLE 库
	if (!AfxOleInit())
	{
		AfxMessageBox(IDP_OLE_INIT_FAILED);
		return FALSE;
	}

	AfxEnableControlContainer();

	EnableTaskbarInteraction(FALSE);

	// 使用 RichEdit 控件需要 AfxInitRichEdit2()
	// AfxInitRichEdit2();

	// 标准初始化
	// 如果未使用这些功能并希望减小
	// 最终可执行文件的大小，则应移除下列
	// 不需要的特定初始化例程
	// 更改用于存储设置的注册表项
	// TODO: 应适当修改该字符串，
	// 例如修改为公司或组织名
	SetRegistryKey(_T("应用程序向导生成的本地应用程序"));
	LoadStdProfileSettings(4);  // 加载标准 INI 文件选项(包括 MRU)

	//LoginDLG dlg;
	//dlg.DoModal();
	//int n = dlg.DoModal();
	//if (n == IDCANCEL) { PostQuitMessage(0); return FALSE; }

	//if (n == IDOK)
	//{

		// 注册应用程序的文档模板。  文档模板
		// 将用作文档、框架窗口和视图之间的连接
		CSingleDocTemplate* pDocTemplate;
		pDocTemplate = new CSingleDocTemplate(
			IDR_MAINFRAME,
			RUNTIME_CLASS(CMFCApplication4Doc),
			RUNTIME_CLASS(CMainFrame),       // 主 SDI 框架窗口
			RUNTIME_CLASS(CMFCApplication4View));
		if (!pDocTemplate)
			return FALSE;
		AddDocTemplate(pDocTemplate);


		// 分析标准 shell 命令、DDE、打开文件操作的命令行
		CCommandLineInfo cmdInfo;
		ParseCommandLine(cmdInfo);



		// 调度在命令行中指定的命令。  如果
		// 用 /RegServer、/Register、/Unregserver 或 /Unregister 启动应用程序，则返回 FALSE。
		if (!ProcessShellCommand(cmdInfo))
			return FALSE;

		// 唯一的一个窗口已初始化，因此显示它并对其进行更新
		m_pMainWnd->ShowWindow(SW_SHOW);
		m_pMainWnd->UpdateWindow();

		//通过不同的登陆身份来选择可以使用的菜单
		CMenu* submenu = m_pMainWnd->GetMenu();
		if (one_man.type == "管理员")
		{
			submenu->EnableMenuItem(4, MF_BYPOSITION | MF_ENABLED | MF_GRAYED);
			submenu->EnableMenuItem(5, MF_BYPOSITION | MF_ENABLED | MF_GRAYED);
		}
		else if (one_man.type == "教师")
		{
			submenu->EnableMenuItem(3, MF_BYPOSITION | MF_ENABLED | MF_GRAYED);
			submenu->EnableMenuItem(5, MF_BYPOSITION | MF_ENABLED | MF_GRAYED);
		}
		else if (one_man.type == "学生")
		{
			submenu->EnableMenuItem(3, MF_BYPOSITION | MF_ENABLED | MF_GRAYED);
			submenu->EnableMenuItem(4, MF_BYPOSITION | MF_ENABLED | MF_GRAYED);
		}


		return TRUE;
	}
//}

int CMFCApplication4App::ExitInstance()
{
	//TODO: 处理可能已添加的附加资源
	AfxOleTerm(FALSE);

	return CWinApp::ExitInstance();
}

// CMFCApplication4App 消息处理程序


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg() noexcept;

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() noexcept : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

// 用于运行对话框的应用程序命令
void CMFCApplication4App::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

// CMFCApplication4App 消息处理程序



string CSTS(CString cstr)
{
	LPCWSTR wstr(cstr);

	int size = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);

	char* p = new char[size + 1];

	WideCharToMultiByte(CP_ACP, 0, wstr, -1, p, size, NULL, NULL);

	return p;
}

LPCWSTR CMFCApplication4App::StringToLPCWSTR(string str)
{
	int size = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t* buffer = new wchar_t[size + 1];

	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, buffer, size);

	return buffer;
}

string CMFCApplication4App::LPCWSTRToString(LPCWSTR wstr)
{
	int size = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);

	char* p = new char[size + 1];

	WideCharToMultiByte(CP_ACP, 0, wstr, -1, p, size, NULL, NULL);

	return p;
}

LPCWSTR StringToLPCWSTR(string str)
{
	int size = MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, NULL, 0);

	wchar_t* buffer = new wchar_t[size + 1];

	MultiByteToWideChar(CP_ACP, 0, str.c_str(), -1, buffer, size);

	return buffer;
}
string LPCWSTRToString(LPCWSTR wstr)
{
	int size = WideCharToMultiByte(CP_ACP, 0, wstr, -1, NULL, 0, NULL, NULL);

	char* p = new char[size + 1];

	WideCharToMultiByte(CP_ACP, 0, wstr, -1, p, size, NULL, NULL);

	return p;
}

double cstring2double(CString cstr)
{
	double score1;
	string str1;
	str1 = CSTS(cstr);
	stringstream s1;
	s1 << str1;
	s1 >> score1;
	return score1;
}

CString int2cstring(int a)
{
	stringstream ss;
	ss << a;
	string str;
	str = ss.str();
	CString cstr;
	cstr = str.c_str();
	return cstr;
}
CString double2cstring(double a)
{
	stringstream ss;
	ss << a;
	string str;
	str = ss.str();
	CString cstr;
	cstr = str.c_str();
	return cstr;
}
string double2string(double a)
{
	stringstream ss;
	ss << a;
	string str;
	str = ss.str();
	return str;
}
double string2double(string str1)
{
	double score1;

	stringstream s1;
	s1 << str1;
	s1 >> score1;
	return score1;
}

void trim(CString &cs)
{
	string s = CSTS(cs);
	if (!s.empty())
	{
		s.erase(0, s.find_first_not_of(" "));
		s.erase(s.find_last_not_of(" ") + 1);
	}
	cs = s.c_str();
}