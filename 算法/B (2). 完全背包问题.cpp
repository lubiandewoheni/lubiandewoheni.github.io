//https://icpc.ldu.edu.cn/contests/3716/problems/1
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
int ww[35], vv[35];
int m, n;
int dp[205][35];
int f(int c, int index) {
    if (dp[c][index] != -1) {
        return dp[c][index];
    }
    int ans;
    if (index == n) {
        if (c >= ww[index]) {
            ans = vv[index];
        } else {
            ans = 0;
        }
    } else {
        if (c < ww[index]) {
            ans = f(c, index + 1);
        } else {
            ans = max(
                f(c, index + 1),
                f(c - ww[index], index) + vv[index]
                );
        }
    }
    dp[c][index] = ans;
    return ans;
}
int main() {
    memset(dp, -1, sizeof(dp));
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ww[i] >> vv[i];
    }
    cout << f(m, 1);
    return 0;
}
