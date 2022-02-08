#pragma once


// StudentSearchDLG 对话框

class StudentSearchDLG : public CDialogEx
{
	DECLARE_DYNAMIC(StudentSearchDLG)

public:
	StudentSearchDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~StudentSearchDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENT_SEARCH };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString StudentSearchCredit;
	//CString StudentSearchScore;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CListCtrl student_search_list;
};
