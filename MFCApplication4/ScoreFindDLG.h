#pragma once


// ScoreFindDLG 对话框

class ScoreFindDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ScoreFindDLG)

public:
	ScoreFindDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ScoreFindDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE_FIND };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Find_Student_ID;
	CComboBox Find_Course_Name;
	CString Find_Student_Name;
	CString Find_Score;
	CString Find_Score1;
	CString Find_Score2;
	//CString Find_Score3;
	afx_msg void OnEnKillfocusEdit5();
	afx_msg void OnEnKillfocusEdit7();
	afx_msg void OnBnClickedButton1();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo3();
	afx_msg void OnCbnKillfocusCombo3();
	CComboBox Find_Course_Name1;
	afx_msg void OnCbnSelchangeCombo1();
	CListCtrl score_find_list;
};
