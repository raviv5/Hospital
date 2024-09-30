#include "VisitCard.h"
#include "Date.h"
#include "Doctor.h"
#include "Patient.h"

//----------------------------------------------------------------------------//
VisitCard::VisitCard(Doctor* d, const Date& p_birthDay, const Date& p_visitDay, int p_id, const string& p_name, const string& p_visitPurpose, const char p_gender)
	:m_BirthDay(p_birthDay), m_visitDate(p_visitDay)
{
	m_mainDoc = d;
	setId(p_id);
	setPatientName(p_name);
	setVisitPurpose(p_visitPurpose);
	setGender(p_gender);
	if (all_of(m_visitPurpose.begin(), m_visitPurpose.end(), [](char c) {return c == ' '; }))
	{
		throw "Invalid expertise ! doctor expertise cant be empty !";
	}
	if (all_of(m_PatientName.begin(), m_PatientName.end(), [](char c) {return c == ' '; }))
	{
		throw "Invalid patient name !patient name cant be empty !";
	}
	if (any_of(m_PatientName.begin(), m_PatientName.end(), [](char c) {return c == '1' || c == '2' || c == '3' || c == '4' || c == '5'
		|| c == '6' || c == '7' || c == '8' || c == '9' || c == '0'; }))
	{
		throw "Invalid patient name ! patient name cant contain !";
	}
	if (!Patient::isValidGender(p_gender))
	{
		throw "Invalid gender !";
	}
}
//----------------------------------------------------------------------------//
VisitCard::VisitCard(const VisitCard& other) :m_BirthDay(other.m_BirthDay), m_visitDate(other.m_visitDate)
{
	*this = other;
}
//----------------------------------------------------------------------------//
VisitCard::VisitCard(VisitCard&& other) :m_BirthDay(other.m_BirthDay), m_visitDate(other.m_visitDate)
{
	*this = std::move(other);
}



//----------------------------------------------------------------------------//
Date VisitCard::getDate()                            const
{
	return m_visitDate;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
Doctor* VisitCard::getDoctor()                 const
{
	return m_mainDoc;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const string& VisitCard::getVisitPurpose()             const
{
	return m_visitPurpose;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const int VisitCard::getId()                         const
{
	return m_id;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const Date VisitCard::getBirthDat()                  const
{
	return m_BirthDay;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const char VisitCard::getGender()                    const
{
	return m_gender;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const string& VisitCard::getPatientName()              const
{
	return m_PatientName;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void VisitCard::setDate(int d, int m, int y)
{
	m_visitDate.setDay(d);
	m_visitDate.setMonth(m);
	m_visitDate.setYear(y);
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void VisitCard::setDoctor(Doctor* p_Doctor)
{
	m_mainDoc = p_Doctor;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void VisitCard::setVisitPurpose(const string& p_purpose)
{
	m_visitPurpose = p_purpose;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void VisitCard::setPatientName(const string& p_namePatient)
{
	m_PatientName = p_namePatient;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void VisitCard::setBirthDay(int d, int m, int y)
{
	m_visitDate.setDay(d);
	m_visitDate.setMonth(m);
	m_visitDate.setYear(y);
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
bool VisitCard::setGender(char gender)
{
	if (gender == 'F' || gender == 'M')
	{
		m_gender = gender;
		return true;
	}
	return false;

}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void VisitCard::setId(int p_id)
{
	m_id = p_id;
}
//----------------------------------------------------------------------------//
const VisitCard& VisitCard::operator=(const VisitCard& other)
{
	if (this != &other)
	{
		m_BirthDay = other.m_BirthDay;
		m_visitDate = other.m_visitDate;
		m_PatientName = other.m_PatientName;
		m_visitPurpose = other.m_visitPurpose;
		m_id = other.m_id;
		m_gender = other.m_gender;
		m_mainDoc = other.m_mainDoc;
	}
	return *this;
}
//----------------------------------------------------------------------------//

const VisitCard& VisitCard::operator=(VisitCard&& other)
{
	m_BirthDay = other.m_BirthDay;
	m_visitDate = other.m_visitDate;
	m_PatientName = other.m_PatientName;
	m_visitPurpose = other.m_visitPurpose;
	m_id = other.m_id;
	m_gender = other.m_gender;
	m_mainDoc = other.m_mainDoc;

	return *this;
}


//----------------------------------------------------------------------------//
void VisitCard::show()                              const
{
	cout << "Visit Date:";
	m_visitDate.show();
	cout << endl;
	cout << "Visit Purpose: " << m_visitPurpose << endl << "main doctor: " << m_mainDoc->getName() << endl;
	cout << "patient detalis:" << endl;
	cout << "Name: " << m_PatientName << endl << "Gender: " << m_gender << endl << "Id: " << m_id << endl << "Birth Day: ";
	m_BirthDay.show();
}
//----------------------------------------------------------------------------//


ostream& operator<<(ostream& os, const VisitCard& card)
{

	os << "Name: " << card.m_PatientName << endl << "Id: " << card.m_id << endl << "Gender: " << card.m_gender << endl << "BirthDay: " << card.m_BirthDay << endl << "Visit Date: " << card.m_visitDate << endl << "Purpose Of Visit: " << card.m_visitPurpose << endl << "main doctor:" << card.m_mainDoc->getName() << endl;
	card.toOs(os);
	return os;

}