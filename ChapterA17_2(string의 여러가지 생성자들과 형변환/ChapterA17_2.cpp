/*
	���ڿ��� �ʱ�ȭ�� �� ���ϰ� ����� �� �ִ� ���� ������, string -> �⺻�� or �⺻�� -> string ����ȯ�� ����
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename T>
string ToString(T x)
{
	ostringstream osstream;

	osstream << x;
	return osstream.str();
}

template <typename T> 
bool FromString(const string &str, T &x)
{
	istringstream isstream(str);
	return (isstream >> x) ? true : false;
}

int main()
{
	string my_string("my string");
	//const char * my_string("my string");

	string second_string(my_string,3);			// �տ� 3�� ©�� , const char *�� �տ� 3�� ������
	string second_string2(my_string, 3,5);		// �տ� 3������ 5�� ��������
	
	string second_string3(10, 'a');				// a 10��

	cout << second_string3 << endl;	

	// stl lib�� itr�� �̿��� string �ʱ�ȭ
	vector<char> vec;
	for (auto e : "Today is a good day")
		vec.push_back(e);

	string second_string4(vec.begin(), vec.end());
	string second_string5(vec.begin(), find(vec.begin(), vec.end(), 's'));	// s�ձ��� �ʱ�ȭ
	cout << second_string5 << endl;
	
	// ������ ��
	string my_str(to_string(1000));		// ������ �ȵǴ� �� to_string()���� ����

	my_str += to_string(128);			// 1128? no 1000128( "1000"+"128")
	int i = stoi(my_str);
	float f = stof(my_str);
	double d = stod(my_str);

	cout << my_str << endl;
	cout << typeid(i).name() << endl;
	cout << typeid(f).name() << endl;
	cout << typeid(d).name() << endl;

	// Ư���� ���
	my_str =ToString("Hello");

	if (FromString(my_str, d))
		cout << d << endl;
	else
		cout << "Cannot covert string to double" << endl;
	
	cout << my_str << endl;

	return 0;
}