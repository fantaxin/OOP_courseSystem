// ScoreChangeDLG.cpp: 实现文件
//

#include "pch.h"
#include "MFCApplication4.h"
#include "ScoreChangeDLG.h"
#include "afxdialogex.h"
#include"Man.h"

int course_num_;
int judge = -1;
// ScoreChangeDLG 对话框

IMPLEMENT_DYNAMIC(ScoreChangeDLG, CDialogEx)

ScoreChangeDLG::ScoreChangeDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCORE_CANGE, pParent)
{

}

ScoreChangeDLG::~ScoreChangeDLG()
{
}

void ScoreChangeDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_TeacherScore);
	DDX_Control(pDX, IDC_COMBO1, Change_Course_Name);
}


BEGIN_MESSAGE_MAP(ScoreChangeDLG, CDialogEx)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, &ScoreChangeDLG::OnNMClickList1)
	ON_BN_CLICKED(IDOK, &ScoreChangeDLG::OnBnClickedOk_2)
	ON_NOTIFY(LVN_COLUMNCLICK, IDC_LIST2, &ScoreChangeDLG::OnLvnColumnclickList1)
	ON_BN_CLICKED(IDC_BUTTON3, &ScoreChangeDLG::OnBnClickedButton3)
	ON_CBN_SELCHANGE(IDC_COMBO1, &ScoreChangeDLG::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()

BOOL ScoreChangeDLG::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化



	size_t n, n2;
	n2 = course.size();
	for (n = 0; n < n2; n++)
	{
		Change_Course_Name.InsertString(n, StringToLPCWSTR(course[n].course_name));
	}
	UpdateData(FALSE);





	//ScoreChangeDLG::ListAgain();





	haveeditcreate = false;//初始化标志位，表示还没有创建编辑框
	haveccomboboxcreate = false;//初始化标志位，表示还没有创建下拉列表框

	RECT  m_rect;
	m_TeacherScore.GetClientRect(&m_rect); //获取list的客户区,方便调节每一列的宽度  
	m_TeacherScore.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT); //设置list风格，LVS_EX_GRIDLINES为网格线（只适用与report风格的listctrl）
	//LVS_EX_FULLROWSELECT为选中某行使整行高亮（只适用与report风格的listctrl）
	m_TeacherScore.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 110);
	m_TeacherScore.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 80);
	m_TeacherScore.InsertColumn(2, _T("课程名称"), LVCFMT_LEFT, 200);
	m_TeacherScore.InsertColumn(3, _T("成绩"), LVCFMT_RIGHT, 60);
	m_TeacherScore.InsertColumn(4, _T("状态"), LVCFMT_CENTER, 80);
	m_TeacherScore.InsertColumn(5, _T("备注"), LVCFMT_CENTER, 80);

	//ifstream infile("data\\score.txt");

	//

	//if (infile)
	//{
	//	string tmpstr, strnum, strname, strtype;
	//	double score;
	//	CString tmpcstr;
	//	int id = 0;

	//	while (!infile.eof() )
	//	{
	//		infile >> strnum;
	//		if ('#' == (*strnum.begin()))
	//		{
	//			getline(infile, tmpstr);
	//		}
	//		else
	//		{
	//			infile >> strname >> strtype >> score;

	//			tmpcstr.Format(L"%s", CStringW(strnum.c_str()));
	//			m_TeacherScore.InsertItem(id, tmpcstr);
	//			tmpcstr.Format(L"%s", CStringW(strname.c_str()));
	//			m_TeacherScore.SetItemText(id, 1, tmpcstr);
	//			tmpcstr.Format(L"%s", CStringW(strtype.c_str()));
	//			m_TeacherScore.SetItemText(id, 2, tmpcstr);
	//			tmpcstr.Format(L"%.1lf", score);
	//			m_TeacherScore.SetItemText(id, 3, tmpcstr);
	//			if (score >= 60)
	//			{
	//				m_TeacherScore.SetItemText(id, 4, L"通过");
	//			}
	//			else
	//				m_TeacherScore.SetItemText(id, 4, L"不通过");

	//			m_TeacherScore.SetItemData(id, id);

	//			id++;


	//		}
	//	}
	//}

	//infile.close();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
