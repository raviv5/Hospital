#include "Nurse.h"
#include "Department.h"


//----------------------------------------------------------------------------//
Nurse::Nurse(const string& p_name, Department& p_department, int p_yearsOfExperience) :Employee(p_name), m_department(p_department), m_yearsOfExperience(p_yearsOfExperience)
{
	if (m_yearsOfExperience < 0)
	{
		throw "The number of years of experience cannot be negative !";
	}
}
//----------------------------------------------------------------------------//
Nurse::Nurse(ifstream & infile,Department& p_department):Employee(infile), m_department(p_department)
{
	fromOs(infile);

}


//----------------------------------------------------------------------------//
int  Nurse::getYearsOfExperience()  const
{
	return m_yearsOfExperience;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const Department& Nurse::getDepartment() const
{
	return m_department;
}
//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//
void Nurse::setYearsOfExperience(int p_yearsOfExperience)
{
	m_yearsOfExperience = p_yearsOfExperience;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Nurse::setDeparyment(Department& p_department)
{
	m_department.removeNurse(this);
	m_department = p_department;
	m_department += *this;
}
//----------------------------------------------------------------------------//




//----------------------------------------------------------------------------//
bool Nurse::updateYearsExperience(int years)
{
	if (m_yearsOfExperience + years < 0)
	{
		return false;
	}
	else
	{
		m_yearsOfExperience += years;
		return true;
	}
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Nurse::show() const
{
	Employee::show();
	cout << "Years of experience:" << m_yearsOfExperience << endl;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
 void Nurse:: toOs(ostream& os) const
 {
	 Employee::toOs(os);
	 if (typeid(os) == typeid(ofstream))
	 {
		 os << m_yearsOfExperience << " ";
	 }
	 else
	 {
		 os << "Years of experience:" << m_yearsOfExperience << endl;
	 }
 }
 //----------------------------------------------------------------------------//

 //----------------------------------------------------------------------------//
 void Nurse:: fromOs(istream& in) 
 {
	 
	 in  >>m_yearsOfExperience;
 }
 //----------------------------------------------------------------------------//
