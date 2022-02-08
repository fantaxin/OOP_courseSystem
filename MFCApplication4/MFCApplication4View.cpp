
// MFCApplication4View.cpp: CMFCApplication4View 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "MFCApplication4.h"
#endif

#include "MFCApplication4Doc.h"
#include "MFCApplication4View.h"
#include"Man.h"
#include"ScoreManageDLG.h"
#include"ClassSelectDLG.h"
#include"StudentSearchDLG.h"

#include"Course_ManageDLG.h"
#include"Student_ManageDLG.h"
#include"Teacher_ManageDLG.h"
#include"ClassSystemDLG.h"
#include"PasswordDLG.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApplication4View

IMPLEMENT_DYNCREATE(CMFCApplication4View, CView)

BEGIN_MESSAGE_MAP(CMFCApplication4View, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)



//	ON_COMMAND(ID_32775, &CMFCApplication4View::OnInputData)
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_TIMER()


	ON_COMMAND(ID_32789, &CMFCApplication4View::On32789)
	ON_COMMAND(ID_32784, &CMFCApplication4View::OnClassSelect)
	ON_COMMAND(ID_32786, &CMFCApplication4View::OnStudentSearch)
	ON_COMMAND(ID_32779, &CMFCApplication4View::On3277922)
	ON_COMMAND(ID_32796, &CMFCApplication4View::On3279611)
	ON_COMMAND(ID_32797, &CMFCApplication4View::On3279733)
	ON_COMMAND(ID_32799, &CMFCApplication4View::On32799)
END_MESSAGE_MAP()

// CMFCApplication4View 构造/析构

CMFCApplication4View::CMFCApplication4View() noexcept
{
	// TODO: 在此处添加构造代码

}

CMFCApplication4View::~CMFCApplication4View()
{
}

BOOL CMFCApplication4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CMFCApplication4View 绘图

