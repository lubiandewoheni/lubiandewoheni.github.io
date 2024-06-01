//https://icpc.ldu.edu.cn/contest/2792/problem/17
//https://icpc.ldu.edu.cn/contest/2069/problem/17
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
	int a,b,c;
	for(a=1000;a<=9999;a++){
		b=a/100;
		c=a%100;
		if((b+c)*(b+c)==a)
			cout<<a<<" ";
	}
	return 0;
}
