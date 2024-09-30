#ifndef _EmptyStrExc_H
#define _EmptyStrExc_H

#include <exception>
#include <stdbool.h>
using namespace std;

class EmptyStrExc : public exception
{
public:
	EmptyStrExc() {};
	~EmptyStrExc() {};
	bool operator()() {}
	/*while (B_d <= 0 || B_d > 31)
	{
		cout << "day has to be between 1-31!. choose another value\n ";
		cin >> B_d;
	}
	while (B_m < 1 || B_m > 12)
	{
		cout << "month has to be between 1-31!.choose another value\n ";
		cin >> B_m;
	}
	while (B_y < 1900 || B_y > 2023)
	{
		cout << "year has to be between 1900-2023!.choose another value\n ";
		cin >> B_y;
	}*/

private:

};






#endif // !_EmptyStrExc_H

