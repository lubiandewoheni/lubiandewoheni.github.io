//https://icpc.ldu.edu.cn/contest/2852/problem/6
/*
题目描述
UpMing在玩一个小游戏：跳格子。
UpMing前方有一列格子共 N+1个，前 N个格子每个格子上都有一个数字1或者2，第 N+1个格子为终点。其中：
1:代表UpMing可以向后跳任意个格子。
2:代表UpMing可以向前跳最多D个格子（即可以跳1,2,3,...,D个格子）。
游戏开始时UpMing将走上第1个格子上，保证第一个格子上的数字一定为2。
现在，UpMing想找到一个最小的D能够使得他从第1个格子跳到第N+1个格子，但UpMing太懒了，他把这个问题交给了爱学习的Fox，Fox当场写了个代码，直接告诉了UpMing答案。
输入描述
第一行 一个整数N（1≤N≤1e5）。
第二行 N个整数,代表前 N个格子上的数字。
输出描述
一个整数，即最小的D。
 */
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define inf 1.0/0.0
#define N 100000
int n, k;
int a[N],cnt = 1, max1 = -inf;
int main() {
	cin >> n;
	for(int i=1; i<=n; i++) {
		cin >> k;
		if(k == 2) {
			max1 = max(cnt, max1);
			cnt = 1;
		} else {
			cnt++;
		}
	}
	max1 = max(cnt, max1);
	cout << max1 ;
	return 0;
}
