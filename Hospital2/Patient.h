#ifndef _PATIENT_H
#define _PATIENT_H

#include "date.h"
class Departnent;
class Doctor;
class VisitCard;
#include "Person.h"
#include <vector>

#include <iostream>
#include <string.h>
#pragma warning(disable: 4996)

class Patient :public Person
{
public:
    Patient(int d, int m, int y, const string& p_name, char p_gender, int p_id) noexcept(false);
    Patient(const Date& p_birthDay, const string& p_name, char p_gender, int p_id);
    Patient(const Patient& other) = delete;
    const Patient& operator=(const Patient& other) = delete;
    virtual ~Patient();

    const vector<VisitCard*>& getVisits()        const;
    const int      getId()                           const;
    const Date     getBirthDay()                     const;
    const char     getGender()                       const;
    const int      getNumOfVisitis()                 const;

    void      addVisit(VisitCard* const p_visitCard);
    void      setId(int p_id);
    void      setBirthDay(int d, int m, int y);
    void      setGender(char gender);

    virtual void show() const override;
    void ShowAllVisits();

    bool operator==(Patient& other);
    bool operator<(Patient& other);

    static bool isValidGender(char theGender);

private:

    int m_id;
    Date m_BirthDay;
    char m_gender;
    vector <VisitCard*> m_arrVisit;
};




#endif // !_PATIENT_H