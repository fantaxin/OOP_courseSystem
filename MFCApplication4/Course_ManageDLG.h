#pragma once


// Course_ManageDLG 对话框

class Course_ManageDLG : public CDialogEx
{
	DECLARE_DYNAMIC(Course_ManageDLG)

public:
	Course_ManageDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Course_ManageDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_course_id;
	CString m_course_name;
	CString m_credit;
	CString m_hours;
	CComboBox m_type;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnKillfocusEdit1();
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeCombo1();
	CComboBox course_teacher;
	afx_msg void OnCbnSelchangeCombo2();
};
