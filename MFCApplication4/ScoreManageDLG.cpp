// ScoreManageDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "ScoreManageDLG.h"
#include "afxdialogex.h"

// ScoreManageDLG 对话框

IMPLEMENT_DYNAMIC(ScoreManageDLG, CDialogEx)

ScoreManageDLG::ScoreManageDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCORE_MANAGE, pParent)
{

}

ScoreManageDLG::~ScoreManageDLG()
{
}

void ScoreManageDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, ScoreManageTab);
}


BEGIN_MESSAGE_MAP(ScoreManageDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ScoreManageDLG::OnBnClickedButton2)
END_MESSAGE_MAP()


// ScoreManageDLG 消息处理程序

//初始化学生成绩管理对话框
BOOL ScoreManageDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//该对话框采用tab，以下代码为初始化tab，tab中的每一项也是一个对话框
	ScoreManageTab.AddPage(TEXT("成绩录入"), &dlg1, IDD_SCORE_ADD);
	ScoreManageTab.AddPage(TEXT("成绩修改"), &dlg2, IDD_SCORE_CANGE);
	ScoreManageTab.AddPage(TEXT("成绩查找"), &dlg3, IDD_SCORE_FIND);
	ScoreManageTab.AddPage(TEXT("成绩分析"), &dlg4, IDD_SCORE_ANDL);
	//显示
	ScoreManageTab.Show();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ScoreManageDLG::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码


}
