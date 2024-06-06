//https://icpc.ldu.edu.cn/contests/2878/problems/1
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
#define p 3.1415926
int main(){
	int a[2][3];
	int i,imax=0,j;
	for(i=0;i<3;i++)
		cin>>a[0][i];
	for(i=0;i<3;i++)
		a[1][i]=a[0][i]*a[0][i];
	for(i=0;i<3;i++){
		if(a[1][i]>imax){
			imax=a[1][i];
			j=i;
		}
	}
	cout<<a[0][j];
	return 0;
}
