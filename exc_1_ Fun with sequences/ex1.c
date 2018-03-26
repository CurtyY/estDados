
/*
Algoritimo:

Entrada:
	- Tamanho n do array S  (2<= m <=100)
	- n elementos no array S (-100<= m <=100)

	- Tamanho m do array Q  (2<= m <=100)
	- m elementos no array Q (-100<= m <=100)

Ação:

	- Após determinar o tamanho de cada array e inserir os números ,
	o programa deve comparar os dois arrays, e retornar quais os números
<<<<<<< HEAD:exc_1_ Fun with sequences/ex1.c
	presentes no primeiro array e não no segundo.
=======
	presentes no array 1 e não no array 2.
>>>>>>> c11a61c595d716c8320fb3a2e94d331a80da8610:ex1.c


Saidas:

	- Numeros que tem no array S e não no Q
	- Numeros que tem no array Q e não no S

			Example
		Input:
		5
		-2 -1 0 1 4
		6
		-3 -2 -1 1 2 3
		Output:
		0 4

*/

#include <stdio.h>
#include <stdlib.h>



int main () {

     int S;
     int Q;
     int *sVector;
     int *qVector;

	       		//solicita o tamanho do array S
	     		 scanf("%d",&S);
	     		//retorna o espaço de memoria alocado para o array
	     		 sVector = malloc(S * sizeof(int));

     		 	//laço de armazenamento de variaveis no array S
		     	for(int cont_S=0;cont_S<S ;cont_S++)
		     	{

		     		scanf("%d",&sVector[cont_S]);
		     	}

     		//solicita o tamanho do array Q
     		scanf("%d",&Q);
     		//retorna o espaço de memoria alocado para o array
     		qVector = malloc(Q * sizeof(int));
     		 	
     		 	//laço de armazenamento de variaveis no array Q

     		    for(int cont_Q=0; cont_Q<Q ;cont_Q++ )
     		    {

		     		scanf("%d",&qVector[cont_Q]);
		     	}

            		//verificação de diferença
                    for(int i = 0; i < S; i++)
                    {                       
                        int diferente = 1; //variavel para verificar se o nuero é diferente
                     
                            for(int j = 0; j < Q; j++){
                                
                                if(sVector[i] == qVector[j]) //verifica se existe igualdade
                                {
                                    diferente = 0;
                                    
                                    break;
                                }
                            }

                            if(diferente)
                            	{
                                    printf("%d", sVector[i]);
                                    if(i+1 != S) printf(" ");
                                }
                    }

	return 0;
}