// ScoreChangeDLG 消息处理程序

void ScoreChangeDLG::ListAgain()
{
	haveeditcreate = false;//初始化标志位，表示还没有创建编辑框
	haveccomboboxcreate = false;//初始化标志位，表示还没有创建下拉列表框

	//RECT  m_rect;
	//m_TeacherScore.GetClientRect(&m_rect); //获取list的客户区,方便调节每一列的宽度  
	//m_TeacherScore.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT); //设置list风格，LVS_EX_GRIDLINES为网格线（只适用与report风格的listctrl）
	////LVS_EX_FULLROWSELECT为选中某行使整行高亮（只适用与report风格的listctrl）
	//m_TeacherScore.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 110);
	//m_TeacherScore.InsertColumn(1, _T("姓名"), LVCFMT_LEFT, 80);
	//m_TeacherScore.InsertColumn(2, _T("课程名称"), LVCFMT_LEFT, 200);
	//m_TeacherScore.InsertColumn(3, _T("成绩"), LVCFMT_RIGHT, 60);
	//m_TeacherScore.InsertColumn(4, _T("状态"), LVCFMT_CENTER, 80);
	//m_TeacherScore.InsertColumn(5, _T("备注"), LVCFMT_CENTER, 80);

	ifstream infile("data\\score.txt");



	if (infile)
	{
		string tmpstr, strnum, strname, strtype;
		double score;
		CString tmpcstr;
		int id = 0;
		int n = -1;
		while (getline(infile, tmpstr))
		{
			n++;
			if (n == 0)
			{
				continue;
			}
			else
			{
				infile >> strnum >> strname >> strtype >> score;

				if (judge == 0 && strtype != course[course_num_].course_name)
				{
					continue;
				}
				//m_TeacherScore.DeleteAllItems();
				tmpcstr.Format(L"%s", CStringW(strnum.c_str()));
				m_TeacherScore.InsertItem(id, tmpcstr);
				tmpcstr.Format(L"%s", CStringW(strname.c_str()));
				m_TeacherScore.SetItemText(id, 1, tmpcstr);
				tmpcstr.Format(L"%s", CStringW(strtype.c_str()));
				m_TeacherScore.SetItemText(id, 2, tmpcstr);
				tmpcstr.Format(L"%.1lf", score);
				m_TeacherScore.SetItemText(id, 3, tmpcstr);
				if (score >= 60)
				{
					m_TeacherScore.SetItemText(id, 4, L"通过");
				}
				else
					m_TeacherScore.SetItemText(id, 4, L"不通过");

				m_TeacherScore.SetItemData(id, id);

				id++;


			}
		}
	}

	infile.close();
}

