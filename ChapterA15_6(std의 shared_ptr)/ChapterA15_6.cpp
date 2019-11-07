/*
	shared_ptr
		�������� �����ϴ� ������
		
		! Shared Pointer�� ����, Unique Pointer�� ����
*/

#include "Resource.h"

void doSomething(std::unique_ptr<Resource> res)
{

}

int main()
{

	/*Resource *res = new Resource(3);
	res->setAll(1); */
	doSomething(std::unique_ptr<Resource>(new Resource(100000)));	// X �̰� new�� �ָ�������
	doSomething(std::make_unique<Resource>(10000));					// O �̰� �� ����

	{
		//std::shared_ptr<Resource> ptr1(res);				// ����� share�� �ϴ��� ����

		auto ptr1 = std::make_shared<Resource> (3);			// �̰� �� ��ȣ��
		ptr1->setAll(3);

		ptr1->print();

		{
			//std::shared_ptr<Resource> ptr2(ptr1);
			//std::shared_ptr <Resource> ptr2(res);			// �̷��� ptr1�� ptr2�� res�� �������� �ٸ� �����Ϳ� �ִ��� �𸣱� ������ ���� ��������
			auto ptr2= ptr1;								// �̰� ����ϴ�, copy ���ƺ������� Resource ������ �����ϴ� �����̰�, �� ������ �����Ͱ� �Ҹ�� �� Resource�� delete�ȴ�

			ptr2->setAll(3);
			ptr2->print();

			std::cout << "Going out of the block" << std::endl;		// ptr2�� ptr1�� �����Ѵٰ� �ؼ� ptr1�� ������� ���� �ƴ�

		}

		ptr1->print();

		std::cout << "Going out of outer the block" << std::endl;	// ptr1�� ������� res�� ���� �����
	}

	return 0;
}