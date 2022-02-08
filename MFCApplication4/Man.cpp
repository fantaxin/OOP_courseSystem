#include "pch.h"
//#include "framework.h"
#include "Man.h"

vector<Course> course;
vector<Teacher> teacher;
vector<Student> student;
vector<Man> man;
int man_num;
Man one_man;

void Read_Login()
{
	int n(-1);
	ifstream file("data\\login.txt");
	string linedata;
	Man m;
	while (getline(file, linedata))
	{
		n++;
		if (n == 0)
		{
			continue;
		}
		if (linedata == "#END")
		{
			break;
		}
		stringstream data(linedata);
		string type, account, password, name;
		bool sfjzmm;
		data >> type >> account >> password >> name >> sfjzmm;
		//if (type == "#END")
		//{
		//	break;
		//}
		m.type = type;
		m.account = account;
		m.password = password;
		m.name = name;
		m.sfjzmm = sfjzmm;
		man.push_back(m);
	}
}
bool Add_Login(string type, string account, string password, string name)
{
	for (int i(0); i < man.size(); i++)
	{
		if (account == man[i].account)
		{
			return false;
		}
		man_num = i;
	}
	Man m;
	m.type = type;
	m.name = name;
	m.account = account;
	m.password = password;
	m.sfjzmm = 0;
	man.push_back(m);
	//return false;
}
void Write_Login()
{
	ofstream outfile;
	outfile.open("data\\login.txt");
	outfile << '#';
	outfile << left << setw(10) << "登陆类别"
		<< left << setw(18) << "登陆账号"
		<< left << setw(14) << "登陆密码"
		<< left << setw(16) << "登陆姓名" 
		<< left << setw(16) << "是否记住密码" << endl;
	size_t ss = man.size();
	for (size_t n(0); n < ss; n++)
	{
		outfile << left << setw(1) << " "
			<< left << setw(10) << man[n].type
			<< left << setw(18) << man[n].account
			<< left << setw(14) << man[n].password
			<< left << setw(16) << man[n].name
			<< left << setw(14) << man[n].sfjzmm<< endl;
	}
	outfile << "#END" << endl;
}

void Read_Course()
{
	int n(-1);
	ifstream file("data\\module.txt");
	string linedata_rcourse;
	Course c_rcourse;
	while (getline(file, linedata_rcourse))
	{
		n++;
		if (n == 0)
		{
			continue;
		}
		if (linedata_rcourse == "#END")
		{
			break;
		}
		stringstream data(linedata_rcourse);
		string id, name, type;
		double credit;
		int hours;
		data >> id >> name >> credit >> hours >> type;
		c_rcourse.course_id = id;
		c_rcourse.course_name = name;
		c_rcourse.course_credit = credit;
		c_rcourse.course_hours = hours;
		c_rcourse.course_type = type;
		course.push_back(c_rcourse);
	}
}
void Read_Teacher()
{
	int n(-1), a(-1), course_num, teacher_num(-1);
	ifstream file("data\\staff.txt");//打开文件
	string linedata;
	while (getline(file, linedata))
	{
		Teacher t;
		n++;
		if (n == 0)//确保第一行（即表头）不会读入
		{
			continue;
		}
		if (linedata == "#END")
		{
			break;
		}
		stringstream data(linedata);
		string id, name, course_name;
		data >> id >> name >> course_name;
		size_t ts = teacher.size();
		size_t cs = course.size();
		for (size_t i(0); i < ts; i++)
		{
			if (id == teacher[i].teacher_id)
			{
				a = 0;//当老师的ID已读入时a=0
				teacher_num = i;
			}
		}
		for (size_t i(0); i < cs; i++)
		{
			if (course_name == course[i].course_name)
			{
				course_num = i;
			}
		}
		if (a != 0)//当老师的ID还未读入时，将老师所有信息都读入
		{
			t.teacher_id = id;
			t.teacher_name = name;
			t.teacher_course.push_back(course[course_num]);
			teacher.push_back(t);
			a = -1;
			continue;
		}
		teacher[teacher_num].teacher_course.push_back(course[course_num]);//当老师的ID已读入时，只将老师的课程信息读入
		a = -1;
	}
}
void Read_Student()
{
	int n(-1);
	ifstream file("data\\student.txt");
	string linedata;
	Student s;
	while (getline(file, linedata))
	{
		n++;
		if (n == 0)
		{
			continue;
		}
		if (linedata == "#END")
		{
			break;
		}
		stringstream data(linedata);
		string id, name, class_name, major;
		data >> id >> name >> class_name >> major;
		s.student_id = id;
		s.student_name = name;
		s.student_class = class_name;
		s.student_major = major;
		student.push_back(s);
	}
}

