
// MFCApplication4.h: MFCApplication4 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // 主符号
#include<string>
using namespace std;

// CMFCApplication4App:
// 有关此类的实现，请参阅 MFCApplication4.cpp
//

class CMFCApplication4App : public CWinApp
{
public:
	CMFCApplication4App() noexcept;


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//string CSTS(CString cstr);//将CString转化成string类型
	LPCWSTR StringToLPCWSTR(string str);//将多字节字符转换为宽字节字符
	string LPCWSTRToString(LPCWSTR wstr);//将宽字节字符转换为多字节字符
	//LPCWSTR是一个指向unicode编码的常量字符串的32位指针，所指向字符串是wchar型。LP表示是一个long指针,C表示是const常量
	//LPCSTR是一个指向以NULL（‘\0’）结尾的常量字符串的指针，所指向字符串是char型。


// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};
extern CMFCApplication4App theApp;
//将CString转化成string类型
string CSTS(CString cstr);
//将多字节字符转换为宽字节字符
LPCWSTR StringToLPCWSTR(string str);
//将宽字节字符转换为多字节字符
string LPCWSTRToString(LPCWSTR wstr);
//将int类型转化为CString类型
CString int2cstring(int);
//将double类型转化为CString类型
CString double2cstring(double);
//将double类型转化为string类型
string double2string(double);
//将CString类型转化为double类型
double cstring2double(CString cstr);
//将string类型转化为double类型
double string2double(string);
//去除CString类型最前或者最后的空格
void trim(CString &cs);