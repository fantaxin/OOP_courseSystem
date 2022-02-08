// ScoreAndlDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "ScoreAndlDLG.h"
#include "afxdialogex.h"
#include"Man.h"
int num(0);
// ScoreAndlDLG 对话框

IMPLEMENT_DYNAMIC(ScoreAndlDLG, CDialogEx)

ScoreAndlDLG::ScoreAndlDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCORE_ANDL, pParent)
	, All_Student_Num(_T(" "))
	, Andl_tgl(_T(" "))
	, Andl_tgrs(_T(" "))
	, Andl_pjcj(_T(" "))
	, Andl_fc(_T(" "))
{

}

ScoreAndlDLG::~ScoreAndlDLG()
{
}

void ScoreAndlDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, Andl_Course_Name);
	//DDX_Control(pDX, IDC_COMBO3, Andl_Class_Name);
	DDX_Text(pDX, IDC_EDIT4, All_Student_Num);
	DDX_Text(pDX, IDC_EDIT9, Andl_tgl);
	DDX_Text(pDX, IDC_EDIT7, Andl_tgrs);
	DDX_Text(pDX, IDC_EDIT8, Andl_pjcj);
	DDX_Text(pDX, IDC_EDIT10, Andl_fc);
}


BEGIN_MESSAGE_MAP(ScoreAndlDLG, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO2, &ScoreAndlDLG::OnCbnSelchangeCombo2)
	//ON_CBN_SELCHANGE(IDC_COMBO3, &ScoreAndlDLG::OnCbnSelchangeCombo3)
END_MESSAGE_MAP()


// ScoreAndlDLG 消息处理程序


void ScoreAndlDLG::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	int a1(0), a3(0);
	double a2(0), a4(0), a5(0);
	vector<double> d_score;
	int index = Andl_Course_Name.GetCurSel();
	size_t s = student.size();
	for (size_t n = 0; n < s; n++)
	{
		size_t x = student[n].student_course.size();
		for (size_t y = 0; y < x; y++)
		{
			if (student[n].student_course[y].course_name == course[index].course_name)
			{
				a1++;
				if (student[n].student_course[y].course_score >= 60)
				{
					a3++;
				}
				a4 += student[n].student_course[y].course_score;
				d_score.push_back(student[n].student_course[y].course_score);
			}
		}
	}

	double aa, aaa;
	aaa = a3;
	aa = a1;
	a2 = aaa / aa;
	a4 = a4 / a1;
	size_t ss = d_score.size();
	for (size_t t = 0; t < ss; t++)
	{
		a5 = a5 + (d_score[t]-a4)*(d_score[t]-a4);
	}
	a5 = a5 / a1;

	trim(All_Student_Num);
	trim(Andl_tgl);
	trim(Andl_tgrs);
	trim(Andl_pjcj);
	trim(Andl_fc);

	All_Student_Num = int2cstring(a1);
	Andl_tgl= double2cstring(a2);
	Andl_tgrs = int2cstring(a3);
	Andl_pjcj = double2cstring(a4);
	Andl_fc = double2cstring(a5);

	UpdateData(FALSE);
}


//void ScoreAndlDLG::OnCbnSelchangeCombo3()
//{
//	// TODO: 在此添加控件通知处理程序代码
//	int a1(0), a3(0);
//	double a2(0), a4(0), a5(0);
//
//
//}


BOOL ScoreAndlDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//string sstr = " ";
	//All_Student_Num = StringToLPCWSTR(sstr);
	//Andl_tgl = StringToLPCWSTR(sstr);
	//Andl_tgrs = StringToLPCWSTR(sstr);
	//Andl_pjcj = StringToLPCWSTR(sstr);
	//Andl_fc = StringToLPCWSTR(sstr);
	UpdateData(FALSE);

	size_t n, n2;
	n2 = course.size();
	for (n = 0; n < n2; n++)
	{
		Andl_Course_Name.InsertString(n, StringToLPCWSTR(course[n].course_name));
	}
	UpdateData(FALSE);

	vector<string> class_num;
	//class_num.push_back("#END");
	size_t n3, n4, n5, n6, n7;
	int judge(1);
	//n6 = class_num.size();
	n4 = student.size();
	for (n5 = 0; n5 < n4; n5++)
	{
		n6 = class_num.size();
		if (n6 == 0)
		{
			class_num.push_back(student[n5].student_class);
			n6 = 1;
		}
		for (n7 = 0; n7 < n6; n7++)
		{
			if (class_num[n7] == student[n5].student_class)
			{
				judge = 0;
			}
		}
		if (judge == 1)
		{
			class_num.push_back(student[n5].student_class);
			n6++;
		}
	}
	/*n6 = class_num.size();
	for (n3 = 0; n3 < n6; n3++)
	{
		Andl_Class_Name.InsertString(n3, StringToLPCWSTR(class_num[n3]));
	}*/
	UpdateData(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
