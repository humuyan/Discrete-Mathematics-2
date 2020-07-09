#include <bits/stdc++.h>
using namespace std;

const int Maxn = 111, Maxm = Maxn*Maxn;
struct Edge {
	int v, w;
	Edge *nxt;
} pool[Maxm], *g[Maxn], *tail = pool, *cur[Maxn];
inline void addedge(const int &u, const int &v, const int &w) {
	tail->v = v, tail->w = w;
	tail->nxt = g[u], g[u] = tail++;
}

int n, m, s, t, level[Maxn];
bool visited[Maxn];

bool bfs() {
	static int q[Maxn];
	memset(level, 0, sizeof(level));
	level[s] = 1, q[1] = s;
	for (int l = 1, r = 1; l <= r; ++l) {
		for (Edge *p = g[q[l]]; p; p = p->nxt) {
			if (p->w && !level[p->v]) {
				level[p->v] = level[q[l]]+1;
				if (p->v == t) {
					return true;
				}
				q[++r] = p->v;
			}
		}
	}
	return false;
}
int dfs(int u, int flow) {
	if (u == t) {
		return flow;
	}
	visited[u] = true;
	int ret = 0;
	for (Edge* &p = cur[u]; p; p = p->nxt) {
		if (p->w && !visited[p->v] && level[p->v] == level[u]+1) {
			int f = dfs(p->v, min(flow-ret, p->w));
			ret += f;
			p->w -= f, (pool+((p-pool)^1))->w += f;
			if (ret == flow){
				break;
			}
		}
	}
	visited[u] = false;
	return ret;
}

int main() {
	scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int u, v, w; m--; ) {
		scanf("%d%d%d", &u, &v, &w);
		addedge(u, v, w), addedge(v, u, w);
	}
	int maxflow = 0;
	while (bfs()) {
		copy(g+1, g+n+1, cur+1);
		maxflow += dfs(s, INT_MAX);
	}
	printf("%d\n", maxflow);
	return 0;
}
