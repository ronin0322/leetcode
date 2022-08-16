#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
  char ch;
  ch = getchar();
  int num[200];
  char s[200];
  int mi = 200;
  int i = 0;
  for (; ch != '\n';i++)
  {
    num[ch - 'A']++;
    s[i] = ch;
    ch = getchar();
  }
  for (int j = 0; j < 26; j++)
  {
    mi = min(mi, num[j]);
  }
  for (int j = 0; j < i; j++)
  {
    if (num[s[j]] == mi)
    {
      continue;
    }
    cout << s[j];
  }
  return 0;
}