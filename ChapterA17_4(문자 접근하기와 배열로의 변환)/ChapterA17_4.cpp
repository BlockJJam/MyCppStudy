/*
	string ���� �����ϱ�� �迭���� ��ȯ
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	string my_str("abcdefg");
	
	cout << my_str[0] << endl;
	cout << my_str[3] << endl;

	my_str[3] = 'Z';

	cout << my_str << endl;

	//my_str[100] = 'x';
	//cout << my_str[100] << endl;

	try {
		//my_str[100] = 'x';			// ����ó���� ������ ������, �� ��������� ����ó���� �ȵ�
		my_str.at(100) = 'X';			// ���� �����鼭 ���� ó���� �ִ� at() �Լ� 
	}
	catch (exception &e)				
	{
		cout << e.what() << endl;
	}
	
	const char *arr = my_str.c_str();	// string -> c��Ÿ�� �� ����, �ڿ� \0�� �ٿ��� �ش�
	cout << int(arr[6]) << endl;
	cout << int(arr[7])<< endl;				// '\0'

	char buf[20];
	
	my_str.copy(buf, 5, 1);				// �ι�° 5�� ������, ����° 1�� ����index
	buf[5] = '\0';

	cout << buf << endl;

	return 0;
}