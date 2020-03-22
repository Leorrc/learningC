#include <stdio.h>
#include "printf.h"

int main()
{

   int   a = 12;
  int   b = 18;
  char  c = 'a';
  int   d = 2147483647;
  int   e = -2147483648;
  int   f = 42;
  int   g = 25;
  int   h = 4200;
  int   i = 8;
  int   j = -12;
  int   k = 123456789;
  int   l = 0;
  int   m = -12345678;
  char  *n = "abcdefghijklmnop";
  char  *o = "-a";
  char  *p = "-12";
  char  *q = "0";
  char  *r = "%%";
  char  *s = "-2147483648";
  char  *t = "0x12345678";
  char  *u = "-0";
  int   pr;

//  ft_printf("|%-c||%*c|\n", '-', -a, '-');
  //printf("|%-c||%*c|\n", '-', -a, '-');
 
  pr = ft_printf("%-*c,  %*c, %-*c", a, p[0], a, q[0], a, r[0], a, c);
  printf("\n%d\n", pr);

  pr = printf("%-*c,  %*c, %-*c", a, p[0], a, q[0], a, r[0], a, c);
  printf("\n%d\n", pr);
  return (0);
}
