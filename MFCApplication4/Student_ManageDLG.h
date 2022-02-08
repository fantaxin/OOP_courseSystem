#pragma once


// Student_ManageDLG 对话框

class Student_ManageDLG : public CDialogEx
{
	DECLARE_DYNAMIC(Student_ManageDLG)

public:
	Student_ManageDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~Student_ManageDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_student_id;
	CString m_student_name;
	CString m_class;
	CString m_major;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnEnKillfocusEdit1();
	virtual BOOL OnInitDialog();
	CString student_password;
};
