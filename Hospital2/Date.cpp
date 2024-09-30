#include "date.h"

enum months{JANUARY=1, FEBRUARY, MARCH , APRIL , MAY , JUNE , JULY , AUGUST , SEPTEMBER , OCTOBER , NOVEMBER , DECEMBER};
const int MAX_YEAR=2023;
const int MAX_MONTH = 12;
const int MAX_DAY_G = 31;
const int MAX_DAY_AJSN = 30;
const int MAX_DAY_F = 29;

const int MIN_YEAR = 1900;
const int MIN_MONTH = 1;
const int MIN_DAY = 1;


//------------------------------------------------------------------------------------//
Date::Date(int p_day, int p_month, int p_year)
{
	m_day = p_day;
	m_month = p_month;
	m_year = p_year;

}
//------------------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
int Date::getDay() const
{
	return m_day;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
int Date::getMonth() const
{
	return m_month;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
int Date::getYear() const
{
	return m_year;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
bool Date::setDay(int p_day)
{
	if (p_day < MIN_DAY || p_day > MAX_DAY_G)
	{
		return false;
	}
	else
	{
		m_day = p_day;
		return true;
	}
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
bool Date::setMonth(int p_month)
{
	if (p_month < JANUARY || p_month > DECEMBER)

	{
		return false;
	}
	else
	{
		m_month = p_month;
		return true;
	}
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
bool Date::setYear(int p_year)
{
	if (p_year < MIN_YEAR || p_year > MAX_YEAR)
	{

		return false;
	}
	else
	{
		m_year = p_year;
		return true;
	}
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void Date::show() const
{
	cout << (m_day < 10 ? "0" : "") << m_day << "/" << (m_month < 10 ? "0" : "") << m_month << "/" << m_year << " ";
}
//----------------------------------------------------------------------------//

ostream& operator<<(ostream& os, const Date& date)
{
	if (typeid(os) == typeid(ofstream))
	{
		os << date.m_day << " " << date.m_month << " " << date.m_year ;
	}
	else
	{
		os << (date.getDay() < 10 ? "0" : "") << date.getDay() << "/" << (date.getMonth() < 10 ? "0" : "") << date.getMonth() << "/" << date.getYear() << " ";
	}
	return os;
}
//----------------------------------------------------------------------------//
istream& operator>>(istream& is, Date& date)
{
	if (typeid(is) == typeid(ifstream))
	{
		is >> date.m_day >> date.m_month >> date.m_year;
	}
	else
	{
		char delimeter;
		is >> date.m_day >> delimeter >> date.m_month >> delimeter >> date.m_year;
		if (date.m_day <= MIN_DAY- 1 || date.m_day > MAX_DAY_G || date.m_month <= MIN_MONTH-1 || date.m_month > MAX_MONTH || date.m_year < MIN_YEAR || date.m_year > MAX_YEAR)
		{
			throw "Invalid Date !";
		}
		if ((date.m_month == APRIL || date.m_month == JUNE || date.m_month == SEPTEMBER || date.m_month == NOVEMBER) && date.m_day == MAX_DAY_G)
		{
			throw "Invalid Date ! the day of the month must be in the range 1 - 30 !";
		}
		if (date.m_month == FEBRUARY && date.m_day > MAX_DAY_F)
		{
			"Invalid Date ! the day of the month must be in the range 1 - 29 !";
		}
	}
	return is;
}