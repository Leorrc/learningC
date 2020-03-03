#include <stdio.h>
#include <stdlib.h>

int main()
{
  char  *n;
  char  *p;
  int   prec;
  int   len;
  
  n = "-12345";
  prec = 10;
  len = 0;
  while (*n++)
    len++;
  if (len < prec)
  {
    p = (char *)malloc(len + prec + 1);
    if (*n == '-')
      *p++ = *n++;
    while (*p)
    {
      while (prec > 0)
      {
        *p = '0';
        p++;
        prec--;
      }
      while (*n)
      {
        *p = *n;
        p++;
        n++;
      }
    }
  }
  return (0);
}
