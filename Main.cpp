#include <iostream>
#include <windows.h>
#include "Date.h"
#include "Log.h"
#include <string>
#include "Company.h"
#include "BaseException.h"
#include "Employee.h"
#include "Department.h"


void companyManagement(Company *comp);
void financesManage();
void filmsManage();

void showBanner(std::string name) {
    LOG("******************************************************");
    LOG("*********"<< name <<"**********");
    LOG("******************************************************");

}

int main()
{
    // Create default company
    Company company = Company();
    company.setCompanyName("Tizen Productions Management System");
    //showBanner(company.getCompanyName());
    //Sleep(5000);
    //system("cls");
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
            companyManagement(&company);
        }
        else if (selectedOption == 2) {
            // Finances
            financesManage();
        }
        else if (selectedOption == 3) {
            // Films
            filmsManage();
        }
        else if (selectedOption == 4) {
            // Quit
            LOG("Good bye, have a nice day!");
            exit(0);
        }
        else {
            LOG("Please select a valid option");
        }
        // Clear the console
        system("cls");
    }
}


void companyManagement(Company *companyRef) {
    // companyRef is a pointer, we use &companyRef to access object
    system("cls");
    while (true) {
        LOG("1. Departments");
        LOG("2. Employees");
        LOG("3. Restructure");
        LOG("4. Go Back");
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
                    for (Department* dep : companyRef->getDepartments()) {
                        LOG(dep->getDeptName());
                    }
                    LOG("...");
                }
                else if (dOption == 2) {
                    // Add department
                    addDepartment(companyRef);
                }
                else if (dOption == 3) {
                    // Manage department
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
                LOG("2. Show employees");
                LOG("3. Go Back");
                std::cout << "> ";
                int eOption;
                std::cin >> eOption;
                if (eOption == 1) {
                    // Add employee
                    addEmployee(companyRef);
                }
                else if (eOption == 2) {
                    // List employees
                }
                else if (eOption == 3) {
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
            // Restructure
        }
        else if (selectedOption == 4) {
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


void financesManage() {
    system("cls");
    while (true) {
        LOG("1. Increase Employee Salary");
        LOG("2. See where's most money being spent?");
        LOG("3. Go Back");
        std::cout << "> ";
        int selectedOption;
        std::cin >> selectedOption;
        if (selectedOption == 1) {
            // Increase salary
        }
        else if (selectedOption == 2) {
            // See where most meny being spent
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



void filmsManage() {
    system("cls");
    while (true) {
        LOG("1. Add film");
        LOG("2. Show films");
        LOG("3. Go Back");
        std::cout << "> ";
        int selectedOption;
        std::cin >> selectedOption;
        if (selectedOption == 1) {
            // Add film
        }
        else if (selectedOption == 2) {
            // Show films
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