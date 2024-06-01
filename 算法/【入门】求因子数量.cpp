//https://icpc.ldu.edu.cn/contest/2851/problem/7
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,s;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		s=0;
		for(int j=2;j<=sqrt(i);j++)
			if(i%j==0)
				s+=2;
		if(float(sqrt(i))==int(sqrt(i))&&i!=1)
			s--;
		cout<<s<<endl;
	}
}
