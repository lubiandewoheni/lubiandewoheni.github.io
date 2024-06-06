//https://icpc.ldu.edu.cn/contest/2852/problem/7
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 10000
int p[N], cnt, t, n;
bool isp(int n) {
	if(n < 2) return 0;
	for(int i=2; i*i<=n; i++)
		if(n % i == 0) return 0;
	return 1;
}
int main() {
	for(int i=1; i<=100; i++) if(isp(i)) p[++cnt] = i;
	cin >> t;
	while(t--) {
		cin >> n;
		bool f = 0;
		for(int i=1; i<=cnt; i++) {
			int cnt = 0;
			while(n % p[i] == 0) {
				cnt++;
				n /= p[i];
			}
			if(cnt > 1) {
				f = 1;
				break;
			}
		}
		if(f) cout << "yes\n";
		else cout << "no\n";
	}
	return 0;
}
