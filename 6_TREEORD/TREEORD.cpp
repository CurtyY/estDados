#include<bits/stdc++.h>

/*o codigo cria as coordenadas em pre ordem com as coordenadas de pos e em ordem para que sejam todas na mesma arvore
  e eu comparo a coordenada pre ordem gerada, com a coordenada pre ordem que inserida pelo usuario, se for diferente
  quer dizer que não são as coordenadas da mesma arvore. Não é a melhor resolução, mas deu certo :)
 */
using namespace std;

struct Node
{
    int data;
    Node* left, * right;
};

Node* newNode(int data);

int search(int arr[], int strt, int end, int value);

Node* buildUtil(int in[], int post[], int inStrt,int inEnd, int *pIndex)
{
    // Base case
    if (inStrt > inEnd)
        return NULL;
    Node *node = newNode(post[*pIndex]);
    (*pIndex)--;

    if (inStrt == inEnd)
        return node;
    int iIndex = search(in, inStrt, inEnd, node->data);

    node->right= buildUtil(in, post, iIndex+1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex-1, pIndex);

    return node;
}

Node *buildTree(int in[], int post[], int n)
{
    int pIndex = n-1;
    return buildUtil(in, post, 0, n - 1, &pIndex);
}

int search(int arr[], int strt, int end, int value)
{
    int i;
    for (i = strt; i <= end; i++)
    {
        if (arr[i] == value)
            break;
    }
    return i;
}

Node* newNode(int data)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->left = node->right = NULL;
    return (node);
}

int preOrder(Node* node)
{   if (node == NULL)
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}
int TreeToArray (Node *node, int arr[], int i) 
{// aqui transformo as coordenadas da arvore pre ordem em um array
    if (node == NULL) return i;
    arr[i] = node->data;
    i++;
    if (node->left != NULL)
    i = TreeToArray(node->left, arr, i);
    if (node->right != NULL)
    i = TreeToArray(node->right, arr, i);
    return i;
} 
int compare(int A[],int B[],int tam){  
    //compara o array gerado na função anterior, com o array das coordenadas inseridas pelo usuario
    int igual=0;

    for (int i=0; i<tam; i++) {

        if (A[i] == B[i])
            {
            igual++;
            }else
        {
            break;
        }
        }
        if(igual==tam){
            return 1;
        }else{
            return 0;
        }
}

int main()
{   int N;
    cin>>N;
    int in[N],post[N],preC[N],preG[N];

        int n = sizeof(in)/sizeof(in[0]);

            for(int i=0;i<N;i++)
            {
                cin>>preC[i];
            }
            for(int j=0;j<N;j++)
            {
                cin>>post[j];
            }
            for(int k=0;k<N;k++)
            {
                cin>>in[k];
            }
            Node *root = buildTree(in, post, n);
            TreeToArray(root,preG,0);
            int x = compare(preG,preC,N);
            if(x==1){
                cout<<"yes";
            }else{
                cout<<"no";
            }


    return 0;
}
