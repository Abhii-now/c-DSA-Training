
#include "dlist.h"

int num_of_players = 0;

struct chair* head = NULL;

struct chair* initDList() {
  struct chair* newchair = (struct chair*)malloc(sizeof(struct chair));
  newchair->leftChair = newchair->rightChair = 0;
  newchair->player = "name";
  assert(newchair != NULL);
}

void insertChair(char* player) {
  struct chair* newchair = initDList();
  newchair->player = player;
  assert(newchair != NULL);
  if (head == NULL) {
    head = newchair;
    newchair->leftChair = head;
    newchair->rightChair = head;
  } else if (head->leftChair == NULL || head->rightChair == NULL) {
    head->leftChair, head->rightChair = newchair;
    newchair->rightChair, newchair->leftChair = head;
    head = newchair;
  } else {
    newchair->rightChair = head;
    newchair->leftChair = head->leftChair;
    head->leftChair->rightChair = newchair;
    head->leftChair = newchair;
  }
  num_of_players++;
  printf("add new player : %s\n", player);
}

char* removeChair(int displacement) {
  printf("implemented in case 3");
}

char* whoInChair() {
  assert(head != NULL);

  if (!isEmpty())
    return head->player;
  else
    return "no player found";
}

int isEmpty() {
  if (num_of_players == 0)
    return 1;
  else {
    return 0;
  }
}