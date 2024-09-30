#ifndef _HOSPITAL_H
#define _HOSPITAL_H



#include <iostream>
#include <string.h>
#include <set>
#include <vector>
#include <stdbool.h>
using namespace std;

class Doctor;
class Nurse;
class Patient;
class Department;
class Articls;
class Researcher;
class ResearchInstitute;
class Date;

const int MAX_VISIT_PURPOSE = 257;

class Hospital
{
public:
	Hospital();
	Hospital(const Hospital& other) = delete;
	Hospital& operator=(const Hospital o) = delete;
	~Hospital();

	vector<Department*>& getAllDepartments();
	set<Patient*>& getAllPatients();
	ResearchInstitute* getResearchInstitute()    const;
	int getCurrentNumOfDepartments()             const;
	int getNumOfPatient()                        const;

	void addDepartment(const string& name_department) noexcept(false);//1
	void addNurse(const string& name, int departmentNum, int yearsOfExperience) noexcept(false);//2
	void addDoctor(const string& name, const string& expertise, int departmentNum, int type, int surgonesNum = 0) noexcept(false);//3
	void addVisit(const Date& b_date, const string& name, char gendr, int id, const Date& v_date, Doctor* p_doc,
		          const string& visitPurpose, int Num_departmrnt, int roomNum = -1, int isfasting = 0) noexcept(false);//4
	void addResearcher(const string& name, int type, int numDepartment = 0, const string& expertise = "", int surgonesNum = 0) noexcept(false);//5
	void addArticale(const string& nameArticle, const string& nameMagzine,const Date& d, Researcher* r) noexcept(false);//6
	void showAllPatientInDepartment();//7
	void showAllCrewMembers();//8
	void showAllResearchers();//9
	void patientSearchById(int id) noexcept(false);//10
	void showAllDoctorResearchers() const;

	



	
	Patient* isPatientExsits(int id);
	Doctor* findDoctor(int id);
	Researcher* findResearcher(int id) noexcept(false);
	void addPatientToHospital(Patient* p_patient);
	Doctor* findDDoctorInDepartment(int employeeNum, int departmentNum);
	Doctor* findDSurgeonInDepartment(int employeeNum, int departmentNum);


	/****************************functions for files************************************/
	void save(ofstream& out);
	void load(ifstream& inFile);
	void saveNurses(ofstream& outfile, Department& d);
	void saveDoctors(ofstream& outfile , Department&d);
	void loadAllNurses(ifstream& inFile , Department& d);
	void loadDoctors(ifstream& inFile , Department& d);


	//******************************function for hardcoded*********************************//
	void addArticale(const char* name, const char* mName, int EmployeeNum);

private:
	vector<Department*> m_allDepartments;
	set<Patient*> m_allPatients;
	ResearchInstitute* m_researchInstitute;

};

#endif // !_HOSPITAL_H
