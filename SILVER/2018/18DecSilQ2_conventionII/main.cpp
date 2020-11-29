#include <bits/stdc++.h>

struct cow{
    int a,t,s;
};

using namespace std;
int n,ans;
cow cows[100005];


bool compa(cow a,cow b){
    return (a.a<b.a || (a.a==b.a&&a.s<b.s));
}

priority_queue<pair <int,int>, vector<pair < int,int> >, greater<pair<int,int> > > pq;

int main()
{
    freopen("convention2.in","r",stdin);
    freopen("convention2.out","w",stdout);

    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>cows[i].a>>cows[i].t;
        cows[i].s=i;
    }
    sort(cows,cows+n,compa);

    int i=0;
//    pq.push({cows[0].s,0});
    int available;
    while(i<n || !pq.empty()) {
        if (pq.empty()) {
            pq.push({cows[i].s,i});
            available = cows[i].a;
            i++;
        }
        int cur = pq.top().second; pq.pop();
        int waited= available-cows[cur].a;
        ans= max(ans,waited);
        available = max(available,cows[cur].a)+ cows[cur].t;
//        available = cows[cur].a+ cows[cur].t;
        while (i<n&& cows[i].a<=available) {
            pq.push({cows[i].s,i});
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}


