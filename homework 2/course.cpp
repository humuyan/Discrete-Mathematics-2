#include <bits/stdc++.h>
using namespace std;

const int Maxn = 15, Maxm = 111, MaxS = 1<<Maxn;

int n, m, a[Maxn][Maxm];
bool legal[MaxS], dp[2][MaxS];

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		cin >> *a[i];
		for (int j = 1; j <= *a[i]; ++j) {
			cin >> a[i][j];
		}
	}
	for (int S = 0; S < 1<<n; ++S) {
		bool used[Maxm];
		memset(used, false, sizeof(used));
		legal[S] = true;
		for (int i = 0; i < n; ++i) {
			if (S>>i&1) {
				for (int j = 1; j <= *a[i]; ++j) {
					if (!used[a[i][j]]) {
						used[a[i][j]] = true;
					} else {
						legal[S] = false;
					}
				}
			}
		}
	}
	dp[0][0] = true;
	for (int ans = 1; ; ++ans) {
		memset(dp[ans&1], false, sizeof(dp[ans&1]));
		for (int S = 0; S < 1<<n; ++S) {
			for (int s = S; s; s = (s-1)&S) {
				if (legal[s] && dp[!(ans&1)][S^s]) {
					dp[ans&1][S] = true;
					break;
				}
			}
		}
		if (dp[ans&1][(1<<n)-1]) {
			cout << ans << endl;
			break;
		}
	}
	return 0;
}
