#include<bits/stdc++.h>
using namespace std;
 
ifstream f("dfs.in");
ofstream g("dfs.out");

vector <int> adiacenta[100010];
int deja_Vizitat[100010];

int nrnoduri, nrmuchii;

void DFS(int nod, int deja_Vizitat[], vector <int>* adiacenta)
{
    int i;
    deja_Vizitat[nod] = 1;
    for( i=0; i<adiacenta[nod].size(); i++)
        if (deja_Vizitat[adiacenta[nod][i]]==0)
            DFS(adiacenta[nod][i], deja_Vizitat, adiacenta);
}

int main()
{

    f>>nrnoduri;
    f>>nrmuchii;

    int nod1, nod2;

    for(int i=0; i<nrmuchii; i++)
    {
        f>>nod1;
        f>>nod2;
        adiacenta[nod1].push_back(nod2);
        adiacenta[nod2].push_back(nod1);
    }

    int cnt = 0;

    for(int i=1; i<=nrnoduri; i++)
        if (deja_Vizitat[i]==0)
        {
            DFS(i,deja_Vizitat,adiacenta);
            cnt++;
        }
    
    g<<cnt;


    return 0;
}