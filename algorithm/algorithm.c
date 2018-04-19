#include <stdio.h>
#include <stdlib.h>

int get_fibonacci_number(int);

int main ()
{
  int n = 4;
  printf("%d", get_fibonacci_number(n));
  return 0;
}

int get_fibonacci_number(int n)
{
   if (1 == n)
        return n;
    if (n <= 0)
        return n;

   return get_fibonacci_number(n-1) + get_fibonacci_number(n-2);
}
