//从文件创建一个带权图，分别求出最小生成树和最短路径
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// 定义图的最大顶点数
#define MAX_VERTICES 100

// 定义无穷大值
#define INFINITY INT_MAX

// 图的邻接矩阵表示
int graph[MAX_VERTICES][MAX_VERTICES];

// 顶点个数和边的个数
int numVertices, numEdges;

// 用于Prim算法的辅助数组
int parent[MAX_VERTICES];
int key[MAX_VERTICES];
int mstSet[MAX_VERTICES];

// 读取图的信息并初始化
void readGraphFromFile(FILE *file) {
	// 从文件中读取顶点个数和边的个数
	fscanf(file, "%d %d", &numVertices, &numEdges);

	// 初始化图的邻接矩阵
	for (int i = 0; i < MAX_VERTICES; i++) {
		for (int j = 0; j < MAX_VERTICES; j++) {
			graph[i][j] = 0;
		}
	}

	// 从文件中读取边的信息并更新图的邻接矩阵
	for (int i = 0; i < numEdges; i++) {
		int src, dest, weight;
		fscanf(file, "%d %d %d", &src, &dest, &weight);
		graph[src][dest] = weight;
		graph[dest][src] = weight;
	}
}

// 使用Prim算法求最小生成树
void primMST() {
	for (int i = 0; i < numVertices; i++) {
		key[i] = INFINITY;
		mstSet[i] = 0;
	}

	key[0] = 0;
	parent[0] = -1;

	for (int count = 0; count < numVertices - 1; count++) {
		int u = -1;
		int minKey = INFINITY;

		// 选择未加入最小生成树的顶点中具有最小键值的顶点
		for (int v = 0; v < numVertices; v++) {
			if (mstSet[v] == 0 && key[v] < minKey) {
				minKey = key[v];
				u = v;
			}
		}

		mstSet[u] = 1;

		// 更新与选定顶点相邻的顶点的键值
		for (int v = 0; v < numVertices; v++) {
			if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v]) {
				parent[v] = u;
				key[v] = graph[u][v];
			}
		}
	}
}

// 打印最小生成树
void printMST() {
	printf("最小生成树的边:\n");
	for (int i = 1; i < numVertices; i++) {
		printf("%d - %d 权重: %d\n", parent[i], i, graph[i][parent[i]]);
	}
}

// 使用Dijkstra算法求最短路径
void dijkstra(int src) {
	int dist[MAX_VERTICES];
	int visited[MAX_VERTICES];

	for (int i = 0; i < numVertices; i++) {
		dist[i] = INFINITY;
		visited[i] = 0;
	}

	dist[src] = 0;

	for (int count = 0; count < numVertices - 1; count++) {
		int u = -1;
		int minDist = INFINITY;

		// 选择未访问的顶点中距离最小的顶点
		for (int v = 0; v < numVertices; v++) {
			if (visited[v] == 0 && dist[v] < minDist) {
				minDist = dist[v];
				u = v;
			}
		}

		visited[u] = 1;

		// 更新与选定顶点相邻的顶点的距离
		for (int v = 0; v < numVertices; v++) {
			if (!visited[v] && graph[u][v] && dist[u] != INFINITY &&
			    dist[u] + graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v];
			}
		}
	}

	// 打印最短路径
	printf("\n从顶点 %d 到其他顶点的最短路径:\n", src);
	for (int i = 0; i < numVertices; i++) {
		printf("到顶点 %d 的最短路径距离: %d\n", i, dist[i]);
	}
}

int main() {
	FILE *file = fopen("graph.txt", "r");
	if (file == NULL) {
		printf("无法打开文件。\n");
		return 1;
	}

	readGraphFromFile(file);
	fclose(file);

	// 使用Prim算法求最小生成树
	primMST();
	printMST();

	// 使用Dijkstra算法求最短路径（假设起点为0）
	dijkstra(0);

	return 0;
}
