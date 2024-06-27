//https://icpc.ldu.edu.cn/contest/2852/problem/5
/*
题目描述
q个操作，每个操作存入一个数x，问最后存了几个不同的数字。
输入描述
第一行 一个整数q（1≤q≤1e5）
接下来q行 每行一个整数x（1≤x≤1e5）
输出描述
一个整数，即答案
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100000
int x[100000];
int n, t, a[N], id;
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> id;
		a[id] = 1;
	}
	int cnt = 0;
	for(int i=1; i<=100000; i++) {
		if(a[i] == 1) cnt++;
	}
	cout << cnt;
	return 0;
}
