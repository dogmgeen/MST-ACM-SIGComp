/*
Author: Doug McGeehan (djmvfb@mst.edu)
Date: March 9th, 2012
*/

#define BUFFER_SIZE 1024
#include <stdio.h>
#include <string.h>

int main()
{
  char buffer[BUFFER_SIZE];
  char name[BUFFER_SIZE];
  unsigned int weight = 0;
  unsigned int days = 0;
  
  do
  {
    int atEnd; 
    do
    {
      fgets(buffer, BUFFER_SIZE, stdin);
      const int AT_START = strncmp( buffer, "START", 5 );
      atEnd = strncmp( buffer, "END", 3 );
      if ( 0 == AT_START )
      {
      }
      else if ( 0 != atEnd )
      {
        sscanf(buffer, "%s %d %d\n", name, &weight, &days);
        puts(name);
/*printf("%s weighed %d pounds and was on the diet for %d days.\n", name, weight, days);*/
      }
      else
      {
        printf("SOMETHING ELSE?\n");
      }

    } while ( 0 != atEnd );
    printf("END\n");
  } while (!feof(stdin));

  return 0;
}

