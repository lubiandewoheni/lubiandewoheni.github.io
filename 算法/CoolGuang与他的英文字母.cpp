//https://icpc.ldu.edu.cn/contests/2878/problems/3
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int main() {
	char ch;
	cin>>ch;
	if(ch>='a'&&ch<='z') {
		cout<<"lower case";
		return 0;
	}
	if(ch>='A'&&ch<='Z') {
		cout<<"upper case";
		return 0;
	}
	if(ch>='0'&&ch<='9') {
		cout<<"digit number";
		return 0;
	}
	return 0;
}
