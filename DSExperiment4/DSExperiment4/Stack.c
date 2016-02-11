/*ջ������ʵ��*/
#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

//����ջ
Stack*  createStack(int maxSize) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if (stack != NULL) {
		stack->top.element = maxSize;
		stack->top.next = NULL;
		stack->currentSize = 0;
	}
	return stack;
}
//�ж϶�ջS�Ƿ�����
int isFullStack(Stack* s) {
	return s->currentSize == s->top.element;
}

// ��Ԫ��itemѹ���ջ
void push(Stack* s, int item) {
	StackNode* newItem = NULL;
	//if (isFullStack(s) == 0) {
	if (!isFullStack(s)) {
		newItem = (StackNode*)malloc(sizeof(StackNode));
		newItem->element = item;
		newItem->next = s->top.next;
		s->top.next = newItem;
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
int pop(Stack* s, int* i) {
	int ret;
	StackNode* t = s->top.next;
	//if (isEmptyStack(s) == 0) {
	if (!isEmptyStack(s)) {
		if (i != NULL) {
			*i = s->top.next->element;
		}
		//printf("pop %d\n", s->top.next->element);//Ϊ����۲�Ч����ӡ���
		s->top.next = t->next;
		free(t);
		s->currentSize--;
		ret = 1;
	} else {
		printf("Stack is  already empty!\n");
		ret = 0;//����ֵ����־����
	}
	return ret;
}

int top(Stack* s, int* i) {
	int ret = 0;
	if (!isEmptyStack(s)) {
		ret = 1;
		*i = s->top.next->element;
	}
	return ret;
}

//Ԥ��ջ��ǰ״̬
/*/
void printAll(Stack* s) {
	StackNode* t = s->top.next;
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