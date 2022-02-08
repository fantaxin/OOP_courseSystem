#pragma once


// PasswordDLG 对话框

class PasswordDLG : public CDialogEx
{
	DECLARE_DYNAMIC(PasswordDLG)

public:
	PasswordDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~PasswordDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PASSWORD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString Password1;
	CString Password2;
	afx_msg void OnBnClickedButton1();
	//afx_msg void OnBnClickedOk();
};
