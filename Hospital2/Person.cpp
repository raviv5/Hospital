#include "Person.h"
using namespace std;

Person::Person(const string& p_name)
{
	setName(p_name);
	if (all_of(m_name.begin(), m_name.end(), [](char c) {return c == ' '; }))
	{
		throw "Invalid name ! person name cant be empty !";
	}
	if (any_of(m_name.begin(), m_name.end(), [](char c) {return c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
		|| c == '6' || c == '7' || c == '8' || c == '9' || c == '0'; }))
	{
		throw "Invalid name ! Name contain a digit !";
	}
}

Person::Person(ifstream & infile)
{
	infile >> *this;

}

const char* Person::getName()   const
{
	return m_name.c_str();
}


void Person::setName(const string& p_name)
{
	m_name = p_name;
}

void Person::show()  const
{
	cout << (typeid(*this).name() + 6) << "--> \n"
		<< "Name:" << m_name << endl;

}

 ostream&  operator <<(ostream& os, const Person& p)
{
	 if (typeid(os) == typeid(ofstream))
	 {
		 os << p.m_name << endl;
	 }
	 else
	 {
		 os<< (typeid(p).name() + 6) << "--> \n"
			 << "Name:" << p.m_name << endl;
	 }
	 p.toOs(os);
	 return os;
}


 ifstream& operator >>(ifstream& in,  Person& p)
 {
	     in.ignore();
		 getline(in, p.m_name);
		 p.fromOs(in);
		 return in;

  }