#include <iostream>

using namespace std;

int wall[1007][1007],ans,n,k;

int main()
{
    int x1,y1,x2,y2,llx=1000,lly=1000,urx=0,ury=0;

    freopen("paintbarn.in","r",stdin);
    freopen("paintbarn.out","w",stdout);

    cin>>n>>k;
    for (int i=0;i<n;i++) {
        cin>>x1>>y1>>x2>>y2;
        wall[x1][y1]++;
        wall[x1][y2]--;
        wall[x2][y1]--;
        wall[x2][y2]++;
        llx=min(llx,x1);
        lly=min(lly,y1);
        urx=max(urx,x2);
        ury=max(ury,y2);
    }

    for (int i=llx;i<=urx+1;i++) {
        for (int j=lly+1;j<=ury+1;j++)
            wall[i][j]=wall[i][j-1]+wall[i][j];
    }

    for (int j=lly;j<=ury+1;j++)
        for (int i=llx+1;i<=urx+1;i++) {
            wall[i][j]=wall[i-1][j]+wall[i][j];
            if (wall[i][j]==k) {ans++;}
        }

    cout<<ans;
    return 0;
}
