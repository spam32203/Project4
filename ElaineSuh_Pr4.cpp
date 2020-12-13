/*

 * Class: CMSC140 23506

 * Instructor: Grigoriy Grinberg

 * Common Project 4

 * Computer/Platform/Compiler: MacbookPro/codelite

 * Description: A program that calculates the average number of days a company's employees are absent during the year.

 * Due Date: 11/22/2020

 * I pledge that I have completed the programming assignment independently.

   I have not copied the code from a student or any source.

   I have not given my code to any student.

   Print your Name here: Elaine Suh

*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//Function prototypes
int NumofEmployees();
int TotDaysAbsent(int);
double AverageAbsent(int,int);
ofstream outputFile;

int main ()
{
	int NumofEmployees_data = 0;
	int TotDaysAbsent_data = 0;
	double AverageAbsent_data = 0.0;
	
	// Open the file
	outputFile.open("employeeAbsences.txt");
	
	// Display the program objective
	cout << "Calculate the average number of days a company's employees are absent.\n";
	cout << endl;
	
	// Record program labels in file
	outputFile << "EMPLOYEE ABSENCE REPORT\n";
	outputFile << "Employee ID           Days Absent\n";
	
	// Process the functions
	NumofEmployees_data = NumofEmployees();
	TotDaysAbsent_data = TotDaysAbsent(NumofEmployees_data);
	AverageAbsent_data = AverageAbsent(NumofEmployees_data,TotDaysAbsent_data);
	
	// Record programmer name in file then close file
	outputFile << "Programmer: Elaine Suh";
	outputFile.close();
	return 0;
}

// Definition of function NumofEmployees
// This function asks the user for the total number of employees in the company
// The function returns the total number of employees in the company
int NumofEmployees()
{
	int NumofEmployees_1;
	
	cout << "Please enter the number of employees in the company: ";
	cin >> NumofEmployees_1;
	
	while (NumofEmployees_1 < 1)
	{
		cout << "The number of employees must not be less than 1\n";
		cout << "Please re-enter the number of employees: ";
		cin >> NumofEmployees_1;
	}
	return NumofEmployees_1;
}

// Definition of function TotDaysAbsent
// This function calculates the total number of days absent
// The parameter holds the total number of employees
// The function records employee IDs, employee absences, and total number of days absent in file employeeAbsences.txt
// The function returns the total number of days absent
int TotDaysAbsent (int NumofEmployees_1)
{
	int TotDaysAbsent_1 = 0;
	int employeeAbsences;
	
	for (int i = 0; i < NumofEmployees_1; i++)
	{
		int employeeID;
		
		cout << "Please enter an employee ID: ";
		cin >> employeeID;
		
		outputFile << employeeID << "                     ";
		
		cout << "Please enter the number of days this employee was absent: ";
		cin >> employeeAbsences;
		
		if (employeeAbsences < 0)
		{
			cout << "The number of days must not be negative.\n";
			cout << "Please re-enter the number of days absent: ";
			cin >> employeeAbsences;
		}
		
		TotDaysAbsent_1 += employeeAbsences;
		
		outputFile << employeeAbsences;
		outputFile << endl;
	}
	outputFile << endl;
	outputFile << "The " << NumofEmployees_1 << " employees were absent a total of " << TotDaysAbsent_1 << " days.\n";
	
	return TotDaysAbsent_1;
}

// Definition of function AverageAbsent
// This function calculates the average number of days absent
// The parameter holds the total number of employees and the total number of days absent
// The function records the average number of days absent in file employeeAbsences.txt
// The function returns the average number of days absent
double AverageAbsent(int NumofEmployees_1, int TotDaysAbsent)
{
	double AverageAbsent_1;
	
	AverageAbsent_1 = static_cast<double>(TotDaysAbsent) / static_cast<double>(NumofEmployees_1);
	
	outputFile << "The average number of days absent is " << AverageAbsent_1 << " days.\n";
	outputFile << endl;
	
	return AverageAbsent_1;
}