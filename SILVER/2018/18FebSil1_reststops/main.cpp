#include <bits/stdc++.h>

using namespace std;

long long N,L,rf,rb,ans;
int c[100001],x[100001];
int main()
{
    ifstream cin("reststops.in");
    ofstream cout("reststops.out");
    cin>>L>>N>>rf>>rb;
    x[0]=0;
    for (int i=1;i<=N;i++) {
        cin>>x[i]>>c[i];
    }
    for (int i=N;i>0;) {
        rest= i;
        while (i>0 && c[i]<=c[rest]) i--;
        long long tf = (x[rest] - x[i])*rf;
        long long tb = (x[rest] - x[i])*rb;
        ans +=(tf-tb) * c[rest];
    }
    cout << ans << endl;
    return 0;
}
