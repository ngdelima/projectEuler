/*
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <stdio.h>

int main(int argc, char* argv[])
{
	if(argc==2)
	{
		int n,i,suma=0;
		sscanf(argv[1],"%d",&n);
		for(i=1;i<n;i++)
		{
			//Conviene usar un and en lugar de or?
			if(i%3==0||i%5==0)
			{
				suma+=i;
			}
		}
		printf("%d\n", suma);
	}
	else
	{
		printf("Bad arguments.\n");
	}
	return 0;
}