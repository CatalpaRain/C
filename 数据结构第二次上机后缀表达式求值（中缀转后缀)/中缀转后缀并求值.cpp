#define SIZE 40
#include <string.h> 
#include <iostream> 
#include <stdlib.h> 
using namespace std;
#define MaxSize 32 

typedef char Qelemtype;

typedef struct {
	Qelemtype* base; //指向队列的存储空间； 
	int front; //指向队头元素； 
	int rear; //指向队尾元素的下一位置； 
}SqQueue;

typedef struct LNode {
	int data;
	struct LNode* next;
}Snode, * LinkStack;


void DestroyLinStack(LinkStack& S) {//销毁链栈S。 
	LinkStack temp = S, p;
	while (temp)
	{
		p = temp;
		temp = temp->next;
		free(p);
	}
}

void Push(LinkStack& S, char x) {//入栈。 
	LinkStack temp = (LinkStack)malloc(sizeof(Snode));
	temp->data = x;
	temp->next = S->next;
	S->next = temp;
}

void Pop(LinkStack& S, char& x) {//出栈。 
	LinkStack temp = S->next;
	x = temp->data;
	S->next = temp->next;
	free(temp);
}

int GetTop(LinkStack& S) {//读栈顶元素. 
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


int InitQueue(SqQueue& Q) {//队列的初始化； 
	Q.front = Q.rear = 0;
	Q.base = (Qelemtype*)malloc(MaxSize * sizeof(Qelemtype));
	if (!Q.base)
		exit(1);
	Q.base[Q.front] = '\0';
	return 1;
}

int QueueLength(SqQueue Q) {//计算队列的长度； 
	return (Q.rear - Q.front + MaxSize) % MaxSize;
}

void EnQueue(SqQueue& Q, Qelemtype x) {//入队； 
	if (QueueLength(Q) == MaxSize)
	{
		cout << "EnQueue Error " << endl;
		return;
	}
	Q.base[Q.rear++] = x;
}


void DispQueue(SqQueue Q) {//输出队列的所有元素； 
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

void DestroyQueue(SqQueue& Q) { //队列的销毁； 
	delete[]Q.base;
	Q.base = 0;
	Q.front = Q.rear = 0;
	return;
}


int StackEmpty(LinkStack S) {//判断栈是否为空. 
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



struct node {//定义两个栈，存放字符
	char* base;
	char* top;        //头指针
	int size;
};
struct list {//整数栈
	float* base;
	float* top;
	int size;
};
node m; list n;             //定义两个对象

void Push2(list& S, float e) {   //将整数放入栈中的算法
	*S.top++ = e;
	//cout<<e<<"已经被放入整数栈中"<<endl;
}

void Push(node& S, char e) {     //将运算符放入栈中
	*S.top++ = e;
	//cout<<e<<"已经被放入字符栈中"<<endl;
}

float Pop2(list& S) {
	if (S.base == S.top) cout << "整数栈为空，不能输出";
	float x = *(--S.top);         //这里的*不代表乘法运算而是指针
//cout<<"计算值为"<<x<<endl;
	return x;
}

char Pop(node& S) {
	if (S.base == S.top) cout << "字符栈为空，不能输出";
	char x = *(--S.top);
	//cout<<"出栈字符为"<<x<<endl;
	return x;
}

void InitStack(node& S) {//初始化字符栈
	S.base = (char*)malloc(SIZE * sizeof(char));    //建立一个节点
	if (!S.base) {
		cout << "errer abc" << endl;
		exit(1);
	}
	S.top = S.base;
	S.size = 20;
}

void InitStack2(list& S) {
	S.base = (float*)malloc(SIZE * sizeof(float));     //建立一个节点
	if (!S.base) {
		cout << "errer efg" << endl;
		exit(1);
	}
	S.top = S.base;
	S.size = 20;
}

int Prior(char c) {
	//这里的问题是解决比较优先级的时候如何处理运算符的值的大小，进而进入下一步的运算
	//cout<<"要求栈内优先数的字符为"<<c<<endl;
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
	//cout<<"要求栈内优先数的字符为"<<c<<endl;
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
	Push(m, '=');           //初始化字符栈，中只有一个元素';'，整数栈为空栈
	while (str[i] && i < SIZE - 1)   //处理中缀表达式循环
	{
		x = 0;
		if (str[i] == ' ') { i++; continue; }
		while (str[i] >= 48 && str[i] <= 57) //这里的48到57 是十进制1到10的ASCII码值，这里主要是来处理多位数的输入操作
		{
			x = x * 10 + str[i] - 48;     //从屏幕上获取的都是以字符的形式展现出来的，所以要ASCILL码值都要减去48 ，这样才能输入多位数
			i++;
		}
		if (x != 0) Push2(n, x);     //如果x的值不等于 0那么就进整数栈
		else
		{
			int a = Prior2(str[i]);   //处理栈外字符
			int b = Prior(*(m.top - 1)); //处理栈内字符，成员变量是字符栈中的栈顶元素
			if (a > b)                  //栈外运算符优先级高于栈内运算符优先级
			{
				Push(m, str[i]); i++; //将其插入到字符栈中
			}
			else
				switch (Pop(m))       //优先级相反，括号里面的参数变量是字符栈内的首元素
				{
				case '+':x = Pop2(n) + Pop2(n); //从整数栈中抛出两个数值，进行以上的运算
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
						cout << "零不能做除数" << endl; i = SIZE - 1;
					}
					break;
				case '(':i++; break;
				case '=':i = SIZE - 1; break;
				default:cout << "====输入有误====" << endl;
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
	cout << "请输入中缀表达式，以=结束:";
	cin >> str;
	SqQueue post;
	convertpostexp(str, post);
	cout << "转换成后缀表达式是:" << endl;
	DispQueue(post);
	cout << endl;
	float z = Compute(str);
	DestroyQueue(post);
	cout << "结果为:" << z << endl;
}