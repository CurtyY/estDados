#include <stdio.h>
#include <stdlib.h>

typedef struct no{
	unsigned long long int id;
	unsigned long long int prox;
	unsigned long long int ant;
}tipo_no;

int main() {
	tipo_no ptr1, ptr2;
	tipo_no *atual = (tipo_no *) malloc(sizeof(tipo_no));
	int cont = 0;
	int flag;

	unsigned long long int id, ant, prox;

	while(scanf(" %llx %llx %llx", &id, &ant, &prox) == 3) {
		cont++;
		atual = (tipo_no *) realloc(atual, cont * sizeof(tipo_no));

		atual[cont-1].id = id;
		atual[cont-1].ant = ant;
		atual[cont-1].prox = prox;

		if(cont == 1)
			ptr1 = atual[cont-1];
		else if(cont == 2)
			ptr2 = atual[cont-1];
	}


	for(tipo_no aux = ptr1; aux.id != ptr2.id;) {
		flag = 0;
		for(int i = 0; i < cont; i++) {
			if(aux.prox == atual[i].id && atual[i].ant == aux.id) {
				aux = atual[i];
				flag = 1;
				break;
			}
		}
		if(!flag)
			break;
	}

	if(flag)
		printf("sana\n");
	else
		printf("insana\n");

	return 0;
}
