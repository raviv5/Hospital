#ifndef _ResearchInstitute_h
#define _ResearchInstitute_h
#include <vector>
using namespace std;

class Researcher;

class ResearchInstitute
{
public:
	ResearchInstitute() {}
	~ResearchInstitute();
	ResearchInstitute(ResearchInstitute& other) = delete;
	ResearchInstitute& operator=(ResearchInstitute& other) = delete;


	int getSLog();
	vector<Researcher*>& getArr();
	void addResearcher(Researcher* ptr_res);


private:
	vector<Researcher*> arr;


};

#endif
