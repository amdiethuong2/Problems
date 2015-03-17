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
using namespace std;

string convert(int x) {
  stringstream w;
  w << x;  return w.str();
}

vector<string> parse(string s) {
  string u = "";
  vector<string> v;
  for (int i = 0; i < s.size(); i++)
    if ('0' <= s[i] && s[i] <= '9') u += s[i]; else if (!u.empty()) {
      v.push_back(u);
      u.clear();
    }
  return v;
}

int main() {
  freopen("sellgold_testdata.txt","r",stdin);
  int T = 0;
  string a,b,c;
  while (cin >> a >> b >> c) {
    T++;
    vector<string> fa = parse(a),fb = parse(b);
    FILE* ga = fopen((convert(T) + ".in").c_str(),"w");
    fprintf(ga,"%d\n", fa.size());
    for (int i = 0; i < fa.size(); i++) fprintf(ga,"%s ", fa[i].c_str());
    fprintf(ga,"\n");
    for (int i = 0; i < fb.size(); i++) fprintf(ga,"%s ", fb[i].c_str());
    FILE* gb = fopen((convert(T) + ".out").c_str(),"w");
    fprintf(gb,"%s",c.c_str());
  }
}
