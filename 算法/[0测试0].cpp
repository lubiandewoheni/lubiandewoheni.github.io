// by 小喾苦 C++17
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node {
	char name[20];
	int age;
	struct node *next;
};
void menu() {
	cout<<"\t\t\t班级信息管理系统"<<endl;
	cout<<"\t\t 1.新建（头插）"<<endl;
	cout<<"\t\t 2.新建（尾插）"<<endl;
	cout<<"\t\t 3.查找"<<endl;
	cout<<"\t\t 4.删除"<<endl;
	cout<<"\t\t 5.插入（中间）"<<endl;
	cout<<"\t\t 6.遍历"<<endl;
	cout<<"\t\t 7.退出"<<endl;
}
void bianli(struct node *head) {
	struct node *temp;
	temp=head;
	cout<<"遍历信息如下："<<endl;
	while(temp!=NULL) {
		cout<<temp->name<<" "<<temp->age<<endl;
		temp=temp->next;
	}
}
struct node *create1() {
	// 头插
	int n,i;
	struct node *temp,*head;
	cout<<"请输入人员数量：";
	cin>>n;
	head=(struct node *)malloc(sizeof(struct node));
	cin>>head->name>>head->age;
	head->next=NULL;
	for(i=0; i<n-1; i++) {
		temp=(struct node *)malloc(sizeof(struct node));
		cin>>temp->name>>temp->age;
		temp->next=head;
		head=temp;
	}
	return head;
}
struct node *create2() {
	// 尾插
	int n,i;
	struct node *temp,*head,*tail;
	cout<<"请输入人员数量：";
	cin>>n;
	head=(struct node *)malloc(sizeof(struct node));
	cin>>head->name>>head->age;
	head->next=NULL;
	tail=head;
	for(i=0; i<n-1; i++) {
		temp=(struct node *)malloc(sizeof(struct node));
		cin>>temp->name>>temp->age;
		temp->next=NULL;
		tail->next=temp;
		tail=temp;
	}
	return head;
}
void search(struct node *head) {
	char name[20];
	struct node *temp;
	cout<<"请输入你要查找的姓名：";
	cin>>name;
	temp=head;
	bool flag=false;
	while(temp!=NULL) {
		if(strcmp(temp->name,name)==0) {
			flag=true;
			cout<<"人找到了，信息如下："<<endl;
			cout<<temp->name<<" "<<temp->age<<endl;
			break;
		}
		temp=temp->next;
	}
	if(!flag) {
		cout<<"sorry，人没找到"<<endl;
	}
	return;
}
struct node *del(struct node *head) {
	char name[20];
	struct node *temp,*t1;
	cout<<"请输入要删除的学生信息：";
	cin>>name;
	if(strcmp(head->name,name)==0) {
		temp=head;
		head=head->next;
		free(temp);
		return head;
	} else {
		temp=head;
		while(temp->next!=NULL) {
			if(strcmp(temp->next->name,name)==0) {
				t1=temp->next;
				temp->next=t1->next;
				free(t1);
				break;
			}
			temp=temp->next;
		}
	}
	return head;
}
int main() {
	int oper;
	struct node *head,*tail;
	while(1) {
		menu();
		cin>>oper;
		switch(oper) {
			case 1:
				head=create1();
				break;
			case 2:
				head=create2();
				break;
			case 3:
				search(head);
				break;
			case 4:
				head=del(head);
				break;
			case 5:
			case 6:
				bianli(head);
				break;
			case 7:
				return 0;
		}
	}
	return 0;
}
