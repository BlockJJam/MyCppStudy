// 보통 typedef 사용하다가 C++ 11에 와서 Using을 사용

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
	typedef double distance_t;			// distance_t를 쓸 때 double대신 주석처럼 사용하겠다( 별명 )
	
	double my_distance;
	distance_t home2work;
	distance_t home2school;

	// 밑에 표현 너무 어렵다
	// std::vector<std::pair<std::string, int>> pairlist; 
	vector<pair<string, int>> pairlist1;
	vector<pair<string, int>> pairlist2;

	// 개선
	// typedef vector<pair<string, int>> pairlist_t;
	// or
	using pairlist_t = vector<pair<string,int>>;

	return 0;
}