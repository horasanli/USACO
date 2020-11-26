#include <bits/stdc++.h>

using namespace std;

struct cow{
    int w,x,d;  //weight position direction
};

bool operator<(cow a,cow b) {
    return a.x<b.x;
}

cow cows[50001];
int N,L,lb,rb,totalw,curw,ans,T;
int leftb[50001],rightb[50001];
queue<int> q;

int main()
{
    freopen("meetings.in","r",stdin);
    freopen("meetings.out","w",stdout);
    cin>>N>>L;
    for (int i=0;i<N;i++) {
        cin>>cows[i].w>>cows[i].x>>cows[i].d;
        totalw +=cows[i].w;
        if (cows[i].d == -1)
            leftb[lb++] = cows[i].x;
        else
            rightb[rb++] = L-cows[i].x;
    }
    sort(cows,cows+N);
    sort(leftb,leftb+lb);
    sort(rightb,rightb+rb);

    int li=0,ri=0;  //leftb iterator and rightb iterators
    while (2*curw<totalw) {
        if (ri>=rb || (li<lb && leftb[li]<rightb[ri])) {
            curw +=cows[li].w;
            T = leftb[li];
            li++;
        }
        else if (li>=lb || (ri<rb && leftb[li]>rightb[ri])) {
            curw +=cows[N-1-ri].w;
            T = rightb[ri];
            ri++;
        }
        else if (leftb[li]==rightb[ri]) {
            curw +=cows[li].w;
            curw +=cows[N-1-ri].w;
            T = rightb[ri];
            li++;
            ri++;
        }
    }

    for (int i=0;i<N;i++) {
        if (cows[i].d==1)
            q.push(i);
        else {
            while (cows[i].x-cows[q.front()].x>2*T)
                q.pop();
            ans+=q.size();
        }
    }

    cout << ans << endl;
    return 0;
}
