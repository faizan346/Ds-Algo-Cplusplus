#include <iostream>
#include <string.h>
using namespace std;
int main()
{
  string s;
  int state = 0, count = 0;

  cout << "the grammar is: S->aS, S->Sb, S->ab \n";
  cout << "enter the string to be checked \n";
  cin >> s;
  while (s[count] != '\0')
  {
    switch (state)
    {
    case 0:
      if (s[count] == 'a')
        state = 1;
      else
        state = 3;
      break;
    case 1:
      if (s[count] == 'a')
        state = 1;
      else if (s[count] == 'b')
        state = 2;
      else
        state = 3;
      break;
    case 2:
      if (s[count] == 'b')
        state = 2;
      else
        state = 3;
      break;
    default:
      break;
    }
    count++;
    if (state == 3)
      break;
  }
  if (state == 2)
    cout << "string is accepted";
  else
    cout << "string is not accepted";
  cout << endl;

  return 0;
}
