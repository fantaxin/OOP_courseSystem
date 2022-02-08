#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<iomanip>
#include<sstream>
using namespace std;
class Course
{
public:
	string course_id;//课程编号
	string course_name;//课程名称
	double course_credit;//学分
	int course_hours;//学时
	string course_type;//课程类别（必修/选修）
	double course_score;//成绩
	bool course_pass;//该课程是否通过
};

class Teacher
{
public:
	vector<Course> teacher_course;//该教师所教授的课程
	string teacher_id;//教师工号
	string teacher_name;//教师姓名
};

class Student
{
public:
	vector<Course> student_course;//该学生所选择的课程
	string student_id;//学生学号
	string student_name;//学生姓名
	string student_major;//学生专业
	string student_class;//学生所在班级
};

class Man
{
public:
	string type;//登录类别
	string account;//登录账号
	string password;//登录密码
	string name;//登录人员姓名
	int sfjzmm;//该账号是否记住密码
};

extern vector<Course> course;
extern vector<Teacher> teacher;
extern vector<Student> student;
extern vector<Man> man;
extern int man_num;
extern Man one_man;


//读取登录信息
void Read_Login();
//读取课程信息
void Read_Course();
//读取教师信息
void Read_Teacher();
//读取学生信息
void Read_Student();
//读取学生成绩
void Read_Student_Course();
//将登陆信息写入文件
void Write_Login();
//将课程信息写入文件
void Write_Course();
//将教师信息写入文件
void Write_Teacher();
//将学生信息写入文件
void Write_Student();
//将学生成绩写入文件
void Write_Student_Course();
//添加登录信息，若成功则返回TRUE
bool Add_Login(string type, string account, string password, string name);
//添加课程信息，若成功则返回TRUE
bool Add_Course(string id, string name, double credit, int hours, string type);
//添加教师信息，若成功则返回TRUE
bool Add_Teacher(vector<Course> c, string id, string name);
//添加学生信息，若成功则返回TRUE
bool Add_Student(vector<Course> c, string id, string name, string major, string classid);

//将wstring类型转化为string类型
string wstring_string(wstring wstr);
//将string类型转化为wstring类型
wstring string_wstring(string str);