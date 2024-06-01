//https://icpc.ldu.edu.cn/contests/2873
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,num,ans;
	cin>>n;
	if(n==1){
		cin>>n;
		cout<<n;
		return 0;
	}
	cin>>ans;
	n=n-1;
	while(n--){
		cin>>num;
		ans=__gcd(ans,num);
	}
	cout<<ans;
	return 0;
}
