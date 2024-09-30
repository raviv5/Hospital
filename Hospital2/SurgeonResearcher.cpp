#include "SurgeonResearcher.h"

//----------------------------------------------------------------------------//
SurgeonResearcher::SurgeonResearcher(const string& p_name, const string& p_expertise, Department& p_department, int p_surgeriesNum) :
	Employee(p_name),
	Doctor(p_name, p_expertise, p_department),
	Surgeon(p_name, p_expertise, p_department, p_surgeriesNum),
	Researcher(p_name)
{

}
//----------------------------------------------------------------------------//
SurgeonResearcher::SurgeonResearcher(ifstream& infile,Department& p_department) :Employee(infile),
Doctor(infile, p_department),
Surgeon(infile, p_department),
Researcher(infile)
{
	fromOs(infile);
}

//----------------------------------------------------------------------------//
void SurgeonResearcher::show() const
{
	Surgeon::show();
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void SurgeonResearcher::toOs(ostream& os) const
{
	Surgeon::toOs(os);
	os << arr;
	
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
void SurgeonResearcher::fromOs(istream& in)
{
}


//----------------------------------------------------------------------------//