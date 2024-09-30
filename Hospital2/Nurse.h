#ifndef NURSE_H_
#define NURSE_H_

#pragma warning(disable: 4996)
#include <iostream>
#include <string.h>

class Department;//// forward declaration
#include "Employee.h"


class Nurse : public Employee
{
public:

	Nurse(ifstream& infile, Department& p_department);
	Nurse(const string& p_name, Department& m_department, int p_yearsOfExperience) noexcept(false);
	Nurse(const Nurse& other) = delete;
	const Nurse& operator=(const Nurse& other) = delete;

	int getYearsOfExperience()                             const;
	const Department& getDepartment()                      const;

	void setYearsOfExperience(int p_yearsOfExperience);
	void setDeparyment(Department& p_department);

	bool updateYearsExperience(int years);
	virtual void show() const override;

	virtual void toOs(ostream& os) const override;
	virtual void fromOs(istream& in) override;


private:
	int              m_yearsOfExperience;
	Department& m_department;


};




#endif // !NURSE_H_
