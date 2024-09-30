#ifndef _Surgeon_h
#define _Surgeon_h

#pragma warning(disable: 4996)
#include <iostream>
#include <string.h>
#include "Doctor.h"

class Surgeon :virtual public Doctor
{
public:
	Surgeon(ifstream& infile, Department& p_department);
	Surgeon(const string& p_name, const string& p_expertise, Department& p_department, int p_surgeriesNum = 0) noexcept(false);
	Surgeon(const Surgeon& other) = delete;
	const Surgeon& operator=(const Surgeon& other) = delete;
	virtual ~Surgeon() {}

	int getSurgeriesNum()       const;
	bool setSurgeriesNum(int p_surgeriesNum);
	bool addToSurgeriesNum(int num);

	virtual void show() const override;

	virtual void toOs(ostream& os) const override;
	virtual void fromOs(istream& in) override;

protected:
	int m_surgeriesNum;
};
#endif // !_Surgeon_h