void CMFCApplication4View::OnDraw(CDC* pDC)
{
	CMFCApplication4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码

	int w, h;

	ROW = 0;

	CRect rect;
	GetWindowRect(&rect);
	w = (int)rect.Width();
	h = (int)rect.Height();
	CPen NewPen(PS_SOLID, 1, RGB(211, 211, 211));
	CPen *pOldPen = pDC->SelectObject(&NewPen);

	//pDC->FillSolidRect(0, 0, w, h, RGB(150, 148, 214));

	pDC->Rectangle(0, 100, w - 5, h - 50);//背景设置
	pDC->FillSolidRect(5, 105, 210, h - 155, RGB(231, 231, 245));
	pDC->FillSolidRect(220, 105, w - 230, 140, RGB(118, 116, 208));
	pDC->FillSolidRect(220, 145, w - 230, h - 195, RGB(242, 242, 251));

	pDC->Rectangle(55, 270, 175, 310);//菜单栏
	pDC->FillSolidRect(56, 271, 118, 38, RGB(118, 116, 208));
	pDC->Rectangle(55, 325, 175, 365);
	pDC->FillSolidRect(56, 326, 118, 38, RGB(118, 116, 208));
	pDC->Rectangle(55, 380, 175, 420);
	pDC->FillSolidRect(56, 381, 118, 38, RGB(118, 116, 208));
	pDC->Rectangle(55, 435, 175, 475);
	pDC->FillSolidRect(56, 436, 118, 38, RGB(118, 116, 208));
	pDC->Rectangle(55, 490, 175, 530);
	pDC->FillSolidRect(56, 491, 118, 38, RGB(118, 116, 208));


	CFont NewFont;
	NewFont.CreateFont(18, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH&FF_SWISS, L"宋体");
	CFont * pOldFont = (CFont *)pDC->SelectObject(&NewFont);
	pDC->SetBkColor(RGB(118, 116, 208));
	pDC->TextOut(75, 283, L"系统首页");
	pDC->TextOut(80, 338, L"系统管理");
	pDC->TextOut(75, 393, L"教师系统");
	pDC->TextOut(75, 448, L"学生系统");
	pDC->TextOut(75, 503, L"修改密码");

	pDC->Rectangle(10, 120, 200, 255);
	pDC->FillSolidRect(11, 121, 188, 133, RGB(118, 116, 208));
	pDC->Rectangle(15, 125, 205, 260);
	pDC->FillSolidRect(16, 126, 188, 133, RGB(242, 242, 251));
	pDC->Rectangle(30, 170, 100, 240);
	pDC->FillSolidRect(31, 171, 68, 68, RGB(0, 255, 0));
	pDC->Rectangle(120, 225, 190, 250);
	pDC->FillSolidRect(121, 226, 68, 23, RGB(118, 116, 208));

	pDC->MoveTo(25, 155);
	pDC->LineTo(195, 155);

	pDC->SelectObject(pOldFont);
	CFont NewFont1;
	NewFont1.CreateFont(15, 0, 0, 0, FW_NORMAL, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH&FF_SWISS, L"宋体");
	CFont * pOldFont1 = (CFont *)pDC->SelectObject(&NewFont1);





	pDC->SetBkColor(RGB(242, 242, 251));


	pDC->TextOut(40, 138, L"个人信息 : ");

	string str = one_man.type;
	wstring wstr = string_wstring(str);
	pDC->TextOut(125, 165, wstr.c_str());

	string str1 = one_man.name;
	wstring wstr1 = string_wstring(str1);
	pDC->TextOut(125, 185, wstr1.c_str());

	string str2 = one_man.account;
	wstring wstr2 = string_wstring(str2);
	pDC->TextOut(125, 205, wstr2.c_str());




	CString tmpstr;
	tmpstr.Format(L"%d", 1/*UserInf.userank + 48*/);
	pDC->TextOut(165, 205, tmpstr);
	pDC->SelectObject(pOldFont);

	CFont NewFont2;
	NewFont2.CreateFont(13, 0, 0, 0, 700, 0, 0, 0, ANSI_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH&FF_SWISS, L"宋体");
	CFont * pOldFont2 = (CFont *)pDC->SelectObject(&NewFont2);
	pDC->SetBkColor(RGB(118, 116, 208));
	pDC->TextOut(128, 232, L"安全退出");
	pDC->SelectObject(&NewFont1);
	///////////////////////////////////////////////////////////////////////////////////////////////////显示图片

	IPicture *pPic;
	IStream *pStm;
	CFileStatus fstatus;
	CFile file;
	LONG cb;

	CString tmpfilepath;                 //存放路径的变量
	GetCurrentDirectory(MAX_PATH, (LPWSTR)(LPCTSTR)tmpfilepath);  //获取程序的当前目录
	CString userfilename = tmpfilepath + "\\res\\user.jpg";

	if (file.Open(userfilename, CFile::modeRead) && file.GetStatus(userfilename, fstatus) && ((cb = fstatus.m_size) != -1))
	{
		HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);
		LPVOID pvData = NULL;
		if (hGlobal != NULL)
		{
			if ((pvData = GlobalLock(hGlobal)) != NULL)
			{
				file.Read(pvData, cb);
				GlobalUnlock(hGlobal);
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);

				if (SUCCEEDED(OleLoadPicture(pStm, fstatus.m_size, TRUE, IID_IPicture, (LPVOID*)&pPic)))
				{
					OLE_XSIZE_HIMETRIC hmWidth;
					OLE_YSIZE_HIMETRIC hmHeight;

					pPic->get_Width(&hmWidth);
					pPic->get_Height(&hmHeight);
					double fX, fY;
					fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth / ((double)pDC->GetDeviceCaps(HORZSIZE)*100.0);
					fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight / ((double)pDC->GetDeviceCaps(VERTSIZE)*100.0);
					if (FAILED(pPic->Render(*pDC, 30, 170, 70, 70, 0, hmHeight, hmWidth, -hmHeight, NULL)))  //30,170,70,70分别表示图片的起点坐标和长宽
						AfxMessageBox(L"Failed To Render The picture!");
					pPic->Release();
				}
				else
					AfxMessageBox(L"Error Loading Picture From Stream!");
			}
		}
	}

	///////////////////////////////////////////////////////////////////////////////////////////////////////////
	switch (WindowsPage)
	{
	case 0://系统首页
	{
		MessageBox(L"系统首页");
		break;
	}
	case 1://系统管理
	{
		MessageBox(L"系统管理");
		break;
	}
	case 2://学生管理
	{
		MessageBox(L"学生管理");
		break;
	}
	case 3://教师管理
	{
		MessageBox(L"教师管理");
		break;
	}
	case 4://日志记录
	{
		MessageBox(L"日志记录");
		break;
	}
	default:
		break;
	}
}


