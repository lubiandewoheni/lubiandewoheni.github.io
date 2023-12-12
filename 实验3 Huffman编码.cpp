//从文件读取n个字符的出现概率，建立哈夫曼树，建立哈夫曼编码
#include <stdio.h>
#include <stdlib.h>

// 定义哈夫曼树节点
typedef struct Node {
	char data;
	int freq;
	struct Node* left;
	struct Node* right;
} Node;

// 函数声明
Node* buildHuffmanTree(Node** nodes, int n);
void generateHuffmanCodes(Node* root, char* code, int depth);

int main() {
	// 打开文件
	FILE* file = fopen("input.txt", "r");
	if (file == NULL) {
		perror("无法打开文件");
		exit(EXIT_FAILURE);
	}

	// 读取文件内容并计算字符频率
	int n = 256; // ASCII 字符数
	int freq[n];
	for (int i = 0; i < n; i++) {
		freq[i] = 0;
	}

	char ch;
	while ((ch = fgetc(file)) != EOF) {
		freq[ch]++;
	}

	// 关闭文件
	fclose(file);

	// 构建哈夫曼树节点数组
	Node* nodes[n];
	for (int i = 0; i < n; i++) {
		if (freq[i] > 0) {
			nodes[i] = (Node*)malloc(sizeof(Node));
			nodes[i]->data = (char)i;
			nodes[i]->freq = freq[i];
			nodes[i]->left = NULL;
			nodes[i]->right = NULL;
		} else {
			nodes[i] = NULL;
		}
	}

	// 构建哈夫曼树
	Node* root = buildHuffmanTree(nodes, n);

	// 生成哈夫曼编码
	char code[n];
	generateHuffmanCodes(root, code, 0);

	// 打印字符及其哈夫曼编码
	for (int i = 0; i < n; i++) {
		if (freq[i] > 0) {
			printf("字符 '%c' 的哈夫曼编码: %s\n", (char)i, code[i]);
		}
	}

	// 释放内存
	// TODO: 实现释放哈夫曼树节点内存的代码

	return 0;
}

// 构建哈夫曼树
Node* buildHuffmanTree(Node** nodes, int n) {
	// TODO: 实现构建哈夫曼树的代码
}

// 生成哈夫曼编码
void generateHuffmanCodes(Node* root, char* code, int depth) {
	// TODO: 实现生成哈夫曼编码的递归代码
}
