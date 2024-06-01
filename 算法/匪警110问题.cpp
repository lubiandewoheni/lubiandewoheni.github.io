//https://icpc.ldu.edu.cn/contests/3714/problems/16
//https://icpc.ldu.edu.cn/contests/3717/problems/5
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
int main() {
	int num, temp, sum, pre, oper, i, n, ans = 0;
	// oper==1 +,    oper==2 -;
	int a[9];
	cin >> n;

	for (num = 0; num < pow(3, 8); num++) {
		temp = num;
		for (i = 1; i < 9; i++) {
			a[i] = temp % 3;
			temp /= 3;
		}
		sum = 0;
		pre = 1;
		oper = 1;
		for (i = 1; i < 9; i++) {
			if (a[i] == 0) {
				pre = pre * 10 + (i + 1);
			} else if (a[i] == 1) {
				if (oper == 1) {
					sum += pre;
				} else {
					sum -= pre;
				}
				oper = 1; // next compute is +
				pre = i + 1;
			} else { // a[i] == 2
				if (oper == 1) {
					sum += pre;
				} else {
					sum -= pre;
				}
				oper = 2;
				pre = i + 1;
			}
		}
        if (a[8] == 0) {
            if (oper == 1) {
                sum += pre;
            } else {
                sum -= pre;
            }
        } else if (a[8] == 1) {
            sum += pre;
        } else {
            sum -= pre;
        }
		if (sum == n) {
			ans ++;
		}
	}
	cout << ans;
	return 0;
}
