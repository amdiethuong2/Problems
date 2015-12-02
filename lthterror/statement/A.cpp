#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define Fit(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define inf 1000000005
#define all(a) (a).begin(), (a).end()
#define ms(a,x) memset(a, x, sizeof(a))
#define mod 1000000000
#define sz(a) ((int)(a).size())

template<class T> int getbit(T s, int i) { return (s >> i) & 1; }
template<class T> T onbit(T s, int i) { return s | (T(1) << i); }
template<class T> T offbit(T s, int i) { return s & (~(T(1) << i)); }
template<class T> int cntbit(T s) { return __builtin_popcount(s);}
#define Rep(i,n) for(int i = 0; i < (n); ++i)
#define Repd(i,n) for(int i = (n)-1; i >= 0; --i)
#define For(i,a,b) for(int i = (a); i <= (b); ++i)
#define Ford(i,a,b) for(int i = (a); i >= (b); --i)

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define eps 1e-9
typedef pair<int, int> II;
template<class T> T gcd(T a, T b){ T r; while (b != 0) { r = a % b; a = b; b = r; } return a;}
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
#define PI 2 * acos(0)

#define maxn 5005

int dad[maxn], a[maxn], n, m;
bool c[5005][5005];

void solve(){
    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);
//        freopen((problem + ".in").c_str(), "r", stdin);
//        freopen((problem + ".out").c_str(), "w", stdout);
    while(scanf("%d %d", &n, &m) > 0){
		For(i, 1, n) scanf("%d", &a[i]);
		int u, v;
		ms(c, 0);
		For(i, 1, m){

			scanf("%d %d", &u, &v);
			if(u > n || v > n){
				cout << u << " " << v << "ngu" << endl;
			}
			c[u][v] = 1;
			c[v][u] = 1;
		}
		For(i, 1, n) dad[i] = i;
		bool check = true;
		Ford(i, n, 1){
			vector<int> V;
			For(j, i + 1, n) if(c[a[i]][a[j]]){
				V.pb(a[j]);
			}

			For(j, 1, sz(V) - 1){
				if(!c[V[0]][V[j]]){
					check = false;
					break;
				}
			}

			if(!check) break;
		}
		if(check) cout << "YES" << endl;
		else cout << "NO" << endl;
    }
}

int main(){
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
	solve();

	cout << clock() << endl;

    return 0;
}
