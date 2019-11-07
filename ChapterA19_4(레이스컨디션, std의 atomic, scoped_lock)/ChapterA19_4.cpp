/*
	��Ƽ�������� ���� ��������� �ϳ��� �޸𸮱����� �������� -> ���� �޸��� �̿��� ���� �����߻� : race condition
		-> �ذ��� : atomic, scoped_lock
*/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <atomic>				// atomic : �ɰ� �� ���� , ������ ó���� 3�ܰ�� �ɰ��� ���� 1�ܰ�� ��ġ��

using namespace std;

//mutex mtx;

int main()
{
	//atomic<int> shared_memory(0);
	// atomic �Ⱦ��� ��� : mutex
	int shared_memory(0);
	auto count_func = [&]() {
		for (int i = 0; i < 1000; i++)
		{
			this_thread::sleep_for(chrono::milliseconds(1));
			//shared_memory++;								// atomic�� ++�� ���
			//shared_memory.fetch_add(1);
			/*mtx.lock();
			shared_memory++;
			mtx.unlock();*/

			//lock_guard lock(mtx);							// C++17 ��������
			//scoped_lock lock(mtx);						// C++17 ���Ĺ���(����) �����ȿ����� �۵��ϴ� lock�Լ�
			
			shared_memory++;								// sleep_for�� ���� 2000�� ����, ��? lock guard�� �Ȱ��� �ƴ϶� ����ó�� ���� �� �����徿 ������ ������ ��
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();								// 2000 �� ������ ����, �ϳ��� ���ϴ� ���� �ٸ� �ϳ��� ���ϸ� �ᱹ 1���� ����

	cout << "After" << endl;
	cout << shared_memory << endl;	

	return 0;
}