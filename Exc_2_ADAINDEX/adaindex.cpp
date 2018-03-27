#include<bits/stdc++.h>
using namespace std;

typedef struct lista{
	struct lista* c[26];
	int cnt;
}Lista;

Lista* get_No(){

	Lista* n = (Lista*)malloc(sizeof(Lista));
		for(int i=0 ; i<26 ; i++)
		{
			n->c[i] = NULL;
		}

	n->cnt = 0;
	return n;
}

void cnstr(Lista* no,string s)
{
	Lista* novo_no = no;

	int l = s.length();

			for(int i=0 ; i<l ; i++)
			{
				if(novo_no->c[s[i]-'a'] == NULL)
				{
					novo_no->c[s[i]-'a'] = get_No();
				}
				novo_no = novo_no->c[s[i]-'a'];
				novo_no->cnt = novo_no->cnt + 1;
			}
}

int verifica(Lista* no,string s)
{
	Lista* novo_no = no;

	int l = s.length();
	int ans=0;

		for(int i=0 ; i<l ; i++)
		{
			if(novo_no->c[s[i]-'a'] != NULL)
			{
				novo_no = novo_no->c[s[i]-'a'];
			}
				else
				{
					return 0;
				}
		}
	return novo_no->cnt;
}

int main()
{
	int N,Q;
	string nPalavra;

	cin >> N;
	cin >> Q;

	Lista* root = get_No();

	for(int i=0 ; i<N ; i++)
		{
			cin >> nPalavra;
			cnstr(root,nPalavra);
		}

		while(Q--)
			{
				cin >> nPalavra;
				int ans = verifica(root,nPalavra);
				cout << ans << endl;
			}
}
