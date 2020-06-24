/*
C++ Advanced Programming Assignment

KR Maendo 217101461
TN David 218057245

*/
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <windows.h>
#include "Date.h"
#include "Log.h"
#include <string>
#include "BaseException.h"
#include "Employee.h"
#include "Manager.h"
#include "Film.h"
#include "DepartmentCompany.h"


void companyManagement(Company& comp);
void financesManage(Company& companyRef, Films& films);
void filmsManage(Films& films);
void loadFilms(Films& films);
std::vector<int> split(std::string str, char sep);

void showBanner(std::string name) {
    LOG("******************************************************");
    LOG("*********"<< name <<"**********");
    LOG("******************************************************");

}

int main()
{
    // Create default company
    Company* company = new Company();
    company->setCompanyName("Tizen Productions Management System");
    Films* films = new Films();
    // Load saved information
    loadFilms(*films);

    showBanner(company->getCompanyName());
    Sleep(5000);
    system("cls");
    
    
    while (true) {
        LOG("1. Company Management");
        LOG("2. Finances");
        LOG("3. Films");
        LOG("4. Quit");
        std::cout << "> ";
        int selectedOption;
        std::cin >> selectedOption;
        if (selectedOption == 1) {
            // Company Hierarchy
            // Pass reference to company object
            companyManagement(*company);
        }
        else if (selectedOption == 2) {
            // Finances
            financesManage(*company, *films);
        }
        else if (selectedOption == 3) {
            // Films
            filmsManage(*films);
        }
        else if (selectedOption == 4) {
            // Quit
            LOG("Good bye, have a nice day!");
            break;
        }
        else {
            LOG("Please select a valid option");
        }
        // Clear the console
        system("cls");
    }

    // Save information to CSV upon exiting
    // Films
    std::ofstream filmFile;
    filmFile.open("films.csv", std::ios_base::app);
    for (int i = 0; i < (int)films->getFilms().size(); i++) {
        filmFile << films->getFilms().at(i)->getTitle() << ","<< films->getFilms().at(i)->getDate().display() <<","<< films->getFilms().at(i)->getBudget()<<","<< films->getFilms().at(i)->getScript() <<","<< films->getFilms().at(i)->getCrewSize()<< "," << films->getFilms().at(i)->getDirector()<<"\n";
    }
    filmFile.close();

    // Employees
    // Loop through all departments writing the employees

    std::vector<Department*> departmentList = company->getDepartments();
    std::ofstream empFile;
    empFile.open("employees.csv", std::ios_base::app);
    
    for (int i = 0; i < (int)departmentList.size(); i++) {
        std::vector<Employee*> employees = departmentList.at(i)->getEmployees();
        std::string deptName = departmentList.at(i)->getDeptName();

        for (int i = 0; i < (int)employees.size(); i++) {
            Employee* e = employees.at(i);
            empFile << e->getEmployeeID()<<","<< e->getPayDay() << "," << e->getPayment() << ","<< e->getDepartment() << ","<<e->getRole()<<","<<e->isFired() << "\n";
        }
    }
    empFile.close();
}


void companyManagement(Company& companyRef) {
    // companyRef is a pointer, we use &companyRef to access object
    system("cls");
    while (true) {
        LOG("1. Departments");
        LOG("2. Employees");
        LOG("3. Go Back");
        std::cout << "> ";
        int selectedOption;
        std::cin >> selectedOption;
        if (selectedOption == 1) {
            // Departments
            while (true) {
                LOG("1. List departments");
                LOG("2. Add department");
                LOG("3. Manage department");
                LOG("4. Go Back");
                std::cout << "> ";
                int dOption;
                std::cin >> dOption;
                if (dOption == 1) {
                    // List departments
                    for (Department* dep : companyRef.getDepartments()) {
                        LOG(dep->getDeptName());
                    }
                }
                else if (dOption == 2) {
                    // Add department
                    addDepartment(companyRef);
                }
                else if (dOption == 3) {
                    // Manage department
                    for (Department* dep : companyRef.getDepartments()) {
                        LOG(dep->getDeptName());
                    }
                    std::cout << "Department Name> ";
                    std::string dname;
                    std::cin >> dname;
                    if (checkIfDeptExist(companyRef, dname)) {
                        while (true) {
                            LOG("1. List employees");
                            LOG("2. Go Back");
                            std::cout << "> ";
                            int dop;
                            std::cin >> dop;
                            if (dop == 1) {
                                // List employees
                                LOG("Listing employees");
                                Department* dep = getDept(companyRef, dname);
                                for (int i = 0; i < (int)dep->getEmployees().size(); i++) {
                                    LOG("***************************************");
                                    LOG("Employee #" << i);
                                    LOG("ID: " << dep->getEmployees().at(i)->getEmployeeID());
                                    LOG("Incentive: " << dep->getEmployees().at(i)->getPayment());
                                    LOG("Pay Day: " << dep->getEmployees().at(i)->getPayDay());
                                    LOG("***************************************");
                                }
                                
                            }
                            else if (dop == 2) {
                                // Go back
                                break;
                            }
                            else {
                                LOG("Please select a valid option.");
                            }
                        }
                    }
                    else {
                        LOG("Department was not found, please try again.");
                    }
                }
                else if (dOption == 4) {
                    // Go back
                    system("cls");
                    break;
                }
                else {
                    LOG("Please select a valid option.");
                }
            }
        }
        else if (selectedOption == 2) {
            // Employees
            while (true) {
                LOG("1. Add employee");
                LOG("2. Go Back");
                std::cout << "> ";
                int eOption;
                std::cin >> eOption;
                if (eOption == 1) {
                    // Add employee
                   addEmployee(companyRef);
                }
                else if (eOption == 2) {
                    // Go back
                    system("cls");
                    break;
                }
                else {
                    LOG("Please select a valid option.");
                }
            }
        }
        else if (selectedOption == 3) {
            // Go Back
            system("cls");
            break;
        }
        else {
            LOG("Please select a valid option");
        }
        system("cls");
    }
}


