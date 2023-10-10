#pragma once
#include "Employee.h"

class Professional : public Employee { // creates derived class 
private:
	double monthlySalary; // sets private member variables
	int vacationDays;
	double healthContributions;

public:
	Professional(); // constructor that sets values to 0
		
	double weeklySalary();  // returns weekly salary by dividing monthly salary by 4
		

	double healthCare(); // returns health contribution which is 5% of employee's monthly salary
	

	int getVacationDays();  // returns set given vacation days
		

	void setMonthlySalary(double salary);


	void setVacationDays(int days);

	
};