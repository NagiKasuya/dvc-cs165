// Nagi Kasuya//

// Nagi Kasuya//

// ID:1871978 //

// Lab Assignment 2, Making Exact Change //

// Date February 25th//

#include <iostream>
using std::cout;
using std::cin;
using std::ios;
using std::endl;

#include <string>
using std::string;

#include <utility>

int main()
{
  double hundreddollor = 0;
  double fiftydollor = 0;
  double twentydollor = 0;
  double tendollor = 0;
  double fivedollor = 0;
  double onedollor = 0;
  double fiftycent = 0;
  double twentyfivecent = 0;
  double tencent = 0;
  double fivecent = 0;
  double onecent = 0;
  double purchase = 0;
  double tender = 0;
  double change = 0;
  string buf;


  cout << "Please enter the purchase amount and tender:";
  cin >> buf; purchase = atof(buf.c_str());
  cin >> buf; tender = atof(buf.c_str());




  cout.setf(ios::fixed);
  cout.precision(2);

  change = tender - purchase;
  cout << "$" << change << endl;

  cout.setf(ios::fixed);
  cout.precision(0);

  if (change >= 100)
  {
    while (change >= 100)
    {
      change = change - 100;
      hundreddollor++;
    }

    if (0.9999 < hundreddollor && hundreddollor < 1.0001)
    {
      cout << hundreddollor << " $100 bill\n";
    }
    else if (hundreddollor > 0.9999)
    {
      cout << hundreddollor << " $100 bills\n";
    }

  }

  if (change >= 50)
  {
    while (change >= 50)
    {
      change = change - 50;
      fiftydollor++;
    }

    if (0.9999 < fiftydollor && fiftydollor < 1.0001)
    {
      cout << fiftydollor << " $50 bill\n";
    }

    else if (fiftydollor > 0.9999)
    {
      cout << fiftydollor << " $50 bills\n";
    }


  }

  if (change >= 20)
  {
    while (change >= 20)
    {
      change = change - 20;
      twentydollor++;
    }

    if (0.9999 < twentydollor && twentydollor < 1.0001)
    {
      cout << twentydollor << " $20 bill\n";
    }

    else if (twentydollor > 0.9999)
    {
      cout << twentydollor << " $20 bills\n";
    }

  }

  if (change >= 10)
  {
    while (change >= 10)
    {
      change = change - 10;
      tendollor++;
    }

    if (0.9999 < tendollor && tendollor < 1.0001)
    {
      cout << tendollor << " $10 bill\n";
    }

    else if (tendollor > 0.9999)
    {
      cout << tendollor << " $10 bills\n";
    }

  }

  if (change >= 5)
  {
    while (change >= 5)
    {
      change = change - 5;
      fivedollor++;
    }

    if (0.9999 < fivedollor && fivedollor < 1.0001)
    {
      cout << fivedollor << " $5 bill\n";
    }

    else if (fivedollor > 0.9999)
    {
      cout << fivedollor << " $5 bills\n";
    }


    if (change >= 1)
    {
      while (change >= 1)
      {
        change = change - 1;
        onedollor++;
      }

      if (0.9999 < onedollor && onedollor < 1.0001)
      {
        cout << onedollor << " $1 bill\n";
      }

      else if (onedollor > 0.9999)
      {
        cout << onedollor << " $1 bills\n";
      }

    }

    if (change >= 0.5)
    {
      double deviation = 0.5 * 0.01;
      while (change > 0.5 - deviation)
      {
        change = change - 0.5;
        fiftycent++;
      }

      if (0.9999 < fiftycent && fiftycent < 1.0001)
      {
        cout << fiftycent << " $50-cent coin\n";
      }

      else if (fiftycent > 0.9999)
      {
        cout << fiftycent << " $50-cent coins\n";
      }

    }

    if (change > 0.25)
    {
      double deviation = 0.25 * 0.01;
      while (change > 0.25 - deviation)
      {
        change = change - 0.25;
        twentyfivecent++;
      }

      if (0.9999 < twentyfivecent && twentyfivecent < 1.0001)
      {
        cout << twentyfivecent << " $25-cent coin\n";
      }

      else if (twentyfivecent > 0.9999)
      {
        cout << twentyfivecent << " $25-cent coins\n";
      }

    }

    if (change > 0.1)
    {
      double deviation = 0.1 * 0.01;
      while (change > 0.1 - deviation)
      {
        change = change - 0.1;
        tencent++;
      }

      if (0.9999 < tencent && tencent < 1.0001)
      {
        cout << tencent << " $10-cent coin\n";
      }

      else if (tencent > 0.9999)
      {
        cout << tencent << " $10-cent coins\n";
      }

    }

    if (change > 0.05)
    {
      double deviation = 0.01 * 0.01;
      while (change > 0.05 - deviation)
      {
        change = change - 0.05;
        fivecent++;
      }

      if (0.9999 < fivecent && fivecent < 1.0001)
      {
        cout << fivecent << " $5-cent coin\n";
      }

      else if (fivecent > 0.9999)
      {
        cout << fivecent << " $50-cent coins\n";
      }

    }

    if (change > 0.01)
    {
      double deviation = 0.01 * 0.01;
      while (change > 0.01 - deviation)
      {
        change = change - 0.01;
        onecent++;
      }

      if (0.9999 < onecent && onecent < 1.0001)
      {
        cout << onecent << " $1-cent coin\n";
      }

      else if (onecent > 0.9999)
      {
        cout << onecent << " $1-cent coins\n";
      }

    }
  }

}
