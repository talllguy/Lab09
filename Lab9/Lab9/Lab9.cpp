/********************************************************************************
COSC 501 
Lab 9
Elliott Plack 
31 OCT 2013									   Due date: 04 NOV 2013 
Problem:	Write a program that reads data from a file into an array of five
			structs.
Algorithm:	Define a struct with five elements ( name, accountid, checking,
			saving, and phone number). input a file using a for loop into a 5
			member array of the struct. Use another for loop to output the
			results in a neat way.
********************************************************************************/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
	//char fileName[50]; // input if the user would type in file
	ifstream inFile;     // define ifstream to inFile command
	

	typedef char nameString[10];	// string to hold names
	typedef string phoneString;	// string to hold phone 

	struct bankRecord
	{
		nameString	name;
		int			accountID;
		float		checking;
		float		saving;
		phoneString phoneNumber;

	} holder[5]; // structure array
	
	inFile.open("BankRecords.txt"); // known file name

	for (int i = 0; i < 5; i++) // loop to fill holder array with info
	{
		inFile >> holder[i].name >> holder[i].accountID >> holder[i].checking >> holder[i].saving
			   >> holder[i].phoneNumber; // infile loop to take the input and add to the struct on each line
	}

	cout << "Record" << setw(9) << "Name" << setw(12)  << "Account ID" << setw(12) 
	     << "Checking" << setw(12) << "Savings" << setw(19) << "Phone Number" << endl; // Headings
	cout << string(70, '-') << endl; // header separator

	for (int i = 0; i < 5; i++)
	{
		    
		cout.setf(ios::fixed);   
		cout.setf(ios::showpoint);   
		cout.precision(2);

		cout << (i+1) << ". " << setw(12) << holder[i].name << setw(12)<< holder[i].accountID
			<< setw(12)<< holder[i].checking << setw(12) << holder[i].saving << setw(6) << "("
			<< holder[i].phoneNumber.substr(0,3) << ") " << holder[i].phoneNumber.substr(3,3)
			<< "-" << holder[i].phoneNumber.substr(6,4) << endl;
		// for the above, used code on http://stackoverflow.com/questions/7786383/formatting-phone-number-in-c
		//     to format the phone number! setw to define the widths to make the output look good
	}

	cout << endl; // one extra line for style

	return 0;


}