#ifndef PERSON_H_
#define PERSON_H_

#pragma warning(disable: 4996)
#include <exception>
#include <iostream>
#include<fstream>
#include <string>
#include <algorithm>
using namespace std;

class Person
{
public:

	Person(ifstream & infile);
	Person(const string& p_name) noexcept(false);
	virtual ~Person() {};
	const char* getName()   const;
	void  setName(const string& p_name) noexcept(false);


	virtual void show()  const = 0;

	friend ostream& operator <<(ostream& os, const Person& p);
	virtual void toOs(ostream & os) const{}

	friend ifstream& operator >>(ifstream& in,  Person& p);
	virtual void fromOs(istream& in)  {}

protected:
	string m_name;

};
#endif // !PERSON_H_
