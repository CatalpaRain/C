#include<stdio.h>
#include<stdlib.h>
#define vertexnum 9 //���嶥����

struct node{
	int vertex; //�ڽӶ�������
	struct node* next;//�¸��ڽӶ���
};

typedef struct node* graph;//����ͼ�ṹ
struct node head[vertexnum];
int visited[vertexnum];//����ѱ����ʽڵ�

//�������������
void Dfs(int vertex)
{
	graph pointer;
	visited[vertex] = 1;//�˽ڵ��Ѿ�����
	printf("[%d]==>", vertex);
	pointer = head[vertex].next;
	while (pointer != NULL)
	{
		if (visited[pointer->vertex] == 0)
			Dfs(pointer->vertex);//�ݹ����
		pointer = pointer->next;//��һ���ڽӵ�
	}
}

//�����ڽӶ��㵽�ڽӱ���
void Creat_graph(int vertex1, int vertex2)
{
	graph pointer, new1;
	new1 = (graph)malloc(sizeof(struct node));//�����ڴ�
	if (new1 != NULL)//���óɹ�
	{
		new1->vertex = vertex2;//�ڽ��ӵ�
		new1->next = NULL;
			pointer = &(head[vertex1]);//��Ϊ���㺯���׽��
			while (pointer->next != NULL)
				pointer = pointer->next;//��һ�����
			pointer->next = new1;//������β
	}	
}

//����ڽӱ�
void Print_graph(struct node* head)
{
	graph pointer;
	pointer = head->next;//ָ���׽��
	while (pointer != NULL)
	{
		printf_s("[%d]", pointer->vertex);
		pointer = pointer->next;//��һ�����
	}
	printf("\n");
}

int main()
{
	int i;
	int node[20][2] = { {1,2},{2,1},{1,3},{3,1},{2,4},{4,2},{2,5},{5,2},{3,6},{6,3},{3,7},{7,3},{4,8},{8,4},{5,8},{8,5},{6,8},{8,6},{7,8},{8,7} };
	//ͼ����ڽӵ���ڽӱ�
	for (i = 0; i < vertexnum; i++)//���нڵ�δ�����ʹ�
	{
		visited[i] = 0;
		for (i = 0; i < 20; i++)
		Creat_graph(node[i][0], node[i][1]);//�����ڽӱ�
		printf("\n���ڽӱ�����ʾͼ��\n");
		for (i = 1; i < vertexnum; i++)
		{
			printf("vertex[%d]:", i);
			Print_graph(&head[i]);
			
		}
		printf("���ܶ�·��Ϊ��\n");
		printf("[��ʼ]==>");
		Dfs(1);//��1��ʼ
		printf("[����]");
	}
}