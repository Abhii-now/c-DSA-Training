#include "expr.h"

#include <stdio.h>
#include <stdlib.h>
/* Gives pointer to the first term in the expression list */
struct term* getFirstTerm(expression* ptrToExpr) {
  assert(ptrToExpr != NULL);
  assert(*ptrToExpr != NULL);
  return (*ptrToExpr)->nextP;
}
/* Initialise a expression with no term */
void createExpr(expression* ptrToExpr) {
  assert(ptrToExpr != NULL);
  (*ptrToExpr) = malloc(sizeof(struct term));
  (*ptrToExpr)->nextP = NULL;
}

void reverseSign(expression* ptrToExpr) {
  struct term* temp;
  temp = *ptrToExpr;
  while (temp != NULL) {
    temp->coeff *= -1;
    temp = getNextTerm(ptrToExpr, temp);
  }
}

/* Insert a new term in expression list -- term with power should not exist
 */
void insertTerm(expression* ptrToExpr, int coeff, int power) {
  struct term *ptr, *prev;
  struct term* newTerm = malloc(sizeof(struct term));
  newTerm->coeff = coeff;
  newTerm->power = power;
  ptr = getFirstTerm(ptrToExpr);
  prev = *ptrToExpr;
  /* Notice that ptr is used only if not NULL */
  while (ptr != NULL && power < ptr->power) {
    // Find the right location for new node
    prev = ptr;
    ptr = getNextTerm(ptrToExpr, ptr);
  }
  assert(ptr == NULL || ptr->power != power);
  newTerm->nextP = ptr;
  prev->nextP = newTerm;
}
/* Gives next term in the expression after one referenced by termP */
struct term* getNextTerm(expression* ptrToExpr, struct term* termP) {
  assert(termP != NULL);
  return termP->nextP;
}
/* Available here but not through expr.h */
static void printTerm(struct term* term) {
  printf("%+d*X^%d ", term->coeff, term->power);
}
/* Prints the expression */
void printExpr(expression* ptrToExpr) {
  struct term* prnt = getFirstTerm(ptrToExpr);
  while (prnt != NULL) {
    printTerm(prnt);
    prnt = getNextTerm(ptrToExpr, prnt);
  }
  printf("\n");
}

void addTerm(expression* prtToExpr, int coeff, int power) {
  struct term* temp = *prtToExpr;

  temp = searchTerm(prtToExpr, power);
  if (power == temp->power) {
    temp->coeff = temp->coeff + coeff;

  } else {
    insertTerm(prtToExpr, coeff, power);
  }
}

struct term* searchTerm(expression* prtToExpr, int pow) {
  struct term* temp = *prtToExpr;

  temp = temp->nextP;

  while (temp->power > pow) {
    if (temp == NULL)
      break;
    assert(temp != NULL);
    temp = (temp)->nextP;
  }
  return (temp);
}

void makeExprCopy(expression* srcExpr, expression* dstExpr) {
  struct term* temp = *srcExpr;
  temp = temp->nextP;
  while (temp != NULL) {
    int coeff = temp->coeff;
    int pow = temp->power;
    insertTerm(dstExpr, coeff, pow);
    temp = temp->nextP;
  }
}