//https://icpc.ldu.edu.cn/contests/2873/problems/7
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
ll n,sum=0,s=0,i;
int main() {
	cin>>n;
	for(i=1; i<=n; i++) {
		sum=sum+i;
		s=s+sum;
	}
	cout<<s;
	return 0;
}
