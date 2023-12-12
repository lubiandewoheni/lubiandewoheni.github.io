//从文件读入数据建立一棵二叉排序树，给定关键字进行查找
#include <stdio.h>
#include <stdlib.h>

// 定义二叉树节点结构
struct TreeNode {
	int data;
	struct TreeNode* left;
	struct TreeNode* right;
};

// 函数声明
struct TreeNode* insertNode(struct TreeNode* root, int key);
struct TreeNode* searchNode(struct TreeNode* root, int key);

// 从文件读取数据并构建二叉搜索树
struct TreeNode* buildBSTFromFile(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (!file) {
		printf("无法打开文件 %s\n", filename);
		return NULL;
	}

	struct TreeNode* root = NULL;
	int value;

	// 从文件中读取数据并插入到二叉搜索树中
	while (fscanf(file, "%d", &value) == 1) {
		root = insertNode(root, value);
	}

	fclose(file);
	return root;
}

// 插入节点
struct TreeNode* insertNode(struct TreeNode* root, int key) {
	if (root == NULL) {
		// 创建新节点
		struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
		newNode->data = key;
		newNode->left = newNode->right = NULL;
		return newNode;
	}

	// 递归地插入节点
	if (key < root->data) {
		root->left = insertNode(root->left, key);
	} else if (key > root->data) {
		root->right = insertNode(root->right, key);
	}

	return root;
}

// 查找节点
struct TreeNode* searchNode(struct TreeNode* root, int key) {
	if (root == NULL || root->data == key) {
		return root;
	}

	// 在左子树或右子树中递归查找
	if (key < root->data) {
		return searchNode(root->left, key);
	} else {
		return searchNode(root->right, key);
	}
}

// 主函数
int main() {
	const char* filename = "data.txt";
	struct TreeNode* root = buildBSTFromFile(filename);

	if (root == NULL) {
		printf("构建二叉搜索树失败\n");
		return 1;
	}

	// 从文件读取关键字进行查找
	int searchKey;
	printf("请输入要查找的关键字: ");
	scanf("%d", &searchKey);

	struct TreeNode* result = searchNode(root, searchKey);

	if (result) {
		printf("找到关键字 %d\n", searchKey);
	} else {
		printf("未找到关键字 %d\n", searchKey);
	}

	return 0;
}

