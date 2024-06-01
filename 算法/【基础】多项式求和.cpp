//https://icpc.ldu.edu.cn/contest/2851/problem/9
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,i,a=1,s=0;
int main()
{
	cin>>n;
	for(i=1;i<=n;i++)
	{
		a*=i;
		if(i%2==0)
			s=s-a;
		else
			s=s+a;
	}
	cout<<s;
	return 0;
}
