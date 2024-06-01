#include <bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
int ww[35], vv[35];
int m, n;
int dp[205][35];
int main() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		cin >> ww[i] >> vv[i];
	}
	for (int i = 0; i < min(ww[n], m); i++) {
		dp[i][n] = 0;
	}
	for (int i = ww[n]; i <= m; i++) {
		dp[i][n] = vv[n];
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 0; j <= m; j++) {
			if (j < ww[i]) {
				dp[j][i] = dp[j][i + 1];
			} else {
				dp[j][i] = max(
				               dp[j][i + 1],
				               dp[j - ww[i]][i + 1] + vv[i]
				           );
			}
		}
//		for (int j = 0; j < min(ww[i], m); j++) {
//			dp[j][i] = dp[j][i + 1];
//		}
//		for (int j = ww[i]; j <= m; j++) {
//			dp[j][i] = max(
//			               dp[j][i + 1],
//			               dp[j - ww[i]][i + 1] + vv[i]
//			           );
//		}
	}
	cout << dp[m][1];
	return 0;
}
