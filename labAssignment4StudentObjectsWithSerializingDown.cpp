// Identification comments code block
// Nagi Kasuya
// ID: 1871978
// File: Lab Assignment 4, Student Objects With Serializing Down 

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <fstream>
using std::ofstream;

#include <string>
using std::string;
using std::getline;

#include <cstdlib>

struct student
{
  string fullname;
  int studentid;
  string address;
  string major;
  double gpa;
};

void outputTableHeading();

void outputStudent(int, student);

student getSomeStudent();

int main()
{
  cout << " Nagi Kasuya \n\n";
  cout << " ID: 1871978\n";
  cout << " File: " << __FILE__ << "\n";
  cout << " Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  student jack = getSomeStudent();
  student jill = getSomeStudent();
  student classmate = getSomeStudent();

  outputTableHeading();

  outputStudent(1, jack);
  outputStudent(2, jill);
  outputStudent(3, classmate);

  ofstream fout;
  fout.open("students.txt");
  fout << jack.fullname << '\n' << jack.studentid << '\n' << jack.address << '\n'
    << jack.major << '\n' << jack.gpa << '\n';
  fout << jill.fullname << '\n' << jill.studentid << '\n' << jill.address << '\n'
    << jill.major << '\n' << jill.gpa << '\n';
  fout << classmate.fullname << '\n' << classmate.studentid << '\n' << classmate.address << '\n'
    << classmate.major << '\n' << classmate.gpa << '\n';
  fout.close();
}

void outputTableHeading()
{
  cout << "# Name            ID    Address                         Major               Gpa  \n";
  cout << "-- --------------- ----- ------------------------------- ------------------- --- \n";
}

void outputStudent(int sequenceNumber, student anystudent)
{
  //column widths + white spaces = 80
  //Left justified 

  cout.width(2);
  cout << sequenceNumber << " ";
  cout.width(15);
  cout << anystudent.fullname << " ";
  cout.width(5);
  cout << anystudent.studentid << " ";
  cout.width(31);
  cout << anystudent.address << " ";
  cout.width(19);
  cout << anystudent.major << " ";
  cout.width(3);
  cout << anystudent.gpa << endl;

}

student getSomeStudent()
{
  student result;
  string buf;

  cout << "Enter the name:";
  getline(cin, result.fullname);

  cout << "And what's " << result.fullname << "'s ID? ";
  cin >> buf; result.studentid = atoi(buf.c_str());
  cin.ignore(1000, 10);

  cout << "And now " << result.fullname << "'s address: ";
  getline(cin, result.address);

  cout << "And now " << result.fullname << "'s major: ";
  getline(cin, result.major);

  cout << "And now " << result.fullname << "'s GPA: ";
  cin >> buf; result.gpa = atof(buf.c_str());
  cin.ignore(1000, 10);

  cout << '\n';

  return result;
}