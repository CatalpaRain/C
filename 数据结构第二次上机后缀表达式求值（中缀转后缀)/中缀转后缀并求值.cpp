#define SIZE 40
#include <string.h> 
#include <iostream> 
#include <stdlib.h> 
using namespace std;
#define MaxSize 32 

typedef char Qelemtype;

typedef struct {
	Qelemtype* base; //ָ����еĴ洢�ռ䣻 
	int front; //ָ���ͷԪ�أ� 
	int rear; //ָ���βԪ�ص���һλ�ã� 
}SqQueue;

typedef struct LNode {
	int data;
	struct LNode* next;
}Snode, * LinkStack;


void DestroyLinStack(LinkStack& S) {//������ջS�� 
	LinkStack temp = S, p;
	while (temp)
	{
		p = temp;
		temp = temp->next;
		free(p);
	}
}

void Push(LinkStack& S, char x) {//��ջ�� 
	LinkStack temp = (LinkStack)malloc(sizeof(Snode));
	temp->data = x;
	temp->next = S->next;
	S->next = temp;
}

void Pop(LinkStack& S, char& x) {//��ջ�� 
	LinkStack temp = S->next;
	x = temp->data;
	S->next = temp->next;
	free(temp);
}

int GetTop(LinkStack& S) {//��ջ��Ԫ��. 
	int x;
	if (S->next)
		x = S->next->data;
	else
		cout << "Stack Null " << endl;
	return x;
}

void Initstack(LinkStack& S) {
	S = (LinkStack)malloc(sizeof(Snode));
	if (!S)
	{
		cout << "Alloctation Error" << endl;
		exit(1);
	}
	S->next = 0;
}


int InitQueue(SqQueue& Q) {//���еĳ�ʼ���� 
	Q.front = Q.rear = 0;
	Q.base = (Qelemtype*)malloc(MaxSize * sizeof(Qelemtype));
	if (!Q.base)
		exit(1);
	Q.base[Q.front] = '\0';
	return 1;
}

int QueueLength(SqQueue Q) {//������еĳ��ȣ� 
	return (Q.rear - Q.front + MaxSize) % MaxSize;
}

void EnQueue(SqQueue& Q, Qelemtype x) {//��ӣ� 
	if (QueueLength(Q) == MaxSize)
	{
		cout << "EnQueue Error " << endl;
		return;
	}
	Q.base[Q.rear++] = x;
}


void DispQueue(SqQueue Q) {//������е�����Ԫ�أ� 
	int i = 0, j = Q.front;
	while (i < QueueLength(Q))
	{
		cout << Q.base[j];
		if (Q.base[j] >= 48 && Q.base[j] <= 57 && Q.base[j - 1] >= 48 && Q.base[j - 1] <= 57)
			cout << " ";
		j++;
		i++;
	}
}

void DestroyQueue(SqQueue& Q) { //���е����٣� 
	delete[]Q.base;
	Q.base = 0;
	Q.front = Q.rear = 0;
	return;
}


int StackEmpty(LinkStack S) {//�ж�ջ�Ƿ�Ϊ��. 
	return (S->next == 0);
}

int Priority(char oper) {
	switch (oper)
	{
	case '(':
		return 0;
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	}
}

void convertpostexp(char* str, SqQueue& post) {
	char c, t;
	int i = 0, k = strlen(str);
	LinkStack S;
	Initstack(S);
	Push(S, '(');
	InitQueue(post);
	while (i < k || !StackEmpty(S))
	{
		c = *str++;
		switch (c)
		{
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			EnQueue(post, c);
			break;
		case '(':
			Push(S, c);
			break;
		case ')':
		case '=':
			do {
				Pop(S, t);
				if (t != '(')
					EnQueue(post, t);
			} while (t != '(' && !StackEmpty(S));
			break;
		case '+':
		case '-':
		case '*':
		case '/':
			while (Priority(c) <= Priority(GetTop(S)))
			{
				Pop(S, t);
				EnQueue(post, t);
			}
			Push(S, c);
			break;
		}
		i++;
	}
	DestroyLinStack(S);
}



struct node {//��������ջ������ַ�
	char* base;
	char* top;        //ͷָ��
	int size;
};
struct list {//����ջ
	float* base;
	float* top;
	int size;
};
node m; list n;             //������������

void Push2(list& S, float e) {   //����������ջ�е��㷨
	*S.top++ = e;
	//cout<<e<<"�Ѿ�����������ջ��"<<endl;
}

void Push(node& S, char e) {     //�����������ջ��
	*S.top++ = e;
	//cout<<e<<"�Ѿ��������ַ�ջ��"<<endl;
}

