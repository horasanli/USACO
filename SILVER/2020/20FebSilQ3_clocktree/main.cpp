#include <bits/stdc++.h>

using namespace std;

int n,ans;
int t[2507],ti[2507];

vector<int> adj[2507];

void dfs(int cur,int par) {
    for (int i:adj[cur]) {
        if (i!=par) {
            t[i]++;
            dfs(i,cur);
        }
    }
    t[par]= ((t[par] + 12-t[cur])%12)+1;
}

int main()
{
    freopen("clocktree.in","r",stdin);
    freopen("clocktree.out","w",stdout);
    cin>>n;
    for (int i=0;i<n;i++ ){
        cin>>ti[i];
    }
    for (int i=0;i<n-1;i++) {
        int x,y;
        cin>>x>>y;
        adj[--x].push_back(--y);
        adj[y].push_back(x);
    }

    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            t[j]=ti[j];
        }
        dfs(i,-1);
        if (t[i]==12 || t[i]==1) { ans++; }
    }
    cout << ans << endl;
    return 0;
}
