/* Author: Doug McGeehan (djmvfb@mst.edu)
   Date: March 2nd, 2012 */

#include <stdio.h>

#define NUM_ROPES 3

typedef struct {
  int totalHeight;
  int highestPitch;
  int ropeLength;
} pitch;

void loadNewClimbData(pitch*, const int);
int getNumberOfClimbersForGivenRope(const pitch*);

int main()
{
  pitch currentClimb;
  int numberOfPitches;
  const int ROPES[NUM_ROPES] = {50, 60, 70};

  scanf("%d", &numberOfPitches);
  while (numberOfPitches != 0)
  {
    loadNewClimbData(&currentClimb, numberOfPitches);

    /* For each of the ropes, display how many people
        will be able to climb all pitches of the current
        trip. */
    int i;
    for (i=0; i < NUM_ROPES; i++)
    {
      /* Test if the descent can be made safely for the given length of rope. */
      currentClimb.ropeLength = ROPES[i];

      if ( 2*(currentClimb.totalHeight) > ROPES[i] )
      {
        /* No descent can be made safely with the current length of rope. */
        printf("%d ", 0);
      }
      else
      {
        if (0 == currentClimb.highestPitch)
        {
          return -1;
        }
        else
        {
          int numberOfClimbers = getNumberOfClimbersForGivenRope( &currentClimb );
          printf("%d ", numberOfClimbers);
        }
      }
    }

    printf("\n");
    scanf("%d", &numberOfPitches);
  }

  return 0;
}

void loadNewClimbData(pitch* currentClimb, const int NUM_PITCHES)
{
  /* Reset values to default. */
  currentClimb->totalHeight = 0;
  currentClimb->highestPitch = 0;

  int currentPitch;

  /* Get all pitch heights from stdin
      + currentClimb->totalHeight is the sum of all pitch heights
      + currentClimb->highestPitch is the highest pitch of the current climb */
  int i;
  for (i=0; i < NUM_PITCHES; i++)
  {
    const int PREV_HIGHEST_PITCH = currentClimb->highestPitch;

    scanf("%d", &currentPitch);
    currentClimb->totalHeight += currentPitch;
  
    if ( PREV_HIGHEST_PITCH < currentPitch )
    {
      currentClimb->highestPitch = currentPitch;
    }
  }
}

int getNumberOfClimbersForGivenRope( const pitch* CURRENT_CLIMB )
{
  if (CURRENT_CLIMB->highestPitch == 0)
  {
    return -1;
  }
  else
  {
    return 1+( CURRENT_CLIMB->ropeLength / CURRENT_CLIMB->highestPitch );
  }
}

