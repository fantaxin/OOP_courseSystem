// ScoreFindDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "ScoreFindDLG.h"
#include "afxdialogex.h"

#include "Man.h"
int num1;
int num2;
int num3;
// ScoreFindDLG 对话框

IMPLEMENT_DYNAMIC(ScoreFindDLG, CDialogEx)

ScoreFindDLG::ScoreFindDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCORE_FIND, pParent)
	, Find_Student_ID(_T(" "))
	, Find_Student_Name(_T(" "))
	, Find_Score(_T(" "))
	, Find_Score1(_T(" "))
	, Find_Score2(_T(" "))
	//, Find_Score3(_T(""))
{

}

ScoreFindDLG::~ScoreFindDLG()
{
}

void ScoreFindDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT5, Find_Student_ID);
	DDX_Control(pDX, IDC_COMBO3, Find_Course_Name);
	DDX_Text(pDX, IDC_EDIT6, Find_Student_Name);
	DDX_Text(pDX, IDC_EDIT3, Find_Score);
	DDX_Text(pDX, IDC_EDIT7, Find_Score1);
	DDX_Text(pDX, IDC_EDIT8, Find_Score2);
	//DDX_Text(pDX, IDC_EDIT2, Find_Score3);
	DDX_Control(pDX, IDC_COMBO1, Find_Course_Name1);
	DDX_Control(pDX, IDC_LIST1, score_find_list);
}


BEGIN_MESSAGE_MAP(ScoreFindDLG, CDialogEx)
	ON_EN_KILLFOCUS(IDC_EDIT5, &ScoreFindDLG::OnEnKillfocusEdit5)
	ON_EN_KILLFOCUS(IDC_EDIT7, &ScoreFindDLG::OnEnKillfocusEdit7)
	ON_BN_CLICKED(IDC_BUTTON1, &ScoreFindDLG::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO3, &ScoreFindDLG::OnCbnSelchangeCombo3)
	ON_CBN_KILLFOCUS(IDC_COMBO3, &ScoreFindDLG::OnCbnKillfocusCombo3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &ScoreFindDLG::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// ScoreFindDLG 消息处理程序

int com_num;
void ScoreFindDLG::OnEnKillfocusEdit5()
{
	// TODO: 在此添加控件通知处理程序代码

	Find_Course_Name.ResetContent();
	UpdateData(TRUE);
	//Find_Student_ID.Delete(0, 1);
	trim(Find_Student_ID);
	int judge = 0;
	size_t i, i2;
	i2 = student.size();
	for (i = 0; i < i2; i++)
	{

		if (CSTS(Find_Student_ID) == student[i].student_id)
		{
			num1 = i;
			judge = 1;
			size_t n, n2;
			n2 = student[i].student_course.size();
			for (n = 0; n < n2; n++)
			{
				Find_Course_Name.InsertString(n, StringToLPCWSTR(student[i].student_course[n].course_name));
				com_num = n;
			}
			Find_Student_Name = StringToLPCWSTR(student[i].student_name);
			UpdateData(FALSE);
		}
	}

}


void ScoreFindDLG::OnEnKillfocusEdit7()
{
	// TODO: 在此添加控件通知处理程序代码
}


void ScoreFindDLG::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//Find_Score1.Delete(0, 1);
	//Find_Score2.Delete(0, 1);
	trim(Find_Score1);
	trim(Find_Score2);

	score_find_list.DeleteAllItems();


	double dd, score1, score2;
	string str1, str2;

	str1 = CSTS(Find_Score1);
	str2 = CSTS(Find_Score2);

	stringstream s1, s2;
	s1 << str1;
	s1 >> score1;
	s2 << str2;
	s2 >> score2;


	string strid = course[num3].course_id;

	string str;
	CString cstr;
	size_t ii = student.size();
	size_t t = 0;
	for (size_t i = 0; i < ii; i++)
	{
		size_t nn = student[i].student_course.size();
		for (size_t n = 0; n < nn; n++)
		{
			if (strid == student[i].student_course[n].course_id)
			{
				double sc = student[i].student_course[n].course_score;
				if (sc >= score1 && sc <= score2)
				{
					//str = student[i].student_name + ": " + to_string(sc);
					//cstr = cstr + CA2T(str.c_str());
					//cstr = cstr + '\t';

					score_find_list.InsertItem(t, StringToLPCWSTR(student[i].student_name));
					score_find_list.SetItemText(t, 1, StringToLPCWSTR(to_string(sc)));
					t++;
				}
			}
		}

		//Find_Score3 = cstr;
		//string sstr = " ";
		//Find_Score1 = StringToLPCWSTR(sstr);
		//Find_Score2 = StringToLPCWSTR(sstr);

		UpdateData(FALSE);

	}
}


BOOL ScoreFindDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	//string sstr = " ";
	//Find_Student_ID = StringToLPCWSTR(sstr);
	//Find_Student_Name = StringToLPCWSTR(sstr);
	//Find_Score = StringToLPCWSTR(sstr);
	//Find_Score1 = StringToLPCWSTR(sstr);
	//Find_Score2 = StringToLPCWSTR(sstr);
	//Find_Score3 = StringToLPCWSTR(sstr);
	UpdateData(FALSE);

	DWORD dwStyle = score_find_list.GetExtendedStyle();
	score_find_list.SetExtendedStyle(dwStyle | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	score_find_list.InsertColumn(0, L"学生姓名", LVCFMT_LEFT, 200);
	score_find_list.InsertColumn(1, L"成绩", LVCFMT_LEFT, 100);
	size_t n, n2;
	n2 = course.size();
	for (n = 0; n < n2; n++)
	{
		Find_Course_Name1.InsertString(n, StringToLPCWSTR(course[n].course_name));
	}
	UpdateData(FALSE);


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ScoreFindDLG::OnCbnSelchangeCombo3()
{
	// TODO: 在此添加控件通知处理程序代码

	num2 = Find_Course_Name.GetCurSel();
	
	string str;
	double score = student[num1].student_course[num2].course_score;
	stringstream ss;
	ss << score;
	str = ss.str();
	Find_Score = str.c_str();
	
	string sstr = " " + student[num1].student_id;
	Find_Student_ID = StringToLPCWSTR(sstr);

	UpdateData(FALSE);
}


void ScoreFindDLG::OnCbnKillfocusCombo3()
{
	// TODO: 在此添加控件通知处理程序代码

}


void ScoreFindDLG::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
	num3 = Find_Course_Name1.GetCurSel();

}