float Pop2(list& S) {
	if (S.base == S.top) cout << "����ջΪ�գ��������";
	float x = *(--S.top);         //�����*������˷��������ָ��
//cout<<"����ֵΪ"<<x<<endl;
	return x;
}

char Pop(node& S) {
	if (S.base == S.top) cout << "�ַ�ջΪ�գ��������";
	char x = *(--S.top);
	//cout<<"��ջ�ַ�Ϊ"<<x<<endl;
	return x;
}

void InitStack(node& S) {//��ʼ���ַ�ջ
	S.base = (char*)malloc(SIZE * sizeof(char));    //����һ���ڵ�
	if (!S.base) {
		cout << "errer abc" << endl;
		exit(1);
	}
	S.top = S.base;
	S.size = 20;
}

void InitStack2(list& S) {
	S.base = (float*)malloc(SIZE * sizeof(float));     //����һ���ڵ�
	if (!S.base) {
		cout << "errer efg" << endl;
		exit(1);
	}
	S.top = S.base;
	S.size = 20;
}

int Prior(char c) {
	//����������ǽ���Ƚ����ȼ���ʱ����δ����������ֵ�Ĵ�С������������һ��������
	//cout<<"Ҫ��ջ�����������ַ�Ϊ"<<c<<endl;
	int r;
	switch (c)
	{
	case '=':r = 0; break;
	case '(':r = 1; break;
	case '*':
	case '/':r = 5; break;
	case '+':
	case '-':r = 3; break;
	case ')':r = 8; break;
	default:cout << "errer asdf" << endl;
	}
	return r;
}

int Prior2(char c) {
	int w;
	//cout<<"Ҫ��ջ�����������ַ�Ϊ"<<c<<endl;
	switch (c)
	{
	case '=':w = 0; break;
	case '(':w = 8; break;
	case '*':
	case '/':w = 4; break;
	case '+':
	case '-':w = 2; break;
	case ')':w = 1; break;
	default:cout << "errer sfd" << endl;
	}
	return w;
}


float Compute(char* str) {
	int i = 0;
	float x;
	Push(m, '=');           //��ʼ���ַ�ջ����ֻ��һ��Ԫ��';'������ջΪ��ջ
	while (str[i] && i < SIZE - 1)   //������׺���ʽѭ��
	{
		x = 0;
		if (str[i] == ' ') { i++; continue; }
		while (str[i] >= 48 && str[i] <= 57) //�����48��57 ��ʮ����1��10��ASCII��ֵ��������Ҫ���������λ�����������
		{
			x = x * 10 + str[i] - 48;     //����Ļ�ϻ�ȡ�Ķ������ַ�����ʽչ�ֳ����ģ�����ҪASCILL��ֵ��Ҫ��ȥ48 ���������������λ��
			i++;
		}
		if (x != 0) Push2(n, x);     //���x��ֵ������ 0��ô�ͽ�����ջ
		else
		{
			int a = Prior2(str[i]);   //����ջ���ַ�
			int b = Prior(*(m.top - 1)); //����ջ���ַ�����Ա�������ַ�ջ�е�ջ��Ԫ��
			if (a > b)                  //ջ����������ȼ�����ջ����������ȼ�
			{
				Push(m, str[i]); i++; //������뵽�ַ�ջ��
			}
			else
				switch (Pop(m))       //���ȼ��෴����������Ĳ����������ַ�ջ�ڵ���Ԫ��
				{
				case '+':x = Pop2(n) + Pop2(n); //������ջ���׳�������ֵ���������ϵ�����
					Push2(n, x); break;
				case '-':x = Pop2(n);
					x = Pop2(n) - x;
					Push2(n, x); break;
				case '*':x = Pop2(n) * Pop2(n);
					Push2(n, x); break;
				case '/':x = Pop2(n);
					if (x != 0.0)
					{
						x = Pop2(n) / x; Push2(n, x);
					}
					else
					{
						cout << "�㲻��������" << endl; i = SIZE - 1;
					}
					break;
				case '(':i++; break;
				case '=':i = SIZE - 1; break;
				default:cout << "====��������====" << endl;
				}
		}
	}
	x = Pop2(n);
	return x;
}

int main() {
	char str[32];
	char a[SIZE];
	InitStack(m);
	InitStack2(n);
	cout << "��������׺���ʽ����=����:";
	cin >> str;
	SqQueue post;
	convertpostexp(str, post);
	cout << "ת���ɺ�׺���ʽ��:" << endl;
	DispQueue(post);
	cout << endl;
	float z = Compute(str);
	DestroyQueue(post);
	cout << "���Ϊ:" << z << endl;
}