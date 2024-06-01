//https://icpc.ldu.edu.cn/contests/2873/problems/4
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int main1(int z) {
	int m;
	for(m=2; m*m<=z; m++) {
		if(z%m==0)
			return 0;
	}
	return z;
}
int main2(int o) {
	int x,y;
	for(x=2; x<o/2; x++) {
		if(main1(x)!=0) {
			y=o/x;
			if(x*y==o&&main1(y)!=0)
				return 1;
		}
	}
	return 0;
}
int main() {
	int a;
	cin>>a;
	if(main2(a)==1)
		cout<<"It's a Tongtong number.";
	else
		cout<<"It's not a Tongtong number.";
	return 0;
}
