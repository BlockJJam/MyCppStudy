/*
	멀티쓰레딩은 여러 쓰레드들이 하나의 메모리구조를 공유가능 -> 같은 메모리의 이용을 통한 문제발생 : race condition
		-> 해결방안 : atomic, scoped_lock
*/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>
#include <atomic>				// atomic : 쪼갤 수 없다 , 데이터 처리를 3단계로 쪼갰던 것을 1단계로 합치기

using namespace std;

//mutex mtx;

int main()
{
	//atomic<int> shared_memory(0);
	// atomic 안쓰는 방식 : mutex
	int shared_memory(0);
	auto count_func = [&]() {
		for (int i = 0; i < 1000; i++)
		{
			this_thread::sleep_for(chrono::milliseconds(1));
			//shared_memory++;								// atomic의 ++를 사용
			//shared_memory.fetch_add(1);
			/*mtx.lock();
			shared_memory++;
			mtx.unlock();*/

			//lock_guard lock(mtx);							// C++17 이전버전
			//scoped_lock lock(mtx);						// C++17 이후버전(권장) 범위안에서만 작동하는 lock함수
			
			shared_memory++;								// sleep_for를 빼면 2000이 나옴, 왜? lock guard가 된것이 아니라 병렬처리 없이 한 스레드씩 빠르게 동작한 것
		}
	};

	thread t1 = thread(count_func);
	thread t2 = thread(count_func);

	t1.join();
	t2.join();								// 2000 이 나오지 않음, 하나가 더하는 동안 다른 하나도 더하면 결국 1번만 더함

	cout << "After" << endl;
	cout << shared_memory << endl;	

	return 0;
}