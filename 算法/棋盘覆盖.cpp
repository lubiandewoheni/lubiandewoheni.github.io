//https://icpc.ldu.edu.cn/contests/3713/problems/18
#include<bits/stdc++.h>
#define inf 1.0/0.0
using namespace std;
typedef long long ll;
int tx,ty,inn=1;
int chess[1100][1100]={0};
void chessboard(int k,int up ,int left,int tx,int ty){
	if(k==0)
		return;
	int len =1<<(k-1);
	if(tx<up+len&&ty<left+len){
		//chess[up+len-1][left+len-1]=index;
		chess[up+len-1][left+len]=inn;
		chess[up+len][left+len-1]=inn;
		chess[up+len][left+len]=inn;
		inn++;
		chessboard(k-1,up,left,tx,ty);
		//chessboard(k-1,up,left,up+len-1,left+len-1);
		chessboard(k-1,up,left+len,up+len-1,left+len);
		chessboard(k-1,up+len,left,up+len,left+len-1);
		chessboard(k-1,up+len,left+len,up+len,left+len);
	}
	else if(tx<up+len&&ty>=left+len){
		chess[up+len-1][left+len-1]=inn;
		//chess[up+len-1][left+len]=index;
		chess[up+len][left+len-1]=inn;
		chess[up+len][left+len]=inn;
		inn++;
		//chessboard(k-1,up,left,tx,ty);
		chessboard(k-1,up,left,up+len-1,left+len-1);
		chessboard(k-1,up,left+len,tx,ty);
		chessboard(k-1,up+len,left,up+len,left+len-1);
		chessboard(k-1,up+len,left+len,up+len,left+len);
	}
	else if(tx>=up+len&&ty<left+len){
		chess[up+len-1][left+len-1]=inn;
		chess[up+len-1][left+len]=inn;
		//chess[up+len][left+len-1]=index;
		chess[up+len][left+len]=inn;
		inn++;
		//chessboard(k-1,up,left,tx,ty);
		chessboard(k-1,up,left,up+len-1,left+len-1);
		chessboard(k-1,up,left+len,up+len-1,left+len);
		chessboard(k-1,up+len,left,tx,ty);
		chessboard(k-1,up+len,left+len,up+len,left+len);
	}
	else{
		chess[up+len-1][left+len-1]=inn;
		chess[up+len-1][left+len]=inn;
		chess[up+len][left+len-1]=inn;
		//chess[up+len][left+len]=index;
		inn++;
		//chessboard(k-1,up,left,tx,ty);
		chessboard(k-1,up,left,up+len-1,left+len-1);
		chessboard(k-1,up,left+len,up+len-1,left+len);
		chessboard(k-1,up+len,left,up+len,left+len-1);
		chessboard(k-1,up+len,left+len,tx,ty);
	}
}
int main() {
	int k;
	cin>>k;
	cin>>tx>>ty;
	chess[tx][ty]=-1;
	chessboard(k,1,1,tx,ty);
	for(int i=1;i<=(1<<k);i++){
		for(int j=1;j<=(1<<k);j++)
			printf("%7d",chess[i][j]);
		cout<<endl;
	}
	return 0;
}
