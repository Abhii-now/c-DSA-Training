#include<stdio.h>


#define SIZE 100001
#define MAX 99999

int queue[SIZE];

int prime[10000];

int j = 0;
int root = 2;
int index = 0;
int temp;

void init();

void isprime();


int main()
{
  init();

  isprime();
  printf("index is %d", index);
  while(queue[i] != )
  {
    
  }
  return 0;
}

void isprime()
{
  if(root < 99999)
{
  if(queue[index] != 0)
  {
    temp = queue[index++];
    root = temp * temp;
    prime[j++] = temp;
    for(int i = root-2; i < MAX; )
    {
      queue[i] = 0;
      i = i + temp;
    }
  }

  else
  {
    index = index + 1;
  }

  isprime();


}
else
return;
}

void init()
{
  for(int i = 0; i <= MAX; i++)
  {
    queue[i] = i + 2;
  }
}
