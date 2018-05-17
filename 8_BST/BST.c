#include<stdio.h>
#include<stdlib.h>

#define S struct

S node
{
    int val,c;
    S node *left, *right;
}*root = NULL,*stack[100];
int c;
void insert(S node **root, int val)
{
    S node *temp;
    if( *root == NULL)
    {
        temp = (S node *)malloc(sizeof(S node));
        temp->val = val;
        temp->left = NULL;
        temp->right = NULL;
        *root = temp;
        return ;
    } else {
        if(val >= (*root)->val)
        {
           insert( &((*root)->right) , val);
        }else{
            insert( &((*root)->left) , val);
        }
    }
    return ;
}

int search(S node *temp,int val)
{   int L=0,R=0;
   S node *nNode;
     while(temp != NULL)
   {    nNode = temp;
        if(val == temp->val)
            break;
        else if( val > temp->val && temp->right != NULL)
        {
            R++;
            temp = temp->right;
        }
        else if( val < temp->val && temp->left != NULL) {
            L++;
            temp = temp->left;
        }
        if( nNode== temp )
            break;
   }
   c=c+R+L;
    return root->c = c;
}

int main()
{
    int i,n;
    scanf("%i",&n);
    while(n--)
    {
        scanf("%i",&i);
        insert(&root,i);
        search(root,i);
        printf("%d\n",root->c);
    }

    return 0;
}
