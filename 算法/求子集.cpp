//https://icpc.ldu.edu.cn/contests/3714/problems/2
//https://icpc.ldu.edu.cn/contests/3717/problems/4
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
int main() {
    char str[26];
    int n, i, num, temp, count;
    for (int i = 0; i < 26; i++) {
        str[i] = 'a' + i;
    }
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> n;
    for (num = 0; num < (1 << n); num++) {
        temp = num;
        count = 0;
        cout << "(";
        for (i = 0; i < n; i++) {
            if (temp % 2 == 1) {
                cout << " "+!count << str[i];
                count ++;
            }
            temp /= 2;
        }
        cout << ")\n";
    }
    return 0;
}
