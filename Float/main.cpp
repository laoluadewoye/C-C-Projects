#include <iostream>

using namespace std;

int
main ()
{
  float ft[4];
  float *p;

  p = ft;
  *p = 3.14;
  p++;
  *p = 4.5;
  p = ft + 2;
  *p = 8.35;
  p = ft + 3;
  *p = 10.85;

  for (int n = 0; n < 4; n++)
    {
      cout << ft[n] << ", " << &ft[n] << endl;
    }

  cout << endl << "Part 2:\n\n";

  string fruit[6];
  string *pt;

  pt = fruit;
  *pt = "Raspberries";
  pt++;
  *pt = "Strawberries";
  pt = fruit + 2;
  *pt = "Apple";
  pt = fruit + 3;
  *pt = "Oranges";
  pt = fruit + 4;
  *pt = "Grapes";
  pt = fruit + 5;
  *pt = "Banana";

  for (int n = 0; n < 6; n++)
    {
      cout << fruit[n] << ", " << &fruit[n] << endl;
    }

  return 0;
}
