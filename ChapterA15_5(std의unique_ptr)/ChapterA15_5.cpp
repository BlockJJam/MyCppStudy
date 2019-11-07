/*
	스마트 포인터 unique_ptr
		포인터가 가리키고 있는 데이터의 소유권이 한 곳에만 속할경우 사용

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

//void doSomething2(unique_ptr <Resource> & res)			// unique_ptr 객체를 참조로 받는다 ,unique하니까(소유권 하나만) -> copy를 거부하기 때문에
void doSomething2(Resource * res)
{
	res->setAll(10);
	res->print();
}

void doSomething3(unique_ptr <Resource> res)			// unique_ptr 객체를 참조로 받는다 -> copy를 거부하기 때문에
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
	//	auto res1 = make_unique<Resource>(5);	//	권장
	//	//auto res1 = doSomething();

	//	res1->setAll(5);
	//	res1->print();
	//	
	//	unique_ptr<Resource> res2;
	//	
	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//	cout << static_cast<bool> (res2) << endl;

	//	// res2= res1 (X) <- 소유권을 하나만 가져야 되기 때문에 copy는 안됨
	//	res2 = move(res1);	//<- unique_ptr 은 move semantic만 가능

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

	//	doSomething2(res1.get()); // res1.get() resource 타입의 res1의 unique ptr가 내부적으로 가지고 있는 Resource포인터를 가져옴

	//	cout << boolalpha;
	//	cout << static_cast<bool>(res1) << endl;
	//}

	{
		Resource * res = new Resource;
		unique_ptr<Resource> res1(res);
		unique_ptr<Resource> res2(res);		// X <- unique ptr인데 소유권을 다른데에도 주는격( res 2번지움 )

		delete res;							// X <- 관리를 unique ptr에게 줘서 unique ptr이 지우는데 또 지우라고 하는격
	}

	return 0;
}