void ScoreChangeDLG::OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	NM_LISTVIEW  *pEditCtrl = (NM_LISTVIEW *)pNMHDR;



	if (pEditCtrl->iItem == -1)//点击到非工作区
	{
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_TeacherScore, &m_Edit, e_Item, e_SubItem);//销毁单元格编辑框对象
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)//如果之前创建了下拉列表框就销毁掉
		{
			distroyCcombobox(&m_TeacherScore, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
	}
	else if (pEditCtrl->iSubItem == 3 || pEditCtrl->iSubItem == 5)//
	{
		if (haveccomboboxcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyCcombobox(&m_TeacherScore, &m_comBox, e_Item, e_SubItem);
			haveccomboboxcreate = false;
		}
		if (haveeditcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyEdit(&m_TeacherScore, &m_Edit, e_Item, e_SubItem);
				haveeditcreate = false;
				createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
			}
			else//点中的单元格是之前创建好的
			{
				m_Edit.SetFocus();//设置为焦点 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			createEdit(pEditCtrl, &m_Edit, e_Item, e_SubItem, haveeditcreate);//创建编辑框
		}
	}
	else if (pEditCtrl->iSubItem == 4)//如果是状态选项，在单元格处生成下拉列表项
	{
		if (haveeditcreate == true)//如果之前创建了编辑框就销毁掉
		{
			distroyEdit(&m_TeacherScore, &m_Edit, e_Item, e_SubItem);
			haveeditcreate = false;
		}
		if (haveccomboboxcreate == true)
		{
			if (!(e_Item == pEditCtrl->iItem && e_SubItem == pEditCtrl->iSubItem))//如果点中的单元格不是之前创建好的
			{
				distroyCcombobox(&m_TeacherScore, &m_comBox, e_Item, e_SubItem);
				haveccomboboxcreate = false;
				createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
				m_comBox.AddString(L"通过");
				m_comBox.AddString(L"不通过");
				m_comBox.ShowDropDown();//自动下拉
			}
			else//点中的单元格是之前创建好的
			{
				m_comBox.SetFocus();//设置为焦点 
			}
		}
		else
		{
			e_Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			e_SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
			createCcombobox(pEditCtrl, &m_comBox, e_Item, e_SubItem, haveccomboboxcreate);//创建编辑框
			m_comBox.AddString(L"通过");
			m_comBox.AddString(L"不通过");
			m_comBox.ShowDropDown();//自动下拉
		}
	}

	*pResult = 0;
}


//自定义函数

//创建单元格编辑框函数 
//pEditCtrl为列表对象指针，createdit为编辑框指针对象，      
//Item为创建单元格在列表中的行，SubItem则为列，havecreat为对象创建标准

void ScoreChangeDLG::createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat)
{
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	createdit->Create(ES_AUTOHSCROLL | WS_CHILD | ES_LEFT | ES_WANTRETURN,
		CRect(0, 0, 0, 0), this, IDC_EDIT_CREATEID);//创建编辑框对象,IDC_EDIT_CREATEID为控件ID号1002，在resource.h中定义
	havecreat = true;
	createdit->SetFont(this->GetFont(), FALSE);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createdit->SetParent(&m_TeacherScore);//将list control设置为父窗口,生成的Edit才能正确定位,这个也很重要
	CRect  EditRect;
	m_TeacherScore.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_TeacherScore.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_TeacherScore.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createdit->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createdit->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createdit->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
	createdit->SetFocus();//设置为焦点 
	createdit->SetSel(-1);//设置光标在文本框文字的最后
}

void ScoreChangeDLG::distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem)
{
	CString meditdata;
	distroyedit->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//获得相应单元格字符
	distroyedit->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}

//创建单元格下拉列表框函数
//pEditCtrl为列表对象指针，createccombobox为下拉列表框指针对象，
//Item为创建单元格在列表中的行，SubItem则为列，havecreat为对象创建标准

void ScoreChangeDLG::createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat)
{
	Item = pEditCtrl->iItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	SubItem = pEditCtrl->iSubItem;//将点中的单元格的行赋值给“刚编辑过的行”以便后期处理
	havecreat = true;
	createccomboboxobj->Create(WS_CHILD | WS_VISIBLE | CBS_DROPDOWN | CBS_OEMCONVERT, CRect(0, 0, 0, 0), this, IDC_COMBOX_CREATEID);
	createccomboboxobj->SetFont(this->GetFont(), FALSE);//设置字体,不设置这里的话上面的字会很突兀的感觉
	createccomboboxobj->SetParent(&m_TeacherScore);//将list control设置为父窗口,生成的Ccombobox才能正确定位,这个也很重要
	CRect  EditRect;
	m_TeacherScore.GetSubItemRect(e_Item, e_SubItem, LVIR_LABEL, EditRect);//获取单元格的空间位置信息
	EditRect.SetRect(EditRect.left + 1, EditRect.top + 1, EditRect.left + m_TeacherScore.GetColumnWidth(e_SubItem) - 1, EditRect.bottom - 1);//+1和-1可以让编辑框不至于挡住列表框中的网格线
	CString strItem = m_TeacherScore.GetItemText(e_Item, e_SubItem);//获得相应单元格字符
	createccomboboxobj->SetWindowText(strItem);//将单元格字符显示在编辑框上
	createccomboboxobj->MoveWindow(&EditRect);//将编辑框位置放在相应单元格上
	createccomboboxobj->ShowWindow(SW_SHOW);//显示编辑框在单元格上面
}

