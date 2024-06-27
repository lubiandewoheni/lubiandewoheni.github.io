//https://icpc.ldu.edu.cn/contests/3130/problems/6
#include<bits/stdc++.h>
using namespace std;
const int N = 3e5+5;
typedef int _int;
#define int long long
int n, m, k, id[N], c[N], vis[N], now = 0, t1[N], t2[N];
vector <int> ve[N];
struct country {
	int ans, k;
} a[N];
struct Change {
	int l, r, k;
} b[N];
int gi() {
	int ans = 0, f = 1;
	char i = getchar();
	while(i<'0' || i>'9') {
		if(i == '-') f = -1;
		i = getchar();
	}
	while(i>='0' && i<='9') ans = ans*10+i-'0', i = getchar();
	return ans * f;
}
int lowbit(int x) {
	return x&-x;
}
void update(int x, int val) {
	for(; x<=m; x+=lowbit(x)) c[x] += val;
}
int query(int x) {
	int res = 0;
	for(; x; x-=lowbit(x)) res += c[x];
	return res;
}
void change(Change x, int val) {
	if(val) {
		if(x.l <= x.r) update(x.l, x.k), update(x.r+1, -x.k);
		else update(1, x.k), update(x.r+1, -x.k), update(x.l, x.k);
	} else {
		if(x.l <= x.r) update(x.l, -x.k), update(x.r+1, x.k);
		else update(1, -x.k), update(x.r+1, x.k), update(x.l, -x.k);
	}
}
int ask(int x, int lim) {
	int res = 0;
	for(int i=0; i<ve[x].size(); i++) {
		res += query(ve[x][i]);
		if(res > lim) return res;
	}
	return res;
}
void solve(int l, int r, int ql, int qr) {
	if(ql > qr) return;
	if(l == r) {
		for(int i=ql; i<=qr; i++) a[id[i]].ans = l;
		return;
	}
	int mid = (l+r>>1), cnt1 = 0, cnt2 = 0, cnt = ql-1;
	while(now < mid) change(b[++now], 1);
	while(now > mid) change(b[now--], 0);
	for(int i=ql; i<=qr; i++) {
		int sum = ask(id[i], a[id[i]].k);
		if(sum >= a[id[i]].k) t1[++cnt1] = id[i];
		else t2[++cnt2] = id[i];
	}
	for(int i=1; i<=cnt1; i++) id[++cnt] = t1[i];
	for(int i=1; i<=cnt2; i++) id[++cnt] = t2[i];
	solve(l, mid, ql, ql+cnt1-1), solve(mid+1, r, ql+cnt1, qr);
}
_int main() {
	int x;
	n = gi(), m = gi();
	for(int i=1; i<=m; i++) x = gi(), ve[x].push_back(i);
	for(int i=1; i<=n; i++) a[i].k = gi(), id[i] = i;
	k = gi();
	for(int i=1; i<=k; i++) b[i].l = gi(), b[i].r = gi(), b[i].k = gi();
	b[++k].l = 1, b[k].r = m, b[k].k = 0x3f3f3f3f;
	solve(1, k, 1, n);
	for(int i=1; i<=n; i++) {
		if(a[i].ans == k) printf("NIE\n");
		else printf("%lld\n", a[i].ans);
	}
	return 0;
}
