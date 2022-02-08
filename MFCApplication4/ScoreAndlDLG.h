#pragma once


// ScoreAndlDLG 对话框

class ScoreAndlDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ScoreAndlDLG)

public:
	ScoreAndlDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ScoreAndlDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE_ANDL };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox Andl_Course_Name;
	//CComboBox Andl_Class_Name;
	CString All_Student_Num;
	CString Andl_tgl;
	CString Andl_tgrs;
	CString Andl_pjcj;
	CString Andl_fc;
	afx_msg void OnCbnSelchangeCombo2();
	//afx_msg void OnCbnSelchangeCombo3();
	virtual BOOL OnInitDialog();
};
