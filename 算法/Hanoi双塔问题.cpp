//https://icpc.ldu.edu.cn/contests/3115/problems/14
#include<cstring>
#include<iostream>
#include<cstdlib>
using namespace std;
string gaojing(string, string);
int main() {
	int n;
	cin >> n;
	string a = "2";
	string b = "2";
	for(int i = 2; i <= n; ++i)
		a = gaojing(gaojing(a, a), b);
	cout << a;
	return 0;
}
string gaojing(string a, string b) {
	int js[200];
	int a1[200] = {0};
	int a2[200] = {0};
	int x = 0;
	int y = 0;
	string liehuo;
	for(int i = a.size() - 1; i >= 0; --i) {
		x++;
		a1[x] = a[i] - 48;
	}
	for(int j = b.size() - 1; j >= 0; --j) {
		y++;
		a2[y] = b[j] - 48;
	}
	int max = x > y ? x : y;
	for(int i = 1; i <= max + 1; ++i) {
		js[i] = (a1[i] + a2[i]) % 10;
		a1[i + 1] += (a1[i] + a2[i]) / 10;
	}
	for(int i = max + 1; i >= 1; --i) {
		if(i == max + 1 && js[i] == 0)
			continue;
		liehuo += js[i] + 48;
	}
	return liehuo;
}
