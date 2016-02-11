/*���е�����ʵ��*/
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
/*/
int TestQueueMain() {
	Queue* queue = NULL;
	int i = 0, size = 10;

	printf("�����ն��У�\n");
	queue = createQueue(size);
	printAll(queue);

	printf("����Ԫ�أ�\n");
	while (isFullQueue(queue) == 0) {
		append(queue, i++);
		printAll(queue);
	}

	printf("�߽���ԣ���������״̬�¼���add��\n");
	append(queue, 10);

	printf("delete * 5��\n");
	serve(queue, NULL);
	serve(queue, NULL);
	serve(queue, NULL);
	serve(queue, NULL);
	serve(queue, NULL);
	printAll(queue);

	printf("add * 2��\n");
	append(queue, 111);
	append(queue, 222);
	printAll(queue);

	printf("delete�������ݣ�\n");
	while (isEmptyQueue(queue) == 0) {
		serve(queue, NULL);
		printAll(queue);
	}

	printf("�߽���ԣ��ڿ�״̬�¼���delete��\n");
	serve(queue, NULL);//�߽����

	system("pause");
 	return 0;
}
//*/

//���ɳ���ΪMaxSize�Ŀն��У�
Queue* createQueue(int maxSize) {
	Queue* queue = NULL;
	queue = (Queue*)malloc(sizeof(Queue));
	queue->maxSize = maxSize;
	queue->currentSize = 0;
	queue->first = NULL;
	queue->last = NULL;
	return queue;
}

// �ж϶���Q�Ƿ�������
int isFullQueue(Queue* q) {
	return q->currentSize == q->maxSize;
}

// ������Ԫ��item�������Q�У�
void append(Queue* q, int item) {
	QueueNode* t = NULL;
	if (!isFullQueue(q)) {
		t = (QueueNode*)malloc(sizeof(QueueNode));
		t->element = item;
		t->next = NULL;
		if (isEmptyQueue(q))	q->first = q->last = t;
		else q->last->next = t;
		q->last = t;
		q->currentSize++;
		//printf("add %d\n", item);
		//Ϊ�˷���۲��ӡ��Ϣ
	} else {
		printf("Queue is Full!\n");
	}
}

// �ж϶���Q�Ƿ�Ϊ�գ�
int isEmptyQueue(Queue* q) {
	return q->currentSize == 0;
}

// ����ͷ����Ԫ�شӶ�����ɾ�������ء�
int serve(Queue* q, int* firstItem) {
	int ret;
	QueueNode* t = q->first;
	if (!isEmptyQueue(q)) {
		if (firstItem != NULL) {
			*firstItem = q->first->element;
		}
		//printf("delete %d\n", q->first->element);
		//Ϊ�˷���۲��ӡ��Ϣ
		q->first = q->first->next;
		free(t);
		q->currentSize--;
		ret = 1;
		
	} else {
		printf("Queue is Empty!\n");
		ret = 0;
	}
	return ret;
}

int getFirst(Queue* q, int* firstItem) {
	int ret = 0;
	if (!isEmptyQueue(q)) {
		*firstItem = q->first->element;
		ret = 1;
	}
	return ret;
}

//Ԥ�����е�ǰ״̬
/*/
void printAll(Queue* q) {
	int i = 0;
	QueueNode* t = NULL;
	if (!isEmptyQueue(q)) {
		t = q->first;
		while (t != NULL) {
			printf("element[%d] = %d\n", i++, t->element);
			t = t->next;
		}
		
	} else {
		printf("Empty Queue\n");
	}
	printf("\n");
}
//*/