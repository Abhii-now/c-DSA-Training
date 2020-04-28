
#include <stdio.h>
#include <stdlib.h>

#include "expr.h"
expression expr1;
expression expr2;
expression result;
struct term *term1P, *term2P;

int main(void) {
  /* Construct expression 1 */
  struct term* temp;
  createExpr(&expr1);  // Get the start pointer set
  insertTerm(&expr1, 10, 1000);
  insertTerm(&expr1, 100, 2000);
  insertTerm(&expr1, -10, 500);
  insertTerm(&expr1, -10, -1000);
  printf("Expression_1 = ");
  printExpr(&expr1);

  /* Construct expression 2 */
  createExpr(&expr2);  // Get the start pointer set
  insertTerm(&expr2, 10, 1000);
  insertTerm(&expr2, 200, 3000);
  insertTerm(&expr2, 110, 500);
  insertTerm(&expr2, 1000, 0);
  insertTerm(&expr2, 10, -1000);
  printf("Expression_2 = ");
  printExpr(&expr2);

  /* Construct result = expr1 + expr2 */
  createExpr(&result);
  makeExprCopy(&expr2, &result);

  term1P = getFirstTerm(&expr1);

  while (term1P != NULL) {
    addTerm(&result, term1P->coeff, term1P->power);
    term1P = getNextTerm(&expr1, term1P);
  }

  printf("Expression_2 + Expression_1 = ");
  printExpr(&result);
  return 0;
}