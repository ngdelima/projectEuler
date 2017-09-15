/*
Se ingresa un numero n y se devuelve una lista con los n primeros numeros primos
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	int numero;
	struct lista* siguiente;
} lista;

lista *raiz = NULL;

int main(int argc, char * argv[])
{
	if(argc==2)
	{
		int n,i,seguir,c;
		sscanf(argv[1],"%d",&n);
		lista *actual = NULL;
		if(n>=2) 
		{
			printf("1: 2\n");
			lista *nuevo=(lista*)malloc(sizeof(lista));
			nuevo->numero=2;
			nuevo->siguiente=NULL;
			raiz=nuevo;
		}
		i=3;c=2;
		while(c<=n)
		{
			seguir=1;
			actual=raiz;
			while(seguir&&actual->siguiente)
			{
				if(i%actual->siguiente->numero==0) seguir=0;
				actual=actual->siguiente;
			}
			if(seguir) 
			{
				lista *nuevo=(lista*)malloc(sizeof(lista));
				nuevo->numero=i;
				nuevo->siguiente=NULL;
				actual->siguiente=nuevo;
				printf("%d: %d \n",c,i);
				c++;
			}
			i+=2;
		}
	}
	else
	{
		printf("Bad arguments.\n");
	}
	return 0;
}