//https://icpc.ldu.edu.cn/contests/2878/problems/2
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int main(){
	int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
	int year,month,day,i,ans=0;
	scanf("%d-%d-%d",&year,&month,&day);
	for(i=1;i<month;i++){
		ans+=a[i];
	}
	ans+=day;
	if(year%400==0||(year%4==0&&year%100!=0)){
		if(month>2)
			ans++;
	}
	cout<<ans;
	return 0;
}
