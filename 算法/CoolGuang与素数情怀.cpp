//https://icpc.ldu.edu.cn/contests/2791/problems/16
//https://icpc.ldu.edu.cn/contests/2878/problems/6
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int main(){
	int m,n,i,leap,j,f=0;
	leap=1;
	scanf("%d %d",&m,&n);
	if(m>n)
		swap(m,n);
	for(j=m;j<=n;j++) {
		for(i=2,leap=1;i<=j-1;i++){
			if(j%i==0){
				leap=0;
				break;
			}
		}
		if(leap==1){
			if(j!=1){
				printf("%d ",j);
				f=f+1;
			}
			if(f%5==0 && f!=0)
				cout<<endl;
		}
	}
	if(f==0)
		cout<<"no";
	return 0;
}
