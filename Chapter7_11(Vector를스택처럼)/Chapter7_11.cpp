
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
	// size, capacity(용량),			!(new - delete은 느림)

	//v.resize(2);
	v.reserve(1024);			// 메모리양을 1024만큼 확보하겠다 , 나중에 추가할 데이터가 있으면 메모리를 새로 받아오고 할 필요 없다

	printStack(v);

	cout << v.size() << endl;
	cout << v.capacity() << endl;

	//cout << v.at(2) << endl;
	int *ptr = v.data();

	cout << ptr[2] << endl;		// 결국 v는 3까지 가지고 있지만, resize로 2까지만 갖는 척하는 거지, 벡터는 3을 delete하지 않고 가지고 있다

	// vector를 스택으로
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
	// 왜 stack을 vector로 구현을 할까? 메모리 확보와 delete에 유리하고, pop을 하면 capacity 가 유지, reserve를 너무 크게 확보하면 낭비를 통한 성능저하
	


	return 0;
}