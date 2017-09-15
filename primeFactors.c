#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Queremos saber cuales son los factores primos de 600851475143

typedef struct lista
{
	unsigned long numero;
	struct lista* siguiente;
} lista;

lista *raiz = NULL;

int main(int argc, char * argv[])
{
	if(argc==2)
	{
		//Sacar la lista de primos hasta la raiz cuadrada
		unsigned long long int n;
		unsigned long int sqrtN;
		int i,seguir;
		sscanf(argv[1],"%llu",&n);
		sqrtN=sqrt(n);
		lista *actual = NULL;
		if(sqrtN>=2) 
		{
			lista *nuevo=(lista*)malloc(sizeof(lista));
			nuevo->numero=2;
			nuevo->siguiente=NULL;
			raiz=nuevo;
		}
		for(i=3;i<=sqrtN;i+=2)
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
			}
		}
		//Sacar los factores primos del numero
		//El programa funciona, pero esta parte funciona lenta
		//Seguramente es por las divisiones
		//Reemplazar por multiplicaciones?
		actual=raiz;
		while(actual)
		{
			if(n%actual->numero==0) 
			{
				printf("%lu\n", actual->numero);
				n/=actual->numero;
			}
			else
			{
				actual=actual->siguiente;	
			}
		}
	}
	else
	{
		printf("Bad arguments.\n");
	}
	return 0;
}