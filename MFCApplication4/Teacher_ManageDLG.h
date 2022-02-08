#pragma once


// Teacher_ManageDLG 对话框

class Teacher_ManageDLG : public CDialogEx
{
	DECLARE_DYNAMIC(Teacher_ManageDLG)

public:
	Teacher_ManageDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Teacher_ManageDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_teacher_id;
	CString m_teacher_name;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnKillfocusEdit1();
	virtual BOOL OnInitDialog();
	CString teacher_password;
};
