#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct chair {
  struct chair* leftChair;
  char* player;
  struct chair* rightChair;
};
/* Free all memory that is accessible to dlist
from pointer marking its start. This includes memory
with struct as well as with string player
*/
struct chair* initDList();
/* Create a new chair for a player. Add it to the
list. Terminate prog if memory not available
*/
void insertChair(char* player);
/* Free person name string and chair too.
Count the fisrt pointed chair as numbered 0.
Displacement can be positive or negative from
chair 0. Player pointer should not be NULL.
*/
char* removeChair(int displacement);
/* Return name of the person in the chair */
char* whoInChair();
/* Is there any chair left in the game? */
int isEmpty();