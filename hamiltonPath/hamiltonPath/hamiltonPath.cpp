#include<stdio.h>
#include<stdlib.h>
#define vertexnum 9 //定义顶点数

struct node{
	int vertex; //邻接顶点数据
	struct node* next;//下个邻接顶点
};

typedef struct node* graph;//定义图结构
struct node head[vertexnum];
int visited[vertexnum];//标记已被访问节点

//深度优先搜索法
void Dfs(int vertex)
{
	graph pointer;
	visited[vertex] = 1;//此节点已经访问
	printf("[%d]==>", vertex);
	pointer = head[vertex].next;
	while (pointer != NULL)
	{
		if (visited[pointer->vertex] == 0)
			Dfs(pointer->vertex);//递归调用
		pointer = pointer->next;//下一个邻接点
	}
}

//建立邻接顶点到邻接表内
void Creat_graph(int vertex1, int vertex2)
{
	graph pointer, new1;
	new1 = (graph)malloc(sizeof(struct node));//配置内存
	if (new1 != NULL)//配置成功
	{
		new1->vertex = vertex2;//邻近接点
		new1->next = NULL;
			pointer = &(head[vertex1]);//设为顶点函数首结点
			while (pointer->next != NULL)
				pointer = pointer->next;//下一个结点
			pointer->next = new1;//串于链尾
	}	
}

//输出邻接表
void Print_graph(struct node* head)
{
	graph pointer;
	pointer = head->next;//指向首结点
	while (pointer != NULL)
	{
		printf_s("[%d]", pointer->vertex);
		pointer = pointer->next;//下一个结点
	}
	printf("\n");
}

int main()
{
	int i;
	int node[20][2] = { {1,2},{2,1},{1,3},{3,1},{2,4},{4,2},{2,5},{5,2},{3,6},{6,3},{3,7},{7,3},{4,8},{8,4},{5,8},{8,5},{6,8},{8,6},{7,8},{8,7} };
	//图结点邻接点的邻接表
	for (i = 0; i < vertexnum; i++)//所有节点未被访问过
	{
		visited[i] = 0;
		for (i = 0; i < 20; i++)
		Creat_graph(node[i][0], node[i][1]);//建立邻接表
		printf("\n以邻接表来表示图：\n");
		for (i = 1; i < vertexnum; i++)
		{
			printf("vertex[%d]:", i);
			Print_graph(&head[i]);
			
		}
		printf("哈密顿路径为：\n");
		printf("[开始]==>");
		Dfs(1);//从1开始
		printf("[结束]");
	}
}