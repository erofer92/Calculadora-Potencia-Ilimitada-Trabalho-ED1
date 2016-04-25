#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"
#include "Trabalho.h"

int main()
{
	Lista * numero;
    Lista * resultado;
    int num;
    int pot;

    printf("Escolha seu numero e potencia, respectivamente. \n");
    printf("Ex: '101 31', onde 101 equivale ao numero e 31 equivale a potencia. \n");

    scanf("%d %d", &num, &pot);

    numero = numero_para_lista(num);

    resultado = potenciacao(numero, pot);

	printf("Numero: ");
	imprimir(numero);
	printf("\nPotencia: ");
	printf("%d \n",pot);
	printf("\nResultado: ");
	imprimir(resultado);

	destruir(numero);
	destruir(resultado);

	return 0;
}
