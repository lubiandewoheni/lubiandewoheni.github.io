//继承和派生
/*
类 {
  
public：对外，外部能看到
  
private：//内部元素，自己用  支持外部
  
  }
  
继承了哪些成员：基础类的接口成员
继承权限：基础类的接口成员在拓展类的权限怎么定义
public:
proteced:
private:

  
  
基础类的接口成员在拓展类中的访问权限=
	  min（接口成员在基础类的原有权限，继承权限）
  
  
  
  
拓展类：继承 基础类 {  //拓展类包括了基础类的接口成员
  
  
  
  }
  
  
 */

#include<iostream>
using namespace std;

class A{
public:
	int a;
private:
	int b;
	
};

class B :public A{
	
};

int main(){
	B b;
	cout<<"b.a="<<b.a<<endl;
}
