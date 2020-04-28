
#include <stdio.h>
#include <stdlib.h>

#include "expr.h"
expression expr1;
expression expr2;
expression result;
struct term *term1P, *term2P;

int main(void) {
  /* Construct expression 1 */
  createExpr(&expr1);  // Get the start pointer set
  insertTerm(&expr1, 10, 1000);
  insertTerm(&expr1, 100, 2000);
  insertTerm(&expr1, -10, 500);
  insertTerm(&expr1, -10, -1000);
  printf("Expression_1 = ");
  printExpr(&expr1);
  // reverse sign to subtract
  reverseSign(&expr1);
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
  term1P = getFirstTerm(&expr1);
  term2P = getFirstTerm(&expr2);
  while (term1P != NULL || term2P != NULL) {
    if (term1P == NULL) {
      insertTerm(&result, term2P->coeff, term2P->power);
      term2P = getNextTerm(&expr2, term2P);
      continue;
    }
    if (term2P == NULL) {
      insertTerm(&result, term1P->coeff, term1P->power);
      term1P = getNextTerm(&expr1, term1P);
      continue;
    }
    if (term1P->power == term2P->power) {
      if (term1P->coeff + term2P->coeff != 0)
        insertTerm(&result,

                   term1P->coeff + term2P->coeff, term2P->power);

      term2P = getNextTerm(&expr2, term2P);
      term1P = getNextTerm(&expr1, term1P);
      continue;
    }
    if (term1P->power > term2P->power) {
      insertTerm(&result, term1P->coeff, term1P->power);
      term1P = getNextTerm(&expr1, term1P);
      continue;
    }
    if (term1P->power < term2P->power) {
      insertTerm(&result, term2P->coeff, term2P->power);
      term2P = getNextTerm(&expr2, term2P);
      continue;
    }
  }
  printf("Expression_1 - Expression_2 = ");
  printExpr(&result);
  return 0;
}