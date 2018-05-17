#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t,n,m,soma;
    cin>>t;
    while(t--)
    {   cin>>n;
        cin>>m;
         m--,n--;
    soma = m+n+2*m*n;
    cout<<soma<<endl;
    }
return 0;
}
