//https://icpc.ldu.edu.cn/contest/2782/problem/12
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int n,a[11],x=0,i;
	cin>>n;
	n=n*n*n;
	a[10]=n/1000000000;
	a[9]=(n%1000000000)/100000000;
	a[8]=(n%100000000)/10000000;
	a[7]=(n%10000000)/1000000;
	a[6]=(n%1000000)/100000;
	a[5]=(n%100000)/10000;
	a[4]=(n%10000)/1000;
	a[3]=(n%1000)/100;
	a[2]=(n%100)/10;
	a[1]=(n%10);
	for(i=1;i<=10;i++)
		x=a[i]*a[i]*a[i]+x;
	cout<<x;
	return 0;
}

