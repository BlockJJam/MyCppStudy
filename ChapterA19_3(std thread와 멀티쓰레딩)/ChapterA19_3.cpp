/*
	thread�� ��Ƽ������
		-> �ϳ��� ���α׷��� ����� �������� �����带 �����Ͽ�, �������� �ھ Ȱ��
		-> ���� ��Ƽ ���μ��� -> ���� cpu�� ���κ��忡 �ȾƼ� Ȱ��, 2) ��Ʈ��ũ�� �̿��ؼ� ���� pc�� �����ؼ��� Ȱ��, ( �л�ó�� )
		->
*/

#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <mutex>

using namespace std;

//mutex�� ��ȣ�����Ͽ� ���ó���� ������ �� �� �ֵ���
mutex mtx;

int main()
{
	const int num_pro = std::thread::hardware_concurrency();
	//cout << std::thread::hardware_concurrency() << endl;			// ���μ��� ����
	cout << std::this_thread::get_id() << endl;						// ���� ����ϴ� �������� ���̵�

	//std::thread t1 = std::thread([]() {
	//	cout << std::this_thread::get_id() << endl;
	//	while (true) {}
	//});															// ������ ���� ���� : ���� ���ξ������ ������ ���

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
	//});															// id�� ���ü� ���α׷������� ���� �� �����尡 ���ÿ� ����, ( id�� �ٹٲ޾��� �޿� ������ ����)

	/*t1.join();
	t2.join();
	t3.join();
	t4.join();*/

	// vector�� ������ ����
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

	// ���� ������ �ڹ��� ����( mutex���� ��ȣ��������)
	auto work_func = [](const string &name)
	{
		for (int i = 0; i < 5; i++)
		{
			this_thread::sleep_for(chrono::milliseconds(100));

			mtx.lock();				// �ƹ��� ���ǵ�� ����
			cout << name << " " << this_thread::get_id() << " is  working " << i << endl;
			mtx.unlock();			// �پ��� Ǯ��
		}
	};

	//work_func("JackJack");
	//work_func("Dash");
	// ��ó�� �ϸ� Dash�� JackJack �ڿ� ������ݾ�? ��Ƽ���������� ���� ���ϱ�

	thread t1 = thread(work_func, "JackJack");
	thread t2 = thread(work_func, "Dash");

	t1.join();
	t2.join();

	return 0;
}