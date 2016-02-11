#ifndef Queue_h
#define Queue_h
typedef struct _queueNode {
	int element;
	struct _queueNode* next;
} QueueNode;

typedef struct _queue {
	int currentSize;//��ǰԪ�ظ���
	int maxSize;
	QueueNode* first;//ָ���һ���ڵ��ָ��
	QueueNode* last;
} Queue;

Queue* createQueue(int maxSize); //���ɳ���ΪMaxSize�Ŀն��У�
int isFullQueue(Queue* q); // �ж϶���Q�Ƿ�������
void append(Queue* q, int item);// ������Ԫ��item�������Q�У�
int isEmptyQueue(Queue* q);// �ж϶���Q�Ƿ�Ϊ�գ�
int serve(Queue* q, int* firstItem); // ����ͷ����Ԫ�شӶ�����ɾ�������ء�
int getFirst(Queue* q, int* firstItem);
//void printAll(Queue* q); //Ԥ�����е�ǰ״̬
#endif