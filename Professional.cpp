#include "Professional.h"


Professional::Professional() : Employee() { // constructor that sets values to 0
	this->monthlySalary = 0;
	this->vacationDays = 0;
	this->healthContributions = 0;
}
double Professional::weeklySalary() { // returns weekly salary by dividing monthly salary by 4
	return monthlySalary / 4;
}

double Professional::healthCare() { // returns health contribution which is 5% of employee's monthly salary
	healthContributions = monthlySalary * .05;
	return healthContributions;
}

int Professional::getVacationDays() { // returns set given vacation days
	return vacationDays;
}

void Professional::setMonthlySalary(double salary) { // sets monthly salary
	monthlySalary = salary;
}

void Professional::setVacationDays(int days) { // sets vacation days
	vacationDays = days;
}
