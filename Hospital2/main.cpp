#include "hospital.h"
#include "VisitCard.h"
#include "Article.h"
#include "Department.h"
#include "ResearchInstitute.h"
#include "Researcher.h"
#include "Doctor.h"
#include "Surgeon.h"
#include "SurgeonResearcher.h"
#include <stdbool.h>
#include <fstream>

const int MAX_LEN_NAME_PERSON = 20;
const int MAX_LEN_NAME_DEPARTMENT = 20;
const int MAX_LEN_NAME_ARTICLE = 30;
const int MAX_LEN_NAME_MAGZINE = 30;

enum options { EXIT, ADD_DEPARTMENT, ADD_NURSE, ADD_DOCTOR, ADD_VISIT, ADD_RESEARCHER, ADD_ARTICLE, SHOW_ALL_PATIENTS_IN_DEPARTMENT, SHOW_ALL_EMPLOYEES, SHOW_ALL_RESEARCHERS, SEARCH_PATIENT, SHOW_ALL_DOCTORRESEARCHERS, CHECK_OPERATORS, HARD_CODED };
enum operators { PRINT_DATE = 1, PRINT_ARTICLE, PRINT_VISITCARD, ADD_EMPLOYEE, COMPARE_RESEARCHERS_BY_ARTICLE };

void printMenu();
void D(int choice, Hospital& h);
void operators(Hospital& h);
void ifException(bool* b);
int printAllDepartments_chooseOne(Hospital& h);

int main()
{
	Hospital ourHospital;
	ifstream in("hospital.txt");
	if (in.is_open())
	{
		ourHospital.load(in);
		in.close();
	}
	int choice;
	printMenu();
	cin >> choice;
	while (choice != 0)
	{
		D(choice, ourHospital);
		printMenu();
		cin >> choice;
	}
	ofstream out("hospital.txt");
	ourHospital.save(out);
	cout << "Bye bye and good day !";
}

