/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include<stdio.h>

int palindromo(int n);

int main()
{
	printf("%d\n", palindromo(101));	
	return 0;
}

int palindromo(int n)
{
	int aInvertir = n, aComparar = 0;
	while(aInvertir>0)
	{
		aComparar*=10;
		aComparar+=(aInvertir%10);
		aInvertir/=10;
	}
	if(aComparar==n)
		return 1;
	else
		return 0;
}