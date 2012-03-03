// Author: Doug McGeehan (djmvfb@mst.edu)
// Date: March 2nd, 2012

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_ROPES 3

int* loadPitchHeights(const int n);

int main()
{
  int numberOfPitches;
  int* pitchHeights;

  const int ROPES[NUM_ROPES] = {50, 60, 70};

  scanf("%d", &numberOfPitches);
  while (numberOfPitches != 0)
  { 
    // Load the pitch heights into an array
    pitchHeights = loadPitchHeights(numberOfPitches);
    
    for (int i=0; i < NUM_ROPES; i++)
    {
      int numberOfClimbers;

      int climbersForCurrentPitch = 1;
      int minimumNumberOfClimbers = 1;
      for (int pitch=0; pitch < numberOfPitches; pitch++)
      {
        const int PITCH_HEIGHT = pitchHeights[pitch];
        const int ROPE_LENGTH  = ROPES[i];
        bool notEnoughRope = (PITCH_HEIGHT > ROPE_LENGTH);
        if (notEnoughRope)
        {
          climbersForCurrentPitch = 0;
          break;
        }
        else
        {
          int lengthOnTop, lengthInUse, lengthOnBottom;

          lengthOnTop = 0;
          lengthInUse = PITCH_HEIGHT;
          lengthOnBottom = ROPE_LENGTH - lengthInUse;
          while (lengthOnBottom >= 0)
          {
            lengthOnTop += PITCH_HEIGHT;
            lengthOnBottom -= PITCH_HEIGHT;
            climbersForCurrentPitch++;
          }

          if (lengthOnBottom >= 0)
          {
            climbersForCurrentPitch++;
          }

        }

        if (pitch > 0)
        {
          if (climbersForCurrentPitch < minimumNumberOfClimbers)
          {
            minimumNumberOfClimbers = climbersForCurrentPitch;
          }
        }
        else
        {
          minimumNumberOfClimbers = climbersForCurrentPitch;
        }
      }

      numberOfClimbers = minimumNumberOfClimbers;

      printf("%d ", numberOfClimbers);
    }

    free(pitchHeights);
    pitchHeights = NULL;

    printf("\n");
    //printf("%d %d %d\n",mOriginal,nOriginal,max);
    scanf("%d", &numberOfPitches);
  }
}

int* loadPitchHeights(const int numberOfPitches)
{
  int* pitchHeight = (int *) malloc(numberOfPitches * sizeof (int));
  for (int i=0; i < numberOfPitches; i++)
  {
    scanf("%d", &(pitchHeight[i]));
  }

  return pitchHeight;
}
