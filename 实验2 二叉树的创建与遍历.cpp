//从文件读取数据建立二叉树，进行该树的先根、后根和中根递归与非递归遍历
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct TreeNode {
	int val; // 节点的值
	struct TreeNode* left; // 左子树
	struct TreeNode* right; // 右子树
};

void createTree(struct TreeNode** root, FILE* fin) {
	int val;
	if (fscanf(fin, "%d", &val) == 1) {
		if (val == -1) {
			*root = NULL; // 如果读到-1，说明这个节点为空
		} else {
			*root = (struct TreeNode*)malloc(sizeof(struct TreeNode)); // 为节点分配空间
			(*root)->val = val; // 节点的值为val
			createTree(&((*root)->left), fin); // 递归创建左子树
			createTree(&((*root)->right), fin); // 递归创建右子树
		}
	}
}

void preOrderRecursive(struct TreeNode* root) {
	if (root) {
		printf("%d ", root->val); // 先访问根节点
		preOrderRecursive(root->left); // 再访问左子树
		preOrderRecursive(root->right); // 最后访问右子树
	}
}

void inOrderRecursive(struct TreeNode* root) {
	if (root) {
		inOrderRecursive(root->left); // 先访问左子树
		printf("%d ", root->val); // 再访问根节点
		inOrderRecursive(root->right); // 最后访问右子树
	}
}

void postOrderRecursive(struct TreeNode* root) {
	if (root) {
		postOrderRecursive(root->left); // 先访问左子树
		postOrderRecursive(root->right); // 再访问右子树
		printf("%d ", root->val); // 最后访问根节点
	}
}

void preOrderNonRecursive(struct TreeNode* root) {
	struct TreeNode* stack[100];
	int top = -1;
	while (root || top != -1) {
		while (root) {
			printf("%d ", root->val); // 访问根节点
			stack[++top] = root;
			root = root->left; // 访问左子树
		}
		if (top != -1) {
			root = stack[top--];
			root = root->right; // 访问右子树
		}
	}
}

void inOrderNonRecursive(struct TreeNode* root) {
	struct TreeNode* stack[100];
	int top = -1;
	while (root || top != -1) {
		while (root) {
			stack[++top] = root;
			root = root->left; // 访问左子树
		}
		if (top != -1) {
			root = stack[top--];
			printf("%d ", root->val); // 访问根节点
			root = root->right; // 访问右子树
		}
	}
}

void postOrderNonRecursive(struct TreeNode* root) {
	struct TreeNode* stack[100];
	int top = -1;
	struct TreeNode* lastVisited = NULL;
	while (root || top != -1) {
		while (root) {
			stack[++top] = root;
			root = root->left; // 访问左子树
		}
		root = stack[top];
		if (!root->right || root->right == lastVisited) {
			printf("%d ", root->val); // 访问根节点
			top--;
			lastVisited = root;
			root = NULL;
		} else {
			root = root->right; // 访问右子树
		}
	}
}

int main() {
	FILE* fin = fopen("input.txt", "r");
	struct TreeNode* root = NULL;
	createTree(&root, fin); // 从文件中读取数据创建二叉树
	printf("先根递归遍历: ");
	preOrderRecursive(root);
	printf("\n");
	printf("中根递归遍历: ");
	inOrderRecursive(root);
	printf("\n");
	printf("后根递归遍历: ");
	postOrderRecursive(root);
	printf("\n");
	printf("先根非递归遍历: ");
	preOrderNonRecursive(root);
	printf("\n");
	printf("中根非递归遍历: ");
	inOrderNonRecursive(root);
	printf("\n");
	printf("后根非递归遍历: ");
	postOrderNonRecursive(root);
	printf("\n");
	return 0;
}
