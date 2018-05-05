//#include <bits/stdc++.h>
//permite usar qualquer biblioteca padrão C / C ++ sem adicionar "includes" um a um.

#include <iostream>
#include <stdio.h>
using namespace std;
//#define MAXTAM 400
class Node{
    public:
    char info;
    Node *proximo;
    Node()
    {
        proximo=NULL;
    }
    Node(char nInfo, Node* nProximo=NULL){

        info=nInfo;
        proximo=nProximo;
    }

};

class Pilha{

    private:
        Node *Cabeca;

    public:
        Pilha()
        {
            Cabeca=NULL;
        }

        bool PilhaVazia();
        void Pop();
        void Push(char);
        int tamPilha();
        char Top();

};

char Pilha::Top(){
    if(!PilhaVazia()){
    return Cabeca->info;
    }

}

bool Pilha::PilhaVazia(){

        return (Cabeca==NULL);

}
void Pilha::Push(char v){
      if(PilhaVazia()){
        Node *novo = new Node(v);
        novo->proximo=Cabeca;
        Cabeca=novo;
        }else{

        Node *tmp = new Node(v);
        tmp->proximo=Cabeca;
        Cabeca=tmp;
        }
}
void Pilha::Pop(){
    if(PilhaVazia()!=true)
    {
        char info = Cabeca->info;
        Node *tmp = Cabeca;
        Cabeca = Cabeca->proximo;
        delete tmp;
    }
}

int main ()
{
    Pilha s;
    int t;
    cin>>t;
    while(t--)
    {
    char a;
    char arr[400];
    cin>>arr;
    int len=strlen(arr);
    for(int i=0;i<len;i++)
    {
        if(arr[i]=='(')
             s.Push(arr[i]);
        else if(arr[i]==')')
             {
                 while(s.Top()!='(')
                 {
                     cout<<s.Top();
                     s.Pop();
                 }
                 s.Pop();
            }
        else if(arr[i]=='+' || arr[i]=='-' ||arr[i]=='*' ||arr[i]=='/' ||arr[i]=='^' )
              s.Push(arr[i]);
        else
            cout<<arr[i];

    }
    cout<<endl;
    }



return 0;
}
