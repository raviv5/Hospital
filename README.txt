Students details:
------------------
Itay Raviv 209229897
Amal Amsis 213905144


:We used 3 functions from algorithms in STL
1.all_of (Article.cpp, Department.cpp,Doctor.cpp)
2.any_of(Doctor.cpp)
3.find(Department.cpp)


******************************************************************************************************************************************
The zip we submitted contains data that can be used as hardcoded when the program starts , in addition to the hardcoded in the menu.

*******************************************************************************************************************************************
                                                                                                        :You wrote to us in the code review 
                                                   ."superfluous typeid check (~ResearchInstitute - each pointer in array is a researcher)"

                                                                                  :we want to explain our purpose behind this typeid check 

                                                           .In the vector there are researchers, doctor researchers and surgeon researchers        We wanted to delete only the researchers because the other types are also in the vector of doctors in Department         
                                                    therefore we would not want to delete them from here. For this reason we do typeid check