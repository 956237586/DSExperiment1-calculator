#ifndef _STACK_
#define _STACK_
#include "BinaryTree.h"
typedef struct _stack_node {
	TreeNode* element;
	struct _stack_node* next;
} StackNode;

typedef struct _stack {
	int currentSize;//��ǰԪ�ظ���
	int size;
	StackNode* top;//ͷָ��
} Stack;

Stack*  createStack(int maxSize); //����ջ
int isFullStack(Stack* s); //�ж϶�ջS�Ƿ�������
void push(Stack* s, TreeNode* item); // ��Ԫ��itemѹ���ջ��
int isEmptyStack(Stack* s); // �ж϶�ջS�Ƿ�Ϊ�գ�
int pop(Stack* s, TreeNode** i); // ɾ��������ջ��Ԫ��,ʧ�ܷ���0,�ɹ��Ļ������ᱻ�浽i��
						   //�����NULL��i����ô�Ͷ�Ԫ�ؾͲ��ᱻ�浽i
//void printAll(Stack* s); //Ԥ��ջ��ǰ״̬
#endif