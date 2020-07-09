#include <bits/stdc++.h>
using namespace std;

const int Max = 111;
class Graph {
	private:
		vector<pair<int, int>> g[Max*2];
		int d[Max*2];

	public:
		inline void addedge(const int &u, const int &v, int w = 0) {
			g[u].push_back({v, w});
			++d[v];
		}
		void topsort(const int &n, int *dist) const {
			int q[Max*2], du[Max*2];
			q[1] = 0;
			copy(d, d+n+1, du);
			for (int l = 1, r = 1; l <= r; ++l) {
				for (auto e: g[q[l]]) {
					dist[e.first] = max(dist[e.first], dist[q[l]]+e.second);
					if (!--du[e.first]) {
						q[++r] = e.first;
					}
				}
			}
		}
} g, revg;

int n, d[Max], ans[Max*2], dist[Max*2], revdist[Max*2];

int main() {
	cin >> n;
	for (int i = 1, t, c, v; i <= n; ++i) {
		cin >> t >> c;
		g.addedge(i, n+i, t), revg.addedge(i, n+i, t);
		if (!c) {
			g.addedge(0, i), revg.addedge(n+i, 2*n+1);
		}
		while (c--) {
			cin >> v;
			g.addedge(n+v, i), revg.addedge(n+i, v);
			++d[v];
		}
	}
	for (int i = 1; i <= n; ++i) {
		if (!d[i]) {
			revg.addedge(0, i), g.addedge(n+i, 2*n+1);
		}
	}
	g.topsort(n*2+1, dist), revg.topsort(n*2+1, revdist);
	for (int i = 1, maxdist = *max_element(dist+1, dist+n*2+1); i <= n; ++i) {
		cout << dist[n+i] << ' ' << (dist[n+i]+revdist[i] == maxdist) << endl;
	}
	return 0;
}
