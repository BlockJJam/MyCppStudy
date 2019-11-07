// ���� typedef ����ϴٰ� C++ 11�� �ͼ� Using�� ���

#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

int main()
{
	typedef double distance_t;			// distance_t�� �� �� double��� �ּ�ó�� ����ϰڴ�( ���� )
	
	double my_distance;
	distance_t home2work;
	distance_t home2school;

	// �ؿ� ǥ�� �ʹ� ��ƴ�
	// std::vector<std::pair<std::string, int>> pairlist; 
	vector<pair<string, int>> pairlist1;
	vector<pair<string, int>> pairlist2;

	// ����
	// typedef vector<pair<string, int>> pairlist_t;
	// or
	using pairlist_t = vector<pair<string,int>>;

	return 0;
}