//从文件读入随机生成的n个数（n>10000)。用Bubble,Select等O(n*n)的复杂度算法进行排序
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 从文件中读取随机数
void readRandomNumbersFromFile(const char *filename, int *arr, int n) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		perror("无法打开文件");
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < n; ++i) {
		if (fscanf(file, "%d", &arr[i]) != 1) {
			fprintf(stderr, "从文件读取数出错");
			exit(EXIT_FAILURE);
		}
	}

	fclose(file);
}

// 冒泡排序
void bubbleSort(int *arr, int n) {
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < n - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				// 交换arr[j]和arr[j+1]
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

// 选择排序
void selectionSort(int *arr, int n) {
	for (int i = 0; i < n - 1; ++i) {
		int minIndex = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[minIndex]) {
				minIndex = j;
			}
		}
		// 交换arr[i]和arr[minIndex]
		int temp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = temp;
	}
}

int main() {
	const char *filename = "random_numbers.txt"; // 文件名
	int n = 10000; // 假设 n > 10000
	int *numbers = (int *)malloc(n * sizeof(int));

	// 从文件中读取随机数
	readRandomNumbersFromFile(filename, numbers, n);

	// 冒泡排序
	// bubbleSort(numbers, n);

	// 选择排序
	selectionSort(numbers, n);

	// 输出排序后的结果
	for (int i = 0; i < n; ++i) {
		printf("%d ", numbers[i]);
	}

	// 释放动态分配的内存
	free(numbers);

	return 0;
}

