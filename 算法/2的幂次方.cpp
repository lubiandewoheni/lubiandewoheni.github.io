//https://icpc.ldu.edu.cn/contests/3115/problems/3
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string DFS(ll n) {
	string str="";
	int count=0;//计算次方数，以便递归，每次递归要清 0 的.
	while(n!=0) {
		if(n%2==1) {
			if(count==0) str="2(0)+"+str;
			else if(count==1)
				str="2+"+str;//这个else肯定要写，主要是影响下面一个
			else
				str="2("+DFS(count)+")+"+str;//后运算的肯定写在前面的！
		}
		count++;
		n/=2;
	}
	str.erase(str.size()-1);
	return str;
}
int main() {
	ll n;
	while(cin>>n) {
		if(n==0)
			cout<<0<<endl;
		else
			cout<<DFS(n)<<endl;
	}
	return 0;
}
