//https://icpc.ldu.edu.cn/contests/3713/problems/6
#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,i,j,k;
	int ans[1005],temp[1005];
	cin>>n;
	for(i=0;i<=n;i++)
		ans[i]=1;
	for(i=2;i<=n;i++){
		memset(temp,0,sizeof(temp));
		for(j=0;j<=n;j++){
			for(k=0;k<=n;k+=i){
				if(j+k<=n){
					temp[j+k]=(temp[j+k]+ans[j])%1000000007;
				}
			}
		}
		for(j=0;j<=n;j++)
			ans[j]=temp[j];
	}
	cout<<ans[n];
	return 0;
}
