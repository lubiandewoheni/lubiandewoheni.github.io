//https://icpc.ldu.edu.cn/contest/2852/problem/4
/*
题目描述
由于上次Fox出题太简单，导致有人38秒就把A题提交了，Fox因此得到了队友的强烈谴责，于是这一次他决定把题出的难一点，但是他也不想太为难学弟学妹们，现在Fox已经出了N道题了(N一定为奇数），每道题被赋予了一个难度值，难度值越大表示这题越难，Fox决定这N道题里面难度处于中间的题作为本次的签到题
如果这个签到题只有一个，这次签到题出题将会很成功，否则本次签到题出题就很失败！
输入描述
第一行 一个数N代表题目数量(3<N<1000)
第二行N个数，代表每个题的难度值(保证在int范围内）
输出描述
一行 如果这次签到题出题很成功，输出“Fox%xoF"(无引号)和本次签到题的难度值（以空格隔开），
否则输出"Bad%daB";
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[1000],b[1000],c[1000];
int main2() {                    //答案错误
	int n,x1,x2=0;
	cin>>n;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
		b[i]=a[i];
	}
	sort(a, a + n);
	x1=a[(n)/2];
	cout<<x1;
	for(int i=1; i<=n; i++) {
		if(b[i]==x1) {
			x2=x2+1;
		}
	}
	if(x2==1)
		cout<<"Fox%xoF "<<x1;
	else
		cout<<"Bad%daB";
	return 0;
}


int main() {
	int n;
	cin >> n;
	int a[n];
	for(int& i : a)
		cin >> i;
	sort(a, a + n);
	int middiff = a[(n - 1) / 2];
	if(middiff == a[(n - 1) / 2 - 1] || middiff == a[(n - 1) / 2 + 1])
		cout << "Bad%daB";
	else
		cout << "Fox%xoF " << middiff;
	return 0;
}


#define N 1000
int n, t, d[N];
int main3() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> d[i];
	sort(d+1,d+1+n);
	int k = d[n/2+1];
	int cnt = 0;
	for(int i=1; i<=n; i++) {
		if(d[i] == k) cnt++;
	}
	if(cnt == 1) {
		cout << "Fox%xoF " << k;
	} else {
		cout << "Bad%daB" ;
	}
	return 0;
}
