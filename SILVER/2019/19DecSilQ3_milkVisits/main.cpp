#include <bits/stdc++.h>

using namespace std;

int N,M,groupno;
string milk;
vector<int> adj[100005];
int group[100005];

void ff(int node,int g) {
    group[node]=g;
    for (int i=0;i<adj[node].size();i++) {
        int neig=adj[node][i];
        if (!group[neig]&&milk[node]==milk[neig])
            ff(neig,g);
    }
}

int main()
{
    int x,y; char wanted;
    freopen("milkvisits.in","r",stdin);
    freopen("milkvisits.out","w",stdout);
    cin>>N>>M;
    cin>>milk;
    milk="0"+milk;  //in order to make milk 1 based indexed. Add a dummy char to beginning
    for (int i=0;i<N-1;i++) {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    for (int i=1;i<=N;i++) {
        if (!group[i]) {
            ff(i,++groupno);
        }
    }
    for (int i=0;i<M;i++) {
        cin>>x>>y>>wanted;
        if (group[x]==group[y] && milk[x]!=wanted) {
            cout<<0;
        }
        else cout<<1;
    }

    cout << endl;
    return 0;
}
