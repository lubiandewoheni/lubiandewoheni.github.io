//https://icpc.ldu.edu.cn/contest/2851/problem/2
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b,d=1;
int main() {
	cin>>a;
	for(; a>0; a/=10) {
		b=a%10;
		if(b!=0) {
			d*=b;
		}
		if(a<10) {
			if(d<10) {
				break;
			} else {
				a=d*10;
				d=1;
			}
		}
	}
	cout<<d;
	return 0;
}
