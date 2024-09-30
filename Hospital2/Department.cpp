#include "Department.h"
#include "Doctor.h"
#include"Surgeon.h"
#include "SurgeonResearcher.h"
#include"DoctorResearcher.h"
#include "Nurse.h"
#include "Patient.h"


//----------------------------------------------------------------------------//
Department::Department(const string& p_name)
{
	setName(p_name);
	if (all_of(m_name.begin(), m_name.end(), [](char c) {return c == ' '; }))
	{
		throw "Invalid name ! Department name cant be empty !";
	}
}
//----------------------------------------------------------------------------//

Department :: Department(ifstream& in)
{
	in >> *this;
}


//----------------------------------------------------------------------------//
Department::Department(Department& other) : m_name(nullptr)
{
	*this = other;
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
Department::Department(Department&& other)
{
	*this = std::move(other);
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
Department::~Department()
{
	for (Doctor* i : m_doctorsArr)
	{
		delete i;
	}

	for (Nurse* i : m_nursesArr)
	{
		delete i;

	}
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const Department& Department:: operator=(const Department& other)
{
	if (this != &other)
	{
		m_name = other.m_name;
		m_doctorsArr = other.m_doctorsArr;
		m_nursesArr = other.m_nursesArr;
		m_patientsArr = other.m_patientsArr;
	}
	return *this;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const Department& Department:: operator=(Department&& other)
{
	if (this != &other)
	{
		std::swap(m_name, other.m_name);
		std::swap(m_doctorsArr, other.m_doctorsArr);
		std::swap(m_nursesArr, other.m_nursesArr);
		std::swap(m_patientsArr, other.m_patientsArr);
	}
	return *this;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
vector<Doctor*>& Department::getDoctorsArray() 
{
	return m_doctorsArr;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
int Department::getcurrentNumOfDoctors()   const
{
	return m_doctorsArr.size();
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
vector<Nurse*>& Department::getNursesArray()  
{
	return m_nursesArr;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
int Department::getcurrentNumOfNurses()  const
{
	return m_nursesArr.size();
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
vector<Patient*> Department::getPatientsArray() const
{
	return m_patientsArr;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
int Department::getcurrentNumOfPatients() const
{
	return m_patientsArr.size();
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void  Department::setName(const string& p_name)
{
	m_name = p_name;
}
//----------------------------------------------------------------------------//




//----------------------------------------------------------------------------//
void Department::removeDoctor(Doctor* doctor)
{
	vector<Doctor*>::iterator found = find(m_doctorsArr.begin(), m_doctorsArr.end(), doctor);
	if (found != m_doctorsArr.end())
	{
		m_doctorsArr.erase(found);
	}

}
//----------------------------------------------------------------------------//




//----------------------------------------------------------------------------//
void Department::removeNurse(Nurse* nurse)
{
	vector<Nurse*>::iterator found = find(m_nursesArr.begin(), m_nursesArr.end(), nurse);
	if (found != m_nursesArr.end())
	{
		m_nursesArr.erase(found);
	}
}
//----------------------------------------------------------------------------//





//----------------------------------------------------------------------------//
void Department::removePatient(Patient* patient)
{
	vector<Patient*>::iterator found = find(m_patientsArr.begin(), m_patientsArr.end(), patient);
	if (found != m_patientsArr.end())
	{
		m_patientsArr.erase(found);
	}
}
//----------------------------------------------------------------------------//


const Department& Department::operator+=(Doctor& doc)
{
	if (m_doctorsArr.size() == m_doctorsArr.capacity())
	{
		m_doctorsArr.reserve(m_doctorsArr.size() * 2);
	}
	m_doctorsArr.push_back(&doc);
	return *this;
}
const Department& Department::operator+=(Nurse& nur)
{
	if (m_nursesArr.size() == m_nursesArr.capacity())
	{
		m_nursesArr.reserve(m_nursesArr.size() * 2);
	}
	m_nursesArr.push_back(&nur);
	return *this;
}
const Department& Department::operator+=(Patient& patient)
{
	if (m_patientsArr.size() == m_patientsArr.capacity())
	{
		m_patientsArr.reserve(m_patientsArr.size() * 2);
	}
	m_patientsArr.push_back(&patient);
	return *this;
}
int Department::operator<(const Department& dep)
{
	return strcmp(m_name.c_str(), dep.m_name.c_str());
}
bool Department::operator==(const Department& dep)
{
	return (strcmp(m_name.c_str(), dep.m_name.c_str()) == 0);
}
const char* Department::getName() const
{
	return m_name.c_str();
}




ostream& operator <<(ostream& os, const Department& d)
{
	if (typeid(os) == typeid(ofstream))
	{
		os << d.m_name << " ";
	}
	else
	{
		os << "Name:" << d.m_name << endl;
	}
	return os;
}


istream& operator >>(istream& in, Department& d)
{
	in >> d.m_name;
	return in;

}
