/*
Author: Doug McGeehan (djmvfb@mst.edu)
Date: March 4th, 2012
*/

#define BUFFER_SIZE 1024
#include <stdio.h>

int main()
{
  char buffer[BUFFER_SIZE];

  while (fgets(buffer, BUFFER_SIZE, stdin))
  {
    puts(buffer);
  }

  return 0;
}