//读学生成绩
void Read_Student_Course()
{
	int n(-1), a, course_num(-1), student_num(-1);
	ifstream file("data\\score.txt");
	string linedata;
	while (getline(file, linedata))
	{
		n++;
		if (n == 0)//确保不读入文件中的第一行（表头）
		{
			continue;
		}
		if (linedata == "#END")
		{
			break;
		}
		stringstream data(linedata);
		string id, name, course_name;
		bool pass;
		double score;
		data >> id >> name >> course_name >> score >> pass;

		vector<Student>::iterator aaaa;//使用迭代器遍历容器
		for (aaaa=student.begin();aaaa!=student.end();aaaa++)
		{
			if (id == aaaa->student_id)//迭代器aaaa指向student_id与id相同的元素
			{
				break;
			}
		}

		vector<Course>::iterator bbbb;
		for (bbbb = course.begin(); bbbb != course.end(); bbbb++)
		{
			if (course_name == bbbb->course_name)////迭代器bbbb指向容器中course_name与course_name相同的元素
			{
				bbbb->course_score = score;
				bbbb->course_pass = pass;
				aaaa->student_course.push_back(*bbbb);//将bbbb所指向的对象添加到aaaa所指向对象的course容器中
				break;
			}
		}
		//bbbb->course_score = score;
		//aaaa->student_course.push_back(*bbbb);
	}
}

