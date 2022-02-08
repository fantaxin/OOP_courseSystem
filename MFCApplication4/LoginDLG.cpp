// LoginDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "LoginDLG.h"
#include "afxdialogex.h"

#include"Man.h"

int index_login;

// LoginDLG 对话框

IMPLEMENT_DYNAMIC(LoginDLG, CDialogEx)

LoginDLG::LoginDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LOGIN, pParent)
	//, cbx_man_account(_T(""))
	, edit_man_password(_T(""))
	, cbx_man_type(_T(""))
{

}

LoginDLG::~LoginDLG()
{
}

void LoginDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	//DDX_Control(pDX, IDC_COMBO2, cbx_man_type);
	//DDX_CBString(pDX, IDC_COMBO1, cbx_man_account);
	DDX_Text(pDX, IDC_EDIT1, edit_man_password);
	DDX_CBString(pDX, IDC_COMBO2, cbx_man_type);
	DDX_Control(pDX, IDC_COMBO1, cbx_man_account);
}


BEGIN_MESSAGE_MAP(LoginDLG, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO2, &LoginDLG::OnCbnSelchangeCombo2)
	ON_BN_CLICKED(IDC_BUTTON1, &LoginDLG::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &LoginDLG::OnBnClickedCheck1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &LoginDLG::OnCbnSelchangeCombo1)
	ON_CBN_SELENDOK(IDC_COMBO1, &LoginDLG::OnCbnSelendokCombo1)
//	ON_NOTIFY(NM_THEMECHANGED, IDC_COMBO1, &LoginDLG::OnNMThemeChangedCombo1)
ON_BN_CLICKED(IDOK, &LoginDLG::OnBnClickedOk)
ON_WM_CLOSE()
END_MESSAGE_MAP()


// LoginDLG 消息处理程序

BOOL LoginDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(L"学生");//初始化登录类别下拉框
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(L"教师");
	((CComboBox*)GetDlgItem(IDC_COMBO2))->AddString(L"管理员");
	((CComboBox*)GetDlgItem(IDC_COMBO2))->SetCurSel(0);

	size_t ss = man.size();
	for (size_t i = 0; i < ss; i++)
	{
		//将选择记住的用户的账号加入下拉框
		if (man[i].sfjzmm==1)
		{
			wstring wstr(man[i].account.begin(), man[i].account.end());
			cbx_man_account.AddString(wstr.c_str());
		}
	}
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


//单击登录对话框中的登录按钮
void LoginDLG::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	//Read_Login();//在主程序已经读过一遍文件了，这里重复读入导致数据重复
	UpdateData(TRUE);
	int judge=0;//判断登录成功或者错误类别
	size_t man_n = man.size();
	for (size_t i = 0; i < man_n; i++)
	{
		CString cstr;
		//cbx_man_account.GetLBText(index_login, cstr);
		GetDlgItem(IDC_COMBO1)->GetWindowText(cstr);//获取账号信息
		if (CSTS(cstr) == man[i].account&&CSTS(edit_man_password) == man[i].password)
		{
			//判断账号和密码是否匹配
			judge = 1;
			if (CSTS(cbx_man_type) == man[i].type)
			{
				//判断登录类别是否匹配
				judge = 2;
				CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);//获取是否选择记住密码
				int state = pBtn->GetCheck();//将记住密码的状态赋给state
				man[i].sfjzmm = state;//将state的值存入容器中
				one_man = man[i];
				man_num = i;
				//Write_Login();
				CDialogEx::OnOK();
			}
		}
	}
	//CDialogEx::OnOK();
	if (judge == 0)
	{
		MessageBox(L"账号或密码输入错误！", TEXT("ERROR!"), MB_OK | MB_ICONERROR);
	}
	if (judge == 1)
	{
		MessageBox(L"请选择正确的登录身份！", TEXT("ERROR!"), MB_OK | MB_ICONERROR);
	}
}
//账号下拉框的值更改时的事件处理程序
void LoginDLG::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	index_login = cbx_man_account.GetCurSel();//获取选择的下拉框的值的序号
	for (size_t i = 0; i < man.size(); i++)
	{
		CString cstr;
		cbx_man_account.GetLBText(index_login, cstr);//获取下拉框第某个序号的值
		//GetDlgItem(IDC_COMBO1)->GetWindowText(cstr);
		if (CSTS(cstr) == man[i].account)
		{
			if (man[i].sfjzmm == 1)
			{
				CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
				pBtn->SetCheck(1); 
				edit_man_password = man[i].password.c_str();//将密码写入编辑框
				//UpdateData(FALSE);
			}
		}
	}
	UpdateData(FALSE);
}


void LoginDLG::OnCbnSelendokCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	//UpdateData(FALSE);
	//UpdateData(TRUE);
	//UpdateData(FALSE);
	//for (int i = 0; i < man.size(); i++)
	//{
	//	if (CSTS(cbx_man_account) == man[i].account)
	//	{
	//		if (man[i].sfjzmm == 1)
	//		{
	//			CButton* pBtn = (CButton*)GetDlgItem(IDC_CHECK1);
	//			pBtn->SetCheck(1);
	//			edit_man_password = man[i].password.c_str();
	//			UpdateData(FALSE);
	//		}
	//	}
	//}
}


void LoginDLG::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	exit(0);
}


void LoginDLG::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值

	//CDialogEx::OnClose();
	exit(0);
}
void LoginDLG::OnBnClickedCheck1()
{
	// TODO: 在此添加控件通知处理程序代码

}
void LoginDLG::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
}
