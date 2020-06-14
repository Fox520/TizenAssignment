#include <iostream>
#include <windows.h>
#include "Date.h"
#include "Log.h"
#include "Company.h"

void companyHierarchy();
void financesManage();
void filmsManage();

void showBanner() {
    LOG("******************************************************");
    LOG("*********Tizen Productions Management System**********");
    LOG("******************************************************");

}

int main()
{
    //showBanner();
    ///Sleep(5000);
    //system("cls");
    while (true) {
        LOG("1. Company Hierarchy");
        LOG("2. Finances");
        LOG("3. Films");
        LOG("4. Quit");
        std::cout << "> ";
        int selectedOption;
        std::cin >> selectedOption;
        if (selectedOption == 1) {
            // Company Hierarchy
            companyHierarchy();
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


void companyHierarchy() {
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
        }
        else if (selectedOption == 2) {
            // Employees
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