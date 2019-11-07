/*
	�۾� ��� �񵿱� ���α׷���
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
		auto fut = async([] { return 1 + 2; });	// main �����尡 ���ϴ� �Ͱ� ������ ���� ��
												// return �� �ٷ� �Ǵ� �۾��� �ƴ϶� �󸶳� �ɸ��� �� -> �̷��� int�� �޾ƿ´ٴ� ���� �˰� �ִ´�
		cout << fut.get() << endl;				// �̷��� get�Լ��� ���ϰ��� ���� ������ ��ٸ���
	}	

	// future and promise
	{
		//sync���� future�� ����ϱ� ���� promise ����
		promise<int> prom;
		auto fut = prom.get_future();			// ����� �Ǹ� future�� ������ �� ����

		auto t = std::thread([](std::promise<int>&& prom)			//async�� ����ص� ������, �׷��� ��ó�� �׳� future<int> t�� �Ǿ����
		{
			prom.set_value(1 + 2);
		}, std::move(prom));

		cout << fut.get() << endl;
		t.join();								// thread�� ����ϴ� �� �±� ������ join �ʿ�
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
		//f2.join();										// async�� main ~ f1.start ~ f2.start ~f2.end ~ f1.end����
															// thread�� f1.start ~ f2.start ~ main ~ f2.end ~ f1.end ������, ������ sync(thread) �� async�� ���α��� ���̰� �ִ�
	}

	return 0;
}