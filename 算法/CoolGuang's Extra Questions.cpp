//https://icpc.ldu.edu.cn/contests/2881/problems/8
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
typedef long long LL;
const int N=100010;
int n,a[N],b[N],s;
LL ans;
vector<int>p[N],q[N];
int main() {
	int i,j;
	cin>>n;
	for(i=1; i<=n; i++){
		scanf("%d",a+i);
		b[n+1-i]=a[i];
	}
	for(i=1; i<=n; i++){
		p[a[i]].push_back(i);
		q[b[i]].push_back(i);
	}
	for(i=1; i<=n; i++){
		for(j=0; j<p[i].size(); j++)
			ans+=abs(p[i][j]-q[i][j]);
	}
	cout<<ans/2;
	return 0;
}
