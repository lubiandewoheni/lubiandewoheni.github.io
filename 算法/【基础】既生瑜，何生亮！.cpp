//https://icpc.ldu.edu.cn/contests/2873/problems/6
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
ll a[10],b[10],c[10],n,m,p[10],q,j=1;
int main1() {                                   //´ð°¸´íÎó
	cin>>n>>m;
	q=m-n;
	for(int i=n; i<=m; i++) {
		p[i]=n*n;
		if(p[i]/1000000!=0 && p[i]/10000000==0) {
			a[j]=i;
			j=j+1;
		}
	}
	for(int i=1; i<=q; i++) {
		c[1]=p[i]%10;
		c[2]=(p[i]%100-p[i]%10)/10;
		c[3]=(p[i]%1000-p[i]%100)/100;
		c[4]=(p[i]%10000-p[i]%1000)/1000;
		c[5]=(p[i]%100000-p[i]%10000)/10000;
		c[6]=(p[i]%1000000-p[i]%100000)/100000;
		c[7]=(p[i]%10000000-p[i]%1000000)/1000000;
		for(int j=1; j<=q; j++) {
			if(c[1]!=c[2]&&c[1]!=c[3]&&c[1]!=c[4]&&c[2]!=c[3]&&c[2]!=c[4]&&c[3]!=c[4])
				b[i]=a[i];
			else
				b[i]=0;
		}
	}
	for(int i=1; i<=q; i++) {
		if(b[i]!=0)
			cout<<b[i]<<endl;
	}
	return 0;
}




int main(){                               //ÕýÈ·
	ll x,y,t,d[10];
	cin>>x>>y;
	for(ll i=x;i<=y;i++) {
		t=i*i;
		if(t<10000000 && t>=1000000){
			memset(d,0,sizeof(d));
			for(int j=0;j<7;j++){
				d[t%10]++;
				t/=10;
			}
			sort(d,d+10);
			if(d[9]==1)
				cout<<i<<endl;
		}
	}
	return 0;
}