void ScoreChangeDLG::distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem)
{
	CString meditdata;
	distroyccomboboxobj->GetWindowTextW(meditdata);
	list->SetItemText(Item, SubItem, meditdata);//更新相应单元格字符
	distroyccomboboxobj->DestroyWindow();//销毁对象，有创建就要有销毁，不然会报错
}







void ScoreChangeDLG::OnBnClickedOk_2()
{
	// TODO: 在此添加控件通知处理程序代码

	CDialogEx::OnOK();
}


void ScoreChangeDLG::OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	//设置排序方式
	if (pNMListView->iSubItem == m_TeacherScore.m_nSortedCol)
		m_TeacherScore.m_fAsc = !m_TeacherScore.m_fAsc;
	else
	{
		m_TeacherScore.m_fAsc = TRUE;
		m_TeacherScore.m_nSortedCol = pNMListView->iSubItem;
	}
	//调用排序函数
	m_TeacherScore.SortItems(FileListCompareFunction, (DWORD)&m_TeacherScore);

	*pResult = 0;
}
int CALLBACK ScoreChangeDLG::FileListCompareFunction(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort)
{
	CSortList* pV = (CSortList*)lParamSort;
	CListCtrl *pListCtrl = (CListCtrl*)lParamSort;
	int rValue = 0;

	int nItem1, nItem2;
	LVFINDINFO FindInfo;
	FindInfo.flags = LVFI_PARAM;
	FindInfo.lParam = lParam1;
	nItem1 = pListCtrl->FindItem(&FindInfo, -1);
	FindInfo.lParam = lParam2;
	nItem2 = pListCtrl->FindItem(&FindInfo, -1);
	if ((nItem1 == -1) || (nItem2 == -1))
	{
		return 0;
	}

	CString szComp1, szComp2;
	szComp1 = pListCtrl->GetItemText(nItem1, pV->m_nSortedCol);
	szComp2 = pListCtrl->GetItemText(nItem2, pV->m_nSortedCol);

	double num1, num2;
	num1 = _ttoi(szComp1.GetBuffer());
	num2 = _ttoi(szComp2.GetBuffer());
	szComp1.ReleaseBuffer();
	szComp2.ReleaseBuffer();

	int iCompRes;
	switch (pV->m_nSortedCol)
	{
	case(0):
	{
	

		iCompRes = 0;
	}
	break;
	case(1):
	{
		//以第2列为根据排序
		//字符串CString需要转成char *, 然后从char *转成string,才能正确的比较出中文字符的顺序
		CStringA szAtemp1, szAtemp2;
		szAtemp1 = szComp1;
		szAtemp2 = szComp2;
		char * szx1 = szAtemp1.GetBuffer();
		char * szx2 = szAtemp2.GetBuffer();
		string str1 = szx1;					//char*转换为string
		string str2 = szx2;

		iCompRes = str1.compare(str2);
	}
	break;
	case(2):
	{
		CStringA szAtemp1, szAtemp2;
		szAtemp1 = szComp1;
		szAtemp2 = szComp2;
		char * szx1 = szAtemp1.GetBuffer();
		char * szx2 = szAtemp2.GetBuffer();
		string str1 = szx1;					//char*转换为string
		string str2 = szx2;

		iCompRes = str1.compare(str2);
	}
	break;
	case(3):
	{
		if (num1 == num2)
			iCompRes = 0;
		else
			iCompRes = (num1 < num2) ? -1 : 1;
	}
	break;
	case(4):
	{
		iCompRes = 0;
	}
	default:
		ASSERT(0);
		break;
	}
	//根据当前的排序方式进行调整
	/*if (num1 == num2)
		iCompRes = 0;
	else
		iCompRes = (num1 < num2) ? -1 : 1;*/

	if (pV->m_fAsc)
		return iCompRes;
	else
		return iCompRes * -1;
}

