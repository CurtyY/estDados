#include<bits/stdc++.h>

//Pré-ordem: Você deve visitar primeiro a raiz, depois a sub-árvore esquerda e por último a sub-árvore direita.
 // 	A 			Pré = ABCDEF
 //    / \
 //	  B   D
//	 /   / \
//	C   E   F
#define MAX_TAM 10001
using namespace std;

char preord[MAX_TAM];
int i;
int max(int p,int q)
{       if(p>q)
            return p;
        else
            return q;
}

int _Profund()
{
        if (preord[i++] =='l')
             return 1;
        else
            return max(_Profund(),_Profund())+1;
}
int main()
{
        int T;
            scanf("%d",&T);

        for(int j=0;j<T;j++)
        {
                scanf("%s", preord);
                i=0;
                printf("%d\n",_Profund() - 1);
        }
        return 0;
}
