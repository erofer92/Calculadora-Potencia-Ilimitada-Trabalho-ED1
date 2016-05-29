#ifndef _EXPO_H
#define _EXPO_H

void menu(Lista *base, int *expoente, Lista *resultado);
void welcome(char *ch);
Lista* definirBase(void);
int definirExpoente(void);
void executarPotenciacao(Lista *base, int *expoente, Lista *resultado);
Lista* numero_para_lista(int n);
Lista* somar(Lista *operando1, Lista *operando2);
Lista* listaXnum(Lista * l, int n);
Lista* listaXlista(Lista *operando1, Lista *operando2);
Lista* potenciacao(Lista *base, int expoente);

#endif /* _EXPO_H */
