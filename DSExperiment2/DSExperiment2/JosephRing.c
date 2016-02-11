/*���Ա�����ʵ��*/
#include "JosephRing.h"

JosephRing* createRing(){
	JosephRing* pList;
	pList = (JosephRing*)malloc(sizeof(JosephRing));
	init(pList);
	return pList;
}

//��ʼ������Ϊ0
void init(JosephRing* pList){
	pList->head = NULL;
	pList->len = 0;
}

//����һ���ڵ�
Node* createNode(int number){
	Node *p = (Node*)malloc(sizeof(Node));
	p->value = number;
	p->next = NULL;
	return p;
}

//���س���n��
int getLength(JosephRing* pList){
	return pList->len;
}

//��ӡ���б�Ԫ��
void printAll(JosephRing* pList){
	Node* t = NULL;
	int i = 0;
	t = pList->head;
	while (i < getLength(pList)){
		printf("element[%d] = %d\n", i++, t->value);
		t = t->next;
	}
	printf("\n");
}

//ɾ��ָ���Ľڵ�
Node* delNode(JosephRing* pList, Node* del){
	Node* pNext = NULL;
	if (del){//������ɾ������
		pNext = del->next;
		if(pNext == pList->head)
			pList->head = del;
		del->value = pNext->value;
		del->next = pNext->next;
		pList->len--;
		free(pNext);
	}
	return del;
}

//�����Ĳ��뷽��
void insert(JosephRing* pList, int x){
	Node* newNode = NULL;
	if (pList->len == 0){//����ǿձ�
		newNode = createNode(x);
		newNode->index = 0;
		newNode->next = newNode;//�ɻ�;
	} else {
		newNode = createNode(pList->head->value);
		newNode->index = pList->head->index;
		newNode->next = pList->head->next;
		pList->head->value = x;
		pList->head->index = pList->len;
		pList->head->next = newNode;
	}
	pList->head = newNode;
	pList->len++;
}

int getNumber(JosephRing* pList, int k, int m) {
	int ret = 0;
	int i = 0;
	Node* p = pList->head;
	while (k--) p = p->next;
	while (pList->len != 1) {
		for (i = 0; i < m - 1; i++)	p = p->next;
#ifdef _DEBUG_
		printf("del %d\n", p->value);
#endif // _DEBUG_

		p = delNode(pList, p);
#ifdef _DEBUG_
		printAll(pList);
#endif // _DEBUG_

	}
	ret = pList->head->value;
	return ret;
}

int newGetNumber(JosephRing* pList, int k) {
	int ret = 0;
	int i = 0;
	int m;
	Node* p = pList->head;
	while (k--) p = p->next;
	m = p->value;
	while (pList->len != 1) {
		for (i = 0; i < m - 1; i++)	p = p->next;
		m = p->value;
#ifdef _DEBUG_
		printf("del %d\n", p->value);
#endif // _DEBUG_

		p = delNode(pList, p);
#ifdef _DEBUG_
		printAll(pList);
#endif // _DEBUG_

	}
	ret = pList->head->value;
	return ret;
}