#include <stdio.h>
#include <stdlib.h>

//�����ڵ�����
typedef struct node {
	int data;
	struct node* pNext;
} Node;

//��������
Node* createLinkedList();
void travel(Node* linkedList);
void sort(Node* linkedList);
Node* getMergeList(Node* linkedList1,Node* linkedList2);
void reverse(Node* linkedList);

int main() {

	//��������1�����
	printf("��������1\n");
	Node* linkedList1 = createLinkedList();
	printf("����1��");
	travel(linkedList1);
	printf("\n");

	//��������2�����
	printf("��������2\n");
	Node* linkedList2 = createLinkedList();
	printf("����2��");
	travel(linkedList2);
	printf("\n");

	//����ϲ�����
	printf("�ϲ�����");
	Node* mergeList = getMergeList(linkedList1,linkedList2);
	travel(mergeList);

	//�����������
	printf("��������");
	reverse(mergeList);
	travel(mergeList);

	return 0;
}

//������������β�巨
Node* createLinkedList() {
	Node* pHead = (Node*)malloc(sizeof(Node));     //����ͷ�ڵ�
	Node* pTail = pHead;      //����β�ڵ㣬��û��Ԫ��ʱͷ�ڵ����β�ڵ�
	Node* pNew = NULL;        //�����½ڵ�

	printf("��������Ҫ������ݵĸ�����");
	int len;
	scanf("%d",&len);
	printf("������%d������",len);
	for (int i=0; i<len; i++) {
		pNew = (Node *) malloc(sizeof(Node));       //�����½ڵ�
		scanf("%d", &pNew->data);

		pTail->pNext = pNew;    //���½ڵ�ҵ�β�ڵ��
		pTail = pNew;           //�½ڵ����µ�β�ڵ�
		pTail->pNext = NULL;    //β�ڵ�����ÿ�
	}
	return pHead;
}

//������������ֻҪ��ǰ�ڵ㲻Ϊ�գ��ͽ����ӡ����
void travel(Node* linkedList) {
	Node* pTemp = linkedList->pNext;
	while (pTemp != NULL) {
		printf("%d  ",pTemp->data);
		pTemp = pTemp->pNext;
	}
	printf("\n");
}

//�����ð������
void sort(Node* linkedList) {
	for (Node* p = linkedList->pNext; p != NULL; p = p->pNext) {
		for (Node* q = p->pNext; q != NULL; q = q->pNext) {
			if (p->data > q->data) {
				int temp = p->data;
				p->data = q->data;
				q->data = temp;
			}
		}
	}
}

//����ĺϲ�����������1�õ�����β�ڵ�������2���ں���,����������
Node* getMergeList(Node* linkedList1,Node* linkedList2) {
	Node* pTemp = linkedList1->pNext;
	while (1) {
		if (pTemp->pNext == NULL) {     //�õ�β�ڵ�
			pTemp->pNext = linkedList2->pNext;  //������2����ȥ
			break;
		}
		pTemp = pTemp->pNext;
	}
	sort(linkedList1);      //����
	return linkedList1;
}

//�������������������ͷ�巨���´���
void reverse(Node* linkedList) {
	Node* pTemp  = linkedList->pNext;
	Node* pNew;
	linkedList->pNext = NULL;

	while (pTemp != NULL) {
		pNew = pTemp;
		pTemp = pTemp->pNext;

		pNew->pNext = linkedList->pNext;
		linkedList->pNext = pNew;
	}
}


