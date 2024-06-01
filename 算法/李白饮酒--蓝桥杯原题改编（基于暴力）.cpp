//https://icpc.ldu.edu.cn/contests/3714/problems/14
//https://icpc.ldu.edu.cn/contests/3717/problems/6
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
int main() {
	// s 次店，f - 1 次花
	// 店 0， 花 1
	int s, f, ans = 0, i, wine, cs, cf, num, temp;
	cin >> s >> f;
	for (num = 0; num < (1 << (s + f - 1)); num++) {
		wine = 2;
		cs = cf = 0;

		temp = num;
		for (i = 0; i < s + f - 1; i++) {
			if (temp % 2 == 0) {
				cf++;
				wine--;
			} else {
				cs++;
				wine *= 2;
			}
            temp /= 2;
		}

		if (wine == 1 && cs == s && cf == f - 1) {
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
