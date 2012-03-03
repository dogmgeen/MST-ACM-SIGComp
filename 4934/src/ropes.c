// Author: Doug McGeehan (djmvfb@mst.edu)
// Date: March 2nd, 2012

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_ROPES 3

int main()
{
  int numberOfPitches;
  int* pitchHeight;

  const int ROPES[NUM_ROPES] = {50, 60, 70};

  scanf("%d", &numberOfPitches);
  while (numberOfPitches != 0)
  { 
    // Load the pitch heights into an array
    pitchHeight = (int *) malloc(numberOfPitches * sizeof (int));
    for (int i=0; i < numberOfPitches; i++)
    {
      scanf("%d", &(pitchHeight[i]));
    }

    for (int i=0; i < NUM_ROPES; i++)
    {
      for (int pitch=0; pitch < numberOfPitches; pitch++)
      {
        const int PITCH_HEIGHT = pitchHeight[pitch];
        const int ROPE_LENGTH  = ROPES[i];
        bool notEnoughRope = (PITCH_HEIGHT > ROPE_LENGTH);
        if (notEnoughRope)
        {
          printf("%d ", 0);
        }
        else
        {
          int lengthOnTop, lengthInUse, lengthOnBottom;
          int climbers = 1;

          lengthOnTop = 0;
          lengthInUse = PITCH_HEIGHT;
          lengthOnBottom = ROPE_LENGTH - lengthInUse;
          while (lengthOnBottom >= 0)
          {
            lengthOnBottom -= PITCH_HEIGHT;
            climbers++;
          }

          if (lengthOnBottom >= 0)
          {
            climbers++;
          }

          printf("%d ", climbers);
        }
      }
    }

    free(pitchHeight);
    pitchHeight = NULL;

    printf("\n");
    //printf("%d %d %d\n",mOriginal,nOriginal,max);
    scanf("%d", &numberOfPitches);
  }
}

