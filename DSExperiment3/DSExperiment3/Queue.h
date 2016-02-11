#ifndef _QUEUE_
#define _QUEUE_
#include "BinaryTree.h"
typedef struct _queue_node {
	TreeNode* element;
	struct _queue_node* next;
} QueueNode;

typedef struct _queue {
	int currentSize;//��ǰԪ�ظ���
	int maxSize;
	QueueNode* first;//ָ���һ���ڵ��ָ��
	QueueNode* last;
} Queue;

Queue* creatQueue(int maxSize); //���ɳ���ΪMaxSize�Ŀն��У�
int isFullQueue(Queue* q); // �ж϶���Q�Ƿ�������
void append(Queue* q, TreeNode* item);// ������Ԫ��item�������Q�У�
int isEmptyQueue(Queue* q);// �ж϶���Q�Ƿ�Ϊ�գ�
int serve(Queue* q, TreeNode** firstItem); // ����ͷ����Ԫ�شӶ�����ɾ�������ء�
//void printAll(Queue* q); //Ԥ�����е�ǰ״̬
#endif