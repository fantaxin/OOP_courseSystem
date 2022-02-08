#pragma once


// ClassSelectDLG 对话框
//这个对话框弃用了
class ClassSelectDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ClassSelectDLG)

public:
	ClassSelectDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ClassSelectDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CLSS_SELECT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CString m_SearchType;
	//CString m_SearchBox;
	CListCtrl m_StudentClass;
	afx_msg void OnBnClickedButton2();
	CString m_SearchBox;
};
