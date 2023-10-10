// assignment 2 cs 303.cpp : This file contains the 'main' function. Program execution begins and ends there.
// I could not define my functions for the linked list in a cpp file because I used a template. 

#include <iostream>
#include "Assignment2.h"
#include "Employee.h"
#include "Nonprofessional.h"
#include "Professional.h"
#include "Assignment2.h"


int main()
{
    // create class objects and implement functions
    Single_Linked_List<int>list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_front(0);
    list.push_back(4);
    list.pop_front();
    list.pop_back();
    std::cout << list.front() << std::endl;
    std::cout << list.back() << std::endl;
    std::cout << list.empty() << std::endl;
    list.insert(2, 100);
    list.remove(2);
    std::cout << list.find(3) << std::endl;
    list.print();
    std::cout<<std::endl;

    // create Professional class instance
    Professional emily;
    emily.setMonthlySalary(7000);
    emily.setVacationDays(35);
    std::cout << emily.weeklySalary() << std::endl;
    std::cout << emily.healthCare() << std::endl;
    std::cout << emily.getVacationDays() << std::endl;


    // create Nonprofessional class instance
    Nonprofessional lily;
    lily.setHourlyRate(35);
    lily.setHoursWorked(40);
    std::cout<<lily.weeklySalary()<<std::endl;
    std::cout << lily.getVacationDays() << std::endl;
    std::cout << lily.healthCare() << std::endl;


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
