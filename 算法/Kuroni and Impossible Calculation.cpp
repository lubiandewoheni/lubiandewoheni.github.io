//https://icpc.ldu.edu.cn/contests/3106/problems/5
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[300000];
int n,m,ans=1;
int main(){
	cin>>n>>m;
	for(int i=1; i<=n; i++) cin>>a[i];
	if(n>m){
		cout<<0;
		return 0;
	}
	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++) {
			ans=(ans%m)*(abs(a[i]-a[j])%m)%m;
		}
	}
	cout<<ans;
	return 0;
}
