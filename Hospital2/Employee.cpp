#include "Employee.h"
#include "Person.h"

int Employee::counter = 0;


//----------------------------------------------------------------------------//
Employee::Employee(const string& p_name) :Person(p_name)
{

	m_employeeNum = ++counter;
}
//----------------------------------------------------------------------------//
Employee::Employee(ifstream & infile):Person(infile)
{
	fromOs(infile);

}



//----------------------------------------------------------------------------//
int Employee::getEmployeeNum()  const
{
	return m_employeeNum;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
int Employee::getNumOfEmployees()  const
{
	return counter;
}
//----------------------------------------------------------------------------//




//----------------------------------------------------------------------------//
void Employee::show() const
{
	Person::show();
	cout << "Employee number: " << m_employeeNum << endl;
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
 void Employee:: toOs(ostream& os) const 
{
	 if (typeid(os) == typeid(ofstream))
	 {
		 os << m_employeeNum << " ";
     }
	 else
	 {
		 os << "Employee number: " << m_employeeNum << endl;
	 }
}


 void Employee:: fromOs(istream& in)  
{
	 in >> m_employeeNum;
	 counter++;
}

//----------------------------------------------------------------------------//