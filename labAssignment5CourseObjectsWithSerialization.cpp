// Identification comments code block
// Nagi Kasuya //
// ID:1871978 //
// Lab Assignment 5, Course Objects With Serialization //

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <fstream>
using std::ofstream;
using std::ifstream;

#include <string>
using std::string;

struct Course
{
  string course;
  int year;
  int units;
  string grade;
};

Course cinOneCourse(int);

void coutAllCourses(Course[], int);

int main()
{
  cout << " Nagi Kasuya \n";
  cout << " ID: 1871978\n";
  cout << " File: " << __FILE__ << "\n";
  cout << " Compiled: " << __DATE__ << " at " << __TIME__ << "\n";

  const int CAPACITY = 100;
  Course coursearr[CAPACITY];
  int size = 0;

  // seriarization up
  ifstream fin;
  fin.open("courses.txt");
  while (fin.good())
  {
    string buf;
    getline(fin, buf);
    if (buf == "EOF")break;
    coursearr[size].course = buf;
    fin >> coursearr[size].year;
    fin.ignore(1000, 10);
    fin >> coursearr[size].units;
    fin.ignore(1000, 10);
    fin >> coursearr[size].grade;
    fin.ignore(1000, 10);
    size++;
  }
  fin.close();

  for (int i = size; i < CAPACITY; i++)
  {
    coutAllCourses(coursearr, i);
    cout << '\n';

    Course newcourse = cinOneCourse(i);
    if (newcourse.course == "q" || newcourse.course == "Q")break;
    coursearr[i] = newcourse;
    size++;
  }

  // seriarization down
  ofstream fout;
  fout.open("courses.txt");
  for (int i = 0; i < size; i++)
  {
    fout << coursearr[i].course << endl;
    fout << coursearr[i].year << endl;
    fout << coursearr[i].units << endl;
    fout << coursearr[i].grade << endl;
  }
  fout << "EOF\n";
  fout.close();
}

Course cinOneCourse(int i)
{
  string buf;
  Course newcourse;
  cout << " Enter course # " << (i + 1) << " [Q to exit]: ";
  cin >> buf; newcourse.course = buf;

  if (newcourse.course == "q" || newcourse.course == "Q")return newcourse;

  cout << " What year for " << newcourse.course << " ? " << " [e.g., 2021]: ";
  cin >> buf; newcourse.year = atoi(buf.c_str());

  cout << " How many units is " << newcourse.course << " ? ";
  cin >> buf; newcourse.units = atoi(buf.c_str());

  cout << " And what was your grade [? for in-progress or planned]: ";
  cin >> buf; newcourse.grade = buf;

  return newcourse;
}

void coutAllCourses(Course anycourse[], int size)
{
  // right-justify

  cout << "  # Course     Year Units Grade\n";
  cout << "--- ---------- ---- ----- ----- \n";

  for (int i = 0; i < size; i++)
  {
    cout.width(3);
    cout << (i + 1) << " ";
    cout.width(10);
    cout << anycourse[i].course << " ";
    cout.width(4);
    cout << anycourse[i].year << " ";
    cout.width(5);
    cout << anycourse[i].units << " ";
    cout.width(5);
    cout << anycourse[i].grade << '\n';
  }
}