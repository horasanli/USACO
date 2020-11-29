#include <bits/stdc++.h>

using namespace std;
int n,k,cnt[1005];
string board[105];
int reg[105][15];
int changedcol[15];
bool cont;
int dr[4]={1,0,-1,0};
int dc[4]={0,-1,0,1};

bool inbound(int r,int c) {
    return (r>=0&&c>=0&&r<n&&c<10);
}

void ff(int r,int c,int region){
    reg[r][c]=region;
    cnt[region]++;
    for (int i=0;i<4;i++){
        int nr=r+dr[i]; int nc=c+dc[i];
        if (inbound(nr,nc)&&board[nr][nc]==board[r][c]&&reg[nr][nc]==0) {
            ff(nr,nc,region);
        }
    }
}

void clearreg(int region) {
    for (int i=0;i<n;i++) {
        for (int j=0;j<10;j++) {
            if (reg[i][j]==region){
                board[i][j]='0';
                changedcol[j]=1;
            }
        }
    }
}


void fall(){
    for (int c=0;c<10;c++){
        if (!changedcol[c]) continue;
        int r=n-1,cur=n-1; int dist=0;
        while (r>-1) {
            while (r>-1&&board[r][c]=='0')
                r--; //find who will fall;
            dist+=cur-r;

            while (r>-1&&board[r][c]!='0') {
                if (dist!=0) {
                    board[r+dist][c]=board[r][c];
                    board[r][c]='0';
                }
                r--;
            }
            cur=r;
        }
    }
}

int main()
{
    freopen("mooyomooyo.in","r",stdin);
    freopen("mooyomooyo.out","w",stdout);

    cin>>n>>k;
    for (int i=0;i<n;i++)
        cin>>board[i];

    cont=true;
    while (cont) {
        cont=false;
        int region=0;
        for (int i=0;i<n;i++)
            for (int j=0;j<10;j++)
                reg[i][j]=0;
        for (int i=0;i<n;i++) {
            for (int j=0;j<10;j++) {
                if (board[i][j]!='0'&&reg[i][j]==0) {
                    ff(i,j,++region);
                }
            }
        }
        for (int i=0;i<10;i++)
            changedcol[i]=0;


//        cout<<endl;
//        for (int i=0;i<n;i++) {
//            for (int j=0;j<10;j++)
//                cout<<reg[i][j];
//            cout<<endl;
//        }
//        for (int i=1;i<=region;i++)
//            cout<<cnt[i]<<" ";

        for (int i=1;i<=region;i++) {
            if (cnt[i]>=k) {
                clearreg(i);
                cont=true;
            }
            cnt[i]=0;
        }
//        for (int i=0;i<10;i++)
//            cout<<changedcol[i];
//        cout<<endl;
//        for (int i=0;i<n;i++)
//            cout<<board[i]<<endl;
        fall();
//        cout<<endl;
//        for (int i=0;i<n;i++)
//            cout<<board[i]<<endl;

    }

    for (int i=0;i<n;i++)
        cout<<board[i]<<endl;
    return 0;
}
/*
6 3
4400000000
3300000000
2300000000
2550000000
1340000000
1340000000


*/
