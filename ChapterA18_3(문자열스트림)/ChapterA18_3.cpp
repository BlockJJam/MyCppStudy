/*
	string stream
*/

#include <iostream>
#include <sstream>

using namespace std;

int main()
{
	stringstream os;

	
	//os << "hello, world ";		// << : insertion operator, >> : extraction operator
	////os.str("hello, world!");	// os.str(...) : �ƿ� ...���� �ٲ����( �߰��� �귯���°��� �ƴ�), parameter�� ������ �׳� os���� ����
	//os << "hello, world2" << endl;
	//string str;

	//str = os.str();

	//cout << str << endl;
	//cout << os.str()<< endl;
	/*int i = 12345;
	double d = 67.89;*/

	//���� �ֱ�
	//os << i << " " << d;;

	/*string str1;
	string str2;
	
	os >> str1 >> str2;

	cout << str1 << "  |  " << str2 << endl;*/

	// ���ڷ� �ޱ�

	os << "12345 678.90";

	/*int i2;
	double d2;
	os >> i2 >> d2;*/
	//cout << i2 << " | " << d2 << endl;

	// stream ����
	os.str("");
	os.clear();				// state ���� �ʱ�ȭ
	os << "hello";

	
	cout << os.str() << endl;
	return 0;
}