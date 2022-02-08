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
	string course_id;//�γ̱��
	string course_name;//�γ�����
	double course_credit;//ѧ��
	int course_hours;//ѧʱ
	string course_type;//�γ���𣨱���/ѡ�ޣ�
	double course_score;//�ɼ�
	bool course_pass;//�ÿγ��Ƿ�ͨ��
};

class Teacher
{
public:
	vector<Course> teacher_course;//�ý�ʦ�����ڵĿγ�
	string teacher_id;//��ʦ����
	string teacher_name;//��ʦ����
};

class Student
{
public:
	vector<Course> student_course;//��ѧ����ѡ��Ŀγ�
	string student_id;//ѧ��ѧ��
	string student_name;//ѧ������
	string student_major;//ѧ��רҵ
	string student_class;//ѧ�����ڰ༶
};

class Man
{
public:
	string type;//��¼���
	string account;//��¼�˺�
	string password;//��¼����
	string name;//��¼��Ա����
	int sfjzmm;//���˺��Ƿ��ס����
};

extern vector<Course> course;
extern vector<Teacher> teacher;
extern vector<Student> student;
extern vector<Man> man;
extern int man_num;
extern Man one_man;


//��ȡ��¼��Ϣ
void Read_Login();
//��ȡ�γ���Ϣ
void Read_Course();
//��ȡ��ʦ��Ϣ
void Read_Teacher();
//��ȡѧ����Ϣ
void Read_Student();
//��ȡѧ���ɼ�
void Read_Student_Course();
//����½��Ϣд���ļ�
void Write_Login();
//���γ���Ϣд���ļ�
void Write_Course();
//����ʦ��Ϣд���ļ�
void Write_Teacher();
//��ѧ����Ϣд���ļ�
void Write_Student();
//��ѧ���ɼ�д���ļ�
void Write_Student_Course();
//��ӵ�¼��Ϣ�����ɹ��򷵻�TRUE
bool Add_Login(string type, string account, string password, string name);
//��ӿγ���Ϣ�����ɹ��򷵻�TRUE
bool Add_Course(string id, string name, double credit, int hours, string type);
//��ӽ�ʦ��Ϣ�����ɹ��򷵻�TRUE
bool Add_Teacher(vector<Course> c, string id, string name);
//���ѧ����Ϣ�����ɹ��򷵻�TRUE
bool Add_Student(vector<Course> c, string id, string name, string major, string classid);

//��wstring����ת��Ϊstring����
string wstring_string(wstring wstr);
//��string����ת��Ϊwstring����
wstring string_wstring(string str);