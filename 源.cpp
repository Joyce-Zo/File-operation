#include<iostream>
using namespace std;
#include<fstream>
#include<string>
// 写文件
void test01()
{
	// 创建流对象
	ofstream ofs; // 或fstream
	// 指定打开方式
	ofs.open("ofs.txt", ios::out);
	// 写内容
	ofs << "Joyce" << endl;
	ofs << "Tatina" << endl;
	// 关闭文件
	ofs.close();
}

// 读文件
void test02()
{
	// 创建流对象
	ifstream ifs; // 或fstream
	// 指定打开方式
	ifs.open("ofs.txt", ios::out);
	// 判断是否打开
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	// 读内容
	// mode 1
	char buf1[1024] = { 0 };
	while (ifs >> buf1)
	{
		cout << buf1 << endl;
	}
	// mode 2
	char buf2[1024] = { 0 };
	while (ifs.getline(buf2, 1024))
	{
		cout << buf2 << endl;
	}
	// mode 3
	string buf3;
	while (getline(ifs, buf3)) // 全局函数getline
	{
		cout << buf3 << endl;
	}
	// mode 4
	char buf4;
	while ((buf4 = ifs.get()) != EOF )// EOF文件末尾标志
	{
		cout << buf4;
	}
	// 关闭文件
	ifs.close();
}

class person
{
public:
	char m_name[64];
	int m_age;
};
void test03()
{
	// 创建流对象
	ofstream ofs;
	// 打开文件
	ofs.open("person.txt", ios::out | ios::binary);
	// 或者创建时直接初始化
	// ofstream ofs("person.txt", ios::out | ios::binary);
	// 写文件
	person p = { "Joyce",22 };
	ofs.write((const char*)&p, sizeof(person));
	// 关闭文件
	ofs.close();
}
void test04()
{
	// 创建流对象
	ifstream ifs;
	// 打开文件
	ifs.open("person.txt", ios::in | ios::binary);
	// 判断是否打开
	if (!ifs.is_open())
	{
		cout << "文件打开失败！" << endl;
		return;
	}
	// 读文件
	person p;
	ifs.read((char*)&p, sizeof(person));
	cout << p.m_name << p.m_age << endl;
	// 关闭文件
	ifs.close();
}
int main()
{
	test04();

	return 0;
}