void financesManage(Company& companyRef, Films& films) {
    system("cls");
    while (true) {
        LOG("1. Increase Employee Salary");
        LOG("2. Show usage of money");
        LOG("3. Go Back");
        std::cout << "> ";
        int selectedOption;
        std::cin >> selectedOption;
        if (selectedOption == 1) {
            // Increase salary
        }
        else if (selectedOption == 2) {
            // See where money is being spent
            LOG("FILMS");
            for (int i = 0; i < (int)films.getFilms().size(); i++) {
                LOG(films.getFilms().at(i)->getTitle()<<" has budget of "<< films.getFilms().at(i)->getBudget());
            }
            LOG("***********************************");
            LOG("EMPLOYEES");
            for (Department* dep : companyRef.getDepartments()) {
                // Calculate overall salary for department
                double total = 0;
                for (int i = 0; i < (int)dep->getEmployees().size(); i++) {
                    total += dep->getEmployees().at(i)->getPayment();
                }
                LOG(dep->getDeptName() << " total salaries: " << total);
            }
        }
        else if (selectedOption == 3) {
            // Go Back
            system("cls");
            break;
        }
        else {
            LOG("Please select a valid option");
        }
    }
}


void filmsManage(Films& films) {
    system("cls");
    while (true) {
        LOG("1. Add film");
        LOG("2. Show films");
        LOG("3. Go Back");
        std::cout << "> ";
        std::string selectedOption;
        std::getline(std::cin, selectedOption);
        if (selectedOption == "1") {
            // Add film
            std::cout << "Title: ";
            std::string ti;
            std::getline(std::cin, ti);

            std::cout << "Director: ";
            std::string director;
            std::getline(std::cin, director);

            std::cout << "Budget: ";
            std::string bu;
            std::getline(std::cin, bu);

            std::cout << "Crew size: ";
            std::string cr;
            //std::cin >> cr;
            std::getline(std::cin, cr);

            std::cout << "Day expected: ";
            std::string day;
            //std::cin >> day;
            std::getline(std::cin, day);

            std::cout << "Month expected: ";
            std::string month;
            //std::cin >> month;
            std::getline(std::cin, month);

            std::cout << "Year expected: ";
            std::string year;
            //std::cin >> year;
            std::getline(std::cin, year);

            std::cout << "Script: ";
            std::string sc;
            std::getline(std::cin, sc);

            Date* dobj = new Date(std::stoi(day), std::stoi(month), std::stoi(year));
            Film* f = new Film(ti, std::stod(bu), director, *dobj, sc, std::stoi(cr) );
            films.addFilm(*f);
            LOG("Film added successfully.");
            Sleep(2000);
        }
        else if (selectedOption == "2") {
            // Show films
            for (int i = 0; i < (int)films.getFilms().size(); i++) {
                LOG("***********************************");
                films.getFilms().at(i)->prettyPrint();
                LOG("***********************************");
            }
        }
        else if (selectedOption == "3") {
            // Go Back
            system("cls");
            break;
        }
    }
}


std::vector<int> split(std::string str, char delimiter){

    std::vector<int> vect;

    std::stringstream ss(str);

    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == delimiter) {
            ss.ignore();
        }   
    }
    return vect;


}

void loadFilms(Films& films) {

    std::ifstream file;
    file.open("films.csv");
    std::string title;
    std::string date;
    std::string script;
    std::string budget;
    std::string crewSize;
    std::string director;

    while (getline(file, title, ',')) {

        getline(file, date, ',');
        getline(file, budget, ',');
        getline(file, script, ',');
        getline(file, crewSize, ',');
        getline(file, director, '\n');

        Date* expected = new Date(split(date, '/'));
        // Create film object
        Film* film = new Film(title, std::stod(budget), director, *expected, script, std::stoi(crewSize));
        films.addFilm(*film);
    }
}

void loadEmployees(Company& company) {

}