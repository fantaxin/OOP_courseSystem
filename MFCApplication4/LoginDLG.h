#pragma once


// LoginDLG 对话框

class LoginDLG : public CDialogEx
{
	DECLARE_DYNAMIC(LoginDLG)

public:
	LoginDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~LoginDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	//CComboBox cbx_man_type;
	virtual BOOL OnInitDialog();
	//CString cbx_man_account;
	CString edit_man_password;
	CString cbx_man_type;
	CComboBox cbx_man_account;
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelendokCombo1();
//	afx_msg void OnNMThemeChangedCombo1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnClose();
};
