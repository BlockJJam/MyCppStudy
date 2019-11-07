/*
	thread와 멀티쓰레딩
		-> 하나의 프로그램을 만들고 여러개의 쓰레드를 관리하여, 여러개의 코어를 활용
		-> 예전 멀티 프로세싱 -> 여러 cpu를 메인보드에 꽂아서 활용, 2) 네트워크를 이용해서 여러 pc를 연동해서도 활용, ( 분산처리 )
		->
*/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

//mutex로 상호배제하여 사용처리를 나눠서 할 수 있도록
mutex mtx;

int main()
{
	const int num_pro = std::thread::hardware_concurrency();
	//cout << std::thread::hardware_concurrency() << endl;			// 프로세서 개수
	cout << std::this_thread::get_id() << endl;						// 현재 사용하는 스레드의 아이디

	//std::thread t1 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true) {}
	//});															// 오류가 나는 이유 : 원래 메인쓰레드와 소통이 없어서

	//std::thread t2 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true) {}
	//});

	//std::thread t3 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true) {}
	//});

	//std::thread t4 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true) {}
	//});															// id가 동시성 프로그래밍으로 인해 각 스레드가 동시에 실행, ( id가 줄바꿈없이 쭈욱 나오는 이유)

	/*t1.join();
	t2.join();
	t3.join();
	t4.join();*/

	// vector로 스레드 생성
	/*vector<std::thread> my_threads;
	my_threads.resize(num_pro);

	for (auto & e : my_threads)										
	{
		e= std::thread([]() {
			cout << std::this_thread::get_id() << endl;
			while (true) {}
		});
	}*/

	/*for (auto & e : my_threads)
		e.join();*/

	// 글자 순서가 뒤밖인 이유( mutex없이 상호배제없이)
	auto work_func = [](const string &name)
	{
		for (int i = 0; i < 5; i++)
		{
			this_thread::sleep_for(chrono::milliseconds(100));

			mtx.lock();				// 아무도 못건들게 막고
			cout << name << " " << this_thread::get_id() << " is  working " << i << endl;
			mtx.unlock();			// 다쓰면 풀고
		}
	};

	//work_func("JackJack");
	//work_func("Dash");
	// 위처럼 하면 Dash는 JackJack 뒤에 실행되잖아? 멀티스레딩으로 같이 일하기

	thread t1 = thread(work_func, "JackJack");
	thread t2 = thread(work_func, "Dash");

	t1.join();
	t2.join();

	return 0;
}