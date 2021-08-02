// Identification comments code block
// Nagi Kasuya 
// ID:1871978 
// Lab Assignment 9, Introducing Linked Lists

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <string>
using std::string;
using std::getline;

#include <algorithm>
using std::swap;

#include<cstring>

#include<cstdlib>

struct Movie
{
  string title;
  int year;
  int rate;
  Movie* next;
};

void coutAllMovie(Movie*);

int main()
{
  cout << " Nagi Kasuya \n";
  cout << " ID: 1871978\n";
  cout << " File: " << __FILE__ << "\n";
  cout << " Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  Movie* firstMovie = 0;
  string buf;
  char sign = ' ';
  int number = 0;
  int count = 3;


  Movie a = { "movie1", 0, 0 };
  Movie b = { "movie2", 0, 0 };
  Movie c = { "movie3", 0, 0 };

  c.next = firstMovie;
  firstMovie = &c;

  b.next = firstMovie;
  firstMovie = &b;

  a.next = firstMovie;
  firstMovie = &a;

  while (sign != 'Q')
  {
    cout << " MENU " << endl;
    cout << " U Update a movie " << endl;
    cout << " E Erase a movie " << endl;
    cout << " L List all movies " << endl;
    cout << " T arrange by Title " << endl;
    cout << " V arrange by year Viewed " << endl;
    cout << " R arrange by Rating " << endl;
    cout << " Q Quit " << endl;
    cout << " ...your choice: ";
    cin >> sign;
    sign = toupper(sign);
    cout << '\n';

    Movie* p = firstMovie;

    switch (sign)

    {
    case 'U':
    {

      do
      {
        cout << " Which movie to update [1-" << count << "]: ";
        cin >> number;
        cin.ignore(1000, '\n');
        if (number < 1 || number > count)
        {
          cout << " Invalid number " << endl;
        }
      } while (number < 1 || number > count);

      Movie* p = firstMovie;
      for (int i = 1; i < number; i++)
        p = p->next;

      if (p)
      {
        do
        {
          cout << " Enter an updated name for " << p->title << ": ";
          getline(cin, buf);

          if (buf.length() > 50)
          {
            cout << "It is too long" << endl;
          }

        } while (buf.length() > 50);

        p->title = buf;

        cout << " Enter the year you saw " << p->title << " [like 2016]: ";
        cin >> buf; p->year = atoi(buf.c_str());
        cin.ignore(1000, 10);

        cout << " Enter your rating for " << p->title << " [1, 2, 3. 4. 5]: ";
        cin >> buf; p->rate = atoi(buf.c_str());
        cin.ignore(1000, 10);
      }
      else
        cout << " Movie not found " << endl;
      cout << '\n';
      break;
    }
    case 'E':
    {

      cout << " Which movie to erase[1 - " << count << "] :";
      cin >> number;
      Movie* p = firstMovie, * prev = 0;
      for (int i = 1; i < number; i++)
      {
        prev = p;
        p = p->next;
      }

      if (p)
      {
        if (prev) prev->next = p->next; // skips over the node at p
        else firstMovie = p->next; // there's a new head, possibly zero
        count--;
      }
      else
        cout << "Movie not found\n";
    }
    coutAllMovie(p);
    cout << '\n';
    break;

    case 'L':
      coutAllMovie(p);
      cout << '\n';
      break;

    case 'T':
      for (Movie* p = firstMovie; p; p = p->next)
        for (Movie* q = p->next; q; q = q->next)
          if (q->title < p->title)
          {
            swap(*p, *q);
            swap(p->next, q->next);
          }
      coutAllMovie(p);
      cout << '\n';
      break;

    case 'V':
      for (Movie* p = firstMovie; p; p = p->next)
        for (Movie* q = p->next; q; q = q->next)
          if (q->year < p->year)
          {
            swap(*p, *q);
            swap(p->next, q->next);
          }
      coutAllMovie(p);
      cout << '\n';
      break;

    case 'R':
      for (Movie* p = firstMovie; p; p = p->next)
        for (Movie* q = p->next; q; q = q->next)
          if (q->rate < p->rate)
          {
            swap(*p, *q);
            swap(p->next, q->next);
          }
      coutAllMovie(p);
      cout << '\n';
      break;

    case 'Q':
      break;
    }
  }
}

void coutAllMovie(Movie* firstMovie)
{

  int index = 1;

  cout << " # Title                       Viewed Rating" << endl;
  cout << "-- --------------------------- ------ ------" << endl;

  for (Movie* p = firstMovie; p; p = p->next, index++)
  {
    cout.width(2);
    cout << index << " ";
    cout.width(27);
    cout.setf(ios::left);
    cout << p->title << " ";
    cout.width(5);
    cout.unsetf(ios::left);
    cout << p->year << "  ";
    cout.width(3);
    cout << p->rate << "    " << endl;
  }

}