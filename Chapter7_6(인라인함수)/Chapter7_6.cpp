/*
	inline �Լ�
		-> �ش� �Լ��� ���� ã���鼭 ���� ������带 ���̱� ���� ���
		-> �Լ��� ȣ��Ǵ� ������ �ƴ� ������ ������ �ش� �Լ� ������ ȣ���� �κп� ���ٳ��� -> ȣ���ϴ� ������ ������
		-> �����Ͽ� ������ �ƴ϶� , �����Ϸ��� �Ǵ��Ͽ� inline�� �޾Ƶ��δ�
		-> ���� �����Ϸ� �ߴ޷� inline�Լ��� �������ص� �˾Ƽ� inline�� Ȱ���Ѵ�
*/

#include <iostream>

using namespace std;

inline int min(int x, int y)
{
	return (x < y) ? x : y;
}

int main()
{
	cout << min(1, 2) << endl;
	return 0;
}
