//https://icpc.ldu.edu.cn/contest/2851/problem/1
#include<bits/stdc++.h>
using namespace std;
long long n,s,a[10],x,m=0;
int main()
{
	cin>>n;
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
	if(a[10]!=m)
		x=10;
	else if(a[9]!=m)
		x=9;
	else if(a[8]!=m)
		x=8;
	else if(a[7]!=m)
		x=7;
	else if(a[6]!=m)
		x=6;
	else if(a[5]!=m)
		x=5;
	else if(a[4]!=m)
		x=4;
	else if(a[3]!=m)
		x=3;
	else if(a[2]!=m)
		x=2;
	else if(a[1]!=m)
		x=1;
	for(int i=1;i<=x;i++){
		if(a[i]%2==0)
			s=s+a[i];
	}
	cout<<x<<" "<<s;
	return 0;
}
