#include <iostream>

using namespace std;

int ans=INT_MAX,N,B,f[300],s[300],d[300];

void solve(int pos,int b) {
    if (pos==N-1) {
        ans=min(ans,b);
        return;
    }

    for (int i=1; pos+i<N && i<=d[b];i++) {
        if (f[pos+i]<=s[b])
            solve(pos+i,b);
    }
    for (int i=1;b+i<B;i++) {
        if (f[pos]<=s[b+i])
            solve(pos,b+i);
    }
}
int main()
{
    cin>>N>>B;
    for (int i=0;i<N;i++)
        cin>>f[i];
    for (int i=0;i<B;i++) {
        cin>>s[i];
        cin>>d[i];
    }

    solve(0,0);

    cout << ans << endl;
    return 0;
}
