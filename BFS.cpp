
#include<bits/stdc++.h>
using namespace std;
 
ifstream f("bfs.in");
ofstream g("bfs.out");

vector <int> adiacenta[1000000];
int cost[1000000];
bool deja_Vizitat[1000000];

void BFS(int nrvarfuri, int start, vector<int>* adiacenta)
{
    queue <int> coada;
    coada.push (start);
    cost[start]=0;
    deja_Vizitat[start]=1;
    
    int varf_curent;

    while (coada.size()!=0)
    {
        varf_curent=coada.front();

        for(long unsigned int i=0; i<adiacenta[varf_curent].size(); i++)
        {
            if(deja_Vizitat[adiacenta[varf_curent][i]]==0)
            {
                coada.push(adiacenta[varf_curent][i]);
                cost[adiacenta[varf_curent][i]] = cost[varf_curent]+1;
                deja_Vizitat[adiacenta[varf_curent][i]] = 1;
            }
        }
        coada.pop();
    }

}

int main()
{
    int nrvarfuri, nrmuchii, start;

    f>>nrvarfuri;
    f>>nrmuchii;
    f>>start;

    int nod1, nod2;

    for(int i=0; i<nrmuchii; i++)
    {
        f>>nod1;
        f>>nod2;
        adiacenta[nod1].push_back(nod2);
    }

    BFS(nrvarfuri, start, adiacenta);

    for(int i=1; i<=nrvarfuri; i++)
    {
        if(deja_Vizitat[i] == 1)
            g<<cost[i]<<" ";
        else
            g<<"-1 ";
    }

    return 0;
}