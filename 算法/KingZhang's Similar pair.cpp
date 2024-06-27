//https://icpc.ldu.edu.cn/contest/2852/problem/3
/*
题目描述
KingZhang定义Similar对为两个数具有相同的奇偶性或者是差值的绝对值为1.
现在给你一个数组，请你判断一个数组的元素是否能两两对应分为Similar对。
如果回答正确的话，KingZhang就会给你糖果吃奥。
输入描述
第一行输入一个整数n（n≤1000）
第二行输入n个整数，a[i]表示第i个数（a[i]≤1e9）
输出描述
如果可以的话，输出“YES”；否则，输出“NO”；（输出不包含引号）
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 1000
int n, k;
int a[N], cnt1, cnt2;
int main() {
	cin >> n;
	if(n % 2 != 0) {
		cout << "NO\n";
		return 0;
	}
	for(int i=1; i<=n; i++) {
		cin >> a[i];
		if(a[i] % 2) cnt1++;
		else cnt2++;
	}
	sort(a+1,a+1+n);
	if(cnt1 % 2 == 0) {           //都是偶数个
		cout << "YES" ;
	} else {                      //否则找有没有差是1的
		bool f= 0;
		for(int i=1; i<n; i++) {
			if(a[i+1] - a[i] == 1) {
				f = 1;
				break;
			}
		}
		if(f) {
			cout << "YES";
		} else {
			cout << "NO";
		}
	}
	return 0;
}
