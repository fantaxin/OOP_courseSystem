// ScoreAddDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "ScoreAddDLG.h"
#include "afxdialogex.h"
#include "Man.h"
int index_;
int num_;
//int student_num_;
// ScoreAddDLG 对话框

IMPLEMENT_DYNAMIC(ScoreAddDLG, CDialogEx)

ScoreAddDLG::ScoreAddDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCORE_ADD, pParent)
	, Add_Student_ID(_T(" "))
	//, Add_Course_Name(_T(""))
	, Add_Course_Score(_T(" "))
	, Add_Student_Name(_T(" "))
{

}

ScoreAddDLG::~ScoreAddDLG()
{
}

void ScoreAddDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Add_Student_ID);
//	DDX_Text(pDX, IDC_EDIT2, Add_Course_Name);
	DDX_Text(pDX, IDC_EDIT3, Add_Course_Score);
	DDX_Text(pDX, IDC_EDIT4, Add_Student_Name);
	DDX_Control(pDX, IDC_COMBO1, Cbx_Pass);
	DDX_Control(pDX, IDC_COMBO2, Cbx_Course_Name);
}


BEGIN_MESSAGE_MAP(ScoreAddDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ScoreAddDLG::OnBnClickedButton1)
	ON_CBN_SELCHANGE(IDC_COMBO1, &ScoreAddDLG::OnCbnSelchangeCombo1)
	ON_EN_KILLFOCUS(IDC_EDIT1, &ScoreAddDLG::OnEnKillfocusEdit1)
	ON_EN_KILLFOCUS(IDC_EDIT3, &ScoreAddDLG::OnEnKillfocusEdit3)
	ON_CBN_SELCHANGE(IDC_COMBO2, &ScoreAddDLG::OnCbnSelchangeCombo2)
END_MESSAGE_MAP()


// ScoreAddDLG 消息处理程序


BOOL ScoreAddDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	//string sstr = " ";
	//Add_Student_ID = StringToLPCWSTR(sstr);
	////Add_Course_Name = StringToLPCWSTR(sstr);
	//Add_Course_Score = StringToLPCWSTR(sstr);
	//Add_Student_Name = StringToLPCWSTR(sstr);
	UpdateData(FALSE);

	Cbx_Pass.InsertString(0, TEXT("通过"));
	Cbx_Pass.InsertString(1, TEXT("不通过"));


	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ScoreAddDLG::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	//Add_Course_Score.Delete(0, 1);
	trim(Add_Course_Score);
	string str = CSTS(Add_Course_Score);
	double score;
	score = string2double(str);
	student[num_].student_course[index_].course_score = score;
	Write_Student_Course();
	//if (score >= 60)
	//{
	//	Cbx_Pass.SetCurSel(0);
	//}
	//else Cbx_Pass.SetCurSel(1);

}



void ScoreAddDLG::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码
     //index_ = Cbx_Pass.GetCurSel();

}

//当成绩添加对话框中的输入学号编辑框失去输入焦点时
void ScoreAddDLG::OnEnKillfocusEdit1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);
	//Add_Student_ID.Delete(0, 1);
	trim(Add_Student_ID);
	int judge = 0;
	size_t i,i2;
	i2 = student.size();
	for (i = 0; i < i2; i++)
	{
		
		if (CSTS(Add_Student_ID) == student[i].student_id)
		{
			//查找学生的id
			num_ = i;
			judge = 1;
			size_t n, n2;
			n2 = student[i].student_course.size();
			for (n = 0; n < n2; n++)//将该学生所有课程名称添加至下拉框中
			{
				Cbx_Course_Name.InsertString(n, StringToLPCWSTR(student[i].student_course[n].course_name));
			}
			//将该学生的姓名写入编辑框中
			Add_Student_Name = StringToLPCWSTR(student[i].student_name);
			UpdateData(FALSE);
		}
	}
}


void ScoreAddDLG::OnEnKillfocusEdit3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//Add_Course_Score.Delete(0, 1);
	trim(Add_Course_Score);
	string str = CSTS(Add_Course_Score);
	double score;
	score = string2double(str);
	//student[num_].student_course[index_].course_score = score;
	if (score >= 60)
	{
		Cbx_Pass.SetCurSel(0);
	}
	else Cbx_Pass.SetCurSel(1);
}


void ScoreAddDLG::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	index_ = Cbx_Course_Name.GetCurSel();
}
