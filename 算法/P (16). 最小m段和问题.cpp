//https://icpc.ldu.edu.cn/contests/3716/problems/15
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;            // 错误
int minMaxSum(int* nums, int n, int m) {
	int dp[n + 1][m + 1];  
	int sum[n + 1];
	for (int i = 0; i <= n; i++) {  
		for (int j = 0; j <= m; j++) {  
			dp[i][j] = INT_MAX;  
		}  
	}
	sum[0] = 0;  
	for (int i = 1; i <= n; i++) {  
		sum[i] = sum[i - 1] + nums[i - 1];  
	}
	for (int i = 1; i <= n; i++) {  
		dp[i][1] = sum[i];  
	}
	for (int j = 2; j <= m; j++) {  
		for (int i = j; i <= n; i++) {
			for (int k = j - 1; k < i; k++) {
				dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sum[i] - sum[k]));
			}
		}
	}
	return dp[n][m];
}
int main() {
	int n, m;  
	scanf("%d %d", &n, &m);
	int *nums = (int*)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		scanf("%d", &nums[i]);
	}
	int result = minMaxSum(nums, n, m);
	printf("%d\n", result);
	free(nums);
	return 0;
}
