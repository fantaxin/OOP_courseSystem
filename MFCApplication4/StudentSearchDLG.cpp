// StudentSearchDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "StudentSearchDLG.h"
#include "afxdialogex.h"
#include"Man.h"

// StudentSearchDLG 对话框

IMPLEMENT_DYNAMIC(StudentSearchDLG, CDialogEx)

StudentSearchDLG::StudentSearchDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENT_SEARCH, pParent)
	, StudentSearchCredit(_T(" "))
	//, StudentSearchScore(_T(""))
{

}

StudentSearchDLG::~StudentSearchDLG()
{
}

void StudentSearchDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, StudentSearchCredit);
	//DDX_Text(pDX, IDC_EDIT2, StudentSearchScore);
	DDX_Control(pDX, IDC_LIST1, student_search_list);
}


BEGIN_MESSAGE_MAP(StudentSearchDLG, CDialogEx)
	ON_BN_CLICKED(IDOK, &StudentSearchDLG::OnBnClickedOk)
END_MESSAGE_MAP()


// StudentSearchDLG 消息处理程序


BOOL StudentSearchDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	DWORD dwStyle = student_search_list.GetExtendedStyle();
	student_search_list.SetExtendedStyle(dwStyle | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	student_search_list.InsertColumn(0, L"课程名称", LVCFMT_LEFT, 200);
	student_search_list.InsertColumn(1, L"成绩", LVCFMT_LEFT, 100);
	student_search_list.InsertColumn(2, L"是否通过", LVCFMT_LEFT, 100);

	string a = one_man.account;
	Student s;
	for (int i = 0; i < student.size(); i++)
	{
		if (a == student[i].student_id)
		{
			s = student[i];
		}
	}

	double credit(0);
	string str,str1;
	CString cstr,cstr1;
	for (size_t i = 0; i < s.student_course.size(); i++)
	{
		int sc = s.student_course[i].course_score;
		credit += s.student_course[i].course_credit;
		str = double2string(s.student_course[i].course_score);
		string str2;
		if (s.student_course[i].course_pass)
		{
			str2 = "通过";
		}
		else str2 = "不通过";
		student_search_list.InsertItem(i, StringToLPCWSTR(s.student_course[i].course_name));
		student_search_list.SetItemText(i, 1, StringToLPCWSTR(str));
		student_search_list.SetItemText(i, 2, StringToLPCWSTR(str2));

		/*str = s.student_course[i].course_name +": "+ to_string(sc);
		cstr = cstr+ CA2T(str.c_str());
		cstr = cstr + '\t';*/
	}

	str1 = to_string(credit);
	cstr1 = CA2T(str1.c_str());
	StudentSearchCredit = cstr1;
	//StudentSearchScore = cstr;

	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void StudentSearchDLG::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
