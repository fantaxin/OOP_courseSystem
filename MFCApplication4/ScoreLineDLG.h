#pragma once


// ScoreLineDLG 对话框
//这个对话框弃用了
class ScoreLineDLG : public CDialogEx
{
	DECLARE_DYNAMIC(ScoreLineDLG)

public:
	ScoreLineDLG(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ScoreLineDLG();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCORE_LINE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
