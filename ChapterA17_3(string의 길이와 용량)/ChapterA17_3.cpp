/*
	string�� ���̿� �뷮�� ������ �

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{	
	string my_str("01234567");				// string�� �ڿ� '\0'�� ������ �ʴ´�, string�� Ŭ�����ϱ� ���̸� ���� ������ �־ �������� Ȯ���� �ٷ� ����
	my_str.reserve(1000);					// 1000���� �ڸ��� ��Ƴ���
	cout << std::boolalpha << endl;
	cout << my_str.length() << endl;
	cout << my_str.size() << endl;
	cout << my_str.capacity() << endl;		// �뷮��ŭ�� ���� �Ҵ� �ȹ޾Ƶ� �ȴ�
	cout << my_str.max_size() << endl;


	return 0;
}