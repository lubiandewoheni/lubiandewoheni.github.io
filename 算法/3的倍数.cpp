//https://icpc.ldu.edu.cn/contests/2884/problems/2
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
char a[1111111];
ll ans=0,i;
int main1() {
	cin>>a;
	for(i=0; i<1111111; i++)
		ans=ans+a[i]-'0';
	if(ans%3==0)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
//(不能本地运行，但能通过)
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main2() {
	ll sum=0;
	char ch;
	while(cin>>ch)
		sum+=ch-'0';
	if(sum%3==0)
		cout<<"Yes";
	else
		cout<<"No";
	return 0;
}
//https://icpc.ldu.edu.cn/contests/2794/problems/12
//答案错误
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
char b[1111];
ll an,n;
int main3() {
	cin>>n;
	for(int j=0; j<n; j++) {
		cin>>b;
		an=0;
		for(int i=0; i<1111; i++)
			an=an+b[i]-'0';
		if(an%3==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
//正确
#include<bits/stdc++.h>
using namespace std;
int main() {
	char str1[300];
	long long l,n,t,i,ans=0;
	cin>>n;
	for(t=0; t<n; t++) {
		ans=0;
		cin>>str1;
		for(i=0;str1[i]!='\0';i++)
			ans=ans+(str1[i]-'0');
		if(ans%3==0)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}
