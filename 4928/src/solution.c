/*
Author: Doug McGeehan (djmvfb@mst.edu)
Date: March 4th, 2012
*/

#include <stdio.h>
#define BUFFER_SIZE 1024

int main()
{
  const char TEMPLATE_LINE[] = "Boudreau is going to spend %d minutes watching movies.\n";
  char buffer[BUFFER_SIZE];

  int numberOfSeries;
  scanf("%d\n", &numberOfSeries);

  while (fgets(buffer, BUFFER_SIZE, stdin))
  {
    printf(TEMPLATE_LINE, 0);
  }

  return 0;
}

