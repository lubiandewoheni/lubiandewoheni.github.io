// 建立一个有n个结点的单链表，进行查询、修改、删除和插入操作
#include <stdio.h>
#include <stdlib.h>

//定义结构体
typedef struct node {
    int data;
    struct node *next;
} Node, *LinkedList;

//初始化链表
LinkedList initList() {
    LinkedList L = (LinkedList)malloc(sizeof(Node));
    L->next = NULL;
    return L;
}

//创建链表
LinkedList createList(int n) {
    LinkedList L = initList();
    Node *p = L;
    for (int i = 0; i < n; i++) {
        Node *newNode = (Node *)malloc(sizeof(Node));
        printf("请输入第%d个结点的值：", i + 1);
        scanf("%d", &newNode->data);
        newNode->next = NULL;
        p->next = newNode;
        p = p->next;
    }
    return L;
}

//遍历链表
void traverseList(LinkedList L) {
    Node *p = L->next;
    while (p) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

//查询数据
void searchList(LinkedList L) {
    int x;
    printf("请输入要查询的数据：");
    scanf("%d", &x);
    Node *p = L->next;
    while (p) {
        if (p->data == x) {
            printf("查询成功，该数据在链表中！\n");
            return;
        }
        p = p->next;
    }
    printf("查询失败，该数据不在链表中！\n");
}

//修改单个数据
void modifyList(LinkedList L) {
    int i, x;
    printf("请输入要修改的结点位置：");
    scanf("%d", &i);
    printf("请输入新的结点值：");
    scanf("%d", &x);
    Node *p = L->next;
    for (int j = 1; j < i; j++) {
        p = p->next;
    }
    p->data = x;
    printf("修改成功！\n");
}

//删除单个数据
void deleteList(LinkedList L) {
    int x;
    printf("请输入要删除的结点值：");
    scanf("%d", &x);
    Node *p = L->next, *pre = L;
    while (p) {
        if (p->data == x) {
            pre->next = p->next;
            free(p);
            printf("删除成功！\n");
            return;
        }
        pre = p;
        p = p->next;
    }
    printf("删除失败，该结点不存在！\n");
}

//在任意位置插入操作
void insertList(LinkedList L) {
    int i, x;
    printf("请输入要插入的位置：");
    scanf("%d", &i);
    printf("请输入要插入的结点值：");
    scanf("%d", &x);
    Node *p = L->next, *pre = L;
    for (int j = 1; j < i; j++) {
        pre = p;
        p = p->next;
    }
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = p;
    pre->next = newNode;
    printf("插入成功！\n");
}

//主函数
int main() {
    int n;
    printf("请输入链表长度：");
    scanf("%d", &n);
    LinkedList L = createList(n);
    int choice;
    while (1) {
        printf("请选择操作：\n");
        printf("1. 遍历链表\n");
        printf("2. 查询数据\n");
        printf("3. 修改单个数据\n");
        printf("4. 删除单个数据\n");
        printf("5. 在任意位置插入操作\n");
        printf("0. 退出程序\n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                traverseList(L);
                break;
            case 2:
                searchList(L);
                break;
            case 3:
                modifyList(L);
                break;
            case 4:
                deleteList(L);
                break;
            case 5:
                insertList(L);
                break;
            case 0:
                printf("程序已退出！\n");
                return 0;
            default:
                printf("输入有误，请重新输入！\n");
                break;
        }
    }
    return 0;
}