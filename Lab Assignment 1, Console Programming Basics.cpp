// Nagi Kasuya //

// Student ID: 1871978 //

// Lab Assignment 1, Console Programming Basics //
 
// February 11th //



#include<iostream>
using std::cout;
using std::cin;
using std::ios;
#include<string>
using std::string;
using std::getline;

#include<cstdlib>

#include<cmath>


int main()
{
	
	int age;
	string buf;
	cout << " Enter your age: ";
	cin >> buf;
	age = atoi(buf.c_str());
	cin.ignore(1000, 10);
	

	string name;
	cout << " Enter your name:  ";
	getline(cin, name);

	double temparture;
	cout << " Enter the temperature outside right now (degrees F): ";
	cin >> buf;
	temparture = atof(buf.c_str());
	cin.ignore(1000, 10);

	string city;
	cout << " What city are you in right now? ";
	getline(cin, city);

	
	


	cout << name << " is " << age << " years old now, and will be " << age + 2 << " two years from now. " << std::endl;
	cout << " It's " << temparture << " degrees F in " << city << " --that's ";
    cout.setf(ios::fixed);
	cout.precision(1);
	cout<< (5.0 / 9.0) * (temparture - 32.0) << " degrees c. " << std::endl;

	
}