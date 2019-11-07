/*
	shared_ptr
		소유권을 공유하는 포인터
		
		! Shared Pointer가 느슨, Unique Pointer가 엄격
*/

#include "Resource.h"

void doSomething(std::unique_ptr<Resource> res)
{

}

int main()
{

	/*Resource *res = new Resource(3);
	res->setAll(1); */
	doSomething(std::unique_ptr<Resource>(new Resource(100000)));	// X 이게 new가 애매해진다
	doSomething(std::make_unique<Resource>(10000));					// O 이게 더 안전

	{
		//std::shared_ptr<Resource> ptr1(res);				// 몇군데서 share를 하는지 센다

		auto ptr1 = std::make_shared<Resource> (3);			// 이게 더 선호됨
		ptr1->setAll(3);

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1);
			//std::shared_ptr <Resource> ptr2(res);			// 이러면 ptr1도 ptr2도 res의 소유권이 다른 포이터에 있는지 모르기 때문에 서로 지워버림
			auto ptr2= ptr1;								// 이게 깔끔하다, copy 같아보이지만 Resource 권한을 공유하는 개념이고, 맨 마지막 포인터가 소멸될 때 Resource가 delete된다

			ptr2->setAll(3);
			ptr2->print();

			std::cout << "Going out of the block" << std::endl;		// ptr2가 ptr1을 공유한다고 해서 ptr1이 사라지는 것이 아님

		}

		ptr1->print();

		std::cout << "Going out of outer the block" << std::endl;	// ptr1이 사라져야 res도 같이 사라짐
	}

	return 0;
}