/*
	����ó���� ���輺�� ����
		-> ����ó���ϴٺ��� �޸�ó���� �ȵǼ� ������ �߻�����
		-> �����ؾߵ� ��: �Ҹ��ڿ����� ����ó�� throw�ϸ� �ȵ�
		-> loop�ȿ� ����ó�� ��������
		-> ��� ������ ����ó�� �Ϸ��� ��������, �������� ���� ó���Ϸ��� �� ���� if���� ����, �������� ����� ���� �Ͼ �� ����ó������
*/

#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
	~A()
	{
		throw "Error";			// �Ҹ��ڿ����� ����ó�� throw�ϸ� �ȵ�
	}
};

int main()
{
	try
	{
		int *i = new int[100000];
		//����Ʈ������
		unique_ptr<int> up_i(i);				// ������ ����⸸ �ϸ� �޸𸮸� �˾Ƽ� ó��, throw�ǵ� ó������

		throw "error";

		//delete[] i;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;
}