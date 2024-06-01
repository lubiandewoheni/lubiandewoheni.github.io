//https://icpc.ldu.edu.cn/contest/2794/problem/13
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int main()
{
	int n,s1,s2,i;
	char str[200];
	cin>>n;
	while(n--){
		cin>>str;
		s1=s2=0;
		for(i=0;i<strlen(str);i++){
			if(i%2)
				s1+=str[i]-'0' ;
			else
				s2+=str[i]-'0' ;
		}
		if(s1%11==s2%11)
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
