#ifndef _DOCTORRESEARCHER_H
#define _DOCTORRESEARCHER_H

#include <iostream>
#include <string.h>
using namespace std;

#include "Employee.h"
#include "Doctor.h"
#include "Researcher.h"

#pragma warning(disable: 4996)

class DoctorResearcher : public Doctor, public Researcher
{
public:
	DoctorResearcher(const string& p_name, const string& p_expertise, Department& p_department);
	DoctorResearcher(ifstream& infile, Department& p_department);
	DoctorResearcher(const DoctorResearcher& other) = delete;
	virtual ~DoctorResearcher() {}
	const DoctorResearcher& operator=(const DoctorResearcher& other) = delete;


	virtual void show() const override;
	virtual void toOs(ostream& os) const override;
	virtual void fromOs(istream& in) override;

private:
};

#endif // !_DOCTORRESEARCHER_H

