//#include <bits/stdc++.h> // chama todos os includes
#include <iostream>
#include <stdio.h>
using namespace std;

class Node{
    public:
    int info;
    Node *proximo;
    Node()
    {
        proximo=NULL;
    }


    Node(int nInfo, Node* nProximo=NULL){

        info=nInfo;
        proximo=nProximo;
    }

};

class Fila{
    private:
        Node *Inicio, *Final;
        int tamanho;
    public:
        Fila()
        {
            Inicio=Final=NULL;
            tamanho=0;
        }

        bool fVazia();
        int Front();
        int Back();
        void Reverse();
        void toFront(int);
        void Push_back(int);
       // int tamFila();

};

bool Fila::fVazia(){
    if(tamanho==0)
    return true;
    else
    return false;

}
/*
int Fila::tamFila()
{
    int tam = 0;
    if(Inicio!=0)
    {
        Node *p;
        for(p=Inicio;p!=0;p=p->proximo){
            tam++;
        }
        return (tam);
    }

} */
void Fila::Push_back(int info){

    if(fVazia()){
        Inicio = Final = new Node(info);
    } else{
            Final->proximo = new Node(info);
            Final = Final->proximo;
            tamanho++;
        }

}


int Fila::Front() //imprime o número da frente e depois apaga
{
    if(!fVazia())
    {
        int info=Inicio->info;
        cout<<Inicio->info;
        cout<<endl;
        Node *tmp = Inicio;
        Inicio = Inicio->proximo;
        delete tmp;
        tamanho--;
    }
        else
    {
        cout<<"No job for Ada?\n";
    }

}
    int Fila::Back () //imprime o número de trás e depois apaga
    {   if(!fVazia())
        {
            int info = Final->info;
            cout<<Final->info;
            cout<<endl;
            Node *tmp = Final;
            Final = Final->proximo;
            delete tmp;
            tamanho--;
        }
            else
        {
            cout<<"No job for Ada?\n";
        }

    }

void Fila::Reverse() //reverte todos os elementos da fila
{
    int v = tamanho;
    for(int i=1;i<v;i++) //utiliza o tamanho da fila enquanto contador for menor que o tamanho, então i++
    {
            int info = Inicio->info;
            Node *tmp = Inicio;
            Inicio = Inicio->proximo;
            delete tmp;
            Push_back(info);
            //tira o da frente e joga pro final
    }
}

void Fila::toFront(int f) // Coloca um numero na frente "Preferencial"
    {
        if(fVazia()){
        Inicio = Final = new Node(f);
        }else{

        Node *tmp = new Node(f);
        tmp->proximo=Inicio;
        Inicio=tmp;
        }
        tamanho++;

    }

 int main(){
    Fila fila;

    string opcao;
    int Q;
    int N,f;

        cin>>Q;
    for(int contador=0;contador<Q;contador++)
    {       cin>>opcao;

            if(opcao=="back"){
                fila.Back();
            }
            else if(opcao=="front"){
                fila.Front();
            }
            else if (opcao=="reverse"){
                fila.Reverse();
            }
            else if(opcao=="push_back"){
                cin>>N;
                if(N>=0 && N <=100){
                fila.Push_back(N);
                }
            }
            else if(opcao=="toFront")
            {   cin>>N;
                if(N>=0 && N <=100){
                fila.toFront(N);
                }
            }

            }
    return 0;
}
