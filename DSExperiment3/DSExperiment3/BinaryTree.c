#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"
#include "Queue.h"
#include "Stack.h"

/*
�������ƣ�createBinaryTree
������������������һ��������
����ֵ������еĻ��������ڵ�ָ��
�������������(��ѡ)����
*/

BinaryTree* createBinaryTree() {
	BinaryTree* tree = createTreeNode();
	printf("Please input root node\n");
	initTreeNode(tree);
	return tree;
}

/*
�������ƣ�createTreeNode
������������������һ���������ڵ�
����ֵ������еĻ��������ڵ�ָ��
�������������(��ѡ)����
*/

TreeNode* createTreeNode() {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->element = -1;
	node->leftChild = node->rightChild = NULL;
	return node;
}


/*
�������ƣ�initTreeNode
����������������ʼ��һ�����������,�����ʼ��
����ֵ������еĻ�������
�������������(��ѡ)�����ڵ�ָ��
*/

void initTreeNode(TreeNode* node) {
	int t;
	TreeNode* temp;
	Queue* queue = creatQueue(10000);
	append(queue, node);
	refresh(node);
	while (!isEmptyQueue(queue)) {
		serve(queue, &temp);
		printf("Please input value of first x:");
		scanf("%d", &temp->element);
		printf("This node has childs ?(1:yes, 0:no)\n", temp->element);
		printf("left child ?:");
		scanf("%d", &t);
		if (t) {
			temp->leftChild = createTreeNode();
			append(queue, temp->leftChild);
		}
		printf("right child ?:", temp->element);
		scanf("%d", &t);
		if (t) {
			temp->rightChild = createTreeNode();
			append(queue, temp->rightChild);
		}
		refresh(node);
	}
}

/*
�������ƣ�preOrderTravel
��������������ǰ��������������ݹ�
����ֵ������еĻ�������
�������������(��ѡ)������ָ��
*/

void preOrderTravel(BinaryTree* tree) {
	if (tree) {
		printf("%d ", tree->element);
		preOrderTravel(tree->leftChild);
		preOrderTravel(tree->rightChild);
	}
}

/*
�������ƣ�preOrderTravel
��������������ǰ��������������ǵݹ�
����ֵ������еĻ�������
�������������(��ѡ)������ָ��
*/
void preOrderTravelNonRecursive(BinaryTree* tree) {
	Stack* stack = createStack(1000);
	TreeNode* temp = tree;
	while (temp || !isEmptyStack(stack)) {
		while (temp) {
			printf("%d ", temp->element);
			push(stack, temp);
			temp = temp->leftChild;
		}
		if (!isEmptyStack(stack)) {
			pop(stack, &temp);
			temp = temp->rightChild;
		}
	}
	printf("\n");
}


/*
�������ƣ�swap
���������������������нڵ����������
����ֵ������еĻ�������
�������������(��ѡ)������ָ��
*/

void swap(BinaryTree* tree) {
	TreeNode* t;
	if (tree) {
		t = tree->leftChild;
		tree->leftChild = tree->rightChild;
		tree->rightChild = t;
		swap(tree->rightChild);
		swap(tree->leftChild);
	}
}

/*
�������ƣ�refresh
��������������ˢ����ʾ
����ֵ������еĻ�������
�������������(��ѡ)������ָ��
*/

void refresh(BinaryTree* node) {
	system("cls");
	printf("Current Tree:\n\n");
	printAll(node, 0);
	printf("\n");
}


/*
�������ƣ�printAll
����������������ӡ������
����ֵ������еĻ�������
�������������(��ѡ)������ָ�룬���n
*/
void printAll(BinaryTree* tree, int n) {
	int i = n;
	if (tree) {
		printAll(tree->leftChild, n + 1);
		while (i--)printf("\t");
		if (tree->element != -1)printf("%d", tree->element);
		else printf("x");
		printf("\n");
		printAll(tree->rightChild, n + 1);
	}
}
