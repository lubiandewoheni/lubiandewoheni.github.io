//https://icpc.ldu.edu.cn/contests/2878/problems/0
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
#define p 3.1415926
int main(){
	double r,h,s,v;
	cin>>r>>h;
	s=2*p*r*r+2*p*r*h;
	v=p*r*r*h;
	printf("%.1lf %.1lf",s,v);
	return 0;
}
