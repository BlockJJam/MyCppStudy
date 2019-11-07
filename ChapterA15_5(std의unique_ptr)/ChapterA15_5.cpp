/*
	����Ʈ ������ unique_ptr
		�����Ͱ� ����Ű�� �ִ� �������� �������� �� ������ ���Ұ�� ���

*/

#include "Resource.h"
#include <memory>

using namespace std;

auto doSomething()
{
	//auto res1 = make_unique<Resource>(5);
	//return res1;
	//return unique_ptr<Resource>(new Resource(5));

	return make_unique<Resource>(5);
}

//void doSomething2(unique_ptr <Resource> & res)			// unique_ptr ��ü�� ������ �޴´� ,unique�ϴϱ�(������ �ϳ���) -> copy�� �ź��ϱ� ������
void doSomething2(Resource * res)
{
	res->setAll(10);
	res->print();
}

void doSomething3(unique_ptr <Resource> res)			// unique_ptr ��ü�� ������ �޴´� -> copy�� �ź��ϱ� ������
{
	res->setAll(100);
	res->print();
}

int main()
{
	//{
	//	//Resource *res = new Resource(10000000);
	//	unique_ptr<Resource> res(new Resource(10000000));

	//}

	//{
	//	unique_ptr<int> upi(new int);

	//	//unique_ptr<Resource> res1(new Resource(5));
	//	//auto *ptr = new Resource(5);
	//	//unique_ptr<Resource> res1(ptr);
	//	auto res1 = make_unique<Resource>(5);	//	����
	//	//auto res1 = doSomething();

	//	res1->setAll(5);
	//	res1->print();
	//	
	//	unique_ptr<Resource> res2;
	//	
	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//	cout << static_cast<bool> (res2) << endl;

	//	// res2= res1 (X) <- �������� �ϳ��� ������ �Ǳ� ������ copy�� �ȵ�
	//	res2 = move(res1);	//<- unique_ptr �� move semantic�� ����

	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//	cout << static_cast<bool> (res2) << endl;

	//	if (res1 != nullptr) res1->print();
	//	if (res2 != nullptr) res2->print();
	//}

	//{
	//	auto res1 = std::make_unique<Resource>(5);
	//	res1->setAll(3);
	//	res1->print();

	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//	
	//	//doSomething2(res1);
	//	//doSomething3(move(res1));

	//	doSomething2(res1.get()); // res1.get() resource Ÿ���� res1�� unique ptr�� ���������� ������ �ִ� Resource�����͸� ������

	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//}

	{
		Resource * res = new Resource;
		unique_ptr<Resource> res1(res);
		unique_ptr<Resource> res2(res);		// X <- unique ptr�ε� �������� �ٸ������� �ִ°�( res 2������ )

		delete res;							// X <- ������ unique ptr���� �༭ unique ptr�� ����µ� �� ������ �ϴ°�
	}

	return 0;
}