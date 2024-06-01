//https://icpc.ldu.edu.cn/contests/3713/problems/3
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
long long hm[1005];
long long h(int n){
	if(hm[n]!=0)
		return hm[n];
	long long ans=0;
	if(n==0)
		ans=1;
	else{
		for(int i=0;i<n;i++)
			ans=(ans+h(i)*h(n-1-i))%1000000007;
	}
	hm[n]=ans;
	return ans;
}
int main() {
	int n;
	cin>>n;
	cout<<h(n);
	return 0;
}
