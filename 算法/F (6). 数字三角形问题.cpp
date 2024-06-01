//https://icpc.ldu.edu.cn/contests/3716/problems/5
#include <bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;            //动态规划
int n, a[105][105], dp[105][105];
int f(int i, int j) {
	if (dp[i][j] != -1) {
		return dp[i][j];
	}
	int ans;
	if (i == n) {
		ans = a[i][j];
	} else {
		ans = max(f(i + 1, j), f(i + 1, j + 1)) + a[i][j];
	}
	dp[i][j] = ans;
	return ans;
}
int main() {
	memset(dp, 0, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = n; i >= 0; i--) {
		for (int j = 1; j <= i; j++) {
			dp[i][j] = a[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
		}
	}
	cout << dp[1][1];
	return 0;
}
