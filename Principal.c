#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Exponenciacao.h"

int main(void)
{
	Lista *base;
	Lista *resultado;
	int *expoente = (int*) malloc(sizeof(int));
	*expoente = -1;

	menu(base, expoente, resultado);

	return 0;
}
