#pragma once
#include "Employee.h"

class Nonprofessional : public Employee { // creates derived class
private: // sets private data members
	int hoursWorked;
	double hourlyRate;
	double healthContributions;
	int vacationDays;

public:
	Nonprofessional(); // constructor that sets variables equal to 0
	
	double weeklySalary(); // returns the weekly salary

	double healthCare();  // returns the health care contributions which is 3% of the employee's monthly salary

	int getVacationDays(); // returns number of vacation days which is 10 times the number of hours worked
		
	void setHoursWorked(int hours); // sets hours worked

	void setHourlyRate(double rate); // sets hourly rate
};