/* 
	ǥ�� ���ø� ���̺귯��(STL) , �����̳�
		-> STL�� C++ǥ�� ���̺귯���� ����: �� ���� �����ϴ� �� �ƴϸ� ���� ���
		-> Container, Algorithm, Iterator , Function
*/

#include <iostream>
#include <vector>
#include <set>
#include <set>
#include <map>
#include <string>
#include <stack>
#include <queue>

using namespace std;

void sequence_containers()
{
	//vector <- �ַ� �տ� �߰�
	{
		vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		for (auto & e : vec)
			cout << e << " ";
		cout << endl;
	}
	// deque	<- ��, �� ��� �߰�
	{
		deque<int> deq;
		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.push_front(i);
		}
		
		for (auto & e : deq)
			cout << e << " ";
		cout << endl;
	}
}

void associative_container()	
{
	// set <- �ߺ� x
	{
		set<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto & e : str_set)
			cout << e << " ";
		cout << endl;
	}

	// multiset <- duplication is allowed
	{
		multiset<string> str_set;

		str_set.insert("Hello");
		str_set.insert("World");
		str_set.insert("Hello");

		cout << str_set.size() << endl;

		for (auto & e : str_set)
			cout << e << endl;
		cout << endl;
	}

	// map <- JSON���� ���� ���� key:value, key : e.first, value : e.second
	{
		map<char, int> map;
		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50;			// key �� c���� �����ص� a,b,c ������ ����ȴ�, �� ������ map�� ���α�������

		cout << map['a'] << endl;

		map['a'] = 100;

		cout << map['a'] << endl;

		for (auto & e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}

	// multimap : duplicate key�� ����
	{
		multimap<char, int> map;
		map.insert(pair('a', 10));				// C++ 17�̻���� ����, ���������� pair<char,int>('a', 10);
		map.insert(pair('b', 20));
		map.insert(pair('c', 10));
		map.insert(pair('a', 1000));

		cout << map.count('a') << endl;

		for (auto & e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}
}

void container_adapters()
{
	//stack
	{
		cout << "Stack " << endl;

		stack<int> stack;
		stack.push(1);						// push adds a copy					(����)
		stack.emplace(2);					// emplace constructs a new object	(���ο� ��ü�� ����)
		stack.emplace(3);
		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl;
	}

	//queue
	{
		cout << "Queue" << endl;

		queue<int> queue;
		queue.push(1);
		queue.push(2);
		queue.push(3);
	
		cout << queue.front() << " " << queue.back() << endl;
		queue.pop();
		cout << queue.front() << " " << queue.back() << endl;

	}

	//priority queue
	{
		cout << "Priority Queue" << endl;
		priority_queue<int> pri_queue;							// Ŭ������ �������� �񱳿����� �����ε� �Լ��� �־���Ѵ�
		for (const int n : {1, 8, 5, 6, 7, 3, 4, 0, 9, 7, 2})
			pri_queue.push(n);

		for (int i = 0; i < 10; i++)
		{
			cout << pri_queue.top() << endl;
			pri_queue.pop();
		}
	}

}

int main()
{
	//sequence_containers();				// vector , deque

	//associative_container();				// set, multiset, map, multimap

	container_adapters();					// stack , queue, priority queue

	return 0;
}
