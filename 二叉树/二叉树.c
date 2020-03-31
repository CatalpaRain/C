#include <stdio.h>
#include <stdlib.h>
#define MAX 20

//�����ڵ�����
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


 //������
int main() {

	BiTree* biTree = (BiTree*)malloc(sizeof(BiNode));       //�������ĸ��ڵ�

	//���ø��ڵ�����һ�ö�����
	printf("������ʽ�������������Ч�ڵ㣬����#���棺");
	createBiTree(biTree);

	//�������
	printf("���������");
	preOrder(*biTree);
	printf("\n");

	//�������
	printf("���������");
	inOrder(*biTree);
	printf("\n");

	//�������
	printf("���������");
	postOrder(*biTree);
	printf("\n");

	//���
	printf("��ȣ�");
	depth(*biTree);
	printf("\n");


	return 0;
}

//����������
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

//�������
void preOrder(BiTree root) {
	if (root) {
		printf("%c  ", root->data);
		preOrder(root->LChild);
		preOrder(root->RChild);
	}
}

//�������
void inOrder(BiTree root) {
	if (root) {
		inOrder(root->LChild);
		printf("%c  ", root->data);
		inOrder(root->RChild);
	}
}

//�������
void postOrder(BiTree root) {
	if (root) {
		postOrder(root->LChild);
		postOrder(root->RChild);
		printf("%c  ", root->data);
	}
}
//���

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