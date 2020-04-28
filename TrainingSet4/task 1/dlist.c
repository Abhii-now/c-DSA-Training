// minimalistic code for compiling purposes stating all the functions required

#include "dlist.h"

struct chair* head = NULL;

struct chair* initDList() {
  struct chair* newchair = (struct chair*)malloc(sizeof(struct chair));
  newchair->leftChair = newchair->rightChair = 0;
  newchair->player = "name";
  assert(newchair != NULL);
}

void insertChair(char* player) {
  printf("NOT IMPLEMMENTED \n");
}

char* removeChair(int displacement) {
  return "NOT IMPLEMMENTED \n";
}

char* whoInChair(int displacement) {
  return "NOT IMPLEMMENTED \n";
}
int isEmpty() {
  if (head = NULL)
    return 0;
  else {
    return 1;
  }
}