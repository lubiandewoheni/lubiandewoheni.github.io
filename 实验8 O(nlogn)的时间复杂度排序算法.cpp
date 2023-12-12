//从文件读入n个数，用Quick，Merge Heap等O(nlogn)的算法进行排序
#include <stdio.h>
#include <stdlib.h>

// 快速排序算法
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int pivot = arr[high];
		int i = low - 1;

		for (int j = low; j < high; j++) {
			if (arr[j] <= pivot) {
				i++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		int temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;

		int partitionIndex = i + 1;

		quickSort(arr, low, partitionIndex - 1);
		quickSort(arr, partitionIndex + 1, high);
	}
}

int main() {
	FILE *file;
	int n;

	// 打开文件
	file = fopen("input.txt", "r");
	if (file == NULL) {
		printf("无法打开文件\n");
		return 1;
	}

	// 读取数字个数
	fscanf(file, "%d", &n);

	// 读取数字数组
	int *arr = (int *)malloc(n * sizeof(int));
	for (int i = 0; i < n; i++) {
		fscanf(file, "%d", &arr[i]);
	}

	// 关闭文件
	fclose(file);

	// 使用快速排序算法排序
	quickSort(arr, 0, n - 1);

	// 输出排序后的结果
	printf("排序后的数组：\n");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}

	// 释放内存
	free(arr);

	return 0;
}

