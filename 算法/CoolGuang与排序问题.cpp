//https://icpc.ldu.edu.cn/contests/2879/problems/6
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
string a[6];
bool cmp(string a,string b) {
	return a+b<b+a;
}
int main() {
	for(int i=0; i<6; i++)
		getline(cin,a[i],'\n');
	sort(a,a+6,cmp);
	for(int i=0; i<6; i++)
		cout<<a[i]<<endl;
	return 0;
}
