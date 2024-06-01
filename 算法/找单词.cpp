//https://icpc.ldu.edu.cn/contests/3713/problems/7
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
void solve(){
	int i,j,k,a[27];
	int ans[51],temp[51];
	for(i=1;i<=26;i++)
		cin>>a[i];
	memset(ans,0,sizeof(ans));
	for(i=0;i<=a[1];i++)
		ans[i]=1;
	for(i=2;i<=26;i++){
		memset(temp,0,sizeof(temp));
		for(j=0;j<51;j++){
			for(k=0;k<=a[i];k++){
				if(j+k*i<51){
					temp[j+k*i]+=ans[j];
				}
			}
		}
		for(j=0;j<51;j++)
			ans[j]=temp[j];
	}
	int res=0;
	for(i=1;i<51;i++)
		res+=ans[i];
	cout<<res<<endl;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
