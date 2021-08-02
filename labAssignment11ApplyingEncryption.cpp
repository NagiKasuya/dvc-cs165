// Identification comments code block
// Nagi Kasuya 
// ID:1871978 
// Lab Assignment 11, Applying Encryption

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <fstream>
using std::ofstream;
using std::ifstream;


#include <string>
using std::string;
using std::getline;


#include<cstring>

#include<cstdlib>

struct Data
{
  string account;
  string password;
  Data* next;
};

int compareData(Data*, Data*);

string encode(string);

string decode(string);

void addData(Data*&, Data*&);

void eraseData(Data*&, Data*&, int);

void coutAllData(Data*);

int main()
{
  cout << " Nagi Kasuya \n";
  cout << " ID: 1871978\n";
  cout << " File: " << __FILE__ << "\n";
  cout << " Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  Data* firstData = 0, * lastData = 0;
  string buf;
  char sign = ' ';
  int number = 0;
  int count = 0;

  ifstream fin;
  fin.open("Data.txt");
  if (fin.good())
  {
    while (true)
    {
      string buf;
      getline(fin, buf);
      if (buf == "EOF") break;

      Data* temp = new Data;
      temp->account = decode(buf);

      fin >> temp->password; fin.ignore(1000, 10);
      temp->password = decode(temp->password);

      temp->next = 0;
      if (lastData) lastData->next = temp;
      else firstData = temp;
      lastData = temp;
    }
  }
  fin.close();

  while (sign != 'Q')
  {
    cout << " MENU " << endl;
    cout << " A Add a password " << endl;
    cout << " E Erase a password " << endl;
    cout << " L List all Password " << endl;
    cout << " Q Quit " << endl;
    cout << " ...your choice: ";
    cin >> sign;
    cin.ignore(1000, '\n');
    sign = toupper(sign);
    cout << '\n';

    switch (sign)
    {
    case 'A':
    {
      addData(firstData, lastData);
      count++;
      cout << '\n';
      break;
    }

    case 'E':
    {
      eraseData(firstData, lastData, count);
      coutAllData(firstData);
      count--;
      cout << '\n';
      break;
    }

    case 'L':
    {
      coutAllData(firstData);
      cout << '\n';
      break;
    }

    case'Q':
      break;
    }
  }

  ofstream fout;
  fout.open("Data.txt");
  Data* temp = firstData;
  while (temp)
  {

    fout << encode(temp->account) << endl;

    fout << encode(temp->password) << endl;

    temp = temp->next;

  }
  fout << "EOF\n";
  fout.close();

  while (firstData)
  {
    Data* p = firstData;
    firstData = firstData->next;
    delete p;
  }
}

void addData(Data*& head, Data*& tail)
{
  string buf;
  Data* temp = new Data;

  cout << " Enter your account: ";
  getline(cin, buf);
  temp->account = buf;

  cout << " Enter your password: ";
  cin >> buf;
  temp->password = buf;
  cin.ignore(1000, 10);

  bool addItem = true;
  Data* p, * prev; // step 4 will need to know the "previous node"
  for (p = head, prev = 0; p; prev = p, p = p->next)
  {
    if (compareData(temp, p) < 0) break;
    if (compareData(temp, p) == 0)  //same name, don't need to add Data
    {
      cout << " You already added this account. " << endl;
      addItem = false;
      break;
    }

  }

  if (addItem)
  {
    temp->next = p; // places the node at p after the new node -- works even if p is zero
    if (prev) prev->next = temp; // places the new node after the node at prev, if there is one...
    else head = temp; // ...or makes it the new head if prev is zero
    if (p == 0) tail = temp; // in case there's a tail pointer
  }



}

void coutAllData(Data* firstData)
{
  int index = 1;

  cout << " # Account               Password " << endl;
  cout << "-- --------------------  --------" << endl;

  for (Data* p = firstData; p; p = p->next, index++)
  {
    cout.width(2);
    cout.unsetf(ios::left);
    cout << index << " ";
    cout.width(20);
    cout.setf(ios::left);
    cout << p->account << "  ";
    cout.width(20);
    cout << p->password << "  " << endl;
  }
}

void eraseData(Data*& firstData, Data*& lastData, int count)
{
  int number = 0;

  if (count == 0)
  {
    cout << " There is no Data to erase" << endl;
  }

  else if (count != 0)
  {
    do
    {
      cout << " Which Data to erase[1 - " << count << "] :";
      cin >> number;

      if (number < 1 || number > count)
        cout << "Invalid sequence number" << endl;

      if (number >= 1 && number <= count)
      {
        Data* p = firstData, * prev = 0;

        for (int i = 1; i < number; i++)
        {
          prev = p;
          p = p->next;
        }

        if (p)
        {
          if (prev)
          {
            prev->next = p->next;
            if (prev->next == 0)
              lastData = prev;
          }
          else
          {
            firstData = p->next;
          }
          delete p;
        }
      }
    } while (number < 1 || number > count);
  }
}


string encode(string aCppString)
{
  int n = aCppString.length();
  for (int i = 0; i < n; aCppString[i]++, i++);
  return aCppString;
}

string decode(string aCppString)
{
  int n = aCppString.length();
  for (int i = 0; i < n; aCppString[i]--, i++);
  return aCppString;
}

int compareData(Data* temp, Data* p)
{

  for (int i = 0; i < p->account.length() && i < temp->account.length(); i++)
  {

    if (toupper(p->account[i]) > toupper(temp->account[i]))
      return -1;
    if (toupper(p->account[i]) < toupper(temp->account[i]))
      return 1;
  }

  if (p->account.length() < temp->account.length())
    return -1;
  else if (p->account.length() != temp->account.length())
    return 1;


  return 0;

}

