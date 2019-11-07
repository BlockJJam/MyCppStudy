/*
	작업 기반 비동기 프로그래밍
	async, future, promise
*/

#include <iostream>
#include <thread>
#include <future>   // async, future, promise
using namespace std;

int main()
{
	// multi-threading
	{
		int result;
		std::thread t([&] {result = 1 + 2; });
		t.join();
		cout << result << endl;
	}

	// task-based parallelism
	{
		// std::future<int> fut = ...
		auto fut = async([] { return 1 + 2; });	// main 스레드가 일하는 것과 별도로 일을 함
												// return 이 바로 되는 작업이 아니라 얼마나 걸릴지 모름 -> 미래에 int로 받아온다는 것을 알고만 있는다
		cout << fut.get() << endl;				// 미래에 get함수로 리턴값을 받을 때까지 기다린다
	}	

	// future and promise
	{
		//sync에서 future를 사용하기 위해 promise 선언
		promise<int> prom;
		auto fut = prom.get_future();			// 약속이 되면 future로 가져올 수 있음

		auto t = std::thread([](std::promise<int>&& prom)			//async를 사용해도 되지만, 그러면 위처럼 그냥 future<int> t가 되어버림
		{
			prom.set_value(1 + 2);
		}, std::move(prom));

		cout << fut.get() << endl;
		t.join();								// thread를 사용하는 건 맞기 때문에 join 필요
	}

	{
		auto f1 = std::async([] {
			cout << "async1 start" << endl;
			this_thread::sleep_for(chrono::seconds(2));
			cout << "async1 end" << endl;
		});

		auto f2 = std::async([] {
			cout << "async2 start " << endl;
			this_thread::sleep_for(chrono::seconds(1));
			cout << "async2 end" << endl;
		});

		std::cout << "Main function" << endl;
		//f1.join();
		//f2.join();										// async는 main ~ f1.start ~ f2.start ~f2.end ~ f1.end지만
															// thread는 f1.start ~ f2.start ~ main ~ f2.end ~ f1.end 순서로, 엄밀히 sync(thread) 와 async는 내부구현 차이가 있다
	}

	return 0;
}