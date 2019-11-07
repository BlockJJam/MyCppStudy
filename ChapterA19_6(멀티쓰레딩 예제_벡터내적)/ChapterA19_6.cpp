/*
	멀티스레딩 예제( 벡터 내적 계산 ) : 이차원 벡터 삼차원 벡터의 내적 계산
*/

#include <iostream>
#include <chrono>
#include <mutex>
#include <random>
#include <thread>
#include <utility>
#include <vector>
#include <atomic>
#include <future>
#include <numeric>			// std::inner_product
#include <execution>		// parallel execution

using namespace std;

mutex mtx;

void dotProductNaive(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, unsigned long long & sum)
{
	for (unsigned i = i_start; i < i_end; i++)
		sum += v0[i] * v1[i];
}

void dotProductLock(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, unsigned long long & sum)
{
	// scoped_lock이 scope 어디에 놨는지에 속도가 차이남( 밖이 지금함수는 더 빠름 ),  근데 밖에다 두면 동기식으로 바뀜 ( 멀티스레딩 X )
	//scoped_lock lock(mtx);							// 0.14초지만 동기식임

	for (unsigned i = i_start; i < i_end; i++)
	{
		scoped_lock lock(mtx);							// 4초로 느리지만 비동기식

		sum += v0[i] * v1[i];
	}
}

void dotProductAtomic(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end, atomic<unsigned long long> & sum)
{
	for (unsigned i = i_start; i < i_end; i++)
		sum += v0[i] * v1[i];
}

auto dotProductFuture(const vector<int>& v0, const vector<int>& v1, const unsigned i_start, const unsigned i_end)
{
	int sum = 0;
	for (unsigned i = i_start; i < i_end; i++)
		sum += v0[i] * v1[i];

	return sum;
}

int main()
{
/*
	v0 = {1,2,3};
	v1 = {4,5,6};
	v0_dot_v1 = 1*4 + 2*5 + 3*6;
	
	
*/
	const long long n_data = 100000000;
	const unsigned n_threads = 4;

	// initialize vectors
	std::vector<int> v0, v1;
	v0.reserve(n_data);
	v1.reserve(n_data);

	random_device seed;
	mt19937 engine(seed());

	uniform_int_distribution<> uniformDist(1, 10);

	for (long long i = 0; i < n_data; i++)
	{
		v0.push_back(uniformDist(engine));
		v1.push_back(uniformDist(engine));
	}

	// numeric의 함수를 그대로 사용( 정답 )
	cout << "std::inner_product" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		const auto sum = std::inner_product(v0.begin(), v0.end(), v1.begin(), 0ull);

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}

	//// 순진하게 프로그래밍했을 때?	-> 답이 안나옴
	//cout << "naive" << endl;
	//{
	//	const auto sta = chrono::steady_clock::now();
	//	
	//	unsigned long long sum = 0;
	//	vector<thread> threads;
	//	threads.resize(n_threads);
	//	const unsigned n_per_thread = n_data / n_threads;
	//	for (unsigned t = 0; t < n_threads; t++)
	//		threads[t] = std::thread(dotProductNaive, std::ref(v0), std::ref(v1), t*n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

	//	for (unsigned t = 0; t < n_threads; ++t)
	//		threads[t].join();

	//	const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

	//	cout << dur.count() << endl;
	//	cout << sum << endl;
	//	cout << endl;
	//}

	//// lock guard를 사용한다면?
	//cout << "Lock guard" << endl;
	//{
	//	const auto sta = chrono::steady_clock::now();

	//	unsigned long long sum = 0;
	//	vector<thread> threads;
	//	threads.resize(n_threads);
	//	const unsigned n_per_thread = n_data / n_threads;
	//	for (unsigned t = 0; t < n_threads; t++)
	//		threads[t] = std::thread(dotProductLock, std::ref(v0), std::ref(v1), t*n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

	//	for (unsigned t = 0; t < n_threads; ++t)
	//		threads[t].join();

	//	const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

	//	cout << dur.count() << endl;
	//	cout << sum << endl;
	//	cout << endl;
	//}

	////Atomic을 사용한다면?
	//cout << "Atomic" << endl;
	//{
	//	const auto sta = chrono::steady_clock::now();

	//	atomic<unsigned long long> sum = 0;				// lock guard를 변수에 선언!
	//	vector<thread> threads;
	//	threads.resize(n_threads);
	//	const unsigned n_per_thread = n_data / n_threads;
	//	for (unsigned t = 0; t < n_threads; t++)
	//		threads[t] = std::thread(dotProductAtomic, std::ref(v0), std::ref(v1), t*n_per_thread, (t + 1) * n_per_thread, std::ref(sum));

	//	for (unsigned t = 0; t < n_threads; ++t)
	//		threads[t].join();

	//	const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

	//	cout << dur.count() << endl;
	//	cout << sum << endl;
	//	cout << endl;
	//}

	// task-based parellelism(future)으로 한다면?
	//cout << "Future" << endl;
	//{
	//	const auto sta = chrono::steady_clock::now();

	//	unsigned long long sum = 0;				// lock guard를 변수에 선언!

	//	vector<future<int>> futures;
	//	futures.resize(n_threads);

	//	const unsigned n_per_thread = n_data / n_threads;

	//	for (unsigned t = 0; t < n_threads; t++)
	//		futures[t] = std::async(dotProductFuture, std::ref(v0), std::ref(v1), t*n_per_thread, (t + 1) * n_per_thread);		// 왜 더 빠를까? main과는 별도로 4개가 서로 동작하므로

	//	for (unsigned t = 0; t < n_threads; ++t)
	//		sum += futures[t].get();

	//	const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

	//	cout << dur.count() << endl;
	//	cout << sum << endl;				
	//	cout << endl;							// 더 빠른 시간이 측정됨!
	//}

	// dot product의 병렬버전이 transform_reduce lib가 있다
	cout << "std::transform_reduce" << endl;
	{
		const auto sta = chrono::steady_clock::now();

		//const auto sum = std::transform_reduce(std::execution::seq, v0.begin(), v0.end(), v1.begin(), 0ull);		// seq은 순차적으로 돌림(병렬X)
		const auto sum = std::transform_reduce(std::execution::par, v0.begin(), v0.end(), v1.begin(), 0ull);			// par은 병렬적으로 돌림(순차X)

		const chrono::duration<double> dur = chrono::steady_clock::now() - sta;

		cout << dur.count() << endl;
		cout << sum << endl;
		cout << endl;
	}
	return 0;
}