//https://icpc.ldu.edu.cn/contests/2873/problems/5
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
ll n,a=1,i,sum;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++){
		sum=sum+a;
		a=a+i;
	}
	cout<<sum;
	return 0;
}
