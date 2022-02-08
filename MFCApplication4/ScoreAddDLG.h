#pragma once


// ScoreAddDLG 对话框

class ScoreAddDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ScoreAddDLG)

public:
	ScoreAddDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ScoreAddDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE_ADD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Add_Student_ID;
	//CString Add_Course_Name;
	CString Add_Course_Score;
	CString Add_Student_Name;
	CComboBox Cbx_Pass;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox Cbx_Course_Name;
	afx_msg void OnEnKillfocusEdit1();
	afx_msg void OnEnKillfocusEdit3();
	afx_msg void OnCbnSelchangeCombo2();
};
