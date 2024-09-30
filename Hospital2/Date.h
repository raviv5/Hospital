#ifndef _DATE_H
#define _DATE_H

#include <iostream>
#include<fstream>
using namespace std;
#pragma warning(disable: 4996)


class Date
{
public:
	Date() {}
	Date(int p_day, int p_month, int p_year);

	int getDay()              const;
	int getMonth()            const;
	int getYear()             const;

	bool setDay(int p_day);
	bool setMonth(int p_month);
	bool setYear(int p_year);

	friend ostream& operator<<(ostream& os, const Date& date);
	friend istream& operator>>(istream& is, Date& date);


	void show()                const;

private:
	int m_day;
	int m_month;
	int m_year;
};

#endif // !_DATE_H



