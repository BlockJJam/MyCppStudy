/*
	�̵��� �ǹ̿� ����Ʈ ������
		-> ����Ʈ ������ : ������ �Ϲ� �����ʹ� �޸� ������ ���� ����� �Ȱ�, ������ ���� �޸������� ��ġ�� ��찡 ����
						 : �׷��� "����Ʈ ������"�� ����ϸ� ������ ����� �˾Ƽ� �޸� ����

*/

#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

// RAII : �ڿ��� new �� ������ delete����� �Ѵ�
void doSomething()
{
	try
	{
		//Resource *res = new Resource;					// dull(��û��) pointer
		AutoPtr<Resource> res (new Resource);			// smart pointer

		return;

		// work with res
		if (true)
		{
			throw - 1;;									// delete�� �ȵ��ڳ�? -> smartpointer ����ض�
		}
		//delete res;
	}
	catch (...)
	{

	}
	return;												// �������� �޸𸮰����� ���α׷��ӿ��� ���� �����Ϸ����� �ѱ��� -> class ����
}

int main()
{
	//doSomething();

	{
		AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;

		cout << std::boolalpha;

		cout << res1._ptr << endl;
		cout << res2._ptr << endl;

		res2 = res1;					// ���� �̵��� �ǹ�( move semantics -> semantic<�ǹ���> )

		cout << res1._ptr << endl;
		cout << res2._ptr << endl;		// new Resource �� �޸𸮸� �ѹ��� �ʱ�ȭ
										// ������ ����� res1, res2 �ι� �޸� ���� �߻� runtime err
										// �ذ��� : res2�� res1�� �������� �����͹�����(res1 ���ѹ�Ż)
		
		doSomething(res2);				// �� �ٸ� ������: auto pointer�� �Լ� �Ķ���ͷ� ���� �� �Լ������ �����Ͱ� �޸� ������  
	}
	
	// value semantics		( copy semantics )
	// reference semantics	( pointer )
	// move semantics		( move )

										
	return 0;
}