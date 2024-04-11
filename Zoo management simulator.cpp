#include<iostream>
#include<fstream>
using namespace std;

class Keeper
{
private:
	string assignment;
public:
	Keeper(string assignment)
		: assignment{ assignment } {}

	void displayInfo()
	{
		cout << "Assignment: " << assignment << endl;
	}
};

class Veterinarian
{
private:
	string assignment;
public:
	Veterinarian(string assignment)
		: assignment{ assignment } {}

	void displayInfo()
	{
		cout << "Assignment: " << assignment << endl;
	}
};

class Guide
{
private:
	string assignment;
public:
	Guide(string assignment)
		: assignment{ assignment } {}

	void displayInfo()
	{
		cout << "Assignment: " << assignment << endl;
	}
};

class Zoo_finance
{
private:
	double ticket_sales, animal_care_costs, salary_employee, result;
public:
	void AllInfoAboutFinance()
	{
		ofstream income_ticket_sales("Ticket Sales.txt", ios::app);
		if (income_ticket_sales.is_open())
		{
			result = ticket_sales - (animal_care_costs + salary_employee);
			cout << "*\n" << "Income" << "Ticket sales: " << ticket_sales << "Expenses" << "\nAnimal care costs: " << animal_care_costs << "\nSalary for Employee: " << salary_employee << "\nTotal income: " << result << "\n*" << endl;
		}
		else
		{
			cout << "Can't find a file" << endl;
		}
	}
};