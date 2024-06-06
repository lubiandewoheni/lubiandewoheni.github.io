//https://icpc.ldu.edu.cn/contest/2841/problem/8
#include<bits/stdc++.h>
using namespace std;
int main()
{
	double a,b,c,d;
	int e;
	cin>>setprecision(2)>>a;
	if(a==0)
		b=0.15;
	else if(a>=0&&a<=400)
		b=0.15;
	else if(a>400&&a<=800)
		b=0.12;
	else if(a>800&&a<=1200)
		b=0.10;
	else if(a>1200&&a<=2000)
		b=0.07;
	else
		b=0.04;
	d=a*b;
	c=a*(b+1); // a+d
	e=b*100;
	printf("Novo salario: ");
	cout<<c<<endl; 
	printf("Reajuste ganho: ");
	cout<<fixed<<setprecision(2)<<d<<endl;
	printf("Em percentual: ");
	cout<<e<<" %";
	return 0;
}
