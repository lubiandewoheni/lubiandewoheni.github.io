//https://icpc.ldu.edu.cn/contests/3142/problems/2
//https://icpc.ldu.edu.cn/contests/2407/problems/2
//https://icpc.ldu.edu.cn/contests/3717/problems/0
#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std ;
int a[15],n,t=0;    //a[i]表示第i行第a[i]列
//判断是否和前面的皇后冲突
bool place(int x) {
	bool ok=true  ;
	for(int i=1; i<x; i++)
		if(a[x]==a[i] || x-i==fabs(a[x]-a[i])) {
			ok=false;
			break;
		}
	return ok ;
}
void search(int x) {
	if(x==n+1) {       //递归边界，只要走到这里所有皇后必然没有冲突
		t=1;
		for(int i=1; i<=n; i++) {
			if(i<=n)
				cout<< a[i] ;
			if(i<n)
				cout<<" ";
		}
		cout <<"\n" ;
	} else for(int i=1; i<=n; i++) {
			a[x]=i;
			if(place(x))   search(x+1) ;    //如果不冲突，则继续递归
		}
}
int main() {
	cin >> n ;
	search(1) ;
	if(t==0) cout << "no solute!" ;
	return 0;
}
