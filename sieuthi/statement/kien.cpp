#include <stdio.h>
#include <math.h>
#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<double, double> lflf;
#define X first
#define Y second

const int N = 1003;
int n, k, Size[N];
lflf a[N], b[N], bb[N], dx[N];
double sx[N], sy[N];

bool minimize(double &a, double b)
	{ if (a>b) a=b; else return false; return true; }

double dist(lflf p, lflf q)
	{ return hypot(p.X-q.X, p.Y-q.Y); }

int nearest(lflf p) {
	int u=1; double Min=dist(p, b[1]);
	for (int i=2; i<=k; i++)
	if (Min > dist(p, b[i]))
	{ Min=dist(p, b[i]); u=i; }
	return u;
}

double k_means() {
	for (int t=1; t<=50; t++) {
		for (int i=1; i<=k; i++)
			{ sx[i]=0, sy[i]=0, Size[i]=0; }
		for (int i=1; i<=n; i++) {
			int u = nearest(a[i]);
			sx[u] += a[i].X;
			sy[u] += a[i].Y;
			Size[u]++;
		}
		for (int i=1; i<=k; i++)
			bb[i] = lflf(sx[i]/Size[i], sy[i]/Size[i]);

		bool Diff = false;
		for (int i=1; i<=k; i++)
		if (b[i]!=bb[i]) Diff=true;

		if (!Diff) break;
		for (int i=1; i<=k; i++)
		b[i]=bb[i];
	}
	double Sum=0;
	for (int i=1; i<=n; i++) {
		int u = nearest(a[i]);
		Sum += dist(a[i], b[u]);
	}
	return Sum;
}

main() {
	scanf("%d%d", &n, &k);
	for (int i=1; i<=n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		a[i] = lflf(x, y);
	}
	double Min = 23e9;
	for (int t=1; t<=50; t++) {
		random_shuffle(a+1, a+n+1);
		for (int i=1; i<=k; i++) b[i]=a[i];
		if (minimize(Min, k_means()))
		for (int i=1; i<=k; i++) dx[i]=b[i];
	}
	for (int i=1; i<=k; i++)
	printf("%.9lf %.9lf\n", dx[i].X, dx[i].Y);
}

