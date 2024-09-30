#ifndef _DOCTOR_H
#define _DOCTOR_H

#include <iostream>
#include <string.h>
#include "Employee.h"
class Department;// forward declaration

#pragma warning(disable: 4996)

class Doctor : virtual public Employee
{
public:

	Doctor(ifstream& infile, Department& p_department);
	Doctor(const string& p_name, const string& p_expertise, Department& p_department) noexcept(false);
	virtual ~Doctor();
	const Doctor& operator=(const Doctor& other) = delete;
	Doctor(const Doctor& other) = delete;

	void setExpertise(const string& p_expertise);
	void setDepartment(Department& p_departments);

	const char* getExpertise()            const;
	const Department& getDepartments()    const;

	virtual void show() const override;
	virtual void toOs(ostream& os) const override;
	virtual void fromOs(istream& in) override;

protected:

	string m_expertise;
	Department& m_department;

};




#endif // !_DOCTOR_H



