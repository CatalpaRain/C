#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define V 510 //最大顶点数
int G[V][V];    //图
int degree[V];  //记录各顶点的入度
void topological_sort(int n)    //拓扑排序函数
{
	int i, j, k;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			if (degree[j] == 0) {     //找到入度为0的顶点
				printf("%d", j);    //输出
				degree[j]--;        //将其入度减为-1
				k = j;              //用k记录此顶点
				break;
			}
		}
		for (j = 1; j <= n; j++) {
			if (G[k][j] == 1) {   //找到被此顶点打败过的顶点
				G[k][j] = 0;    //标记
				degree[j]--;    //将找到的顶点的入度减一
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
	int n;  //队伍的个数
	int m;  //每组数据后接的输入行数
	while (scanf_s("%d%d", &n, &m) != EOF) {
		memset(G, 0, sizeof(G));            //图的初始化
		memset(degree, 0, sizeof(degree));  //顶点入度的初始化
		while (m--) {
			int u, v;
			scanf_s("%d%d", &u, &v);  //u打败了v
			if (G[u][v] == 0) {
				/*去重
				  这里要记录的是v被多少人打败过，
				  而不是被打败了多少次
				*/
				G[u][v] = 1;    //u打败过v
				degree[v]++;    //顶点v的入度加一
			}
		}
		topological_sort(n);    //调用拓扑排序函数
	}
	return 0;
}
