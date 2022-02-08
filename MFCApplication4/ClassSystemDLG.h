#pragma once


// ClassSystemDLG 对话框

class ClassSystemDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ClassSystemDLG)

public:
	ClassSystemDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ClassSystemDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLASS_MANAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox course_select1;
	CComboBox course_delete1;
	CListCtrl m_course;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
