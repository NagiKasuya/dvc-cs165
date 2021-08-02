// Identification comments code block
// Nagi Kasuya //
// ID:1871978 //
//Lab Assighment 3 part2 MY HDTV //

#include <iostream>
using std::cout;
using std::cin;
using std::ios;
using std::endl;

#include <string>
using std::string;


#include <cmath>

#include <cstdlib>

void TV(int diagonal);

double width(int diagonal);

double height(int diagonal);

double area(int diagonal);

int main()
{
  cout << " Nagi Kasuya \n";
  cout << " ID: 1871978\n";
  cout << " File: " << __FILE__ << "\n";
  cout << " Compiled: " << __DATE__ << " at " << __TIME__ << "\n";

  cout << '\n';

  int diagonal1 = 0;
  int diagonal2 = 0;
  int diagonal3 = 0;
  int diagonal4 = 0;
  int diagonal5 = 0;
  string buf;
  cout << "Enter the diagonal inches for 1st TV :";
  cin >> buf; diagonal1 = atoi(buf.c_str());
  cout << "Enter the diagonal inches for 2st TV :";
  cin >> buf; diagonal2 = atoi(buf.c_str());
  cout << "Enter the diagonal inches for 3st TV :";
  cin >> buf; diagonal3 = atoi(buf.c_str());
  cout << "Enter the diagonal inches for 4st TV :";
  cin >> buf; diagonal4 = atoi(buf.c_str());
  cout << "Enter the diagonal inches for 5st TV :";
  cin >> buf; diagonal5 = atoi(buf.c_str());

  cout << '\n';

  cout << " diagonal      width      height      area " << '\n';
  cout << " --------      -----      ------      ---- " << '\n';

  TV(diagonal1);
  TV(diagonal2);
  TV(diagonal3);
  TV(diagonal4);
  TV(diagonal5);
}

double width(int diagonal)
{

  double width = 0;
  double x = pow(16.0, 2.0);
  double y = pow(9.0, 2.0);
  double z = sqrt(x + y);

  width = ((double)(diagonal / z) * 16);

  return width;
}

double height(int diagonal)
{

  double height = 0;
  double x = pow(16.0, 2.0);
  double y = pow(9.0, 2.0);
  double z = sqrt(x + y);

  height = double((diagonal / z) * 9);

  return height;
}

double area(int diagonal)
{

  double width = 0;
  double height = 0;
  double area = 0;
  double x = double(pow(16.0, 2.0));
  double y = double(pow(9.0, 2.0));
  double z = sqrt(x + y);

  width = (diagonal / z) * 16;
  height = (diagonal / z) * 9;

  area = width * height;

  return area;
}

void TV(int diagonal)
{


  cout.width(6);
  cout << diagonal;

  cout.setf(ios::fixed);
  cout.precision(1);

  cout.width(14);
  cout << width(diagonal);

  cout.width(12);
  cout << height(diagonal);

  cout.setf(ios::fixed);
  cout.precision(0);

  cout.width(10);
  cout << area(diagonal) << endl;

}