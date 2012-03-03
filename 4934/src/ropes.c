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
    
    // For each of the ropes, display how many people
    //  will be able to climb all pitches of the current
    //  trip.
    for (int i=0; i < NUM_ROPES; i++)
    {
      int numberOfClimbers = 0;
      int climbersForCurrentPitch = 1;

      for (int pitch=0; pitch < numberOfPitches; pitch++)
      {
        const int PITCH_HEIGHT = pitchHeights[pitch];
        const int ROPE_LENGTH  = ROPES[i];
        bool notEnoughRope = (PITCH_HEIGHT > ROPE_LENGTH);
        if (notEnoughRope)
        {
          numberOfClimbers = 0;
          break;
        }
        else
        {
          int piled = 0;
          int dangled = ROPE_LENGTH;
          do {
            climbersForCurrentPitch++;
            piled += PITCH_HEIGHT;
            dangled -= PITCH_HEIGHT;
          } while ( piled < ROPE_LENGTH );
        }

        // Update the value of numberOfClimbers
        if (0 == pitch)
        {
          numberOfClimbers = climbersForCurrentPitch;
        }
        else
        {
          if (numberOfClimbers > climbersForCurrentPitch)
          {
            numberOfClimbers = climbersForCurrentPitch;
          }
        }
      }

      printf("%d ", numberOfClimbers);
    }

    free(pitchHeights);
    pitchHeights = NULL;

    printf("\n");
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
