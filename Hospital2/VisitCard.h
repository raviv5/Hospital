#ifndef _VISITCARD_H
#define _VISITCARD_H

#include <iostream>
#include <string.h>
#include "date.h"
#include "doctor.h"


#pragma warning(disable: 4996)

class VisitCard
{
public:

	VisitCard(Doctor* d, const Date& p_birthDay, const Date& p_visitDay, int p_id, const string& p_name, const string& p_visitPurpose, const char p_gender) noexcept(false);
	VisitCard(const VisitCard& other);
	VisitCard(VisitCard&& other);
	virtual ~VisitCard() {};

	Date getDate()                              const;
	Doctor* getDoctor()                         const;
	const string& getVisitPurpose()             const;
	const int getId()                           const;
	const Date getBirthDat()                    const;
	const char getGender()                      const;
	const string& getPatientName()              const;

	void setDate(int d, int m, int y);
	void setDoctor(Doctor* p_Doctor);
	void setVisitPurpose(const string& p_purpose);
	void setPatientName(const string& p_namePatient);
	void setBirthDay(int d, int m, int y);
	bool setGender(char gender);
	void setId(int p_id);

	const VisitCard& operator=(const VisitCard& other);
	const VisitCard& operator=(VisitCard&& other);
	virtual void toOs(ostream& os) const {}
	void show()                              const;

	friend ostream& operator<<(ostream& os, const VisitCard& card);

protected:
	Date m_visitDate;
	Date m_BirthDay;
	Doctor* m_mainDoc = nullptr;
	string  m_visitPurpose;
	string  m_PatientName;
	int m_id;
	char m_gender;
};

#endif // !_VISITCARD_H
