#include "Department.h"
#include "Doctor.h"

//----------------------------------------------------------------------------//
Doctor::Doctor(const string& p_name, const string& p_expertise, Department& p_department) :m_department(p_department), Employee(p_name)
{
	setExpertise(p_expertise);
	if (all_of(m_expertise.begin(), m_expertise.end(), [](char c) {return c == ' '; }))
	{
		throw "Invalid expertise ! doctor expertise cant be empty !";
	}
	if (any_of(m_expertise.begin(), m_expertise.end(), [](char c) {return c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
		|| c == '6' || c == '7' || c == '8' || c == '9' || c == '0'; }))
	{
		throw "Invalid expertise ! expertise cant contain a digit !";
	}
}
//----------------------------------------------------------------------------//
Doctor::~Doctor() {}
//----------------------------------------------------------------------------//
const char* Doctor::getExpertise() const
{
	return m_expertise.c_str();
}
//----------------------------------------------------------------------------//
Doctor::Doctor(ifstream & infile, Department& p_department):Employee(infile),m_department(p_department)
{
	
	fromOs(infile);

}

//----------------------------------------------------------------------------//
const Department& Doctor::getDepartments() const
{
	return m_department;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Doctor::show() const
{
	Employee::show();
	cout << "Expertise:" << m_expertise << endl;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Doctor::setExpertise(const string& p_expertise)
{
	m_expertise = p_expertise;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Doctor::setDepartment(Department& p_department)
{
	m_department.removeDoctor(this);
	m_department = p_department;
	m_department += *this;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Doctor::toOs(ostream& os) const
{
	Employee::toOs(os);
	if (typeid(os) == typeid(ofstream))
	{
		os  << m_expertise << endl;//*
	}
	else
	{
		os << "Expertise:" << m_expertise << endl;
	}
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//??
void Doctor::fromOs(istream& in)
{

	in.ignore();
	getline(in, this->m_expertise);
}
//----------------------------------------------------------------------------//