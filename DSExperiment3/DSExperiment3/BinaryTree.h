#ifndef _BINARY_TREE_
#define _BINARY_TREE_
typedef struct _tree_node {
	int element;
	struct _tree_node* leftChild;
	struct _tree_node* rightChild;
} TreeNode;

typedef TreeNode BinaryTree;

BinaryTree* createBinaryTree();//����һ��������
TreeNode* createTreeNode();//����һ���������ڵ�
void initTreeNode(TreeNode* node);//��ʼ��һ�����������
void preOrderTravel(BinaryTree* tree);//ǰ��������������ݹ�
void preOrderTravelNonRecursive(BinaryTree* tree);//ǰ��������������ǵݹ�
void swap(BinaryTree* tree);//�������нڵ����������
void refresh(BinaryTree* node);//ˢ����ʾ
void printAll(BinaryTree* tree, int n);//��ӡ������
#endif
