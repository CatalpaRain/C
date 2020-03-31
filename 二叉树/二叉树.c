#include <stdio.h>
#include <stdlib.h>
#define MAX 20

//创建节点类型
typedef struct node {
	char data;
	struct node* LChild;
	struct node* RChild;
}BiNode, * BiTree;

void createBiTree(BiTree* root);
void preOrder(BiNode* root);
void inOrder(BiNode* root);
void postOrder(BiNode* root);
int depth(BiTree root);


 //主函数
int main() {

	BiTree* biTree = (BiTree*)malloc(sizeof(BiNode));       //生成树的根节点

	//利用根节点生成一棵二叉树
	printf("以先序方式输入二叉树的有效节点，空以#代替：");
	createBiTree(biTree);

	//先序遍历
	printf("先序遍历：");
	preOrder(*biTree);
	printf("\n");

	//中序遍历
	printf("先序遍历：");
	inOrder(*biTree);
	printf("\n");

	//后序遍历
	printf("后序遍历：");
	postOrder(*biTree);
	printf("\n");

	//深度
	printf("深度：");
	depth(*biTree);
	printf("\n");


	return 0;
}

//创建二叉树
void createBiTree(BiTree* root) {
	char data = getchar();
	if (data == '#') {
		*root = NULL;
	}
	else {
		*root = (BiTree)malloc(sizeof(BiNode));
		(*root)->data = data;
		createBiTree(&((*root)->LChild));
		createBiTree(&((*root)->RChild));
	}
}

//先序遍历
void preOrder(BiTree root) {
	if (root) {
		printf("%c  ", root->data);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}

//中序遍历
void inOrder(BiTree root) {
	if (root) {
		inOrder(root->LChild);
		printf("%c  ", root->data);
		inOrder(root->RChild);
	}
}

//后序遍历
void postOrder(BiTree root) {
	if (root) {
		postOrder(root->LChild);
		postOrder(root->RChild);
		printf("%c  ", root->data);
	}
}
//深度

int depth(BiTree t)
{
	if (t == NULL)
		return 0;
	else
	{
		int left_h = depth(t->LChild);
		int right_h = depth(t->RChild);
		return (left_h > right_h ? left_h : right_h) + 1;
	}
}