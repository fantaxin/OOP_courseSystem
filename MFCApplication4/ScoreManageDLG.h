#pragma once

#include"TabSheet.h"

#include"ScoreAddDLG.h"
#include"ScoreAndlDLG.h"
#include"ScoreChangeDLG.h"
#include"ScoreFindDLG.h"
#include"ScoreLineDLG.h"

// ScoreManageDLG 对话框

class ScoreManageDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ScoreManageDLG)

public:
	ScoreManageDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ScoreManageDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE_MANAGE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CTabSheet ScoreManageTab;

	ScoreAddDLG dlg1;
	ScoreAndlDLG dlg4;
	ScoreChangeDLG dlg2;
	ScoreFindDLG dlg3;
	//ScoreLineDLG dlg5;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton2();
};
