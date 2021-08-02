// Identification comments code block
// Nagi Kasuya 
// ID:1871978 
//  Lab Assignment 7, A Card Game With Array Serialization   

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::ios;

#include <fstream>
using std::fstream;

#include <algorithm>
using std::swap;

#include<cstring>

#include<cstdlib>

#include<ctime>

struct Cards
{
  int value;
  int suit;
};

void shufflecards(Cards[]);

int main()
{
  cout << " Nagi Kasuya \n";
  cout << " ID: 1871978\n";
  cout << " File: " << __FILE__ << "\n";
  cout << " Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  const int CAPACITY = 52;
  const int HAND = 5;
  Cards cardarr[CAPACITY];
  Cards handfive[HAND];
  char buf[100];
  int size = 0;
  int deckpos = 0;

  const char names[13][80] = { "Ace", "Two","Three","Four","Five","Six","Seven",
                               "Eight","Nine","Ten","Jack","Queen","King" };

  const char symbol[4][80] = { "Spades", "Clubs","Hearts","Damonds" };


  for (int i = 1; i <= 13; i++)
  {
    for (int j = 1; j <= 4; j++)
    {
      Cards temp;
      temp.value = i;
      temp.suit = j;
      cardarr[size] = temp;
      size++;
    }
  }


  srand(time(0));

  shufflecards(cardarr);

  for (int i = 0; i < 5; i++)
  {
    handfive[i] = cardarr[deckpos];
    deckpos++;
  }

  // serialize up 

  fstream fin;
  fin.open("cards.dat", ios::binary | ios::in);
  if (fin.good()) fin.read(reinterpret_cast<char*>(cardarr), CAPACITY * sizeof(Cards));
  if (fin.good()) fin.read(reinterpret_cast<char*>(handfive), HAND * sizeof(Cards));
  if (fin.good()) fin.read(reinterpret_cast<char*>(&deckpos), sizeof(int));
  fin.close();

  while ((deckpos < CAPACITY) && (toupper(buf[0]) != 'Q'))
  {

    cout << " My hand: " << endl;

    for (int i = 1; i <= 5; i++)
    {
      cout << i << "." << names[(handfive[i - 1].value) - 1] << "  of  "
        << symbol[(handfive[i - 1].suit) - 1] << endl;
    }

    cout << " There are " << (CAPACITY - deckpos) << " cards remaining in the deck. " << endl;
    cout << endl;
    cout << " Choose a card to recycle or Q to quit : ";
    cin >> buf; int Entern = atoi(buf);

    if (Entern >= 1 && Entern <= 5)
    {

      handfive[Entern - 1] = cardarr[deckpos];
      deckpos++;
    }

    if (deckpos >= CAPACITY)
    {
      cout << " My hand: " << endl;

      for (int i = 1; i <= 5; i++)
      {
        cout << i << "." << names[(handfive[i - 1].value) - 1] << "  of  " << symbol[(handfive[i - 1].suit) - 1] << endl;
      }
      cout << "no more cards";
    }
  }
  // seriarlze down

  fstream fout;
  fout.open("cards.dat", ios::binary | ios::out);
  fout.write(reinterpret_cast<char*>(cardarr), CAPACITY * sizeof(Cards));
  fout.write(reinterpret_cast<char*>(handfive), HAND * sizeof(Cards));
  fout.write(reinterpret_cast<char*>(&deckpos), sizeof(int));
  fout.close();
}

void shufflecards(Cards anycards[])
{
  for (int i = 0; i < 52; i++)
  {
    for (int j = i + 1; j < 52; j++)
    {
      if (rand() % 2)
        swap(anycards[i], anycards[j]);
    }
  }
}