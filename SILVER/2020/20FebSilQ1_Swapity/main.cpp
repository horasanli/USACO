#include <bits/stdc++.h>

using namespace std;

int l[100],r[100],p[100001],ans[100001],newans[100001];
int N,M,K;
int perm[32][100001];

int main()
{
    ifstream cin("swap.in");
    ofstream cout("swap.out");
    cin>>N>>M>>K;
    for (int i=0;i<M;i++) {
        cin>>l[i]>>r[i];
        l[i]--; r[i]--;
    }
    for (int i=0;i<N;i++) {
        p[i]=i;
    }
    //generate initial permutation array
    for (int i=0;i<M;i++) {
        for (int j=0;j<=(r[i]-l[i])/2;j++) {
            swap(p[l[i]+j],p[r[i]-j]);
        }
    }

    for (int i=0;i<N;i++) {
        perm[0][i]=p[i];
    }
    //generate all powers of permuration array p, p^2, p^4, p^8
    for (int i=1;i<32;i++) {
        for (int j=0;j<N;j++) {
            perm[i][j]=perm[i-1][perm[i-1][j]];
        }
    }

    //initialy answer is no permutation applied
    for (int i=0;i<N;i++) {
        ans[i]=i;
    }

    //convert K into base 2 sample K=2^6 + 2^2 + 2^1
    bitset<32> a(K);

    //sample apply perm[6], perm[2] and perm[1]
    for (int i=0;i<32;i++) {
        if (a[i]) {
            for (int j=0;j<N;j++) {
                newans[j] = ans[perm[i][j]];
            }
            for (int j=0;j<N;j++) {
                ans[j] = newans[j];
            }
        }
    }
    for (int j=0;j<N;j++) {
        cout<<ans[j]+1<<endl;
    }
    return 0;
}
