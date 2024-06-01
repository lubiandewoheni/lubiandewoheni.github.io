//https://icpc.ldu.edu.cn/contests/3716/problems/7
#include <bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int a[1005],b[1005],dp[1005][1005];
int n;
int f(int i,int j) {
	int ans;
	if(dp[i][j]!=-1)
		return dp[i][j];
	if(i==0||j==0)
		ans=0;
	else {
		if(a[i]==b[j])
			ans=f(i-1,j-1)+1;
		else
			ans=max(f(i-1,j),f(i,j-1));
	}
	dp[i][j]=ans;
	return ans;
}
int main() {
	int i;
	cin>>n;
	memset(dp,-1,sizeof(dp));
	for(i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(i=1; i<=n; i++)
		cin>>b[i];
	cout<<f(n,n);
	return 0;
}