void Write_Course()
{
	ofstream outfile;
	outfile.open("data\\module.txt");
	outfile << '#';
	outfile << left << setw(12) << "课程编号"
		<< left << setw(32) << "课程名称"
		<< left << setw(12) << "学分"
		<< left << setw(12) << "学时"
		<< left << setw(12) << "课程类别" << endl;
	size_t s_course = course.size();
	for (size_t n(0); n < s_course; n++)
	{
		outfile << left << setw(1) << " "
			<< left << setw(12) << course[n].course_id
			<< left << setw(32) << course[n].course_name
			<< left << setw(12) << course[n].course_credit
			<< left << setw(12) << course[n].course_hours
			<< left << setw(12) << course[n].course_type << endl;
	}
	outfile << "#END" << endl;
}
void Write_Teacher()
{
	ofstream outfile;
	outfile.open("data\\staff.txt");
	outfile << '#';
	outfile << left << setw(18) << "工号"
		<< left << setw(14) << "姓名"
		<< left << setw(12) << "授课"<< endl;

	for (size_t n(0); n < teacher.size(); n++)
	{
		size_t size_ttcs;
		size_ttcs = teacher[n].teacher_course.size();
		if (size_ttcs > 0)
		{
			for (size_t i(0); i < size_ttcs; i++)
			{
				outfile << left << setw(1) << " "
					<< left << setw(18) << teacher[n].teacher_id
					<< left << setw(14) << teacher[n].teacher_name
					<< left << setw(12) << teacher[n].teacher_course[i].course_name << endl;
			}
		}
		else if (size_ttcs == 0)
		{
			outfile << left << setw(1) << " "
				<< left << setw(18) << teacher[n].teacher_id
				<< left << setw(14) << teacher[n].teacher_name<< endl;
		}
	}
	outfile << "#END" << endl;
}
void Write_Student()
{
	ofstream outfile;
	outfile.open("data\\student.txt");
	outfile << '#';
	outfile << left << setw(18) << "学号"
		<< left << setw(14) << "姓名"
		<< left << setw(12) << "班级"
		<< left << setw(12) << "专业" << endl;
	for (size_t n(0); n < student.size(); n++)
	{
		outfile << left << setw(1) << " "
			<< left << setw(18) << student[n].student_id
			<< left << setw(14) << student[n].student_name
			<< left << setw(12) << student[n].student_class
			<< left << setw(12) << student[n].student_major << endl;
	}
	outfile << "#END" << endl;
}
void Write_Student_Course()
{
	ofstream outfile;
	outfile.open("data\\score.txt");
	outfile << '#';
	outfile << left << setw(18) << "学号"
		<< left << setw(10) << "姓名"
		<< left << setw(26) << "课程名称"
		<< left << setw(12) << "成绩" 
		<< left << setw(12) << "是否通过" << endl;
	for (size_t n(0); n < student.size(); n++)
	{
		for (size_t i(0); i < student[n].student_course.size(); i++)
		{
			string str0;
			if (student[n].student_course[i].course_pass)
			{
				str0 = "1";
			}
			else str0 = "0";
			outfile << left << setw(1) << " "
				<< left << setw(18) << student[n].student_id
				<< left << setw(10) << student[n].student_name
				<< left << setw(26) << student[n].student_course[i].course_name
				<< left << setw(12) << student[n].student_course[i].course_score 
				<< left << setw(12) << str0 << endl;
		}
	}
	outfile << "#END" << endl;
}

bool Add_Course(string id, string name, double credit, int hours, string type)
{
	size_t i;
	for (i=0; i < course.size(); i++)
	{
		if (id == course[i].course_id || name == course[i].course_name)
		{
			return false;
		}
	}
	Course a;
	a.course_id = id;
	a.course_name = name;
	a.course_credit = credit;
	a.course_hours = hours;
	a.course_type = type;
	course.push_back(a);
	return true;
}
bool Add_Teacher(vector<Course> c, string id, string name)
{
	//c是需要添加的课程，id是教师工号，name是教师姓名
	for (size_t i(0); i < teacher.size(); i++)
	{
		if (id == teacher[i].teacher_id)
		{
			return false;
		}
	}
	Teacher t;
	t.teacher_course = c;
	t.teacher_id = id;
	t.teacher_name = name;
	teacher.push_back(t);
	return true;
}
bool Add_Student(vector<Course> c, string id, string name, string major, string classid)
{
	for (size_t i(0); i < student.size(); i++)
	{
		if (id == student[i].student_id)
		{
			return false;
		}
	}
	Student s;
	s.student_course = c;
	s.student_id = id;
	s.student_name = name;
	s.student_major = major;
	s.student_class = classid;
	student.push_back(s);
	return true;
}

string wstring_string(wstring wstr)
{
	string result;
	int len = WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), NULL, 0, NULL, NULL);
	if (len <= 0)return result;
	char* buffer = new char[len + 1];
	if (buffer == NULL)return result;
	WideCharToMultiByte(CP_ACP, 0, wstr.c_str(), wstr.size(), buffer, len, NULL, NULL);
	buffer[len] = '\0';
	result.append(buffer);
	delete[] buffer;
	return result;
}
wstring string_wstring(string str)
{
	wstring result;
	int len = MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), NULL, 0);
	if (len < 0)return result;
	wchar_t* buffer = new wchar_t[len + 1];
	if (buffer == NULL)return result;
	MultiByteToWideChar(CP_ACP, 0, str.c_str(), str.size(), buffer, len);
	buffer[len] = '\0';
	result.append(buffer);
	delete[] buffer;
	return result;
}