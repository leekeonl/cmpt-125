#include <stdio.h>
#include <math.h>

int main (int argc, char *argv[])
{
int x, y, z;
char space = ' ';
scanf("%d", &x);
scanf("%d", &y);
scanf("%d", &z);

for(int i=z-1;i>=0;i--)
  {
    int left = floor(i * (x/(2.0*z))) ;
    int right = ceil((x-1) + -i * (x/(2.0*z))); 
    if(i==0 || i==z-1)
    {
	for(int j=0; j<=right; j++)
	{
	  if(j>=left)
	  {
	    printf("#");
	  }
	  else
	  {
	    printf("%c",space);
	  }
	}
	printf("\n");
    }
    else
    {
	for(int j=0; j<=right; j++)
	{
	  if(j==left || j==right)
	  {
	    printf("#");
	  }
	  else
	  {
	    if(j>=left && j<right)
	    {
	      printf(".");
	    }
	    else
	    {
	      printf("%c",space);
	    }
	  }
	}
	printf("\n");
    }
  }
  return 0;
}

