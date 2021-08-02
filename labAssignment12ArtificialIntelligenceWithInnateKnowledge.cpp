// Identification comments code block
// Nagi Kasuya 
// ID:1871978 
// Lab Assignment 12, Artificial Intelligence With Innate Knowledge

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include <string>
using std::string;

struct Sports
{
  string sayThis;
  Sports* yes;
  Sports* no;
};

int main()
{
  cout << " Nagi Kasuya \n";
  cout << " ID: 1871978\n";
  cout << " File: " << __FILE__ << "\n";
  cout << " Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  char sign = ' ';

  // all of the diagnoses
  Sports a = { "It is basketball" };
  Sports b = { "It is rugby" };
  Sports c = { "It is soccer." };
  Sports d = { "It is sepak takraw" };
  Sports e = { "It is table tennis." };
  Sports f = { "It is badminton." };
  Sports g = { "It is an esports." };
  Sports h = { "It is mind sports." };

  // all of the questions
  Sports i = { "Does the team consist of 5 people?", &a, &b };
  Sports j = { "Does the team consist of 11 people?", &c, &d };
  Sports k = { "Do you use small rakets and ping-pong balls for this sport?", &e, &f };
  Sports l = { "Do you use a computer for this sport?", &g, &h };
  Sports m = { "Is it a foot sport?", &j, &i };
  Sports n = { "Is not it a vigorous sport?", &l, &k };
  Sports o = { "Is it a sport you play outside?", &m, &n };
  Sports* top = &o; 
  string buf;

  cout << "\nTell me about the sports you are playing and I'll identify it.\n";

  Sports* p = top;
  while (true) 
  {
    cout << p->sayThis; 
    if (p->yes == 0 && p->no == 0) break; 
    cout << " [yes/no] ";
    cin >> sign;

    if (toupper(sign) == 'Y') p = p->yes;
    else if (toupper(sign) == 'N') p = p->no;
  }
}