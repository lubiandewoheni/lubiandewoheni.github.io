//https://icpc.ldu.edu.cn/contests/2792/problems/7
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int main() {
	ll n,a,sum=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		a=i;
		while(a!=0) {
			if(a%10==1)
				sum++;
			a=a/10;
		}
	}
	cout<<sum;
	return 0;
}
