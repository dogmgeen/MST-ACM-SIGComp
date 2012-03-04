/*
Author: Doug McGeehan (djmvfb@mst.edu)
Date: March 2nd, 2012
*/

#include <stdio.h>

#define NUM_ROPES 3
#define HIGHEST_NUMBER_OF_PITCHES_FOR_LONGEST_ROPE 35

static int ignore;

typedef struct {
  int totalHeight;
  int highestPitch;
  int ropeLength;
} pitch;

int main()
{
  pitch currentClimb;
  int numberOfPitches;
  const int ROPES[ NUM_ROPES ] = {50, 60, 70};

  /* In order to descend, the total height of all pitch heights
      must be less than or equal to half the length of the rope being used. */
  const int MAX_DESCENT_HEIGHT[ NUM_ROPES ] = {25, 30, 35};

  ignore = scanf("%d", &numberOfPitches);
  while (numberOfPitches)
  {
    if ( HIGHEST_NUMBER_OF_PITCHES_FOR_LONGEST_ROPE < numberOfPitches )
    {
      /* We know a pitch can be at least one foot. The longest rope we have
          available is 70 feet. Thus, the upper bound of a total climbable 
          mountain is half of the length of our largest rope. In this case,
          35 feet. If the number of pitches is greater than 35, there is no
          possible way we'll be able to descend from the top, even with the
          longest rope. */
      printf("0 0 0");

      /* Move to next line of input. Just ignore everything until newline. */
      ignore = scanf("%*[ 0123456789]\n");
    }
    else
    {
      int startingRopeIndex;
      if ( 30 < numberOfPitches )
      {
        /* The 60- and 50-foot rope will not be able to descend the mountain! */
        printf("0 0 ");
        startingRopeIndex = 2;
      }
      else if ( 25 < numberOfPitches )
      {
        /* The 50-foot rope will not be able to descend the mountain! */
        printf("0 ");
        startingRopeIndex = 1;   
      }
      else
      {
        startingRopeIndex = 0;
      }

      /* Reset values to default. */
      currentClimb.totalHeight = 0;
      currentClimb.highestPitch = 0;

      int currentPitch;

      /* Get all pitch heights from stdin
          + currentClimb->totalHeight is the sum of all pitch heights
          + currentClimb->highestPitch is the highest pitch of the current climb */
      int itr;
      for (itr=0; itr < numberOfPitches; itr++)
      {
        scanf("%d", &currentPitch);
        currentClimb.totalHeight += currentPitch;
  
        if ( currentClimb.highestPitch < currentPitch )
        {
          currentClimb.highestPitch = currentPitch;
        }
      }

      /* For each of the ropes, display how many people
          will be able to climb all pitches of the current
          trip. */
      for (itr=startingRopeIndex; itr < NUM_ROPES; itr++)
      {
        /* Test if the descent can be made safely for the given length of rope. */
        currentClimb.ropeLength = ROPES[itr];

        if ( 2*(currentClimb.totalHeight) > ROPES[itr] )
        {
          /* No descent can be made safely with the current length of rope. */
          printf("0 ");
        }
        else
        {
          if (currentClimb.highestPitch)
          {
            printf("%d ", 1+( currentClimb.ropeLength / currentClimb.highestPitch ));
          }
          else
          {
            printf("0 ");
          }
        }
      }
    }

    printf("\n");
    ignore = scanf("%d", &numberOfPitches);
  }

  return 0;
}

