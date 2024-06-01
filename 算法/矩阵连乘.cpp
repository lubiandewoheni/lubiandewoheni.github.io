//https://icpc.ldu.edu.cn/contests/3716/problems/3
#include <bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int a[105],n;
int dp[105][105];
int f(int bb,int ee) {
	int ans,i;
	if(dp[bb][ee]!=-1)
		return dp[bb][ee];
	if(bb==ee)
		ans=0;
	else {
		ans=f(bb,bb)+f(bb+1,ee)+a[bb]*a[bb+1]*a[ee+1];
		for(i=bb+1; i<ee; i++) {
			int temp=f(bb,i)+f(i+1,ee)+a[bb]*a[i+1]*a[ee+1];
			if(temp<ans)
				ans=temp;
		}
	}
	dp[bb][ee]=ans;
	return ans;
}
int main() {
	int i;
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(i=1; i<=n; i++) {
		cin>>a[i]>>a[i+1];
	}
	cout<<f(1,n);
	return 0;
}
