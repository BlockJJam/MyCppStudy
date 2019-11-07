/*
	우리가 만든 프로그램이 원하는 만큼 성능이 안나오는 경우, 더 개선을 하고 싶은경우 -> 프로파일링 하기
		-> cpu 따로, 메모리 따로 프로파일링 해주기

*/

#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <numeric>

using namespace std;

void func1()
{
	long long sum = 0;
	for (unsigned i = 0; i < 1'000'000; i++)
		sum += i;

	cout << sum << endl;
}

void func2()
{
	long long sum = 0;
	for (unsigned i = 0; i < 1'000'000'000; i++)
		sum += i;

	cout << sum << endl;
}

void run()
{
	func1();
	func2();
}

int main()
{
	// cpu 사용량을 측정 프로파일링
	//run();

	// 힙메모리 프로파일링
	int *d = new int[10000];
	float *f = new float[100];

	delete[] d;
	delete[] f;
	
	return 0;
}