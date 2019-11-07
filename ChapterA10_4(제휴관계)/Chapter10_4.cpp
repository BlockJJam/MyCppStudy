/*
	제휴관계
	어느쪽이 명확히 주가 되고 부가 되는지 모를 경우
	예시 - 의사/환자 관계
		
		용도외엔 무관 관계
		다른 클래스에 속할 수 있는가?			Yes
		멤버의 존재를 클래스가 관리하는가?		No
		단방향 or 양방향
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Doctor;			// 전방선언: 서로 동등관계로 서로가 필요한 제휴관계

class Patient
{
private:
	string _name;
	vector<Doctor*> _doctors;

public:
	Patient(string name_in)
		: _name(name_in)
	{}

	void addDoctor(Doctor * new_doctor)
	{
		_doctors.push_back(new_doctor);
	}

	void meetDoctors();

	friend class Doctor;
};

class Doctor
{
private:
	string _name;
	vector<Patient*> _patients;
public:
	Doctor(string name_in)
		: _name(name_in)
	{}

	void addPatient(Patient * new_patient)
	{
		_patients.push_back(new_patient);
	}

	void meetPatients()
	{
		for (auto & ele : _patients)
		{
			cout << "Meet patient : " << ele->_name << endl;
		}
	}

	friend class Patient;
};

void Patient::meetDoctors()
{
	for (auto & ele : _doctors)
	{
		cout << "Meet doctor : " << ele->_name << endl;
	}
}

int main()
{
	Patient *p1 = new Patient("Jack Jack");
	Patient *p2 = new Patient("Dash");
	Patient *p3 = new Patient("Violet");

	Doctor *d1 = new Doctor("Doctor K");
	Doctor *d2 = new Doctor("Doctor J");

	p1->addDoctor(d1);
	d1->addPatient(p1);

	p2->addDoctor(d1);
	d2->addPatient(p1);

	p2->addDoctor(d1);
	d1->addPatient(p2);

	// patients meet doctors
	p1->meetDoctors();

	// doctors meet patients
	d1->meetPatients();
	// deletes
	delete p1;
	delete p2;
	delete p3;

	delete d1;
	delete d2;

	return 0;
}