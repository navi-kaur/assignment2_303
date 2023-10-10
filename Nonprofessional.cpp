#include "Nonprofessional.h"

Nonprofessional::Nonprofessional() : Employee() { // constructor that sets variables equal to 0
	hoursWorked = 0;
	hourlyRate = 0;
	healthContributions = 0;
	vacationDays = 0;
}
double Nonprofessional::weeklySalary() { // returns weekly salary by multiplying the number of hours worked and hourly rate
	return hoursWorked * hourlyRate;
}

double Nonprofessional::healthCare() { // returns the health care contributions which is 3% of the employee's monthly salary
	double monthlySalary = weeklySalary() * 4;
	healthContributions = monthlySalary * .03;
	return healthContributions;
}

int Nonprofessional::getVacationDays() { // returns number of vacation days which is 10 times the number of hours worked
	return hoursWorked * 10;
}

void Nonprofessional::setHoursWorked(int hours) 
{
	hoursWorked = hours;
}

void Nonprofessional::setHourlyRate(double rate)
{
	hourlyRate = rate;
}


