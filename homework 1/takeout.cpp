#include <bits/stdc++.h>
using namespace std;

const int Maxn = 111;

int n, x[Maxn], y[Maxn], m, u[Maxn*Maxn], v[Maxn*Maxn];
double d[Maxn][Maxn];

inline int sqr(const int &base) {
	return base*base;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i) {
		scanf("%d%d", &x[i], &y[i]);
	}
	scanf("%d", &m);
	memset(d, 127, sizeof(d));
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &u[i], &v[i]);
		d[u[i]][v[i]] = d[v[i]][u[i]] = sqrt(sqr(x[u[i]]-x[v[i]])+sqr(y[u[i]]-y[v[i]]));
	}
	for (int i = n+1, e, p; i <= n+3; ++i) {
		scanf("%d%d", &e, &p);
		d[u[e]][i] = d[i][u[e]] = p;
		d[v[e]][i] = d[i][v[e]] = d[u[e]][v[e]]-p;
	}
	for (int i = 1; i <= n+3; ++i) {
		for (int j = 1; j <= n+3; ++j) {
			for (int k = 1; k <= n+3; ++k) {
				d[j][k] = min(d[j][k], d[j][i]+d[i][k]);
			}
		}
	}
	printf("%.2lf\n", d[n+1][n+2]+d[n+2][n+3]);
	return 0;
}