// CMFCApplication4View 打印

BOOL CMFCApplication4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CMFCApplication4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CMFCApplication4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}


// CMFCApplication4View 诊断

#ifdef _DEBUG
void CMFCApplication4View::AssertValid() const
{
	CView::AssertValid();
}

void CMFCApplication4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCApplication4Doc* CMFCApplication4View::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCApplication4Doc)));
	return (CMFCApplication4Doc*)m_pDocument;
}
#endif //_DEBUG


// CMFCApplication4View 消息处理程序

void CMFCApplication4View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CView::OnPaint()

	CDC *pDC = GetDC();


	CRect rect;
	GetWindowRect(&rect);
	int w = (int)rect.Width();
	int h = (int)rect.Height();

	CPen NewPen(PS_SOLID, 1, RGB(211, 211, 211));
	CPen *pOldPen = pDC->SelectObject(&NewPen);

	//pDC->FillSolidRect(0, 0, w, h, RGB(150, 148, 214));
	pDC->FillSolidRect(0, 0, w, h, RGB(118, 116, 208));


	IPicture *pPic;
	IStream *pStm;
	CFileStatus fstatus;
	CFile file;
	LONG cb;

	CString tmpfilepath;                 //存放路径的变量
	GetCurrentDirectory(MAX_PATH, (LPWSTR)(LPCTSTR)tmpfilepath);  //获取程序的当前目录
	CString userfilename = tmpfilepath + "\\res\\logo.jpg";

	if (file.Open(userfilename, CFile::modeRead) && file.GetStatus(userfilename, fstatus) && ((cb = fstatus.m_size) != -1))
	{
		HGLOBAL hGlobal = GlobalAlloc(GMEM_MOVEABLE, cb);
		LPVOID pvData = NULL;
		if (hGlobal != NULL)
		{
			if ((pvData = GlobalLock(hGlobal)) != NULL)
			{
				file.Read(pvData, cb);
				GlobalUnlock(hGlobal);
				CreateStreamOnHGlobal(hGlobal, TRUE, &pStm);

				if (SUCCEEDED(OleLoadPicture(pStm, fstatus.m_size, TRUE, IID_IPicture, (LPVOID*)&pPic)))
				{
					OLE_XSIZE_HIMETRIC hmWidth;
					OLE_YSIZE_HIMETRIC hmHeight;

					pPic->get_Width(&hmWidth);
					pPic->get_Height(&hmHeight);
					double fX, fY;
					fX = (double)pDC->GetDeviceCaps(HORZRES)*(double)hmWidth / ((double)pDC->GetDeviceCaps(HORZSIZE)*100.0);
					fY = (double)pDC->GetDeviceCaps(VERTRES)*(double)hmHeight / ((double)pDC->GetDeviceCaps(VERTSIZE)*100.0);
					//                     if(FAILED(pPic->Render(*pDC,30,170,70,70,0,hmHeight,hmWidth,-hmHeight,NULL)))  //30,170,70,70分别表示图片的起点坐标和长宽
					if (FAILED(pPic->Render(*pDC, 0, 0, 1100, 100, 0, hmHeight, hmWidth, -hmHeight, NULL)))
						AfxMessageBox(L"Failed To Render The picture!");
					pPic->Release();
				}
				//				else
				//					AfxMessageBox("Error Loading Picture From Stream!");
			}
		}
	}
	OnDraw(pDC);
}