void ScoreChangeDLG::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码

	//	if (m_TeacherScore.GetItemCount() <= 0)
	//{
	//	MessageBox(L"当前列表中没有数据");
	//	return;
	//}

	//CString szFilter = L"txt文件(*.txt)|*.txt|xls文件(*.xls)|*.word|word文件(*.word)|*.word|所有文件(*.*)|*.*||";
	//CFileDialog dlg(FALSE, _T("txt"), _T("outfile"), OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT, szFilter, this);

	//if (dlg.DoModal() != IDOK)
	//{
	//	return;
	//}

	//CString strFileName;
	//strFileName = dlg.GetPathName();
	//DWORD dwRe = GetFileAttributes(strFileName);
	//if (dwRe != (DWORD)-1)
	//{
	//	DeleteFile(strFileName);
	//}

	//ofstream outfile(strFileName);

	int nRow = m_TeacherScore.GetItemCount();
	int nCol = m_TeacherScore.GetHeaderCtrl()->GetItemCount();

	TCHAR     lpBuffer[256];
	LPCTSTR   lpszmyString;
	HDITEM   hdi;
	hdi.mask = HDI_TEXT;
	hdi.pszText = lpBuffer;
	hdi.cchTextMax = 256;

	//outfile << "#";
	//for (int i = 0; i < nCol; i++)
	//{
	//	m_TeacherScore.GetHeaderCtrl()->GetItem(i, &hdi);
	//	outfile << CSTS(hdi.pszText).c_str() << "\t";
	//}
	//outfile << endl;

	string student_id1;
	string course_name1;
	string course_score;
	string pass1;
	size_t student_num1;
	size_t course_num1;
	double csd;
	for (size_t i = 0; i < nRow; i++)
	{
		for (size_t j = 0; j < nCol; j++)
		{
			//string student_id1;
			//string course_name1;
			//string course_score;
			//string pass1;
			//size_t student_num1;
			//size_t course_num1;
			//double csd;
			switch (j)
			{
			case 0:
				student_id1 = CSTS(m_TeacherScore.GetItemText(i, j)).c_str();
				for (size_t i=0; i < student.size(); i++)
				{
					if (student[i].student_id == student_id1)
					{
						student_num1 = i;
						break;
					}
				}
			    break;
			case 1:
				//course_name1 = CSTS(m_TeacherScore.GetItemText(i, j)).c_str();
				break;
			case 2:
				course_name1 = CSTS(m_TeacherScore.GetItemText(i, j)).c_str();
				for (size_t i=0; i < student[student_num1].student_course.size(); i++)
				{
					if (student[student_num1].student_course[i].course_name == course_name1)
					{
						course_num1 = i;
						break;
					}
				}
				break;
			case 3:
				course_score = CSTS(m_TeacherScore.GetItemText(i, j)).c_str();
				csd = string2double(course_score);
				student[student_num1].student_course[course_num1].course_score = csd;
				break;
			case 4:
				pass1 = CSTS(m_TeacherScore.GetItemText(i, j)).c_str();
				bool passb;
				if (pass1 == "通过")
				{
					passb = true;
				}
				else passb = false;
				student[student_num1].student_course[course_num1].course_pass = passb;
				break;
			default:
				break;
			}
			//outfile << CSTS(m_TeacherScore.GetItemText(i, j)).c_str() << "\t";
		}
		//outfile << endl;
	}

	/*outfile << endl << "#END" << endl;


	outfile.close();

	if (IDOK == MessageBox(L"信息保存完成，打开查看？", L"结果保存", IDOK))
	{
		string file = "notepad ";
		file += CSTS(strFileName).c_str();
		WinExec(file.c_str(), SW_SHOW);
	}*/
}


void ScoreChangeDLG::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码



	m_TeacherScore.DeleteAllItems();

	course_num_ = Change_Course_Name.GetCurSel();
	judge = 0;
	ScoreChangeDLG::ListAgain();

}
