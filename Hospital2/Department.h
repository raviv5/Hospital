#ifndef _DEPARTMENT_H
#define _DEPARTMENT_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;


class Doctor;
class Nurse;
class Patient;

class Department
{
public:

	Department(const string& p_name) noexcept(false);// c'tor
	Department(Department& other); //copy c'tor
	Department(Department&& other); //move c'tor
	Department(ifstream& in);
	~Department();//d'tor

	const Department& operator=(const Department& other);
	const Department& operator=(Department&& other);

	const char* getName()                     const;

	vector<Doctor*>&  getDoctorsArray()             ;
	vector<Nurse*> &  getNursesArray()              ;
	vector<Patient*> getPatientsArray()            const;

	int getcurrentNumOfDoctors()          const;
	int getcurrentNumOfNurses()           const;
	int getcurrentNumOfPatients()         const;


	

	void removeDoctor(Doctor * doctor);
	void removeNurse(Nurse * nurse);
	void removePatient(Patient * patient);

	void setName(const string& p_name);

	

	const Department& operator+=(Doctor& doc);
	const Department& operator+=(Nurse& nur);
	const Department& operator+=(Patient& patient);
	int operator<(const Department& dep);
	bool operator==(const Department& dep);

	friend ostream& operator <<(ostream& os, const Department& d);

	friend istream& operator >>(istream& in, Department& d);
	



private:
	string m_name;
	vector<Doctor*> m_doctorsArr;
	vector<Nurse*> m_nursesArr;
	vector<Patient*> m_patientsArr;
};


#endif // !_DEPARTMENT_H