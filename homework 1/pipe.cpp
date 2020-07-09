#include <bits/stdc++.h>
using namespace std;

const int Maxv = 111, Maxe = 1111;
struct Edge {
	int v, id;
	bool del;
	Edge *nxt;
} pool[Maxe*2], *g[Maxv], *cur[Maxv], *tail = pool;
inline void addedge(const int &u, const int &v, const int &id) {
	tail->v = v, tail->id = id;
	tail->nxt = g[u], g[u] = tail++;
}

int n, ans[Maxe], d[Maxv];

void dfs(int u) {
	while (cur[u]) {
		if (cur[u]->del) {
			cur[u] = cur[u]->nxt;
			continue;
		}
		int v = cur[u]->v, id = cur[u]->id;
		(pool+((cur[u]-pool)^1))->del = true;
		cur[u] = cur[u]->nxt;
		dfs(v);
		ans[++*ans] = id;
	}
}

int main() {
	scanf("%d", &n);
	int start;
	for (int i = 1, a, b; i <= n; ++i) {
		scanf("%d%d", &a, &b);
		addedge(a, b, i), addedge(b, a, i);
		++d[a], ++d[b];
		start = a;
	}
	copy(g+50, g+101, cur+50);
	for (int i = 50; i <= 100; ++i) {
		if (d[i]&1) {
			start = i;
		}
	}
	dfs(start);
	for (int i = 1; i <= *ans; ++i) {
		printf("%d%c", ans[i], " \n"[i == *ans]);
	}
	return 0;
}
