//https://icpc.ldu.edu.cn/contests/2791/problems/23
#include<bits/stdc++.h>
using namespace std;
int main() {
	long long a,b,p,ans=1;
	cin>>a>>b>>p;
	while(b) {
		if(b%2==1)
			ans=ans*a%p;
		b/=2;
		a=(a*a)%p;
	}
	cout<<ans%p;
	return 0;
}
