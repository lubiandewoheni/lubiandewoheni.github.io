//从文件创建一个图，分别用邻接矩阵和邻接表存储。分别用深度和广度优先策略遍历。
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTEX 100

// 图的结点定义
typedef struct Node {
	int vertex;
	struct Node *next;
} Node;

// 邻接表定义
typedef struct {
	Node *head;
} AdjList[MAX_VERTEX];

// 图的定义
typedef struct {
	int numVertices;
	int numEdges;
	int isDirected;
	int matrix[MAX_VERTEX][MAX_VERTEX];
	AdjList adjList;
} Graph;

// 初始化图
void initGraph(Graph *graph, int numVertices, int isDirected) {
	int i, j;
	graph->numVertices = numVertices;
	graph->numEdges = 0;
	graph->isDirected = isDirected;

	// 初始化邻接矩阵
	for (i = 0; i < numVertices; ++i) {
		for (j = 0; j < numVertices; ++j) {
			graph->matrix[i][j] = 0;
		}
	}

	// 初始化邻接表
	for (i = 0; i < numVertices; ++i) {
		graph->adjList[i].head = NULL;
	}
}

// 添加边到邻接矩阵和邻接表
void addEdge(Graph *graph, int src, int dest) {
	// 添加到邻接矩阵
	graph->matrix[src][dest] = 1;

	// 添加到邻接表
	Node *newNode = (Node *)malloc(sizeof(Node));
	newNode->vertex = dest;
	newNode->next = graph->adjList[src].head;
	graph->adjList[src].head = newNode;
}

// 从文件读取图的信息并创建图
void createGraphFromFile(Graph *graph, const char *filename) {
	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		printf("无法打开文件\n");
		exit(EXIT_FAILURE);
	}

	int numVertices, numEdges, isDirected;
	fscanf(file, "%d %d %d", &numVertices, &numEdges, &isDirected);

	initGraph(graph, numVertices, isDirected);

	int i, src, dest;
	for (i = 0; i < numEdges; ++i) {
		fscanf(file, "%d %d", &src, &dest);
		addEdge(graph, src, dest);
		if (!isDirected) {
			addEdge(graph, dest, src); // 无向图需添加反向边
		}
	}

	fclose(file);
}

// 邻接矩阵的深度优先遍历
void DFSMatrix(Graph *graph, int vertex, int *visited) {
	printf("%d ", vertex);
	visited[vertex] = 1;

	int i;
	for (i = 0; i < graph->numVertices; ++i) {
		if (graph->matrix[vertex][i] && !visited[i]) {
			DFSMatrix(graph, i, visited);
		}
	}
}

// 邻接表的深度优先遍历
void DFSList(Graph *graph, int vertex, int *visited) {
	printf("%d ", vertex);
	visited[vertex] = 1;

	Node *temp = graph->adjList[vertex].head;
	while (temp != NULL) {
		if (!visited[temp->vertex]) {
			DFSList(graph, temp->vertex, visited);
		}
		temp = temp->next;
	}
}

// 邻接矩阵的广度优先遍历
void BFSMatrix(Graph *graph, int start, int *visited) {
	int queue[MAX_VERTEX];
	int front = 0, rear = 0;

	printf("%d ", start);
	visited[start] = 1;
	queue[rear++] = start;

	while (front < rear) {
		int current = queue[front++];
		int i;
		for (i = 0; i < graph->numVertices; ++i) {
			if (graph->matrix[current][i] && !visited[i]) {
				printf("%d ", i);
				visited[i] = 1;
				queue[rear++] = i;
			}
		}
	}
}

// 邻接表的广度优先遍历
void BFSList(Graph *graph, int start, int *visited) {
	int queue[MAX_VERTEX];
	int front = 0, rear = 0;

	printf("%d ", start);
	visited[start] = 1;
	queue[rear++] = start;

	while (front < rear) {
		int current = queue[front++];
		Node *temp = graph->adjList[current].head;
		while (temp != NULL) {
			if (!visited[temp->vertex]) {
				printf("%d ", temp->vertex);
				visited[temp->vertex] = 1;
				queue[rear++] = temp->vertex;
			}
			temp = temp->next;
		}
	}
}

// 主函数
int main() {
	Graph graph;
	createGraphFromFile(&graph, "graph.txt");

	// 中文提示：深度优先遍历（邻接矩阵）
	int visited[MAX_VERTEX] = {0};
	printf("深度优先遍历（邻接矩阵）: ");
	DFSMatrix(&graph, 0, visited);
	printf("\n");

	// 中文提示：深度优先遍历（邻接表）
	for (int i = 0; i < MAX_VERTEX; ++i) {
		visited[i] = 0;
	}
	printf("深度优先遍历（邻接表）: ");
	DFSList(&graph, 0, visited);
	printf("\n");

	// 中文提示：广度优先遍历（邻接矩阵）
	for (int i = 0; i < MAX_VERTEX; ++i) {
		visited[i] = 0;
	}
	printf("广度优先遍历（邻接矩阵）: ");
	BFSMatrix(&graph, 0, visited);
	printf("\n");

	// 中文提示：广度优先遍历（邻接表）
	for (int i = 0; i < MAX_VERTEX; ++i) {
		visited[i] = 0;
	}
	printf("广度优先遍历（邻接表）: ");
	BFSList(&graph, 0, visited);
	printf("\n");

	return 0;
}

