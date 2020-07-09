#include <bits/stdc++.h>
using namespace std;

const int Maxn = 111, Maxm = Maxn*Maxn;
struct Edge {
	int v, w;
	Edge *nxt;
} pool[Maxm], *g[Maxn], *tail = pool;
inline void addedge(const int &u, const int &v, const int &w) {
	tail->v = v, tail->w = w;
	tail->nxt = g[u], g[u] = tail++;
}

int n, m, s, t;

bool visited[Maxn];
void dfs(int u, const int &bound) {
	visited[u] = true;
	for (Edge *p = g[u]; p; p = p->nxt) {
		if (p->w >= bound && !visited[p->v]) {
			dfs(p->v, bound);
		}
	}
}
bool check(const int &bound) {
	memset(visited, false, sizeof(visited));
	dfs(s, bound);
	return visited[t];
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int u, v, w; m--; ) {
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w), addedge(v, u, w);
	}
	int left = 1, right = 1001;
	while (left+1 < right) {
		int mid = (left+right)/2;
		if (check(mid)) {
			left = mid;
		} else {
			right = mid;
		}
	}
	printf("%d\n", left);
	return 0;
}
