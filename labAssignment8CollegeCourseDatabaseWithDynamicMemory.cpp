// Identification comments code block
// Nagi Kasuya 
// ID:1871978 
//  Lab Assignment 8, College Course Database With Dynamic Memory 


#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <fstream>
using std::fstream;

#include <string>
using std::string;

#include <algorithm>
using std::swap;

#include<cstring>

#include<cstdlib>

struct Course
{
  char course[12];
  int year;
  int units;
  char grade;
};
void toUpperCase(char[]);

void coutAllCourses(Course[], int);

void doubleArrayCapacity(Course*&, int&);

int main()
{
  cout << " Nagi Kasuya \n";
  cout << " ID: 1871978\n";
  cout << " File: " << __FILE__ << "\n";
  cout << " Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  int capacity = 2; // maximum size 
  string buf;
  char sign = ' ';
  int numberOFcourses = 0; // current size

  Course* courses = new Course[capacity];

  //Serializing up
  fstream fin;
  fin.open("courses.dat", ios::binary | ios::in);
  if (fin.good())
  {
    fin.read(reinterpret_cast<char*>(&numberOFcourses), sizeof(int));
    capacity = numberOFcourses; // capacity is always initialized to be equal to numberOFcourses
    delete[] courses;
    courses = new Course[capacity];
    fin.read(reinterpret_cast<char*>(courses), capacity * sizeof(Course));
  }
  fin.close();

  while (sign != 'Q')

  {

    cout << " Array size: " << numberOFcourses << ", " << " capacity: " << capacity << endl;
    cout << " MENU " << endl;
    cout << " A Add a course " << endl;
    cout << " L List all courses " << endl;
    cout << " C Arrange by course " << endl;
    cout << " Y arrange by Year " << endl;
    cout << " U arrange by Units " << endl;
    cout << " G arrange by Grade " << endl;
    cout << " Q Quit " << endl;
    cout << " ...your choice: ";
    cin >> sign;
    sign = toupper(sign);

    switch (sign)

    {
    case 'A':
      if (numberOFcourses == capacity) // always executes when serializing up
        // since numberOFcourses is set to capacity in the read block
      {
        doubleArrayCapacity(courses, capacity);
      }
      cout << " Enter a courses' name: ";
      cin >> courses[numberOFcourses].course;

      cout << " Enter the year for " << courses[numberOFcourses].course << " [like 2020]: ";
      cin >> buf; courses[numberOFcourses].year = atoi(buf.c_str());

      cout << " Enter the units for " << courses[numberOFcourses].course << " [0, 1, 2,...]: ";
      cin >> buf; courses[numberOFcourses].units = atoi(buf.c_str());

      cout << " Enter the grade for " << courses[numberOFcourses].course << " [A, B,..., X if still in progress or planned]: ";
      cin >> courses[numberOFcourses].grade;
      courses[numberOFcourses].grade = toupper(courses[numberOFcourses].grade);

      toUpperCase(courses[numberOFcourses].course);

      numberOFcourses++;
      break;

    case 'L':
      coutAllCourses(courses, numberOFcourses);
      break;

    case 'C':
      for (int i = 0; i < numberOFcourses; i++)
        for (int j = i + 1; j < numberOFcourses; j++)
          if (strcmp(courses[i].course, courses[j].course) > 0)
            swap(courses[i], courses[j]);
      coutAllCourses(courses, numberOFcourses);
      break;

    case 'Y':
      for (int i = 0; i < numberOFcourses; i++)
        for (int j = i + 1; j < numberOFcourses; j++)
          if (courses[j].year < courses[i].year)
            swap(courses[i], courses[j]);
      coutAllCourses(courses, numberOFcourses);
      break;

    case 'U':
      for (int i = 0; i < numberOFcourses; i++)
        for (int j = i + 1; j < numberOFcourses; j++)
          if (courses[j].units < courses[i].units)
            swap(courses[i], courses[j]);
      coutAllCourses(courses, numberOFcourses);
      break;

    case 'G':
      for (int i = 0; i < numberOFcourses; i++)
        for (int j = i + 1; j < numberOFcourses; j++)
          if (courses[j].grade < courses[i].grade)
            swap(courses[i], courses[j]);
      coutAllCourses(courses, numberOFcourses);

    case 'Q':
      break;
    }
  }
  // Serializing down
  fstream fout;
  fout.open("courses.dat", ios::binary | ios::out);
  fout.write(reinterpret_cast<char*>(&numberOFcourses), sizeof(int));
  fout.write(reinterpret_cast<char*>(courses), numberOFcourses * sizeof(Course));
  fout.close();


}


void doubleArrayCapacity(Course*& array, int& capacity)
{
  Course* temp = new Course[2 * capacity];
  for (int i = 0; i < capacity; i++)
    temp[i] = array[i];
  delete[] array;
  array = temp;
  capacity *= 2;
}


void coutAllCourses(Course anycourse[], int size)
{
  cout << "      Course Year Units Grade\n";
  cout << "------------ ---- ----- ----- \n";

  for (int i = 0; i < size; i++)
  {
    cout.width(12);
    cout << anycourse[i].course << " ";
    cout.width(4);
    cout << anycourse[i].year << " ";
    cout.width(3);
    cout << anycourse[i].units << "   ";
    cout.width(3);
    cout << anycourse[i].grade << endl;

  }


}

void toUpperCase(char aCString[])
{
  for (int i = 0; aCString[i] != 0; i++)
    aCString[i] = toupper(aCString[i]);
}