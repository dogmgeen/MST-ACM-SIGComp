// Author: Doug McGeehan (djmvfb@mst.edu)
// Date: March 2nd, 2012

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "climb.h"

#define NUM_ROPES 3

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

    const int TOTAL_CLIMB_HEIGHT = totalHeightOfAllPitches(pitchHeights, numberOfPitches);

    // For each of the ropes, display how many people
    //  will be able to climb all pitches of the current
    //  trip.
    for (int i=0; i < NUM_ROPES; i++)
    {
      // Test if the descent can be made safely for the given length of rope.
      const int ROPE_LENGTH  = ROPES[i];
      if ( 2*TOTAL_CLIMB_HEIGHT > ROPE_LENGTH )
      {
        // No descent can be made safely with the current length of rope.
        printf("%d ", 0);
      }
      else
      {
        int numberOfClimbers = getNumberOfClimbersForGivenRope( ROPE_LENGTH, pitchHeights, numberOfPitches );
        printf("%d ", numberOfClimbers);
      }
    }

    free(pitchHeights);
    pitchHeights = NULL;

    printf("\n");
    scanf("%d", &numberOfPitches);
  }
}

int getNumberOfClimbersForGivenRope( const int ROPE_LENGTH, const int* pitchHeights, const int numberOfPitches )
{
  const int HIGHEST_PITCH = getHighestPitch( pitchHeights, numberOfPitches );
  return 1+(ROPE_LENGTH / HIGHEST_PITCH);
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

int totalHeightOfAllPitches(const int* pitches, const int numberOfPitches)
{
  int totalHeight = 0;
  for (int i=0; i<numberOfPitches; i++)
  {
    totalHeight += pitches[i];
  }
  return totalHeight;
}

int getHighestPitch( const int* pitches, const int numberOfPitches )
{
  int highestPitch = 0;
  for (int i=0; i < numberOfPitches; i++)
  {
    if ( pitches[i] > highestPitch )
    {
      highestPitch = pitches[i];
    }
  }

  return highestPitch;
}

