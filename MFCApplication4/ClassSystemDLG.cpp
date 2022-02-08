// ClassSystemDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "ClassSystemDLG.h"
#include "afxdialogex.h"
#include"Man.h"

// ClassSystemDLG 对话框

IMPLEMENT_DYNAMIC(ClassSystemDLG, CDialogEx)

ClassSystemDLG::ClassSystemDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLASS_MANAGE, pParent)
{

}

ClassSystemDLG::~ClassSystemDLG()
{
}

void ClassSystemDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, course_select1);
	DDX_Control(pDX, IDC_COMBO2, course_delete1);
	DDX_Control(pDX, IDC_LIST1, m_course);
}


BEGIN_MESSAGE_MAP(ClassSystemDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ClassSystemDLG::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ClassSystemDLG::OnBnClickedButton2)
END_MESSAGE_MAP()


// ClassSystemDLG 消息处理程序
size_t studentn1;

BOOL ClassSystemDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//size_t studentn1;
	for (size_t i = 0; i < student.size(); i++)
	{
		if (student[i].student_id == one_man.account)
		{
			studentn1 = i;
			break;
		}
	}

	DWORD dwStyle = m_course.GetExtendedStyle();
	m_course.SetExtendedStyle(dwStyle | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_course.InsertColumn(0, L"未选课程", LVCFMT_LEFT, 200);
	m_course.InsertColumn(1, L"学分", LVCFMT_LEFT, 80);
	m_course.InsertColumn(2, L"学时", LVCFMT_LEFT, 80);
	m_course.InsertColumn(3, L"课程类别", LVCFMT_LEFT, 80);

	size_t n;	
	size_t n1;
	n1 = course.size();
	n = student[studentn1].student_course.size();
	for (size_t i = 0; i < n; i++)
	{
		course_delete1.InsertString(i, StringToLPCWSTR(student[studentn1].student_course[i].course_name));
	}
    int nnn = 0;
	for (size_t i1 = 0; i1 < n1; i1++)
	{
		int jjj=1;
		
		for (size_t i2 = 0; i2 < n; i2++)
		{
			if (course[i1].course_name == student[studentn1].student_course[i2].course_name)
			{
				jjj = 0;
			}
		}
		if (jjj == 1)
		{
			course_select1.InsertString(nnn, StringToLPCWSTR(course[i1].course_name));

			m_course.InsertItem(nnn, StringToLPCWSTR(course[i1].course_name));
			m_course.SetItemText(nnn, 1, StringToLPCWSTR(double2string(course[i1].course_credit)));
			m_course.SetItemText(nnn, 2, StringToLPCWSTR(double2string(course[i1].course_hours)));
			m_course.SetItemText(nnn, 3, StringToLPCWSTR(course[i1].course_type));
			nnn++;
		}
	}

//course_select1.InsertString(i, StringToLPCWSTR(student[studentn1].student_course[i].course_name));



	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ClassSystemDLG::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cstr;
	int index_login = course_select1.GetCurSel();
	course_select1.GetLBText(index_login, cstr);


	m_course.DeleteAllItems();
	course_select1.ResetContent();
	course_delete1.ResetContent();
	//CString cstr;
	//GetDlgItem(IDC_COMBO1)->GetWindowText(cstr);
	size_t cccs = course.size();
	for (size_t i = 0; i < cccs; i++)
	{
		if (CSTS(cstr) == course[i].course_name)
		{
			course[i].course_score = 0;
			course[i].course_pass = false;
			student[studentn1].student_course.push_back(course[i]);
			break;
		}
	}


	size_t n;
	size_t n1;
	n1 = course.size();
	n = student[studentn1].student_course.size();
	for (size_t i = 0; i < n; i++)
	{
		course_delete1.InsertString(i, StringToLPCWSTR(student[studentn1].student_course[i].course_name));
	}
	int nnn = 0;
	for (size_t i1 = 0; i1 < n1; i1++)
	{
		int jjj = 1;

		for (size_t i2 = 0; i2 < n; i2++)
		{
			if (course[i1].course_name == student[studentn1].student_course[i2].course_name)
			{
				jjj = 0;
			}
		}
		if (jjj == 1)
		{
			course_select1.InsertString(nnn, StringToLPCWSTR(course[i1].course_name));

			m_course.InsertItem(nnn, StringToLPCWSTR(course[i1].course_name));
			m_course.SetItemText(nnn, 1, StringToLPCWSTR(double2string(course[i1].course_credit)));
			m_course.SetItemText(nnn, 2, StringToLPCWSTR(double2string(course[i1].course_hours)));
			m_course.SetItemText(nnn, 3, StringToLPCWSTR(course[i1].course_type));
			nnn++;
		}
	}
}


void ClassSystemDLG::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString cstr;
	int index_login1 = course_delete1.GetCurSel();
	course_delete1.GetLBText(index_login1, cstr);


	m_course.DeleteAllItems();
	course_select1.ResetContent();
	course_delete1.ResetContent();


	//CString cstr;
	//GetDlgItem(IDC_COMBO2)->GetWindowText(cstr);
	size_t sccs = student[studentn1].student_course.size();
	for (size_t i = 0; i < sccs; i++)
	{
		if (CSTS(cstr) == student[studentn1].student_course[i].course_name)
		{
			student[studentn1].student_course.erase(student[studentn1].student_course.begin() + i);
			break;
		}
	}


	size_t n;
	size_t n1;
	n1 = course.size();
	n = student[studentn1].student_course.size();
	for (size_t i = 0; i < n; i++)
	{
		course_delete1.InsertString(i, StringToLPCWSTR(student[studentn1].student_course[i].course_name));
	}
	int nnn = 0;
	for (size_t i1 = 0; i1 < n1; i1++)
	{
		int jjj = 1;

		for (size_t i2 = 0; i2 < n; i2++)
		{
			if (course[i1].course_name == student[studentn1].student_course[i2].course_name)
			{
				jjj = 0;
			}
		}
		if (jjj == 1)
		{
			course_select1.InsertString(nnn, StringToLPCWSTR(course[i1].course_name));

			m_course.InsertItem(nnn, StringToLPCWSTR(course[i1].course_name));
			m_course.SetItemText(nnn, 1, StringToLPCWSTR(double2string(course[i1].course_credit)));
			m_course.SetItemText(nnn, 2, StringToLPCWSTR(double2string(course[i1].course_hours)));
			m_course.SetItemText(nnn, 3, StringToLPCWSTR(course[i1].course_type));
			nnn++;
		}
	}
}
