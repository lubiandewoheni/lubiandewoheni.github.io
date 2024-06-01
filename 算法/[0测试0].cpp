// by С෿� C++17
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
struct node {
	char name[20];
	int age;
	struct node *next;
};
void menu() {
	cout<<"\t\t\t�༶��Ϣ����ϵͳ"<<endl;
	cout<<"\t\t 1.�½���ͷ�壩"<<endl;
	cout<<"\t\t 2.�½���β�壩"<<endl;
	cout<<"\t\t 3.����"<<endl;
	cout<<"\t\t 4.ɾ��"<<endl;
	cout<<"\t\t 5.���루�м䣩"<<endl;
	cout<<"\t\t 6.����"<<endl;
	cout<<"\t\t 7.�˳�"<<endl;
}
void bianli(struct node *head) {
	struct node *temp;
	temp=head;
	cout<<"������Ϣ���£�"<<endl;
	while(temp!=NULL) {
		cout<<temp->name<<" "<<temp->age<<endl;
		temp=temp->next;
	}
}
struct node *create1() {
	// ͷ��
	int n,i;
	struct node *temp,*head;
	cout<<"��������Ա������";
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
	// β��
	int n,i;
	struct node *temp,*head,*tail;
	cout<<"��������Ա������";
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
	cout<<"��������Ҫ���ҵ�������";
	cin>>name;
	temp=head;
	bool flag=false;
	while(temp!=NULL) {
		if(strcmp(temp->name,name)==0) {
			flag=true;
			cout<<"���ҵ��ˣ���Ϣ���£�"<<endl;
			cout<<temp->name<<" "<<temp->age<<endl;
			break;
		}
		temp=temp->next;
	}
	if(!flag) {
		cout<<"sorry����û�ҵ�"<<endl;
	}
	return;
}
struct node *del(struct node *head) {
	char name[20];
	struct node *temp,*t1;
	cout<<"������Ҫɾ����ѧ����Ϣ��";
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
