#include<iostream>
using namespace std;
#include<fstream>
#include<string>
// д�ļ�
void test01()
{
	// ����������
	ofstream ofs; // ��fstream
	// ָ���򿪷�ʽ
	ofs.open("ofs.txt", ios::out);
	// д����
	ofs << "Joyce" << endl;
	ofs << "Tatina" << endl;
	// �ر��ļ�
	ofs.close();
}

// ���ļ�
void test02()
{
	// ����������
	ifstream ifs; // ��fstream
	// ָ���򿪷�ʽ
	ifs.open("ofs.txt", ios::out);
	// �ж��Ƿ��
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	// ������
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
	while (getline(ifs, buf3)) // ȫ�ֺ���getline
	{
		cout << buf3 << endl;
	}
	// mode 4
	char buf4;
	while ((buf4 = ifs.get()) != EOF )// EOF�ļ�ĩβ��־
	{
		cout << buf4;
	}
	// �ر��ļ�
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
	// ����������
	ofstream ofs;
	// ���ļ�
	ofs.open("person.txt", ios::out | ios::binary);
	// ���ߴ���ʱֱ�ӳ�ʼ��
	// ofstream ofs("person.txt", ios::out | ios::binary);
	// д�ļ�
	person p = { "Joyce",22 };
	ofs.write((const char*)&p, sizeof(person));
	// �ر��ļ�
	ofs.close();
}
void test04()
{
	// ����������
	ifstream ifs;
	// ���ļ�
	ifs.open("person.txt", ios::in | ios::binary);
	// �ж��Ƿ��
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	// ���ļ�
	person p;
	ifs.read((char*)&p, sizeof(person));
	cout << p.m_name << p.m_age << endl;
	// �ر��ļ�
	ifs.close();
}
int main()
{
	test04();

	return 0;
}
