#pragma once

#include"SortList.h"
// ScoreChangeDLG 对话框

class ScoreChangeDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ScoreChangeDLG)

public:
	ScoreChangeDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ScoreChangeDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE_CANGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CSortList m_TeacherScore;
	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	virtual BOOL OnInitDialog();

	static int CALLBACK FileListCompareFunction(LPARAM lParam1, LPARAM lParam2, LPARAM lParamSort);//该函数必须是静态或者全局函数
public:
	int e_Item;    //刚编辑的行  
	int e_SubItem; //刚编辑的列  

	CEdit m_Edit;  //生成单元编辑框对象
	bool haveeditcreate;//标志编辑框已经被创建
	void createEdit(NM_LISTVIEW  *pEditCtrl, CEdit *createdit, int &Item, int &SubItem, bool &havecreat);//创建单元格编辑框函数
	void distroyEdit(CListCtrl *list, CEdit* distroyedit, int &Item, int &SubItem);//销毁单元格编辑框对象

	CComboBox m_comBox;//生产单元格下拉列表对象
	bool haveccomboboxcreate;//标志下拉列表框已经被创建
	void createCcombobox(NM_LISTVIEW  *pEditCtrl, CComboBox *createccomboboxobj, int &Item, int &SubItem, bool &havecreat);//创建单元格下拉列表框函数
	void distroyCcombobox(CListCtrl *list, CComboBox* distroyccomboboxobj, int &Item, int &SubItem);//销毁单元格下拉列表框

	void ListAgain();

	afx_msg void OnBnClickedOk_2();
	afx_msg void OnLvnColumnclickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton3();
	CComboBox Change_Course_Name;
	afx_msg void OnCbnSelchangeCombo1();
};
