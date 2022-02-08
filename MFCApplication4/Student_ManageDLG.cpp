// Student_ManageDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "Student_ManageDLG.h"
#include "afxdialogex.h"
#include"Man.h"
int judge2 = 0;
int student_n;
int man_n;
// Student_ManageDLG 对话框

IMPLEMENT_DYNAMIC(Student_ManageDLG, CDialogEx)

Student_ManageDLG::Student_ManageDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG6, pParent)
	, m_student_id(_T(" "))
	, m_student_name(_T(" "))
	, m_class(_T(" "))
	, m_major(_T(" "))
	, student_password(_T(" "))
{

}

Student_ManageDLG::~Student_ManageDLG()
{
}

void Student_ManageDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_student_id);
	DDX_Text(pDX, IDC_EDIT2, m_student_name);
	DDX_Text(pDX, IDC_EDIT3, m_class);
	DDX_Text(pDX, IDC_EDIT4, m_major);
	DDX_Text(pDX, IDC_EDIT6, student_password);
}


BEGIN_MESSAGE_MAP(Student_ManageDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Student_ManageDLG::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Student_ManageDLG::OnBnClickedButton4)
	ON_EN_KILLFOCUS(IDC_EDIT1, &Student_ManageDLG::OnEnKillfocusEdit1)
END_MESSAGE_MAP()


// Student_ManageDLG 消息处理程序


void Student_ManageDLG::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	if (judge2 == 1)
	{
		MessageBox(TEXT("该学生信息已存在！"));
		return;
	}


	UpdateData(TRUE);
	//m_student_id.Delete(0, 1);
	//m_student_name.Delete(0, 1);
	//m_class.Delete(0, 1);
	//m_major.Delete(0, 1);
	trim(m_student_id);
	trim(m_student_name);
	trim(m_class);
	trim(m_major);
	trim(student_password);
	vector<Course> c;

	if (Add_Student(c, CSTS(m_student_id), CSTS(m_student_name), CSTS(m_major), CSTS(m_class)))
	{
		if (Add_Login("学生", CSTS(m_student_id), CSTS(student_password), CSTS(m_student_name)))
		{
			MessageBox(TEXT("添加成功！"));
			Write_Student();
		}
	}
	else
		MessageBox(TEXT("添加失败！"));

}


void Student_ManageDLG::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码

	if (judge2 == 0)
	{
		MessageBox(TEXT("未找到该学生信息！"));
		return;
	}
	man.erase(man.begin()+man_n);
	student.erase(student.begin() + student_n);
	MessageBox(TEXT("删除成功！"));
	Write_Student();
}


void Student_ManageDLG::OnEnKillfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码

	//GetDlgItem(IDC_EDIT1)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT3)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT4)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT6)->SetWindowTextW(_T(""));
	UpdateData(TRUE);
	//m_student_id.Delete(0, 1);
	trim(m_student_id);
	size_t i, i2;
	i2 = student.size();
	for (i = 0; i < i2; i++)
	{

		if (CSTS(m_student_id) == student[i].student_id)
		{
			for (size_t t = 0; t < man.size(); t++)
			{
				if (CSTS(m_student_id) == man[t].account)
				{
					man_n = t;
				}
			}
			judge2 = 1;
			size_t n, n2;
			m_student_name = StringToLPCWSTR(student[i].student_name);
			m_class = StringToLPCWSTR(student[i].student_class);
			m_major = StringToLPCWSTR(student[i].student_major);
			//student_password= StringToLPCWSTR(man[i].password);
			UpdateData(FALSE);

			student_n = i;
			return;
		}
		judge2 = 0;
	}

}


BOOL Student_ManageDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//string sstr = " ";
	//m_student_id = StringToLPCWSTR(sstr);
	//m_student_name = StringToLPCWSTR(sstr);
	//m_class = StringToLPCWSTR(sstr);
	//m_major = StringToLPCWSTR(sstr);
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