void CMFCApplication4View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	CClientDC dc(this);

	if (point.x >= 55 && point.x <= 175 && point.y >= 270 && point.y <= 310)
	{
		WindowsPage = 0;
	}
	else if (point.x >= 55 && point.x <= 175 && point.y >= 325 && point.y <= 365)
	{
		WindowsPage = 1;
	}
	else if (point.x >= 55 && point.x <= 175 && point.y >= 380 && point.y <= 420)
	{
		WindowsPage = 2;
	}
	else if (point.x >= 55 && point.x <= 175 && point.y >= 435 && point.y <= 475)
	{
		WindowsPage = 3;
	}
	else if (point.x >= 55 && point.x <= 175 && point.y >= 490 && point.y <= 530)
	{
		WindowsPage = 4;
	}
	else if (point.x >= 120 && point.y >= 225 && point.x <= 190 && point.y <= 250)
	{
		//this->SendMessage(WM_CLOSE);
		if (IDOK == MessageBox(L"是否关闭程序？", L"程序退出", IDOK))
		{
			Write_Course();
			Write_Student();
			Write_Student_Course();
			Write_Teacher();
			Write_Login();
			::PostMessage(GetSafeHwnd(), WM_COMMAND, MAKELONG(ID_FILE_CLOSE, 0), 0);
		}
		WindowsPage = -1;
	}
	else
	{
		WindowsPage = -1;
	}

	OnDraw(&dc);
	CView::OnLButtonDown(nFlags, point);
}


int CMFCApplication4View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码
	SetTimer(100, 100, NULL);
	return 0;
}


void CMFCApplication4View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值
	const char *m_week[7] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	GetLocalTime(&m_time);
	mydate.Format(L"%4d-%02d-%02d %s", m_time.wYear, m_time.wMonth, m_time.wDay, CStringW(m_week[m_time.wDayOfWeek]));
	mytime.Format(L"%02d:%02d:%02d", m_time.wHour, m_time.wMinute, m_time.wSecond);
	CDC *pDC = GetDC();
	pDC->SetBkColor(RGB(118, 116, 208));
	pDC->TextOut(870, 30, mydate);
	pDC->TextOut(910, 65, mytime);

	CView::OnTimer(nIDEvent);
}


void CMFCApplication4View::On32789()
{
	// TODO: 在此添加命令处理程序代码

	ScoreManageDLG dlg;
	dlg.DoModal();
}


void CMFCApplication4View::OnClassSelect()
{
	// TODO: 在此添加命令处理程序代码
	ClassSystemDLG dlg;
	dlg.DoModal();

}


void CMFCApplication4View::OnStudentSearch()
{
	// TODO: 在此添加命令处理程序代码

	StudentSearchDLG dlg;
	dlg.DoModal();

}

//教师
void CMFCApplication4View::On3277922()
{
	// TODO: 在此添加命令处理程序代码

	Teacher_ManageDLG dlg;
	dlg.DoModal();
}

//学生
void CMFCApplication4View::On3279611()
{
	// TODO: 在此添加命令处理程序代码
	Student_ManageDLG dlg;
	dlg.DoModal();

}

//课程
void CMFCApplication4View::On3279733()
{
	// TODO: 在此添加命令处理程序代码
	Course_ManageDLG dlg;
	dlg.DoModal();

}


void CMFCApplication4View::On32799()
{
	// TODO: 在此添加命令处理程序代码
	PasswordDLG dlg;
	dlg.DoModal();
}
