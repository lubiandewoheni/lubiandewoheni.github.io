//https://icpc.ldu.edu.cn/contests/3714/problems/1
//https://icpc.ldu.edu.cn/contests/3717/problems/20
#include <bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
int main() {
	int m, n, w[16], c[16];
	int i, temp, num, tempw, tempc, maxc = 0;
	cin >> m >> n;
	for (i = 0; i < n; i++) {
		cin >> w[i] >> c[i];
	}
	for (num = 0; num < (1 << n); num++) {
		temp = num;
		tempw = tempc = 0;
		for (i = 0; i < n; i++) {
			if (temp % 2 == 1) {
				tempw += w[i];
				tempc += c[i];
			}
			temp /= 2;
		}
		if (tempw <= m && tempc > maxc) {
			maxc = tempc;
		}
	}
	cout << maxc;
	return 0;
}
