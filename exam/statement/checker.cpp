#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>
#include <cstring>
#define maxn 505
#define maxv 50005
using namespace std;

int low[maxn],high[maxn];
int p[maxv],w[maxv];
int n,T;
int order[maxv];
int rem[maxn],used[maxv],pos[maxv];

int main(int argc,char** argv) {
  FILE* fa = fopen(argv[1], "r");
  FILE* fb = fopen(argv[2], "r");
  FILE* fc = fopen(argv[3], "r");
  FILE* fd = fopen(argv[4], "w");
  fscanf(fa,"%d", &n);
  for (int i = 0; i < n; i++) {
    int x;
    fscanf(fa,"%d", &x);
    if (i) low[i] = high[i - 1];
    high[i] = low[i] + x;
    T += x;
    for (int j = low[i]; j < high[i]; j++) pos[j] = i;
  }
  for (int i = 0; i < T; i++) fscanf(fa,"%d", &p[i]);
  for (int i = 0; i < T; i++) fscanf(fa,"%d", &w[i]);
  int expected;
  fscanf(fb,"%d", &expected);
  int found;
  fscanf(fc,"%d", &found);
  if (expected != found) {
    fprintf(fd,"Not optimal answer\n");
    return 0;
  }  
  for (int i = 0; i < n; i++) rem[i] = high[i] - low[i];
  for (int i = 0; i < T; i++) fscanf(fc,"%d", &order[i]);
  int sum = 0,elapsed = 0,prev = -1;
  for (int i = 0; i < T; i++) {
    int u = order[i];
    u--;
    if (u < 0 || u >= T || used[u]) {
      fprintf(fd,"Invalid index\n");
      return 0;
    }    
    used[u] = true;
    if (prev < 0 || !rem[prev]) prev = pos[u];
    if (prev >= 0 && prev != pos[u] && rem[prev]) {
      fprintf(fd,"Unfinished homework\n");
      return 0;
    }
    rem[pos[u]]--;
    elapsed += p[u];
    sum += elapsed * w[u];
  }
  if (sum != expected) {
    fprintf(fd,"Incorrect ordering\n");
    return 0;
  }
  fprintf(fd,"OK\n");
}
