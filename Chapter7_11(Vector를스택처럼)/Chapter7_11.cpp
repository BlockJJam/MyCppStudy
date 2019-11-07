
#include <iostream>
#include <vector>

using namespace std;

void printStack(const std::vector<int> &stack)
{
	for (auto &e : stack)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	vector<int> v{ 1,2,3 };
	// size, capacity(�뷮),			!(new - delete�� ����)

	//v.resize(2);
	v.reserve(1024);			// �޸𸮾��� 1024��ŭ Ȯ���ϰڴ� , ���߿� �߰��� �����Ͱ� ������ �޸𸮸� ���� �޾ƿ��� �� �ʿ� ����

	printStack(v);

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	//cout << v.at(2) << endl;
	int *ptr = v.data();

	cout << ptr[2] << endl;		// �ᱹ v�� 3���� ������ ������, resize�� 2������ ���� ô�ϴ� ����, ���ʹ� 3�� delete���� �ʰ� ������ �ִ�

	// vector�� ��������
	vector<int> stack;

	stack.push_back(3);
	printStack(stack);

	stack.push_back(5);
	printStack(stack);

	stack.push_back(7);
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);
	// �� stack�� vector�� ������ �ұ�? �޸� Ȯ���� delete�� �����ϰ�, pop�� �ϸ� capacity �� ����, reserve�� �ʹ� ũ�� Ȯ���ϸ� ���� ���� ��������
	


	return 0;
}