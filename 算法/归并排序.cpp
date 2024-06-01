//https://icpc.ldu.edu.cn/contests/3713/problems/13
#include <bits/stdc++.h>              //时间超限
#define N 100000
using namespace std;
typedef long long ll;
int a[N+10],b[N+10];
int n;
void merge(int l,int mid,int r) {
	int a_l=l,b_l=mid+1,idx=l;
	while(a_l<=mid&&b_l<=r) {
		if(a[a_l]<=a[b_l])
			b[idx++]=a[a_l++];
		else
			b[idx++]=a[b_l++];
	}
	while(a_l<=mid)
		b[idx++]=a[a_l++];
	while(b_l<=r)
		b[idx++]=a[b_l++];
	for(int i=1; i<=r; i++)
		a[i]=b[i];
}
void MergeSort(int l,int r) {
	if(l==r)
		return;
	int mid=(l+r)/2;
	MergeSort(l,mid);
	MergeSort(mid+1,r);
	merge(l,mid,r);
}//递归分解再合并
void MergePass(int l,int r) {
	int n=r-l+1;
	for(int len=2; len<=n*2; len*=2) {
		for(int left=l; left<=r-len/2; left+=len) {
			int mid=left+len/2-1;
			int right=min(left+len-1,r);
			merge(left,mid,right);
		}
	}
}//递归 等长合并
int main() {
	cin>>n;
	for(int i=1; i<=n; i++)
		cin>>a[i];
	//MergeSort(1,n);
	MergePass(1,n);
	for(int i=1; i<=n; i++)
		cout<<a[i]<<" ";
	return 0;
}
