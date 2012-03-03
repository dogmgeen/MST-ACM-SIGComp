// Author: Doug McGeehan (djmvfb@mst.edu)
// Date: March 2nd, 2012

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int numberOfPitches;
  int* pitchHeight;

  const int ROPES[3] = {50, 60, 70};

  scanf("%d", &numberOfPitches);
  while (numberOfPitches != 0)
  { 
    printf("%s %d\n", "Number of pitches: ", numberOfPitches);

    // Load the pitch heights into an array
    pitchHeight = (int *) malloc(numberOfPitches * sizeof (int));
    for (int i=0; i < numberOfPitches; i++)
    {
      printf("%s %d%s", "Pitch number", i, ": ");
      scanf("%d", &(pitchHeight[i]));
      printf("%d\n", pitchHeight[i]);
    }

    free(pitchHeight);
    pitchHeight = NULL;

    //printf("%d %d %d\n",mOriginal,nOriginal,max);
    scanf("%d", &numberOfPitches);
  }
}

