#include "Surgeon.h"


//----------------------------------------------------------------------------//
Surgeon::Surgeon(const string& p_name, const string& p_expertise, Department& p_department, int p_surgeriesNum) : Employee(p_name), Doctor(p_name, p_expertise, p_department)
{
	
	if (!setSurgeriesNum(p_surgeriesNum))
	{
		throw "A number of surgery cannot be negative !";
	}

}
//----------------------------------------------------------------------------//
Surgeon::Surgeon(ifstream& infile,Department& p_department):Doctor(infile, p_department),Employee(infile)
{
	fromOs(infile);
}
//----------------------------------------------------------------------------//
int Surgeon::getSurgeriesNum()       const
{
	return m_surgeriesNum;
}
//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//
bool Surgeon::setSurgeriesNum(int p_surgeriesNum)
{
	if (p_surgeriesNum >= 0)
	{
		m_surgeriesNum = p_surgeriesNum;
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
bool Surgeon::addToSurgeriesNum(int num)
{
	if (num >= 0)
	{
		m_surgeriesNum += num;
		return true;
	}
	return false;
}
//----------------------------------------------------------------------------//


void Surgeon::show() const
{
	Doctor::show();
	cout << "Number of surgeries " << m_surgeriesNum << endl;
}



//----------------------------------------------------------------------------//
void Surgeon::toOs(ostream& os) const
{
	Doctor::toOs(os);
	if (typeid(os) == typeid(ofstream))
	{
		os << m_surgeriesNum << " ";
	}
	else
	{
		os << "Number of surgeries " << m_surgeriesNum << endl;
	}
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//??
void Surgeon::fromOs(istream& in)
{
	
	in >> m_surgeriesNum;
}
//----------------------------------------------------------------------------//