// Course_ManageDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "Course_ManageDLG.h"
#include "afxdialogex.h"
#include"Man.h"

int judge3=0;
int course_n;
int comb_n;
int course_teacher_n;
// Course_ManageDLG 对话框

IMPLEMENT_DYNAMIC(Course_ManageDLG, CDialogEx)

Course_ManageDLG::Course_ManageDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG8, pParent)
	, m_course_id(_T(" "))
	, m_course_name(_T(" "))
	, m_credit(_T(" "))
	, m_hours(_T(" "))
{

}

Course_ManageDLG::~Course_ManageDLG()
{
}

void Course_ManageDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_course_id);
	DDX_Text(pDX, IDC_EDIT2, m_course_name);
	DDX_Text(pDX, IDC_EDIT3, m_credit);
	DDX_Text(pDX, IDC_EDIT4, m_hours);
	DDX_Control(pDX, IDC_COMBO1, m_type);
	DDX_Control(pDX, IDC_COMBO2, course_teacher);
}


BEGIN_MESSAGE_MAP(Course_ManageDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Course_ManageDLG::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Course_ManageDLG::OnBnClickedButton4)
	ON_EN_KILLFOCUS(IDC_EDIT1, &Course_ManageDLG::OnEnKillfocusEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &Course_ManageDLG::OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, &Course_ManageDLG::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// Course_ManageDLG 消息处理程序


void Course_ManageDLG::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码


	if (judge3 == 1)
	{
		MessageBox(TEXT("该课程信息已存在！"));
		return;
	}
	UpdateData(TRUE);
	//m_course_id.Delete(0, 1);
	//m_course_name.Delete(0, 1);
	//m_credit.Delete(0, 1);
	//m_hours.Delete(0, 1);
	trim(m_course_id);
	trim(m_course_name);
	trim(m_credit);
	trim(m_hours);

	string str;
	if (comb_n == 0)
	{
		str = "必修";
	}
	else
	{
		str = "选修";
	}

	if (Add_Course(CSTS(m_course_id),CSTS(m_course_name),cstring2double(m_credit),cstring2double(m_hours),str))
	{
		teacher[course_teacher_n].teacher_course.push_back(course[course.size() - 1]);
		MessageBox(TEXT("添加成功！"));
		Write_Teacher();
	}
	else
		MessageBox(TEXT("添加失败！"));

}


void Course_ManageDLG::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (judge3 == 0)
	{
		MessageBox(TEXT("未找到该课程信息！"));
		return;
	}

	course.erase(course.begin() + course_n);
	MessageBox(TEXT("删除成功！"));
	Write_Course();
}


void Course_ManageDLG::OnEnKillfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT2)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT3)->SetWindowTextW(_T(""));
	GetDlgItem(IDC_EDIT4)->SetWindowTextW(_T(""));

	UpdateData(TRUE);
	trim(m_course_id);
	trim(m_course_name);
	trim(m_credit);
	trim(m_hours);
	size_t i, i2;
	i2 = course.size();
	for (i = 0; i < i2; i++)
	{

		if (CSTS(m_course_id) == course[i].course_id)
		{
			judge3 = 1;
			size_t n, n2;
			m_course_name = StringToLPCWSTR(course[i].course_name);
			m_credit = double2cstring(course[i].course_credit);
			m_hours = double2cstring(course[i].course_hours);
			if (course[i].course_type == "必修")
			{
				m_type.SetCurSel(0);
			}
			else
			{
				m_type.SetCurSel(1);
			}

			UpdateData(FALSE);
			course_n = i;
			return;
		}
		judge3 = 0;
	}

}


BOOL Course_ManageDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//string sstr = " ";
	//m_course_id = StringToLPCWSTR(sstr);
	//m_course_name = StringToLPCWSTR(sstr);
	//m_credit = StringToLPCWSTR(sstr);
	//m_hours = StringToLPCWSTR(sstr);
	UpdateData(FALSE);


	size_t n, n2;
	CString cstr1 = _T("必修");
	CString cstr2 = _T("选修");
	m_type.InsertString(0, cstr1);
	m_type.InsertString(1, cstr2);

	for (size_t i = 0; i < teacher.size(); i++)
	{
		course_teacher.InsertString(i, StringToLPCWSTR(teacher[i].teacher_name));
	}

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void Course_ManageDLG::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	comb_n = m_type.GetCurSel();

}


void Course_ManageDLG::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	course_teacher_n = course_teacher.GetCurSel();
}
