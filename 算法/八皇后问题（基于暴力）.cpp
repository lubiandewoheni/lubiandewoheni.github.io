//https://icpc.ldu.edu.cn/contests/3714/problems/12
#include <bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
bool judge(int *, int);
int main() {
	int n, k, i, ans = 0, a[15];
	long long num, temp, cnt;
	cin >> n >> k;
	if (k > n) {
		cout << 0;
		return 0;
	}
	for (num = 0; num < pow(n + 1, n); num++) {
		temp = num;
		cnt = 0;
		for (i = 0; i < n; i++) {
			a[i] = temp % (n + 1);
			cnt += (a[i] != 0);
			temp /= n + 1;
		}
		if (cnt == k and judge(a, n) == true) {
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
bool judge(int *a, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (a[i] != 0 and a[j] != 0) {
				if (a[i] == a[j] or abs(i - j) == abs(a[i] - a[j])) {
					return false;
				}
			}
		}
	}
	return true;
}
