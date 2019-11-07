/*
	실행시간 측정
		-> 클래스 하나 만들어놓고 쓰면 됨
		-> debug 모드와 release 모드가 다른데 release모드가 더 빠르다 ( 배포 모드니까 )
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Timer													// 타이머 클래스 하나만 있어도 쓰기 편하다
{
	using clock_t = chrono::high_resolution_clock;
	using second_t = chrono::duration<double, ratio<1>>;

	chrono::time_point<clock_t> start_time = clock_t::now();

public :
	void elapsed()
	{
		chrono::time_point<clock_t> end_time = clock_t::now();

		cout << chrono::duration_cast<second_t>(end_time - start_time).count() << endl;
	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(1000000);
	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;
	
	shuffle(begin(vec), end(vec), mersenne_engine);			//순서 섞기

	/*for (auto &e : vec) cout << e << " ";
	cout << endl;*/

	Timer timer;											//타이머 설정

	sort(begin(vec), end(vec));

	timer.elapsed();										// 지나간 시간 측정

	/*for (auto &e : vec) cout << e << " ";
	cout << endl;*/


	return 0;
}
