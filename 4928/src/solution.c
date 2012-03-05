/*
Author: Doug McGeehan (djmvfb@mst.edu)
Date: March 4th, 2012
*/

#include <stdio.h>

int main()
{
  int numberOfSeries;
  scanf("%d", &numberOfSeries);
  printf("Number of series: %d\n", numberOfSeries);

  while (!feof(stdin))
  {
    puts("Just keep looping until the EOF");
    scanf("%*[ 0123456789\n]");
  }

  return 0;
}

