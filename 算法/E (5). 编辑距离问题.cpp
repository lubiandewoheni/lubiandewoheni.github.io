//https://icpc.ldu.edu.cn/contests/3716/problems/4
#include <bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
string str1, str2;
int dp[2005][2005];
int imin(int t1, int t2, int t3) {
	return min(t1, min(t2, t3));
}
int main() {
	int len1, len2;
	cin >> str1 >> str2;
	len1 = str1.size();
	len2 = str2.size();

	for (int i = 0; i <= len1; i++) {
		dp[i][0] = i;
	}
	for (int j = 0; j <= len2; j++) {
		dp[0][j] = j;
	}
	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (str1[i - 1] == str2[j - 1]) {
				dp[i][j] = dp[i - 1][j - 1];
			} else {
				dp[i][j] = imin(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
			}
		}
	}
	cout << dp[len1][len2];
	return 0;
}
