#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

long long n,ftotal,best=1e9,ans,a,b;
map<int, int> slope;

int main()
{
    ifstream cin("teleport.in");
    ofstream cout("teleport.out");
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>a>>b;
        ftotal+=abs(a-b);

        if (abs(a)>abs(a-b)) continue;
        if (a>b && a>0) { slope[0]--; slope[2*b]--;}
        if (a<=b && a<=0) {slope[0]--; slope[2*b]--;}
        if (a>b && a<=0) {slope[2*a]--; slope[2*b - 2*a]--;}
        if (a<=b && a>0) {slope[2*a]--; slope[2*b - 2*a]--;}
        slope[b]+=2;
    }


    long long curslope=0, prevpos=-1e9; best= ftotal;
    for (auto e:slope) {
        ftotal += curslope * (e.f - prevpos);
        best = min(best, ftotal);
        curslope +=e.s;
        prevpos = e.f;
    }

    cout<<best;
    return 0;
}
