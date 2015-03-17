#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <cstdio>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define MAX 1001
//#define INF 1000
#define fo(i, a, b) for(int i=a; i<=b; i++)
#define fod(i, a, b) for(int i=a; i>=b; i--)
#define fi first
#define se second
#define pb push_back
#define pp pop_back
#define as assign
#define mp make_pair

typedef pair <int, float> ii;
typedef pair <int, int > iif;
typedef vector <int> vi;
typedef vector <ii> vii;
typedef vector <iif> viif;

vi pset(1000), ssize(1000);
int num;

void init(int N)
{
     ssize.as(N, 1);
     num=N;
     pset.as(N, 0);
     fo(i, 1, N) pset[i]=i;
}

int finds(int i)
{
    return (pset[i]==i) ? i : (pset[i]=finds(pset[i]));
}

bool issset(int i, int j)
{
     return finds(i)==finds(j);
}

int unions(int i, int j)
{
    if(!issset(i, j)) {
       num--;
       ssize[finds(j)]+=ssize[finds(i)];
       pset[finds(i)]=finds(j);
    }
}

int nums()
{
    return num;
}

int sizes(int i)
{
    return ssize[finds(i)] ;
}

vector <viif> AList;

main()
{
    //  freopen ("tmp.inp","r", stdin);
      int N, E, u, v;
      float w;
      //getch();
      vector<pair<float, ii> > EList;
      //getch();
      scanf("%d %d", &N, &E);
      //getch();
      int x[N], y[N];
      //getch();
      float e[N][N];
      //getch();
      fo(i, 0, N-1)
	  fo(j, 0, N-1) e[i][j]=-1;
	  //getch();
	  
      AList.as(N, viif());
      //getch();
      fo(i,0, N-1) {
			scanf("%d%d", &x[i], &y[i]);
      }
      //getch();
      fo(i, 0, E-1) {
            scanf("%d %d", &u, &v);
            EList.push_back(mp(0, ii(u, v)));
            AList[u-1].push_back(iif(v-1, 0));
            AList[v-1].push_back(iif(u-1, 0));
            e[u-1][v-1]=0;
            e[v-1][u-1]=0;
      }
      fo(i, 1, N)
      fo(j, 1, N) {
			if(e[i][j]==-1) {
				e[i][j]=e[j][i]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
				EList.pb(mp(e[i][j], ii(i, j)));
			}
      }
      sort(EList.begin(), EList.end());
      //printf("ghs");
      float mst=0; init(N);
      fo(i, 0, E-1)
      {
            pair<int, ii> a=EList[i];
            if(!issset(a.se.fi, a.se.se)) {
                       mst+=a.fi;
                       unions(a.se.fi, a.se.se);
            }
      }
      printf("%.2f", mst);
      return 0;
}     
    
