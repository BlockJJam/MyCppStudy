#include <iostream>
#include <array>

using namespace std;
int main()
{
	int scores[] = { 56,38,78,18,30 };
	const int num_students = sizeof(scores) / sizeof(int);

	int total_score = 0;
	int max_score = 0;
	for (int i = 0; i < num_students; i++)
	{
		total_score += scores[i];
		max_score = (max_score < scores[i]) ? scores[i] : max_score;
	}
	double avg_score = static_cast<double>(total_score) / num_students;

	cout << "max_score : " << max_score << endl;
	cout << "avg_score : " << avg_score << endl;

	return 0;
}