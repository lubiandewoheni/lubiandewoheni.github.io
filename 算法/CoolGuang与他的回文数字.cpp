//https://icpc.ldu.edu.cn/contests/2878/problems/4
/*
题目描述
一个数字如果正读和反读都相同，称为回文数字，例如数字121，判断数字n是否是回文数（不超过3位）。
输入描述
正整数n 
输出描述
yes或no
 */
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int main() {
	int n,t,m=0;
	cin>>n;
	t=n;
	while(n) {
		m=m*10+n%10;
		n/=10;
	}
	if(m==t)
		cout<<"yes";
	else
		cout<<"no";
	return 0;
}
