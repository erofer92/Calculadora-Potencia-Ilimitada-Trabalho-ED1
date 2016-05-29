#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Lista.h"
#include "Exponenciacao.h"

void welcome(char *ch) //funcionando perfeitamente
{
	printf(
		"\nBem vindo a \"Smart Calculator\", a calculadora de potencias ilimitadas! \n"
		"\nSelecione o que deseja fazer: \n\n"
		"1 - Definir valor da Base \n"
		"2 - Definir valor do Expoente \n"
		"3 - Mostrar resultado da potenciacao \n"
		"4 - Sair \n"
		"\nEste programa foi desenvolvido por Eron Fernandes e Jefferson Santos. \n"
	);

	*ch = getch();

	while(*ch != '1' && *ch != '2' && *ch != '3' && *ch != '4')
	{
		fflush(stdin);
		printf("\nSelecione uma opcao valida: ");
		*ch = getch();
	}
}

//case 1
Lista* definirBase(void) //funcionando perfeitamente
{
	Lista *base;
	int num;
	printf("\nEscolha o valor da Base: \n");
	scanf("%d", &num);
	while(num < 0)
	{
		fflush(stdin);
		printf(
			"\n\tWARNING!\n"
			"A Base deve ter um valor positivo.\n"
			"Escolha o valor da Base: \n"
		);
		scanf("%d", &num);
	}
	base = numero_para_lista(num);
	return base;
}

//case 2
int definirExpoente(void) //funcionando perfeitamente
{
	int expoente;
	printf("\n");
	printf("Escolha o valor do Expoente: \n");
	scanf("%d", &expoente);

	while(expoente < 0)
	{
		fflush(stdin);
		printf(
			"\n\tWARNING!\n"
			"O Expoente deve ter um valor positivo.\n"
			"Escolha o valor do Exooente: \n"
		);
		scanf("%d",&expoente);
	}
	return expoente;
}

//case 3
void executarPotenciacao(Lista *base, int *expoente, Lista *resultado)
{
	if(*expoente < 0 || tamanho(base) == 0)
	{
		printf(
			"Para efetuar a potenciacao, voce deve escolher primeiro os valores da Base e do Expoente.\n"
			"Tente novamente.\n"
		);
		return;
	}
	resultado = potenciacao(base, *expoente);
	printf("\nResultado: ");
	imprimir(resultado);

	printf("\nPara calcular uma nova potencia, pressione qualquer tecla.\n");
	getch();
}

void menu(Lista *base, int *expoente, Lista *resultado) //funcionando perfeitamente
{
	char ch;

	welcome(&ch);

	switch(ch)
	{
		case '1':
			base = definirBase();
			break;
		case '2':
			*expoente = definirExpoente();
			break;
		case '3':
			executarPotenciacao(base, expoente, resultado);
			break;
		case '4':
			exit(0);
			break;
		default:
			printf("Menu Switch Error\n");
			break;
	}
	system("cls");
	menu(base, expoente, resultado);
}

Lista * numero_para_lista(int n) // funcionando perfeitamente
{
	Lista *resultado = criar();
	if(n == 0)
		inserir_primeiro(resultado,0);
	else
	{
		while(n>0)
		{
			inserir_primeiro(resultado,n%10);
			n = n/10;
		}
	}

	return resultado;
}

Lista * somar(Lista *operando1, Lista *operando2) //funcionando perfeitamente
{
	int i;
	int valor = 0;
	int tam1 = tamanho(operando1);
	int tam2 = tamanho(operando2);
	Lista *resultadoSoma = criar();

	// caso os operandos sejam de tamanhos distintos, completa-se com zeros no inicio.
	if(tam1 > tam2){
		for(i = 0; i < tam1-tam2; i++)
			inserir_primeiro(operando2, 0);
	}
	// caso os operandos sejam de tamanhos distintos, completa-se com zeros no inicio.
	if(tam2 > tam1){
		for(i = 0; i < tam2-tam1; i++)
			inserir_primeiro(operando1, 0);
	}

	// soma do ultimo algarismo até o primeiro
	// colocando as unidades no resultado e somando a dezena na proxima soma.
	tam1 = tamanho(operando1);

	while(tam1 > 0){
		valor = ler_pos(operando1, tam1-1) + ler_pos(operando2, tam1-1) + valor/10 ;
		inserir_primeiro(resultadoSoma, valor%10);
		tam1--;
	}

	// caso sobre uma dezena da soma do primeiro algarismo, ela é adicionada no inicio do numero.
	if(valor/10 > 0)
		inserir_primeiro(resultadoSoma, valor/10);
	return resultadoSoma;
}

Lista * listaXnum(Lista * l, int n) // funcionando perfeitamente
{
	Lista * resultadoMult = criar();
	int valor = 0; // resultado da multiplicação de 'n' por um valor da lista
	int tam;

	// multiplica 'n' por toda a lista 'l'
	for(tam = tamanho(l); tam > 0; tam--)
	{
		valor = n*ler_pos(l, tam-1) + valor/10;     //valor é um numero de dois digitos
		inserir_primeiro(resultadoMult, valor%10);  // insere a unidade no final
	}

	// ao terminar a multiplicacao, insere o "vai um", que é a dezena, no inicio do numero;
	if(valor/10 > 0)
		inserir_primeiro(resultadoMult, valor/10);

	return resultadoMult;
}

Lista * listaXlista(Lista *operando1, Lista *operando2) // funcionando perfeitamente
{
	int tam2 = tamanho(operando2);
	int i,j;
	Lista *resultado1 = criar();
	Lista *resultado2;
	Lista *lixo;

	for(j = 0; tam2 > 0; j++, tam2--)
	{
		resultado2 = listaXnum(operando1, ler_pos(operando2, tam2-1));
		for(i = 0; i<j ;i++)
		{
			inserir_ultimo(resultado2, 0);
		}
		// como o resultado1 sempre vai pegar um valor de soma e vai perder o caminho para a lista original
		// a variavel "lixo" sempre pega os endereços perdidos e destrói.
		lixo = resultado1;
		resultado1 = somar(resultado1, resultado2);
		destruir(lixo);
	}

	return resultado1;
}

Lista * potenciacao(Lista *base, int expoente) // funcionando perfeitamente
{
	Lista *resultado;
	int i;

	resultado = base;

	for(i=1; i<expoente; i++)
	{
		resultado = listaXlista(resultado, base);
	}
	return resultado;
}

