#ifndef EMPLOYEE_H_
#define EMPLOYEE_H_

#pragma warning(disable: 4996)

#include <iostream>
#include <string.h>
#include "Person.h"

class Employee :public Person
{
public:

	Employee(ifstream & infile);
	Employee(const string& p_name);
	Employee(const Employee& other) = delete;
	const Employee& operator=(const Employee& other) = delete;
	virtual ~Employee() {};

	int         getEmployeeNum()     const;
	int         getNumOfEmployees()  const;

	virtual void show() const override;

	virtual void toOs(ostream& os) const override;
	virtual void fromOs(istream& in) override;

protected:
	static int counter;
	int m_employeeNum;
};


#endif // !EMPLOYEE_
