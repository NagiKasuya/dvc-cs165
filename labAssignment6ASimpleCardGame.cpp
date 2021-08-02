// Identification comments code block
// Nagi Kasuya //
// ID:1871978 //
// Lab Assignment 6, A Simple Card Game  //

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <algorithm>
using std::swap;

#include<cstring>

#include<cstdlib>

#include<ctime>

struct CARDS
{
  int value;
  int suit;
};

void shufflecards(CARDS[]);

int main()
{
  cout << " Nagi Kasuya \n";
  cout << " ID: 1871978\n";
  cout << " File: " << __FILE__ << "\n";
  cout << " Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  const int CAPACITY = 52;
  const int HAND = 5;
  CARDS cardarr[CAPACITY];
  CARDS handfive[HAND];
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
      CARDS temp;
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

  while ((deckpos < CAPACITY) && (toupper(buf[0]) != 'Q'))
  {

    cout << " My hand: " << endl;

    for (int i = 1; i <= 5; i++)
    {
      cout << i << "." << names[(handfive[i - 1].value) - 1] << "  of  " << symbol[(handfive[i - 1].suit) - 1] << endl;
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
      cout << "no more cards";
    }
  }
}

void shufflecards(CARDS anycards[])
{
  for (int i = 0; i < 52; i++)
  {
    for (int j = 0; j < i; j++)
    {
      if (rand() % 2)
        swap(anycards[i], anycards[rand() % (j + 1)]);
    }
  }
}
