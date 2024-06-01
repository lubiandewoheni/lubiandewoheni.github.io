//https://icpc.ldu.edu.cn/contests/2873/problems/8
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int main2(int z) {
	int m;
	for(m=2; m*m<=z; m++) {
		if(z%m==0)
			return 0;
	}
	return z;
}
int main() {
	int a,b,c[200],d=0,g,i;
	double f=0;
	char j[21];
	cin>>j;
	for(a=0; a<strlen(j)-2; a++) {
		b=(j[a]-'0')*10;
		g=j[a+1]-'0';
		i=b+g;
		if(main2(i)==i) {
			c[d]=i;
			d++;
		}
	}
	for(a=0; a<d; a++) {
		if(a==d-1)
			cout<<c[a];
		else
			cout<<c[a]<<",";
	}
}
