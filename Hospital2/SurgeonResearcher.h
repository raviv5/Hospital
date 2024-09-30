#ifndef SURGEONRESEARCHER_H_
#define SURGEONRESEARCHER_H_

#include <iostream>
#include <string.h>
#include "Doctor.h"
#include "Surgeon.h"
#include"Researcher.h"

#pragma warning(disable: 4996)

class SurgeonResearcher : public Surgeon, public Researcher
{
public:
	SurgeonResearcher(const string& p_name, const string& p_expertise, Department& p_department, int p_surgeriesNum = 0);
	SurgeonResearcher(ifstream& infile, Department& p_department);
	SurgeonResearcher(const Surgeon& other) = delete;
	virtual ~SurgeonResearcher() {}
	const SurgeonResearcher& operator=(const SurgeonResearcher& other) = delete;

	virtual void show() const override;
	virtual void toOs(ostream& os) const override;
	virtual void fromOs(istream& in) override;

private:
};

#endif // !SURGEONRESEARCHER_H_