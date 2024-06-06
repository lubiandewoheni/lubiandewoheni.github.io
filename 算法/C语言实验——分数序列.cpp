//https://icpc.ldu.edu.cn/contest/2783/problem/13
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main2()            //正确
{
	int f1;
	double f2=1,f3=2,s=0.0,t;
	cin>>f1;
	while(f1--)
	{
		s+=(f3/f2);
		t=f3;
		f3=f2+f3;
		f2=t;
	}
	printf("%.6lf",s);
	return 0;
}

int main()              //正确
{
	double n,i,a,c,b,s=0,t;
	cin>>n;
	a=1;b=2;
	for(i=1;i<=n;i++){
		t=b/a;
		s=s+t;
		c=a+b;
		a=b;
		b=c;
	}
	printf("%.6lf",s);
	return 0;
}

