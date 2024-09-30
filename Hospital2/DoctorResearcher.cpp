#include "DoctorResearcher.h"

//----------------------------------------------------------------------------//
DoctorResearcher::DoctorResearcher(const string& p_name, const string& p_expertise, Department& p_department) : Doctor(p_name, p_expertise, p_department), Researcher(p_name), Employee(p_name)
{

}
//----------------------------------------------------------------------------//
DoctorResearcher::DoctorResearcher(ifstream& infile,Department& p_department):Doctor(infile, p_department), Researcher(infile), Employee(infile)
{
    fromOs(infile);
}

//----------------------------------------------------------------------------//
void DoctorResearcher::show() const
{
	Employee::show();
	cout << "Expertise:" << m_expertise << endl;
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
void DoctorResearcher::toOs(ostream& os) const
{
	Employee::toOs(os);
	if (typeid(os) == typeid(ofstream))
	{
		os << m_expertise << endl << arr;
	}
	else
	{
		os << "Expertise:" << m_expertise << endl;
	}
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//??
void DoctorResearcher::fromOs(istream& in)
{
	/*Employee::fromOs(in);
	in >> m_expertise;
	in.ignore();
	getline(in, this->m_expertise);
	if (typeid(in) == typeid(ifstream))
	{
		in >> arr ;
	}*/

}
//----------------------------------------------------------------------------//