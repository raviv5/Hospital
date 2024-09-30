#include "researchInstitute.h"
#include"Researcher.h"
using namespace std;

//----------------------------------------------------------------------------//
ResearchInstitute::~ResearchInstitute()
{

    for (Researcher* i : arr)
    {
        if (typeid(*i) == typeid(Researcher)) /*In the vector there are researchers, doctor researchers and surgeon researchers.
                                                We wanted to delete only the researchers because the other types are in the vector of doctors in the Department, 
                                                therefore we would not want to delete them from here. For this reason we do typeid check*/
        {
            delete i;
        }
    }

}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
int ResearchInstitute::getSLog()
{
    return arr.size();
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
vector<Researcher*>& ResearchInstitute::getArr()
{
    return arr;
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
void ResearchInstitute::addResearcher(Researcher* ptr_res)
{
    if (arr.size() == arr.capacity())
    {
        arr.reserve(arr.capacity() * 2);
    }

    arr.push_back(ptr_res);

}
//----------------------------------------------------------------------------//