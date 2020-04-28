
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
  struct chair* temp = head;
  assert(displacement != 0);

  if (displacement < 0) {
    displacement *= -1;
    for (int i = 0; i < displacement; i++)
      temp = temp->leftChair;
  } else {
    for (int i = 0; i < displacement; i++)
      temp = temp->rightChair;
  }

  if (head == NULL) {
    return "no player left to be removed";
  } else if (head->rightChair == head) {
    temp = head;
    printf("all players removed");
  } else {
    if (head == temp) {
      head = head->leftChair;
    }

    temp->leftChair->rightChair = temp->rightChair;
    temp->rightChair->leftChair = temp->leftChair;
  }

  char* name = temp->player;
  assert(temp != NULL);

  free(temp);

  num_of_players--;
  printf(" number of players : %d", num_of_players);
  return name;
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