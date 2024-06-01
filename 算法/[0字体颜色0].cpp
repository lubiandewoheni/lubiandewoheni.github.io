// 北23# 312专用C++颜色更改 by 王玉林
// 使你的程序能够让人眼前一亮
/*使用时复制下面这两行代码放在开头*/
#include <windows.h> // 支持改变颜色的头文件
void chc(int n) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),n);
	return;
}
/*复制到我结束*/
#include <bits/stdc++.h>
using namespace std;
int main() {
	/* 使用方法：
	  更改颜色调用chc()函数 chc = change color 改变颜色
	  chc(颜色数字);
	  颜色数字请运行我来查表
	 */
	// 使用示例
	chc(207); // 10进制 改成红底白字
	cout<<"错误：被除数不能为0！"<<endl;
	chc(0x0a); // 16进制 改成黑底绿字
	cout<<"插入成功！"<<endl;
	chc(14); // 黑底黄字
	cout<<"--------------------------------请录入商品信息----------------------------------"<<endl;
	chc(0x0b); // 黑底蓝字
	cout<<"请依次输入“商品名”、“商品编号”、“生产商名”、“型号”、“生产日期”、“价格”"<<endl;
	// 显示十进制颜色数字对照表
	int i,j;
	chc(7); // 改回默认
	cout<<"\n十进制颜色数字对照表"<<endl;
	for(i=0; i<=15; i++) {
		for(j=0; j<=15; j++) {
			chc(i*16+j); // 改变颜色
			printf("%-3d",i*16+j);
			chc(7); // 改回默认
			printf(" ");
		}
		cout<<endl;
	}
	// 显示十六进制颜色数字对照
	chc(0x07); // 改回默认
	cout<<"\n十六进制颜色数字对照表"<<endl;
	for(i=0; i<=0xf; i++) {
		for(j=0; j<=0xf; j++) {
			chc(i*0x10+j); // 改变颜色
			printf("0x%02x",i*0x10+j);
			chc(0x07); // 改回默认
			printf(" ");
		}
		cout<<endl;
	}
	system("pause");
	return 0;
}
