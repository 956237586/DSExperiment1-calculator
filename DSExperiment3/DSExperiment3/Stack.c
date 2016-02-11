/*ջ������ʵ��*/
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
/*/
int testStackMain() {
	Stack* stack = NULL;
	int i = 0, size = 10;

	printf("������ջ��\n");
	stack = createStack(size);
	printAll(stack);

	printf("����Ԫ�أ�\n");
	while (isFullStack(stack) == 0) {
		push(stack, i++);
		printAll(stack);
	}

	printf("�߽���ԣ�����ջ״̬�¼���push��\n");
	push(stack, 10);

	printf("pop * 5��\n");
	pop(stack, NULL);
	pop(stack, NULL);
	pop(stack, NULL);
	pop(stack, NULL);
	pop(stack, NULL);
	printAll(stack);

	printf("push * 2��\n");
	push(stack, 111);
	push(stack, 222);
	printAll(stack);

	printf("pop�������ݣ�\n");
	while (isEmptyStack(stack) == 0) {
		pop(stack, NULL);
		printAll(stack);
	}

	printf("�߽���ԣ��ڿ�ջ״̬�¼���pop��\n");
	pop(stack, NULL);//�߽����

	system("pause");
	return 0;
}
//*/
//����ջ
Stack*  createStack(int maxSize) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack != NULL) {
		stack->size = maxSize;
		stack->top = NULL;
		stack->currentSize = 0;
	}
	return stack;
}
//�ж϶�ջS�Ƿ�����
int isFullStack(Stack* s) {
	return s->currentSize == s->size;
}

// ��Ԫ��itemѹ���ջ
void push(Stack* s, TreeNode* item) {
	StackNode* newItem = NULL;
	//if (isFullStack(s) == 0) {
	if (!isFullStack(s)) {
		newItem = (StackNode*)malloc(sizeof(StackNode));
		newItem->element = item;
		newItem->next = s->top;
		s->top = newItem;
		s->currentSize++;
		//printf("push %d\n", item);
	} else {
		printf("Stack is already full!\n");
	}
}

// �ж϶�ջS�Ƿ�Ϊ�գ�
int isEmptyStack(Stack* s) {
	return s->currentSize == 0;
}

// ɾ��������ջ��Ԫ��,ʧ�ܷ���0,�ɹ��Ļ������ᱻ�浽i��
int pop(Stack* s, TreeNode** i) {
	int ret;
	StackNode* t = s->top;
	//if (isEmptyStack(s) == 0) {
	if (!isEmptyStack(s)) {
		if (i != NULL) {
			*i = s->top->element;
		}
		//printf("pop %d\n", s->top.next->element);//Ϊ����۲�Ч����ӡ���
		s->top = t->next;
		free(t);
		s->currentSize--;
		ret = 1;
	} else {
		printf("Stack is  already empty!\n");
		ret = 0;//����ֵ����־����
	}
	return ret;
}
/*/
//Ԥ��ջ��ǰ״̬
void printAll(Stack* s) {
	StackNode* t = s->top->next;
	int i = s->currentSize - 1;
	
	if (t == NULL) {
		printf("Empty Stack\n");
	} else {
		while (t != NULL) {
			printf("elements[%d] = %d\n", i--, t->element);
			t = t->next;
		}
	}
	printf("\n");
}
//*/