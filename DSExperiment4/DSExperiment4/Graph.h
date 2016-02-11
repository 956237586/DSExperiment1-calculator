#ifndef Graph_h
#define Graph_h
#include "Linearlist.h"
#include "Stack.h"
//#define _DEBUG_
typedef struct _tableNode {
	int value;
	List* adj;
} TableNode;

typedef struct _vertex {
	int id;
} Vertex;

typedef struct _edge {
	Vertex* vertex1;
	Vertex* vertex2;
} Edge;


typedef struct _searchConfig {
	int src;
	int des;
	int length;
} SearchConfig;

typedef struct _graph {
	int countVertexes;
	int countEdges;
	char* path;
	Vertex** vertexes;
	Edge** edges;
	TableNode* adjacencyTable;
	SearchConfig* searchConfig;
} Graph;


Graph* loadFile(char* path);//���ļ�����ͼ��Ϣ��������ͼ
FILE* initFile(char* path, char* fileName, char* mode);//ָ��ģʽ��ʼ���ļ�
Graph* createGraph(char* path);//����һ��ͼ
void initGraph(Graph* graph, FILE* in);//��ʼ��ͼ��Ϣ
void initSearch(Graph* graph, FILE* in);//��ʼ��������Ϣ
void initAdjacencyTable(Graph* graph, FILE* in);//��ʼ���ڽӱ�
void initVertexes(Graph* graph, FILE* in);//��ʼ�����ж���
void initEdges(Graph* graph, FILE* in);//��ʼ�����б�
void outputVertex(FILE* file, int vertex);//���������Ϣ
Vertex* createVertex(int id);//����һ������
Edge* createEdge(Vertex* vertex1, Vertex* vertex2);//����һ����
void DFS(Graph* graph);//�����������
void BFS(Graph* graph);//�����������
void printResult(Graph* graph, Stack* s, FILE* out);//��ӡ���
void search(Graph* graph);//����ָ�����ȵ�·��������ID��src��des
#endif
