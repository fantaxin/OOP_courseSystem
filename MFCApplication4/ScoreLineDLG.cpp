// ScoreLineDLG.cpp: 实现文件
//这个对话框弃用了

#include "pch.h"
#include "MFCApplication4.h"
#include "ScoreLineDLG.h"
#include "afxdialogex.h"


// ScoreLineDLG 对话框

IMPLEMENT_DYNAMIC(ScoreLineDLG, CDialogEx)

ScoreLineDLG::ScoreLineDLG(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCORE_LINE, pParent)
{

}

ScoreLineDLG::~ScoreLineDLG()
{
}

void ScoreLineDLG::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ScoreLineDLG, CDialogEx)
END_MESSAGE_MAP()


// ScoreLineDLG 消息处理程序
