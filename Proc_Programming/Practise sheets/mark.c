int main()
{
#include<stdio.h>

int mark;

printf("Enter your score:");
scanf("%i", &mark);

if (mark>=0)
{
  if (0<=mark&&mark<=49)
  {
  printf("Sorry, you have failed \n");
  }

  else if (50<=mark&&mark<=59)
  {
      printf("OK, you are not bad\n");
    }

  else if (60<=mark&&mark<=79)
  {
      printf("That is good\n");
  }
  else if(80<=mark&&mark<=89)
  {
      printf("Very good\n");
    }
}

else
{
      printf("You are excellent\n");
}
return 0;
}
