// ����ϵر�֤��

// ���Լ��������������������ӷ�������Ƶ���������й�����
// ��������������У���������ʲô���Ѷ�������ˣ���ô���ҽ��ڳ���ʵϰ������
// ��ϸ���о��������������⣬�Լ����˸��ҵ���ʾ��

// �ڴˣ��Ҹ�л XXX, ��, XXX���ҵ������Ͱ���������ı����У��һ��������ᵽ
// �����ڸ����������ҵİ�����

// �ҵĳ������з������õ�����������ĵ�֮����
// ����̲ġ����ñʼǡ����ϵ�Դ�����Լ������ο����ϵĴ����,
// �Ҷ��Ѿ��ڳ����ע����������ע�������õĳ�����

// �Ҵ�δû��Ϯ�����˵ĳ���Ҳû�е��ñ��˵ĳ���
// �������޸�ʽ�ĳ�Ϯ����ԭ�ⲻ���ĳ�Ϯ��

// �ұ�д������򣬴���û�����Ҫȥ�ƻ���������������ϵͳ��������ת��

// ������

/*/
�ļ����ƣ�stack.c
��Ŀ���ƣ�DSExperiment1
�����ߣ�������
����ʱ�䣺201.9.12
����޸�ʱ�䣺2015.9.17
���ܣ�ջ������ʵ��
�ļ��еĺ������ƺͼ򵥹���������������
�ļ��ж����ȫ�ֱ����ͼ򵥹���������������
�ļ����õ������������ȫ�ֱ��������������
�������ļ���������ϵ��stack.h
//*/

#include "stack.h"

/*/
�������ƣ�testStack
�������������������������������в��ԣ�����޷�����1˵���д�
��������֮ǰ��Ԥ��������������������
����ֵ������еĻ�����1
�����������������
//*/
int testStack() {
	Stack* stack = NULL;
	int i = 0, size = 10;

	printf("������ջ��\n");
	stack = createStack(size);
	printAll(stack);

	printf("����Ԫ�أ�\n");
	while (isFull(stack) == 0) {
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
	while (isEmpty(stack) == 0) {
		pop(stack, NULL);
		printAll(stack);
	}

	printf("�߽���ԣ��ڿ�ջ״̬�¼���pop��\n");
	pop(stack, NULL);//�߽����

	system("pause");
	return 0;
}

/*/
�������ƣ�createStack
������������������ָ����С��ջ
��������֮ǰ��Ԥ����������
����ֵ������еĻ����������ɹ���ջָ�룬ʧ�ܷ���NULL
���������������ջ������С
//*/
Stack*  createStack(int maxSize) {
	Stack* stack = (Stack*)malloc(sizeof(Stack));
	if(stack != NULL){
		stack->size = maxSize;
		stack->top = -1;
		stack->elements = (double*)malloc(maxSize * sizeof(double));
	}
	return stack;
}

/*/
�������ƣ�isFull
���������������ж϶�ջs�Ƿ�����
��������֮ǰ��Ԥ��������ջָ�벻��NULL
����ֵ������еĻ�������ջ����1�����򷵻�0
���������������ջָ��
//*/
int isFull(Stack* s) {
	return s->top == s->size - 1;
}

/*/
�������ƣ�push
����������������Ԫ��itemѹ���ջ
��������֮ǰ��Ԥ��������ջָ�벻��NULL����ջ����
����ֵ������еĻ�������
���������������ջָ�룬Ҫpush��Ԫ��
//*/
void push(Stack* s, double item) {
	//if (isFull(s) == 0) {
	if (!isFull(s)) {
		s->top++;
		s->elements[s->top] = item;//ע���������˳��
		//printf("push %lf\n", item);
	} else {
		printf("Stack is already full!\n");
	}
}

/*/
�������ƣ�isEmpty
���������������ж϶�ջs�Ƿ�Ϊ��ջ��
��������֮ǰ��Ԥ��������ջָ�벻��NULL
����ֵ������еĻ��������򷵻�1���򷵻�0
���������������ջָ��
//*/
int isEmpty(Stack* s) {
	return s->top == -1;
}

/*/
�������ƣ�pop
��������������ɾ��������ջ��Ԫ��
��������֮ǰ��Ԥ��������ջ����
����ֵ������еĻ�����ʧ�ܷ���0���ɹ�����1���ұ����ᱻ�浽i
���������������ջָ�룬Ҫ�洢����ı�����ַ������NULL�����д��棩
//*/
int pop(Stack* s, double* i) {
	int ret;
	//if (isEmpty(s) == 0) {
	if (!isEmpty(s)) {
		if (i != NULL) {
			*i = s->elements[s->top];
		}
		//printf("pop %lf\n", s->elements[s->top]);//Ϊ����۲�Ч����ӡ���
		s->top--;//ע���������˳��
		ret = 1;
	} else {
		printf("Stack is  already empty!\n"); 
		ret = 0;//����ֵ����־����
	}
	return ret;
}

/*/
�������ƣ�seek
���������������鿴��ǰջ��
��������֮ǰ��Ԥ��������ջ����
����ֵ������еĻ�����ջ��Ԫ��
���������������ջָ��
//*/
double seek(Stack* s) {
	return s->elements[s->top];
}

/*/
�������ƣ�printAll
��������������Ԥ��ջ��ǰ״̬
��������֮ǰ��Ԥ��������ջָ�벻Ϊ��
����ֵ������еĻ�������
���������������ջָ��
//*/
void printAll(Stack* s) {
	int i = 0;
	if (!isEmpty(s)) {
		for (i = s->top; i >= 0; i--) {
			printf("elements[%d] = %lf\n", i, s->elements[i]);
		}
	} else {
		printf("Empty Stack\n");
	}
	printf("\n");
}