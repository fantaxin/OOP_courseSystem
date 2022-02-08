// ClassSelectDLG.cpp: 实现文件
//这个对话框弃用了

#include "pch.h"
#include "MFCApplication4.h"
#include "ClassSelectDLG.h"
#include "afxdialogex.h"

#include<iostream>
#include<string>
#include<fstream>
using namespace std;

// ClassSelectDLG 对话框

IMPLEMENT_DYNAMIC(ClassSelectDLG, CDialogEx)

ClassSelectDLG::ClassSelectDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CLSS_SELECT, pParent)
	, m_SearchType(_T(" "))
	//, m_SearchBox(_T(""))
	, m_SearchBox(_T(" "))
{

}

ClassSelectDLG::~ClassSelectDLG()
{
}

void ClassSelectDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO1, m_SearchType);
	//DDX_Text(pDX, IDC_EDIT1, m_SearchBox);
	DDX_Control(pDX, IDC_LIST2, m_StudentClass);
	DDX_LBString(pDX, IDC_LIST1, m_SearchBox);
}


BEGIN_MESSAGE_MAP(ClassSelectDLG, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ClassSelectDLG::OnBnClickedButton2)
END_MESSAGE_MAP()


// ClassSelectDLG 消息处理程序


BOOL ClassSelectDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(L"按课程名查询");
	((CComboBox*)GetDlgItem(IDC_COMBO1))->AddString(L"按老师查询");
	((CComboBox*)GetDlgItem(IDC_COMBO1))->SetCurSel(0);



	DWORD dwStyle = m_StudentClass.GetExtendedStyle();
	m_StudentClass.SetExtendedStyle(dwStyle | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
	m_StudentClass.InsertColumn(0, L"状态", LVCFMT_LEFT, 80);
	m_StudentClass.InsertColumn(1, L"课程编号", LVCFMT_LEFT, 100);
	m_StudentClass.InsertColumn(2, L"课程名称", LVCFMT_LEFT, 150);
	m_StudentClass.InsertColumn(3, L"学分", LVCFMT_LEFT, 50);
	m_StudentClass.InsertColumn(4, L"学时", LVCFMT_LEFT, 50);
	m_StudentClass.InsertColumn(5, L"课程类别", LVCFMT_LEFT, 70);

	//对对话框的格式进行编写 将学课信息以列表形式呈现

	//编辑对话框
	ifstream infile("data\\module.txt");

	if (infile) {
		int i = 0;
		string temp;
		string Classnum, Classname, Classtype;
		double credit, time;
		CString cstr;
		while (!infile.eof())
		{
			infile >> Classnum;
			if ('#' == *Classnum.begin()) {
				getline(infile, temp);

			}
			else {
				infile >> Classname >> credit >> time >> Classtype;
				m_StudentClass.InsertItem(i, L"选择");
				cstr.Format(L"%s", CStringW(Classnum.c_str()));
				m_StudentClass.SetItemText(i, 1, cstr);
				cstr.Format(L"%s", CStringW(Classname.c_str()));
				m_StudentClass.SetItemText(i, 2, cstr);
				cstr.Format(L"%.11f", credit);
				m_StudentClass.SetItemText(i, 3, cstr);
				cstr.Format(L"%.11f", time);
				m_StudentClass.SetItemText(i, 4, cstr);
				cstr.Format(L"%s", CStringW(Classtype.c_str()));
				m_StudentClass.SetItemText(i, 5, cstr);

				i++;
			}
		}
	}

	//m_StudentClass.ShowCaret();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void ClassSelectDLG::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	m_SearchBox;
	m_SearchType;
	if (m_SearchType == "按课程名查询") {





	}
	else if (m_SearchType == "按老师查询") {



	}



}
