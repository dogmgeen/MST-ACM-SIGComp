/* Allocate space for an array with ten elements of type
   int. */

int *ptr = (int *) malloc(10 * sizeof (int));
if (ptr == NULL) {
  /* Memory could not be allocated, the program should
      handle the error here as appropriate. */
} else {
  /* Allocation succeeded.  Do something.  */
  free(ptr);  /* We are done with the int objects, and
                  free the associated pointer. */
  ptr = NULL; /* The pointed-to-data  must not be used again,
                  unless re-assigned by using malloc
                  again. */
}
