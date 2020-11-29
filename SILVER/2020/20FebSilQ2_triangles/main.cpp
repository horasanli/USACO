#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pii pair<int,int>

pii p[100001];
map <int, set<pii> > mapx;  //for each x value a list of y values and the index of the point
map <int, set<pii> > mapy;
int indexes[100001];
int positions[100001];
long long dy[100001],dx[100001];
long long ans;
const int MOD = 1e9+7;

int main()
{
    ifstream cin("triangles.in");
    ofstream cout("triangles.out");
    int n;
    cin>>n;
    for (int i=0;i<n;i++) {
        cin>>p[i].f>>p[i].s;
    }

    sort(p,p+n);
    for (int i=0;i<n;i++) {
        mapx[p[i].f].insert({p[i].s,i});
        mapy[p[i].s].insert({p[i].f,i});
    }

    //calculate dy values for each point
    for (auto x=mapx.begin();x!=mapx.end();x++) {
        if (x->s.size()<2) continue;
        //i have a set of points with {y,index} values in x->s

        //calculate the distances for the first point
        long long dist=0; int sz=0;
        auto fp = x->s.begin(); //fp : firstpoint :{y of the first point, index of first point}
//        cout<<fp->s<<endl;
        for (auto point=x->s.begin();point!=x->s.end();point++) {
            dist += point->f - fp->f; //add distance with each point in the set
            positions[sz] = point->f;
            indexes[sz++] = point->s;
        }
        dy[fp->s] = dist; //set the initial points dy total value;
        //cout<<"dist first "<<dist<<" "<<dy[fp->s]<<endl;

//        cout<<" positions"<<endl;
//        //calculate total y distances for other points in the set
//        for (int i=0;i<x->s.size();i++) {
//            cout<<positions[i]<<" ";
//        }
//        cout<<endl;
//        cout<<" indexes"<<endl;
//        for (int i=0;i<x->s.size();i++) {
//            cout<<indexes[i]<<" ";
//        }
//        cout<<endl;


//        cout<<indexes[0]<<" "<<dy[indexes[0]]<<" "<<positions[0]<<" "<<dist<<endl;
        for (int i=1;i<sz;i++) {
//            cout<<indexes[i]<<" "<<dy[indexes[i-1]]<<" "<<positions[i]<<" "<<positions[i-1]<<endl;
            dy[indexes[i]] = dy[indexes[i-1]] + (2*i-sz) *(positions[i]-positions[i-1]);
        }
    }
    for (auto y=mapy.begin();y!=mapy.end();y++) {
        if (y->s.size()<2) continue;
        //i have a set of points with {x,index} values in y->s

        //calculate the distances for the first point
        long long dist=0; int sz=0;
        auto fp = y->s.begin(); //fp : firstpoint :{y of the first point, index of first point}
        for (auto point=y->s.begin();point!=y->s.end();point++) {
            dist += point->f - fp->f; //add distance with each point in the set
            positions[sz] = point->f;
            indexes[sz++] = point->s;
        }
        dx[fp->s] = dist; //set the initial points dy total value;

        //calculate other points distances in the set;
        for (int i=1;i<sz;i++) {
//            cout<<indexes[i]<<" "<<dx[indexes[i-1]]<<" "<<positions[i]<<" "<<positions[i-1]<<endl;
            dx[indexes[i]] = dx[indexes[i-1]] + (2*i-sz) *(positions[i]-positions[i-1]);
            dx[indexes[i]] = dx[indexes[i]] ;
        }
    }

    for (int i=0;i<n;i++) {
        ans +=dx[i]*dy[i];
        ans %=  MOD;
    }

    cout<<ans<<endl;
    return 0;
}
