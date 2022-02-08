
// MFCApplication4View.h: CMFCApplication4View 类的接口
//

#pragma once


class CMFCApplication4View : public CView
{
protected: // 仅从序列化创建
	CMFCApplication4View() noexcept;
	DECLARE_DYNCREATE(CMFCApplication4View)

// 特性
public:
	CMFCApplication4Doc* GetDocument() const;

// 操作
public:

	////////////////////自定义
public:
	int WindowsPage;
	int ROW;

	SYSTEMTIME m_time;
	CString mytime;
	CString mydate;

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~CMFCApplication4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()

	/////////////////
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void On32789();
	afx_msg void OnClassSelect();
	afx_msg void OnStudentSearch();
	afx_msg void On3277922();
	afx_msg void On3279611();
	afx_msg void On3279733();
	afx_msg void On32799();
};

#ifndef _DEBUG  // MFCApplication4View.cpp 中的调试版本
inline CMFCApplication4Doc* CMFCApplication4View::GetDocument() const
   { return reinterpret_cast<CMFCApplication4Doc*>(m_pDocument); }
#endif

