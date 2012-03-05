/*
Author: Doug McGeehan (djmvfb@mst.edu)
Date: March 2nd, 2012
*/

#include <stdio.h>

int main()
{
  do 
  {
    printf("0 0 0\n");
  } while (!scanf("%*[ 0123456789]\n"));

  return 0;
}

