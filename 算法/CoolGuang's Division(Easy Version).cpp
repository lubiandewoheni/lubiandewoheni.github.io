//https://icpc.ldu.edu.cn/contests/2881/problems/7
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
const int abc=3e5+10;
int n,a[abc],x,y,t,i;
ll s;
map<int,int>mp;
int main() {
	cin>>n;
	for(i=1; i<=n; i++) {
		cin>>x;
		mp[x]++;
		a[i]=x;
		cin>>x;
	}
	sort(a,a+n);
	for(i=1; i<=n; i++) {
		y=a[i];
		t=max(t,y+1);
		while(mp[y]>1) {
			while(mp[t])
				t++;
			mp[t]=1;
			s+=t-y;
			mp[a[i]]--;
		}
	}
	printf("%lld",s);
}