//----------------------------------------------------------------------------//
void printMenu()
{
	cout << "\n\nEnter a number to choose an option from the following list:\n";
	cout << ADD_DEPARTMENT << ".Adding a department to the hospital " << endl
		<< ADD_NURSE << ".Adding a nurse to the hospital , and assigning her/him to a department" << endl
		<< ADD_DOCTOR << ".Adding a doctor to the hospital , and assigning her/him to a department" << endl
		<< ADD_VISIT << ".Add a visit" << endl
		<< ADD_RESEARCHER << ".Add a researcher to the research institute" << endl
		<< ADD_ARTICLE << ".Add an article to a researcher" << endl
		<< SHOW_ALL_PATIENTS_IN_DEPARTMENT << ".Show all the patients in a specific department " << endl
		<< SHOW_ALL_EMPLOYEES << ".Show all the employees in the hospital" << endl
		<< SHOW_ALL_RESEARCHERS << ".Show all the researchers in the research institute" << endl
		<< SEARCH_PATIENT << ".Search for a patient by ID" << endl
		<< SHOW_ALL_DOCTORRESEARCHERS << ".Show all the doctor-researchers in the research institute" << endl
		<< CHECK_OPERATORS << ".check operators" << endl
		<< HARD_CODED << ".hard coded departments, doctor , etc." << endl
		<< EXIT << ".exit and save" << endl;
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void D(int choice, Hospital& h)
{

	switch (choice)
	{
	case ADD_DEPARTMENT:
	{
		bool valid_Data = false;
		while (!valid_Data)
		{
			char name[MAX_LEN_NAME_DEPARTMENT];
			cout << "Name of the dapartment: ";
			cin.ignore();
			cin.getline(name, MAX_LEN_NAME_DEPARTMENT);
			try
			{
				h.addDepartment(name);
				cout << "the department was added to hospital !" << endl;
				valid_Data = true;
			}
			catch (const char* msg)
			{
				cout << msg << endl;

			}
			catch (...) //not should get here
			{
				cout << "unknown error ! check return exception !" << endl;
			}
			ifException(&valid_Data);
		}
		break;
	}
	case ADD_NURSE:
	{
		if (h.getAllDepartments().size() == 0)
		{
			cout << "There are no departments in the hospital yet, you must add at least one department before adding a nurse ";
		}
		else
		{
			int num=  printAllDepartments_chooseOne( h);
			bool valid_Data = false;
			while (!valid_Data)
			{
				try
				{
					char name[MAX_LEN_NAME_PERSON];
					int yearsOfExperience;

					cout << "name:";
					cin.ignore();
					cin.getline(name, MAX_LEN_NAME_PERSON);
					cout << "years of experience:";
					cin >> yearsOfExperience;

					h.addNurse(name, num, yearsOfExperience);
					cout << "The nurse was added to the department !" << endl;
					valid_Data = true;
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
				catch (...) //not should get here
				{
					cout << "unknown error ! check return exception !" << endl;
				}
				ifException(&valid_Data);
			}
		}

		break;
	}
	case ADD_DOCTOR:
	{
		if (h.getAllDepartments().size() == 0)
		{
			cout << "There are no departments in the hospital yet, you must add at least one department before adding a doctor ";
		}

		else
		{
			int num = printAllDepartments_chooseOne(h);
			bool valid_Data = false;
			while (!valid_Data)
			{
				try
				{
					char name[MAX_LEN_NAME_PERSON];
					char expertise[MAX_LEN_NAME_DEPARTMENT];
					int type;

					cout << "name:";
					cin.ignore();
					cin.getline(name, MAX_LEN_NAME_PERSON);

					cout << "expertise:";
					cin.getline(expertise, MAX_LEN_NAME_DEPARTMENT);
					cout << "Enter 1 for doctor, 2 for surgeon, 3 researcher surgeon,4 researcher doctor :";
					cin >> type;

					switch (type)
					{
					case 1:
					{
						h.addDoctor(name, expertise, num, type);
						break;
					}
					case 2:
					{
						int surgonesNum;
						cout << "Enter number of surgerys: ";
						cin >> surgonesNum;
						h.addDoctor(name, expertise, num, type, surgonesNum);
						break;
					}
					case 3:
					{
						int surgonesNum;
						cout << "Enter number of surgerys: ";
						cin >> surgonesNum;
						h.addDoctor(name, expertise, num, type, surgonesNum);
						break;
					}
					case 4:
					{
						h.addDoctor(name, expertise, num, type);
						break;
					}
					default:
					{
						cout << "wrong choice , try again" << endl;
						break;
					}
					}
					cout << "The doctor was successfully added to the hospital !" << endl;
					valid_Data = true;
				}
				catch (const char* msg)
				{
					cout << msg << endl;
				}
				catch (...) //not should get here
				{
					cout << "unknown error ! check return exception !" << endl;
				}

				ifException(&valid_Data);
			}
			break;
		}
	case ADD_VISIT:
	{

		int id, Num_department, Doc_id, B_d, B_m, B_y, v_d, v_m, v_y;
		Patient* p = nullptr;
		char name[MAX_LEN_NAME_PERSON];
		char VisitPurpose[MAX_VISIT_PURPOSE];
		char gender;
		Doctor* d;
		Date birthday, VisitDate;
		bool valid_Data = false;

		while (!valid_Data)
		{
			try
			{
				cout << "please Enter Patient id: ";
				cin >> id;
				p = h.isPatientExsits(id); //return pointer to that patient. null if new., need to change to find algorithim
				if (p == nullptr)
				{
					cin.ignore();
					cout << "please Enter Patient Name: ";
					cin.getline(name, MAX_LEN_NAME_PERSON);
					cout << "please Enter BirthDay: ";
					cout << "(Enter a delimiter between the values. For example , \"January 1 , 2000\" , we will enter it as follows: \" 1 /1/ 2000 \" or \" 1.1.2000 \" ) ";
					cin >> birthday; 
					cout << "please Enter gender for , for Male press 'M' for Female press 'F':";
					cin >> gender;

				}
				
				Num_department = printAllDepartments_chooseOne(h);

				cout << "Enter visit Date: ";
				cout << "(Enter a delimiter between the values. For example , \"January 1 , 2000\" , we will enter it as follows: \" 1 /1/ 2000 \" or \" 1.1.2000 \" ) ";
				cin >> VisitDate;
				cout << endl;
				cin.ignore();
				cout << "purpose of visit?" << endl;
				cin.getline(VisitPurpose, MAX_VISIT_PURPOSE);

				bool isSurgery = false;
				cout << "Enter 0 for genrel visit or  1 for surgey visit: " << endl;
				cin >> isSurgery;

				vector<Department*> ::iterator itr = h.getAllDepartments().begin() + Num_department; //itr,to dep.
				vector<Doctor*> tmp = (*itr)->getDoctorsArray();                                 //vec of doc in dep.

				if (isSurgery)
				{
					int count = 0;
					cout << "Select the number of the surgeon who treated you from the list: ";
					for (Doctor* i : tmp)
					{
						if (typeid((*i)) == typeid(Surgeon) || typeid((*i)) == typeid(SurgeonResearcher))
						{
							cout << endl << "Name: " << i->getName() << endl << "Employee Name: " << i->getEmployeeNum();
							count++;
						}
					}
					if (count == 0)
					{
						cout << endl << "no surgeons in this current department !" << endl;
						return;
					}
					cout << endl;
					cin >> Doc_id;
					cout << endl;

					d = h.findDSurgeonInDepartment(Doc_id, Num_department);
					while (d == nullptr)
					{
						cout << "wrong value,no surgeon with this employee number was found in th department . Please try again" << endl;
						cin >> Doc_id;
						cout << endl;
						d = h.findDSurgeonInDepartment(Doc_id, Num_department);
					}

					cout << "Please enter the operating room number:" << endl;
					int room_num;
					cin >> room_num;

					cout << endl << "If the patient is fasting , please enter 1 otherwise enter 0:" << endl;
					bool isfasting;
					cin >> isfasting;

					h.addVisit(birthday, name, gender, id, VisitDate, d, VisitPurpose, Num_department, room_num, isfasting);
				}
				else
				{
					if ((*itr)->getcurrentNumOfDoctors() == 0)
					{
						cout << "no doctors in this current department !" << endl;
						return;
					}
					cout << "Select the number of the doctor who treated you from the list: ";
					for (Doctor* i : tmp)
					{
						cout << endl << "Name: " << i->getName() << endl << "Employee Number: " << i->getEmployeeNum();
					}
					cout << endl;
					cin >> Doc_id;
					cout << endl;
					d = h.findDDoctorInDepartment(Doc_id, Num_department);
					while (d == nullptr)
					{
						cout << "wrong value,no doctor with this employee number was found in th department . Please try again" << endl;
						cin >> Doc_id;
						cout << endl;
						d = h.findDDoctorInDepartment(Doc_id, Num_department);
					}
					h.addVisit(birthday, name, gender, id, VisitDate, d, VisitPurpose, Num_department);

				}
				cout << endl;
				cout << "Thank You and Take care !";
				valid_Data = true;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			catch (...) //not should get here
			{
				cout << "unknown error ! check return exception !" << endl;
			}

			ifException(&valid_Data);
		}
		break;
	}
	case ADD_RESEARCHER:
	{
		bool valid_Data = false;
		while (!valid_Data)
		{
			char name[MAX_LEN_NAME_PERSON];
			cin.ignore();
			cout << "name of researcher:";
			cin.getline(name, MAX_LEN_NAME_PERSON);

			int type;
			cout << "Enter 1 for researcher , 2 for doctor researcher or 3 for surgeon researcher: " << endl;
			cin >> type;
			try
			{
				switch (type)
				{
				case 1:
				{
					h.addResearcher(name, type);
					break;
				}
				case 2:
				{
					char expertise[20];
					cin.ignore();
					cout << "expertise:";
					cin.getline(expertise, 20);

					int num = printAllDepartments_chooseOne(h);
					h.addResearcher(name, type, num, expertise);
					break;
				}

				case 3:
				{
					char expertise[20];
					cin.ignore();
					cout << "expertise:";
					cin.getline(expertise, 20);

					int count = 1;
					int num = printAllDepartments_chooseOne(h);

					int surgerysNum;
					cout << "Enter number of surgones: ";
					cin >> surgerysNum;

					h.addResearcher(name, type, num, expertise, surgerysNum);
					cout << "surgeon researcher added !" << endl;
					break;
				}

				default:
				{
					cout << "wrong choice ! " << endl;
					break;
				}
				}
				cout << "researcher added !" << endl;
				valid_Data = true;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			catch (...) //not should get here
			{
				cout << "unknown error ! check return exception !" << endl;
			}
			ifException(&valid_Data);
		}

		break;
	}
	case ADD_ARTICLE:
	{

		char nameArticle[MAX_LEN_NAME_ARTICLE];
		char nameMagzine[MAX_LEN_NAME_MAGZINE];
		int d, m, y, id;
		Date date;
		bool valid_Data = false;

		while (!valid_Data)
		{
			cin.ignore();
			cout << "Name Of Article:  ";
			cin.getline(nameArticle, MAX_LEN_NAME_ARTICLE);
			cout << "Name Of Magzine:  ";
			cin.getline(nameMagzine, MAX_LEN_NAME_MAGZINE);
			cout << "Date of publish: ";
			cout << "(Enter a delimiter between the values. For example , \"January 1 , 2000\" , we will enter it as follows: \" 1 /1/ 2000 \" or \" 1.1.2000 \" ) ";
			cin >>date;
			cout << endl;

			vector<Researcher*> tmp = h.getResearchInstitute()->getArr();

			cout << "Select the number of the researcher from the following list:  ";
			for (Researcher* i : tmp)
			{
				cout << endl << "Name: " << i->getName() << endl << "Employee Number: " << i->getEmployeeNum();
			}
			cout << endl;
			cin >> id;
			cout << endl;

			Researcher* r = h.findResearcher(id); 

			if (r == NULL)
			{
				cout << "no employee number exists in system !";
			}
			else
			{
				try
				{
					h.addArticale(nameArticle, nameMagzine, date, r);
					cout << "The article has been added !";
					valid_Data = true;
				}
				catch (const char* msg)
				{
					cout << "Invalid name ! name cant be empty !" << endl;
				}
			}
			ifException(&valid_Data);
		}

		break;
	}
	case SHOW_ALL_PATIENTS_IN_DEPARTMENT:
	{
		h.showAllPatientInDepartment();
		break;
	}
	case SHOW_ALL_EMPLOYEES:
	{
		h.showAllCrewMembers();
		break;
	}
	case SHOW_ALL_RESEARCHERS:
	{
		h.showAllResearchers();
		break;
	}
	case SEARCH_PATIENT:
	{
		bool valid_Data = false;
		while (!valid_Data)
		{
			int id;
			cout << "Please enter the patient's ID ";
			cin >> id;
			cout << endl;
			try
			{
				h.patientSearchById(id);
				valid_Data = true;
			}
			catch (const char* msg)
			{
				cout << msg << endl;
			}
			ifException(&valid_Data);
		}

		break;
	}
	case SHOW_ALL_DOCTORRESEARCHERS:
	{
		h.showAllDoctorResearchers();
		break;
	}
	case HARD_CODED:
	{
		h.addDepartment("Cardiology");
		h.addDoctor("amal amsis", "Cardiology", 0, 1, 10);
		h.addDepartment("Pediatrics");
		h.addDoctor("yossi choen", "Pediatrics", 1, 2, 10);
		h.addDepartment("internal");
		h.addDoctor("itay raviv", "internal", 2, 3, 10);

		h.addVisit(Date(22, 11, 1999), "izik cohen", 'M', 213905144, Date(4, 4, 2000), h.findDoctor(1), "aches", 0);//4
		h.addVisit(Date(1, 9, 2003), "tom aviv", 'M', 209229897, Date(7, 7, 2005), h.findDoctor(2), "sickness", 1);//4
		h.addResearcher("daniel fo", 1);//5
		h.addArticale("grade 100", "c++ project", 4);//6
		h.addNurse("keren kalif", 2, 25);//2
		break;
	}
	case CHECK_OPERATORS:
	{
		operators(h);
		break;
	}
	default:
	{
		cout << "Incorrect number selection , please try again" << endl;
		break;
	}
	}
	}
}
//----------------------------------------------------------------------------//


//----------------------------------------------------------------------------//
void operators(Hospital& h)
{
	cout << "\n\n enter a number to choose an option from the following list:\n";
	cout << PRINT_DATE << ".print date " << endl
		<< PRINT_ARTICLE << ".print article" << endl
		<< PRINT_VISITCARD << ".print visitCard" << endl
		<< ADD_EMPLOYEE << ".adding a employee doctor/nurse" << endl
		<< COMPARE_RESEARCHERS_BY_ARTICLE << ".compering two reseachers by number of article" << endl;

	int choice;
	cin >> choice;

	switch (choice)
	{
	case PRINT_DATE:
	{
		Date d(22, 11, 1999);
		cout << d;
		break;
	}
	case PRINT_ARTICLE: 
	{
		Article a(Date(1,1,1999), "c++ summer", "grade 100");
		cout << a;
		break;
	}
	case PRINT_VISITCARD:
	{
		Department dep("department1");
		Doctor d("daniel fo", "e", dep);
		Date da1(1, 1, 2000);
		Date da2(5, 8, 2022);
		VisitCard v(&d, da1, da2, 666666, "yaniv dvir", "sickness", 'M');

		cout << v;
		break;
	}
	case ADD_EMPLOYEE:
	{
		cout << "please check optins 2 and 3 in the main menu , cause we didnt want to duplicate an unneccessary code. it is exectly the same ! thank you.";
		break;
	}
	case COMPARE_RESEARCHERS_BY_ARTICLE:
	{
		vector<Researcher*> arr = h.getResearchInstitute()->getArr();
		int num = (h.getResearchInstitute())->getSLog();
		if (num <= 1)
		{

		}
		else if (num == 2)
		{
			Researcher* r1 = arr[0];
			Researcher* r2 = arr[1];
			cout << "there is only 2 researchers." << endl;
			cout << "the researcher with most article is (drums):" << endl;

			if ((*r1) > (*r2))
			{
				r1->show();
				r1->showArticles();
			}
			else
			{
				if (r1->getNumOfArticles() == r2->getNumOfArticles())
				{
					cout << "number of articles is equal !" << endl;
					r1->show();
					r1->showArticles();
					r2->show();
					r2->showArticles();
				}
				else
				{
					r2->show();
					r2->showArticles();
				}
			}

		}
		else
		{
			Researcher* r1;
			Researcher* r2;
			int num1, num2;
			cout << "Please choose two researchers by choosing their number in the list" <<
				"(for example if you want the first and third researcher write 1 and 3)" << endl;
			h.showAllResearchers();
			cout << endl << "first researcher : ";
			cin >> num1;
			cout << "second researcher : ";
			cin >> num2;
			cout << "the researcher with most article is (drums):" << endl;
			r1 = arr[num1 - 1];
			r2 = arr[num2 - 1];
			if ((*r1) > (*r2))
			{
				r1->show();
				r1->showArticles();
			}
			else
			{
				if (r1->getNumOfArticles() == r2->getNumOfArticles())
				{
					cout << "number of articles is equal !" << endl;
					r1->show();
					r1->showArticles();
					r2->show();
					r2->showArticles();
				}
				else
				{
					r2->show();
					r2->showArticles();
				}
			}
		}

		break;
	}
	default:

	{
		cout << "wrong number choice!";
		break;
	}
	}

}
//----------------------------------------------------------------------------//
void ifException(bool* b)
{
	if (!(*b))
	{
		cout << "Press 0 to re-enter details or 1 to return to the main menu:" << endl;
		cin >> *b;
		cout << endl;
	}
}
//----------------------------------------------------------------------------//

//----------------------------------------------------------------------------//
int printAllDepartments_chooseOne(Hospital& h)
{
	int num;
	cout << "select a department to add the nurse to , from the following list" << endl;
	int count = 1;
	for (Department* i : h.getAllDepartments())
	{
		cout << count++ << "." << i->getName() << endl;
	}
	cin >> num;
	while (num > h.getAllDepartments().size()&& num<0)
	{
		cout << "wrong choice , try again" << endl;
		cin >> num;
	}
	num = num - 1;
	return num;
}
//----------------------------------------------------------------------------//

