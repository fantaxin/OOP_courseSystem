// PasswordDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "PasswordDLG.h"
#include "afxdialogex.h"
#include "Man.h"


// PasswordDLG 对话框

IMPLEMENT_DYNAMIC(PasswordDLG, CDialogEx)

PasswordDLG::PasswordDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PASSWORD, pParent)
	, Password1(_T(" "))
	, Password2(_T(" "))
{

}

PasswordDLG::~PasswordDLG()
{
}

void PasswordDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Password1);
	DDX_Text(pDX, IDC_EDIT2, Password2);
}


BEGIN_MESSAGE_MAP(PasswordDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &PasswordDLG::OnBnClickedButton1)
	//ON_BN_CLICKED(IDOK, &PasswordDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// PasswordDLG 消息处理程序

//单击修改密码对话框中的确定按钮
void PasswordDLG::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int judge1(0), judge2(0);//用于判断错误类别
	trim(Password1);
	trim(Password2);
	if (CSTS(Password1).empty())//当输入密码编辑框没有值时
	{
		MessageBox(TEXT("请输入新密码！"));
	}
	if (CSTS(Password1) != CSTS(Password2))
	{
		judge1 = 1;
		MessageBox(TEXT("两次输入的密码不一致，请重新输入！"));
	}
	if (CSTS(Password1) == one_man.password)
	{
		judge2 = 2;
		MessageBox(TEXT("新密码与原密码一致，请重新输入！"));
	}
	if (judge1 == 0 && judge2 == 0)
	{
		one_man.password = CSTS(Password1);
		man[man_num].password = CSTS(Password1);//修改密码
		CDialogEx::OnOK();
	}
}


//void PasswordDLG::OnBnClickedOk()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	CDialogEx::OnOK();
//}
