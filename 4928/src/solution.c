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

  int series_itr;
  for (series_itr=0; series_itr<numberOfSeries; series_itr++)
  {
    int totalMinutes = 0;
    fgets(buffer, BUFFER_SIZE, stdin);

    int numberOfBooks;
    sscanf(buffer, "%d ", &numberOfBooks);

printf("  Number of books for series #%d: %d\n", series_itr+1, numberOfBooks);

    int book_itr;
    for (book_itr=0; book_itr<numberOfBooks; book_itr++)
    {
      int durationOfMovie;
      sscanf(buffer, "%d ", &durationOfMovie);

printf("    Length of the movie for book #%d: %d\n", book_itr+1, durationOfMovie);
    }

    printf(TEMPLATE_LINE, 0);
  }

  return 0;
}

