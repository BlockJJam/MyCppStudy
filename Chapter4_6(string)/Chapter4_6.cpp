#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
	const char my_strs[] = "hello, world";			// c���� ����� ��
	const string my_hello = "hello, world";			//string
	const string my_hello1( "hello, world");
	const string my_hello2{ "hello, world" };
	//string my_ID = 123;								// string -> 123 �̷����·δ� ���ٲ�
	cout << my_hello << endl;

	// int�� �Է¹ޱ�
	cout << " your age ? :";
	int age;
	cin >> age;
	// std::cin.ignore(32767, '\n');	// \n�� ���������� �ִ� 32767 ���� ���ڸ� �����ض�
	std::cin.ignore(numeric_limits<streamsize>::max(), '\n');

	//string�� �Է¹ޱ�
	cout << " Your Name ? :" ;
	string name;
	std::getline(std::cin, name);

	cout << name << " " << age << endl;

	// ���ڿ� �ΰ� ��ġ��, ���ڿ� ����
	string a("Hello,");
	string b("World! ");
	string hw = a + b;				// append

	hw += "I'm good ";
	
	cout << hw << endl;
	cout << a.length() << endl;
	

 
	return 0;
}