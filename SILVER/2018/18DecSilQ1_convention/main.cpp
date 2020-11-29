#include <bits/stdc++.h>

using namespace std;
int n,m,c,mini,maxi,a[200007];

bool isok2(int limit) {
    int first=0,last;

    for(int x=0;x<m;x++) { //for each bus
        if (a[first+c-1]-a[first]<=limit)
            last=first+c-1;
        else {
//            last= lower_bound(a+first,a+first+c,a[first]+limit)-a-1; //a[first]+limit
            last=first+c-1;
            while(a[last]>a[first]+limit) last--;
        }
        first=last+1;
        if (first>=n) return true;
    }

    if (first>=n) return true;
    return false;
}
bool isok(int limit) {
    int first,last=-1;

    for(int x=0;x<m;x++) { //for each bus
        first= last+1;
        last= last+c; if (last>n-1) return true; //last=n-1; // you can return true; also
        if (a[last]-a[first]<=limit) // C cows came before the wait time limit. Buss full skip to next bus
            continue
        else {
            last= lower_bound(a+first,a+first+c,a[first]+limit+1)-a-1; //a[first]+limit

            //remove the latter cows that came after the time limit
//            while(a[last]>a[first]+limit) last--;
        }
        if (first>=n) return true;  //efficiency pruning can be skipped.
    }

    if (first>=n) return true;
    return false;
}


int main()
{
    freopen("convention.in","r",stdin);
    freopen("convention.out","w",stdout);

    cin>>n>>m>>c;
    for (int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for (int i=n;i<=n+c;i++)
        a[i]=a[i-1];
    maxi = a[n-1]-a[0];
    mini=0;
    while (mini<maxi){
        int mid=(mini+maxi)/2;
        if (isok(mid))
            maxi=mid;
        else mini=mid+1;
    }
    cout<<maxi<<endl;
    return 0;
}
