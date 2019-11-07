/* 
	표준 템플릿 라이브러리(STL) , 컨테이너
		-> STL과 C++표준 라이브러리의 차이: 언어를 깊이 공부하는 거 아니면 둘이 비슷
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
	//vector <- 주로 앞에 추가
	{
		vector<int> vec;
		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		for (auto & e : vec)
			cout << e << " ";
		cout << endl;
	}
	// deque	<- 앞, 뒤 모두 추가
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
	// set <- 중복 x
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

	// map <- JSON에서 많이 쓰는 key:value, key : e.first, value : e.second
	{
		map<char, int> map;
		map['a'] = 10;
		map['b'] = 20;
		map['c'] = 50;			// key 를 c부터 선언해도 a,b,c 순으로 저장된다, 그 이유는 map의 내부구조때문

		cout << map['a'] << endl;

		map['a'] = 100;

		cout << map['a'] << endl;

		for (auto & e : map)
			cout << e.first << " " << e.second << " ";
		cout << endl;
	}

	// multimap : duplicate key가 가능
	{
		multimap<char, int> map;
		map.insert(pair('a', 10));				// C++ 17이상부터 가능, 이전버전은 pair<char,int>('a', 10);
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
		stack.push(1);						// push adds a copy					(복사)
		stack.emplace(2);					// emplace constructs a new object	(새로운 객체를 만들어서)
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
		priority_queue<int> pri_queue;							// 클래스를 넣으려면 비교연산자 오버로딩 함수가 있어야한다
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
