//https://icpc.ldu.edu.cn/contest/2852/problem/8
/*
题目描述
实验室有n个人，从左向右为1到n编号，给出实验室每个人的篮球熟练度。（篮球熟练度越高，能力越强）
有一天实验室要进行篮球赛了，Cutele要做的事情就是将n个人分成两个队，每个队必须有一个人，而且一个人只能在一个队里。
为了防止被CoolGuang这个篮球高手虐，Cutele希望第一队里最强的人和第二队里最弱的人的篮球熟练度差别尽可能的小。
例如n=5, a=[3,1,2,6,4];
第一队=[1,2,4]
第二队=[3,6]
在这种情况下，第一队里最强的人和第二队里最弱的人的篮球熟练度差别是|4-3|=1,可以证明是最优分解。
你能帮助聪明可爱美丽善良大方的Cutele解决这个问题吗？
 */
#include<bits/stdc++.h>
using namespace std;
#define N 1000000000
#define inf 1.0/0.0
typedef long long ll;
int n, t, a[N], id;
int min1 = inf;              //有问题
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) cin >> a[i];
	sort(a+1,a+1+n);
	for(int i=1; i<n; i++) {
		min1 = min(min1, abs(a[i] - a[i+1]));
	}
	cout << min1 ;
	return 0;
}
