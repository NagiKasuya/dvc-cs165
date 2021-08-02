// Identification comments code block
// Nagi Kasuya
// ID: 1871978



#include <iostream>
using std::cout;
using std::cin;
using std::ios;

# include <string>
using std::string;

#include <cstdlib>

#include <cmath>

int main()
{
  cout << " Nagi Kasuya \n\n";
  cout << " ID: 1871978\n";
  cout << " File: " << __FILE__ << "\n";
  cout << " Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";

  cout.setf(ios::fixed);
  cout.precision(1);

  double diagonal = 0;
  double width = 0;
  double height = 0;
  double area = 0;

  string buf;

  cout << " Enter the diagonal size of your favorite TV, in inches : ";
  cin >> buf; diagonal = atof(buf.c_str());

  /* side square is x, vertical square is y, and diagonal ratio is z.*/

  double x = pow(16.0, 2.0);
  double y = pow(9.0, 2.0);
  double z = sqrt(x + y);

  width = (diagonal / z) * 16.0;
  height = (diagonal / z) * 9.0;

  area = width * height;



  cout << " The area of a 42 inch TV is " << area << '\n';




}