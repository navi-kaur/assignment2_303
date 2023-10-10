#pragma once
#include <string.h>
#include <iostream>
class Employee { // creates parent class 
public:
	virtual double weeklySalary() = 0; // abstract functions created
	virtual double healthCare() = 0;
	virtual int getVacationDays() = 0;
};

