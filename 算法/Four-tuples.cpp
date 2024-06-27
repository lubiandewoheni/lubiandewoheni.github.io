//https://icpc.ldu.edu.cn/contests/3106/problems/4
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int main() {
	int t;
	scanf ("%d",&t);
	while(t--) {
		ll l1, r1, l2, r2, l3, r3, l4, r4;
		scanf ("%lld %lld %lld %lld %lld %lld %lld %lld",&l1,&r1,&l2,&r2,&l3,&r3,&l4,&r4);
		ll t1 = r1-l1 + 1;
		ll t2 = r2-l2 + 1;
		ll t3 = r3-l3 + 1;
		ll t4 = r4 -l4 + 1;
		ll res = t1 * t2 % mod * t3 % mod * t4 % mod;
		ll t12 = max(min(r1, r2) - max(l1, l2) + 1ll, 0ll);
		ll t23 = max(min(r2, r3) - max(l2, l3) + 1ll, 0ll);
		ll t34 = max(min(r3, r4) - max(l3, l4) + 1ll, 0ll);
		ll t41 = max(min(r1, r4) - max(l1, l4) + 1ll, 0ll);
		ll t123 = max(min(r1, min(r2, r3)) - max(l1, max(l2, l3)) + 1ll, 0ll);
		ll t124 = max(min(r1, min(r2, r4)) - max(l1, max(l2, l4)) + 1ll, 0ll);
		ll t423 = max(min(r4, min(r2, r3)) - max(l4, max(l2, l3)) + 1ll, 0ll);
		ll t143 = max(min(r1, min(r4, r3)) - max(l1, max(l4, l3)) + 1ll, 0ll);
		ll t1234 = max(min(min(r1, r2), min(r3, r4)) - max(max(l1, l2), max(l3, l4)) + 1ll, 0ll);
		ll temp1 = (t12 * t3 % mod * t4 % mod + t23 * t1 % mod * t4 % mod + t34 * t1 % mod * t2 % mod + t41 * t2 % mod * t3 % mod ) % mod;
		ll temp2 = (t123 * t4 % mod + t124 * t3 % mod + t423 * t1 % mod + t143 * t2 % mod + t12 * t34 % mod + t23 * t41 % mod) % mod;
		res = (res % mod - temp1 % mod + mod) % mod;
		res =(res % mod + temp2 % mod) % mod;
		res = (res % mod - 3 * t1234 % mod + mod) % mod;
		printf ("%lld\n", res);
	}
	return 0;
}
