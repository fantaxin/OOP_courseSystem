// Teacher_ManageDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "Teacher_ManageDLG.h"
#include "afxdialogex.h"
#include"Man.h"
int judge1 = 0;
int teacher_num;
int man_n2;
// Teacher_ManageDLG 对话框

IMPLEMENT_DYNAMIC(Teacher_ManageDLG, CDialogEx)

Teacher_ManageDLG::Teacher_ManageDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG7, pParent)
	, m_teacher_id(_T(" "))
	, m_teacher_name(_T(" "))
	, teacher_password(_T(" "))
{

}

Teacher_ManageDLG::~Teacher_ManageDLG()
{
}

void Teacher_ManageDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_teacher_id);
	DDX_Text(pDX, IDC_EDIT2, m_teacher_name);
	DDX_Text(pDX, IDC_EDIT3, teacher_password);
}


BEGIN_MESSAGE_MAP(Teacher_ManageDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Teacher_ManageDLG::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Teacher_ManageDLG::OnBnClickedButton4)
	ON_EN_KILLFOCUS(IDC_EDIT1, &Teacher_ManageDLG::OnEnKillfocusEdit1)
END_MESSAGE_MAP()


// Teacher_ManageDLG 消息处理程序


void Teacher_ManageDLG::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (judge1 == 1)
	{
		MessageBox(TEXT("该教师信息已存在！"));
		return;
	}
	UpdateData(TRUE);
	//m_teacher_id.Delete(0, 1);
	//m_teacher_name.Delete(0, 1);
	trim(m_teacher_id);
	trim(m_teacher_name);
	trim(teacher_password);
	vector<Course> c;

	if (Add_Teacher(c, CSTS(m_teacher_id), CSTS(m_teacher_name)))
	{
		if (Add_Login("教师", CSTS(m_teacher_id), CSTS(teacher_password), CSTS(m_teacher_name)))
		{
			MessageBox(TEXT("添加成功！"));
			Write_Teacher();
		}
	}
	else
		MessageBox(TEXT("添加失败！"));

}

//单击教师管理对话框中的删除按钮
void Teacher_ManageDLG::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (judge1 == 0)
	{
		MessageBox(TEXT("未找到该教师信息！"));
		return;
	}
	man.erase(man.begin() + man_n2);
	teacher.erase(teacher.begin() + teacher_num);
	MessageBox(TEXT("删除成功！"));
	Write_Teacher();
}

//当教师管理对话框中的教师id编辑框失去输入焦点时
void Teacher_ManageDLG::OnEnKillfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码

	GetDlgItem(IDC_EDIT2)->SetWindowTextW(_T(""));//清除编辑框中原来的值
	GetDlgItem(IDC_EDIT3)->SetWindowTextW(_T(""));
	UpdateData(TRUE);
	//m_teacher_id.Delete(0, 1);
	trim(m_teacher_id);//去除编辑框中的内容中的空格
	size_t i, i2;
	i2 = teacher.size();
	for (i = 0; i < i2; i++)//遍历teacher容器
	{
		if (CSTS(m_teacher_id) == teacher[i].teacher_id)
		{
			//如果输入的id与容器中的教师id 相等时
			for (size_t t = 0; t < man.size(); t++)
			{
				if (CSTS(m_teacher_id) == man[t].account)
				{
					//如果该id与登录人员容器中的账号相等时
					man_n2 = t;//该教师在man中的序号
				}
			}
			judge1 = 1;
			size_t n, n2;
			m_teacher_name;
			m_teacher_name = StringToLPCWSTR(teacher[i].teacher_name);//将该id的教师姓名写入编辑框
			UpdateData(FALSE);
			teacher_num = i;//该教师在teacher中的序号
			return;
		}
		judge1 = 0;//找到该教师时judge1=0
	}
}


BOOL Teacher_ManageDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//string sstr = " ";
	//m_teacher_id = StringToLPCWSTR(sstr);
	//m_teacher_name = StringToLPCWSTR(sstr);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
