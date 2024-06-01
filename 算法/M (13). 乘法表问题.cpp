//https://icpc.ldu.edu.cn/contests/3716/problems/12
#include <bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
string str;          //递归
int dp[1006][1006][3]; // 0->a, 1->b, 2->c
int f(int bb, int ee, int ch) {
	if (dp[bb][ee][ch] != -1) {
		return dp[bb][ee][ch];
	}
	int ans = 0;
	if (bb == ee) {
		ans = (str[bb] - 'a') == ch;
	} else {
		switch (ch) {
			case 0:
				for (int i = bb; i < ee; i++) {
					ans += f(bb, i, 0) * f(i + 1, ee, 2)
					       + f(bb, i, 1) * f(i + 1, ee, 2)
					       + f(bb, i, 2) * f(i + 1, ee, 0);
				}
				break;
			case 1:
				for (int i = bb; i < ee; i++) {
					ans += f(bb, i, 0) * f(i + 1, ee, 0)
					       + f(bb, i, 0) * f(i + 1, ee, 1)
					       + f(bb, i, 1) * f(i + 1, ee, 1);
				}
				break;
			case 2:
				for (int i = bb; i < ee; i++) {
					ans += f(bb, i, 1) * f(i + 1, ee, 0)
					       + f(bb, i, 2) * f(i + 1, ee, 1)
					       + f(bb, i, 2) * f(i + 1, ee, 2);
				}
				break;
		}
	}
	dp[bb][ee][ch] = ans;
	return ans;
}
int main() {
	cin >> str;
	memset(dp, -1, sizeof(dp));
	cout << f(0, str.size() - 1, 0);
	return 0;
}
