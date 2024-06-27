//https://icpc.ldu.edu.cn/contests/3106/problems/6
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int main1() {                           //时间超限
	ll n,x=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(i%2!=0 and i%3!=0 and i%4!=0 and i%5!=0 and i%6!=0 and i%7!=0 and i%8!=0 and i%9!=0 and i%10!=0)
			x=x+1;
	}
	cout<<x;
	return 0;
}
int main(){
	long long n,x,y,z;
	cin>>n;
	y=(n/2+n/3+n/5+n/7);
	z=(n/30+n/42+n/70+n/105);
	x=n-y+n/6+n/10+n/14+n/15+n/21+n/35-z+n/210;
	cout<<x;
} 
