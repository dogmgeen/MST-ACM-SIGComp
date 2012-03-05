/*
Author: Doug McGeehan (djmvfb@mst.edu)
Date: March 4th, 2012
*/

#include <stdio.h>

int main()
{
  while (!feof(stdin))
  {
    puts("Just keep looping until the EOF");
    scanf("%*[ 0123456789\n]");
  }

  return 0;
}

