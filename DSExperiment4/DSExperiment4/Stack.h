#ifndef Stack_h
#define Stack_h

typedef struct _stackNode {
	int element;
	struct _stackNode* next;
} StackNode;

typedef struct _stack {
	int currentSize;//��ǰԪ�ظ���
	StackNode top;//��һ���ڵ㵱ͷָ���ã����������ջ�Ĵ�С
} Stack;

Stack*  createStack(int maxSize); //����ջ
int isFullStack(Stack* s); //�ж϶�ջS�Ƿ�������
void push(Stack* s, int item); // ��Ԫ��itemѹ���ջ��
int isEmptyStack(Stack* s); // �ж϶�ջS�Ƿ�Ϊ�գ�
int pop(Stack* s, int* i); // ɾ��������ջ��Ԫ��,ʧ�ܷ���0,�ɹ��Ļ������ᱻ�浽i��
						   //�����NULL��i����ô�Ͷ�Ԫ�ؾͲ��ᱻ�浽i
int top(Stack* s, int* i);
//void printAll(Stack* s); //Ԥ��ջ��ǰ״̬
#endif