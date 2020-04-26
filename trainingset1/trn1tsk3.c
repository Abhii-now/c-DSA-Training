//tran1tsk3.c


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define POW '^'
#define LPAR '('
#define RPAR ')'
#define PLUS '+'
#define MULT '*'
#define MOD '%'
#define FINISH '\0'
#define INT '0'

char output[100];
char stack[100];
int index = 0;
  int i,j = 0;

int isFull()
{
	if(index == 50)
		return 1;
	else
		return 0;

}

int isEmpty()
{
	if(index <= 0)
		return 1;
	else
		return 0;
}

void push(int a)
{
  if(isFull())
  {
  	printf("stack overflow");
  }
  else
  	stack[++index] = a;
}

int pop()
{
	if(isEmpty())
	{
		printf("stack underflow");
	}
	else
		return stack[index--];

}

void peek()
{

	printf("%d\n", stack[index]);
}

struct token
{
  char kind;
  int value;
};

char expr[100];
int where = 0;
void skipWhite()
{
  while (isspace(expr[where]))
  where++;
}
void skipDigits()
{
  while (isdigit(expr[where]))
  where++;
}
struct token getNextToken()
{
  struct token token;
  skipWhite();
  if(isdigit(expr[where]))
  {
    sscanf(&expr[where],"%d", &token.value);
    token.kind = INT;
    skipDigits();
  }
    else
    {
        token.kind = expr[where];
        where++;
    }

  return token;
}

int precedence(char ch)
{
   if(ch == '+' || ch == '-')
   {
      return 1;
   }
   else if(ch == '*' || ch == '%')
   {
      return 2;
   }
   else if(ch == '^')
   {
      return 3;
   }
   else
   {
      return 0;
   }
}

void emptystack()
{
  while(index != 0)
  {
    output[i++] = pop();
  }
}

void checkprecedence(char ch)
{
    char temp[100];
    temp[index] = precedence(ch);
    if(ch == ')')
    {
      char temp;
      while ('(' != temp)
      {
          temp = pop()
      }
    }

    if(ch)
  for(int k = index; k > 0; k--)
	{
    if(temp[index] <= stack[k])
		{
      output[i++] = pop();
    }
	}
}



//char convert(char *)

/*int eval(int a, int b, char ch)
{
  int c;
  switch(ch)
  {
    case '+':
      c = a + b;
      return c;
    break;

    case '*':
     c = a * b;
     return c;
    break;

    case '%':
      c = a % b;
      return c;
    break;

    default :
    printf("error, invalid operator");
  }
}*/

int main()
{
  struct token token;

  printf("Input expression:");
  fgets(expr, 99, stdin);
  token = getNextToken();
  while (token.kind != FINISH)
  {
      if (token.kind == INT)
      {
        output[i++] = (char)token.value;
      }
      else
      {
      	checkprecedence(token.kind);
        push(token.kind);

      }
      token = getNextToken();
  }
  emptystack();
int a = 0;
while(a != 10)
      {
        printf("%c ",output[a]);
        a++;}

        printf("%d", index);
  return 0;
}
