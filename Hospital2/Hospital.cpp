#include "hospital.h"
#include "department.h"
#include "doctor.h"
#include "nurse.h"
#include "patient.h"
#include "researcher.h"
#include "Article.h"
#include "ResearchInstitute.h"
#include "VisitCard.h"
#include "Surgeon.h"
#include"DoctorResearcher.h"
#include "SurgeryVisit.h"
#include "SurgeonResearcher.h"


const int MAX_LEN_NAME_PERSON = 20;
const int MAX_LEN_NAME_DEPARTMENT = 20;
const int MAX_LEN_NAME_ARTICLE = 30;
const int MAX_LEN_NAME_MAGZINE = 30;



//----------------------------------------------------------------------------//
Hospital::Hospital()
{
	m_researchInstitute = new ResearchInstitute();
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
Hospital::~Hospital()
{
	delete m_researchInstitute;
	for (Department* i : m_allDepartments)
	{
		delete i;
	}

	for (Patient* i : m_allPatients)
	{

		delete i;
	}

}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
vector <Department*>& Hospital::getAllDepartments()
{
	return m_allDepartments;
}

//----------------------------------------------------------------------------//
int Hospital::getCurrentNumOfDepartments() const
{
	return m_allDepartments.size();
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
ResearchInstitute* Hospital::getResearchInstitute() const
{
	return m_researchInstitute;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::addDepartment(const string& name)
{
	Department* newDepartment = new Department(name);
	m_allDepartments.push_back(newDepartment);
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::addNurse(const string& name, int departmentNum, int yearsOfExperience)
{
	vector<Department*>::iterator itr = m_allDepartments.begin() + departmentNum;
	Nurse* newNurse = new Nurse(name, **itr, yearsOfExperience);
	**itr += *newNurse;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::addDoctor(const string& name, const string& expertise, int departmentNum, int type, int surgonesNum)
{

	Doctor* newDoctor = nullptr;
	vector<Department*>::iterator itr = m_allDepartments.begin() + departmentNum;

	switch (type)
	{
	case 1:
	{
		newDoctor = new Doctor(name, expertise, **itr);
		**itr += *newDoctor;
		break;
	}
	case 2:
	{

		newDoctor = new Surgeon(name, expertise, **itr, surgonesNum);
		**itr += *newDoctor;
		break;
	}
	case 3:
	{
		SurgeonResearcher* newSurgeonResearcher;
		newSurgeonResearcher = new SurgeonResearcher(name, expertise, **itr, surgonesNum);
		m_researchInstitute->addResearcher(newSurgeonResearcher);
		**itr += *newSurgeonResearcher;
		break;
	}
	case 4:
	{
		DoctorResearcher* newDoctorResearcher;
		newDoctorResearcher = new DoctorResearcher(name, expertise, **itr);
		m_researchInstitute->addResearcher(newDoctorResearcher);
		**itr += *newDoctorResearcher;
		break;
	}
	default:
	{
		break;
	}
	}
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::addVisit(const Date& b_date, const string& name, char gendr, int id, const Date& v_date, Doctor* p_doc,
	const string& visitPurpose, int Num_department, int roomNum, int isfasting)
{
	//to create a patient first
	Patient* p = new Patient(b_date, name, gendr, id);//main change function;
	addPatientToHospital(p);  //main

	vector<Department*> ::iterator itr = m_allDepartments.begin() + Num_department;  //func

	(**itr) += (*p);   //add patient to department.
	VisitCard* newVisit;
	if (roomNum == -1)
	{
		newVisit = new VisitCard(p_doc, p->getBirthDay(), v_date, p->getId(), p->getName(), visitPurpose, p->getGender());

	}
	else
	{
		newVisit = new SurgeryVisit(VisitCard(p_doc, p->getBirthDay(), v_date, p->getId(), p->getName(), visitPurpose, p->getGender()), roomNum, isfasting);

	}
	p->addVisit(newVisit);
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::addResearcher(const string& name, int type, int numDepartment, const string& expertise, int surgonesNum)
{

	Researcher* newResearcher = nullptr;
	switch (type)
	{
	case 1:
	{
		newResearcher = new Researcher(name);
		break;
	}
	case 2:
	{
		vector<Department*>::iterator itr = m_allDepartments.begin() + numDepartment;
		newResearcher = new DoctorResearcher(name, expertise, **itr);
		(**itr).getDoctorsArray().push_back(dynamic_cast<Doctor*> (newResearcher));
		break;
	}

	case 3:
	{
		vector<Department*>::iterator itr = m_allDepartments.begin() + numDepartment;
		newResearcher = new SurgeonResearcher(name, expertise, **itr, surgonesNum);
		(**itr).getDoctorsArray().push_back(dynamic_cast<Doctor*> (newResearcher));
		
		break;
	}

	default:
	{
		cout << "wrong choice " << endl;
		break;
	}
	}
	m_researchInstitute->addResearcher(newResearcher);

}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::addArticale(const string& nameArticle, const string& nameMagzine, const Date& d, Researcher* r)
{

	Article newArticle(d, nameMagzine, nameArticle);
	r->addArticle(newArticle);


}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::showAllPatientInDepartment()
{
	int num;
	cout << "select a department from the following list\n";
	int count = 1;
	for (Department* i : m_allDepartments)
	{
		cout << count++ << "." << i->getName() << endl;
	}
	cin >> num;
	while (!(num > 0 && num <= m_allDepartments.size()))
	{
		cout << "incorrect value, choose again" << endl;
		cin >> num;
	}
	num = num - 1;
	vector<Department*>::iterator itr = m_allDepartments.begin() + num;

	int pNum = (*itr)->getcurrentNumOfPatients();
	if (pNum == 0)
	{
		cout << "there is no patients in this department" << endl;
	}
	vector<Patient*> pArr = (*itr)->getPatientsArray();
	count = 1;
	for (Patient* i : pArr)
	{
		cout << "patient#" << count++ << ": ";
		i->show();
	}

}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::showAllCrewMembers()
{
	cout << "Doctors:" << endl;
	for (Department* i : m_allDepartments)
	{
		int numD = i->getcurrentNumOfDoctors();
		vector <Doctor*> arr = i->getDoctorsArray();
		int count = 1;
		for (Doctor* j : arr)
		{
			cout << "Doctor#" << count++ << ":\n";
			j->show();
			cout << "\n\n";

		}
	}
	cout << "Nurses:" << endl;
	for (Department* i : m_allDepartments)
	{
		int numN = i->getcurrentNumOfNurses();
		vector<Nurse*> arr = i->getNursesArray();
		int count = 1;
		for (Nurse* j : arr)
		{
			cout << "Nurse#" << count++ << ":\n";
			j->show();
			cout << "\n\n";
		}
	}


}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::showAllResearchers()
{

	vector<Researcher*> arr = m_researchInstitute->getArr();

	int count = 1;
	for (Researcher* i : arr)
	{
		cout << "No." << count++ << endl;
		i->show();


	}
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::patientSearchById(int id)
{
	bool foundP = false;
	for (Patient* i : m_allPatients)
	{
		if (i->getId() == id)
		{
			foundP = true;
			cout << "Patient's name:" << i->getName() << endl;
			i->ShowAllVisits();

		}
	}
	if (foundP == false)
	{
		throw "The patient is not found in the system !";
	}

}
//----------------------------------------------------------------------------//






//----------------------------------------------------------------------------//
Researcher* Hospital::findResearcher(int id)
{

	vector<Researcher*> arr = m_researchInstitute->getArr();
	for (Researcher* i : arr)
	{

		if (i->getEmployeeNum() == id)
		{
			return i;
		}

	}
	return nullptr;

}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
int Hospital::getNumOfPatient()                        const
{
	return m_allPatients.size();
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::addPatientToHospital(Patient* p_patient)
{
	m_allPatients.insert(p_patient);
}
//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//
Patient* Hospital::isPatientExsits(int id)
{

	for (Patient* i : m_allPatients)
	{

		if (i->getId() == id)
		{
			return i;
		}

	}
	return nullptr;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
Doctor* Hospital::findDoctor(int employeeNum)
{
	for (Department* i : m_allDepartments)
	{
		vector<Doctor*> arr = i->getDoctorsArray();
		for (Doctor* j : arr)
		{
			if (j->getEmployeeNum() == employeeNum)
			{
				return j;
			}
		}
	}
	return nullptr;

}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
Doctor* Hospital::findDDoctorInDepartment(int employeeNum, int departmentNum)
{
	Doctor* d = nullptr;

	vector<Department*>::iterator itr = m_allDepartments.begin() + departmentNum;
	int numD = (*itr)->getcurrentNumOfDoctors();
	vector<Doctor*> arr = (*itr)->getDoctorsArray();

	for (Doctor* j : arr)
	{
		if (j->getEmployeeNum() == employeeNum)
		{
			d = j;
		}
	}
	return d;

}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
Doctor* Hospital::findDSurgeonInDepartment(int employeeNum, int departmentNum)
{
	Doctor* d = nullptr;

	vector<Department*>::iterator itr = m_allDepartments.begin() + departmentNum;
	int numD = (*itr)->getcurrentNumOfDoctors();
	vector<Doctor*> arr = (*itr)->getDoctorsArray();

	for (Doctor* j : arr)
	{
		if (typeid((*j)) == typeid(Surgeon) || typeid((*j)) == typeid(SurgeonResearcher))
		{
			if (j->getEmployeeNum() == employeeNum)
			{
				d = j;
			}
		}
	}
	return d;

}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital::showAllDoctorResearchers() const
{
	vector<Researcher*> arr = m_researchInstitute->getArr();
	for (Researcher* i : arr)
	{
		if (typeid((*i)) == typeid(DoctorResearcher) || typeid((*i)) == typeid(SurgeonResearcher))
		{
			i->show();
		}
	}
}
//----------------------------------------------------------------------------//



//------------------------------------------------------------------------------------------//
//*****************************function for hardcoded******************************//
void Hospital::addArticale(const char* name, const char* mName, int EmployeeNum)
{

	Article* newArticle = new Article(Date(12,12,1999), mName, name);

	Researcher* r = findResearcher(EmployeeNum);

	r->addArticle(*newArticle);
}
//-------------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital:: save(ofstream& out)
{
	out << m_allDepartments.size() << endl;
	for (auto i : m_allDepartments )
	{
		out << *i<<endl;
		saveNurses(out , *i);
		saveDoctors(out, *i);
		out << endl;
	}
	int count = 0;
	for (auto i : m_researchInstitute->getArr())
	{
		if (typeid(Researcher) == typeid(*i))
		{
			count++;
		}
	}
	out << count << endl;
	
	for (auto i : m_researchInstitute->getArr())
	{
		
		if (typeid(Researcher) == typeid(*i))
		{
			out << *i<<endl;
		}
	}
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital:: load(ifstream& inFile)
{
	int numOfDepartment;
	inFile >> numOfDepartment;
	m_allDepartments.reserve(numOfDepartment);
	for (int i = 0; i < numOfDepartment; i++)
	{
		Department* newDepartment = new Department(inFile);
	  m_allDepartments.push_back( newDepartment);
	  loadAllNurses(inFile, *newDepartment);
	  loadDoctors(inFile, *newDepartment);
	}
	
	
	int researchersNum;
	inFile >> researchersNum;
	
	for (int i=0 ; i<researchersNum ; i++)
	{
		Researcher* newResearcher = new Researcher(inFile);
		m_researchInstitute->getArr().push_back(newResearcher);
	}
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Hospital ::saveDoctors(ofstream& outfile , Department & d)
{
	vector<Doctor*> doctorsArray = d.getDoctorsArray();
	outfile << doctorsArray.size() << endl;

	for (auto i : doctorsArray)
	{
		outfile << (typeid(*i).name() + 6) << endl;
		outfile << (*i);

	}
}
//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//
void Hospital::loadDoctors(ifstream& infile,Department& d)
{
	int size;
	char type[20];
	
	infile >> size;
	
	d.getDoctorsArray().reserve(size);
	Doctor* newDoctor;

	for (int i = 0; i < size ;i++)
	{
		infile >> type;
		
		if (strcmp(type, typeid(Doctor).name() + 6) == 0)
		{
			newDoctor = new Doctor(infile, d);
			d.getDoctorsArray().push_back(newDoctor);
		}
		else if (strcmp(type, typeid(Surgeon).name() + 6) == 0)
		{
			newDoctor = new Surgeon(infile, d);
			d.getDoctorsArray().push_back(newDoctor);
		}
		else if (strcmp(type, typeid(SurgeonResearcher).name() + 6) == 0)
		{
			newDoctor = new SurgeonResearcher(infile, d);
			d.getDoctorsArray().push_back(newDoctor);
			m_researchInstitute->getArr().push_back(dynamic_cast<Researcher*>(newDoctor));
		}
		else
		{
			newDoctor = new DoctorResearcher(infile, d);
			d.getDoctorsArray().push_back(newDoctor);
			m_researchInstitute->getArr().push_back(dynamic_cast<Researcher*>( newDoctor));
		}

	}
}
//----------------------------------------------------------------------------//





//----------------------------------------------------------------------------//
void Hospital::saveNurses(ofstream& outfile , Department& d)
{
	vector<Nurse*> nursesArray = d.getNursesArray();
	outfile << nursesArray.size() << endl;
	for (auto i : nursesArray)
	{
		outfile << (*i) << endl;

	}
}
//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//
void Hospital::loadAllNurses(ifstream& inFile,Department& d)
{
	int size, i;
	inFile >> size;
	d.getNursesArray().reserve(size);
	for (i = 0;i < size ; i++)
	{
		
		Nurse* newNurse = new Nurse(inFile, d);
		d.getNursesArray().push_back(newNurse);
		inFile.ignore();
	}
}
//----------------------------------------------------------------------------//