#include "Patient.h"
#include"VisitCard.h"
#include "Date.h"

//----------------------------------------------------------------------------//
Patient::Patient(int d, int m, int y, const string& p_name, char p_gender, int p_id) : Person(p_name), m_BirthDay(d, m, y)
{
    setGender(p_gender);
    setId(p_id);
    if (!Patient::isValidGender(p_gender))
    {
        throw "Invaid gender !";
    }
    if (m_id <= 0)
    {
        throw "Invalid id !";
    }
}
//----------------------------------------------------------------------------//
Patient::Patient(const Date& p_birthDay, const string& p_name, char p_gender, int p_id) : Person(p_name), m_BirthDay(p_birthDay)
{
    setId(p_id);
    setGender(p_gender);
    if (!Patient::isValidGender(p_gender))
    {
        throw "Invaid gender !";
    }
    if (m_id <= 0)
    {
        throw "Invalid id !";
    }
}

//----------------------------------------------------------------------------//
Patient::~Patient()
{

    for (VisitCard* i : m_arrVisit) // +
    {
        delete i;
    }


}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const vector<VisitCard*>& Patient::getVisits()        const
{
    return m_arrVisit;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const int      Patient::getId()                           const
{
    return m_id;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const Date   Patient::getBirthDay()                     const
{
    return m_BirthDay;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
const char     Patient::getGender()                       const
{
    return m_gender;
}




//----------------------------------------------------------------------------//
const int     Patient::getNumOfVisitis()                 const
{
    return m_arrVisit.size();
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void      Patient::addVisit(VisitCard* const p_visitCard)
{

    if (m_arrVisit.size() == m_arrVisit.capacity())
    {
        m_arrVisit.reserve(m_arrVisit.capacity() * 2);
    }

    m_arrVisit.push_back(p_visitCard);

}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void      Patient::setId(int p_id)
{
    m_id = p_id;

}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void   Patient::setBirthDay(int d, int m, int y)
{
    m_BirthDay.setDay(d);
    m_BirthDay.setMonth(m);
    m_BirthDay.setYear(y);
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void      Patient::setGender(char gender)
{
    m_gender = gender;
}
//----------------------------------------------------------------------------//




//----------------------------------------------------------------------------//
void Patient::show() const
{
    Person::show();
    cout << "Id: " << m_id << endl << "Gender: " << m_gender << endl << "Birthday: ";
    m_BirthDay.show();
    cout << endl;
}
//----------------------------------------------------------------------------//



//----------------------------------------------------------------------------//
void Patient::ShowAllVisits()
{
    int count = 1;
    for (VisitCard* i : m_arrVisit)
    {
        cout << endl;
        cout << "Visit No." << count << ":" << endl << *i << endl;
        cout << endl;
        count++;
    }
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
bool Patient:: operator==(Patient& other)
{
    if (m_id == other.m_id)
    {
        return true;
    }
    return false;
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
bool Patient:: operator<(Patient& other)
{
    return (m_id < other.m_id);
}
//----------------------------------------------------------------------------//
bool Patient::isValidGender(char theGender)
{
    return (theGender == 'F' || theGender == 'M' || theGender == 'f' || theGender == 'm');
}