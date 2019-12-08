#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define V 510 //��󶥵���
int G[V][V];    //ͼ
int degree[V];  //��¼����������
void topological_sort(int n)    //����������
{
	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (degree[j] == 0) {     //�ҵ����Ϊ0�Ķ���
				printf("%d", j);    //���
				degree[j]--;        //������ȼ�Ϊ-1
				k = j;              //��k��¼�˶���
				break;
			}
		}
		for (j = 1; j <= n; j++) {
			if (G[k][j] == 1) {   //�ҵ����˶����ܹ��Ķ���
				G[k][j] = 0;    //���
				degree[j]--;    //���ҵ��Ķ������ȼ�һ
			}
		}
		if (i != n)
			printf(" ");
		else
			printf("\n");
	}
}
int main(void)
{
	int n;  //����ĸ���
	int m;  //ÿ�����ݺ�ӵ���������
	while (scanf_s("%d%d", &n, &m) != EOF) {
		memset(G, 0, sizeof(G));            //ͼ�ĳ�ʼ��
		memset(degree, 0, sizeof(degree));  //������ȵĳ�ʼ��
		while (m--) {
			int u, v;
			scanf_s("%d%d", &u, &v);  //u�����v
			if (G[u][v] == 0) {
				/*ȥ��
				  ����Ҫ��¼����v�������˴�ܹ���
				  �����Ǳ�����˶��ٴ�
				*/
				G[u][v] = 1;    //u��ܹ�v
				degree[v]++;    //����v����ȼ�һ
			}
		}
		topological_sort(n);    //��������������
	}
	return 0;
}
