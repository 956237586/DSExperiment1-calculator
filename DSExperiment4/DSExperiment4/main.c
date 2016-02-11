// ����ϵر�֤��

// ���Լ��������������������ӷ�������Ƶ���������й�����
// ��������������У���������ʲô���Ѷ�������ˣ���ô���ҽ��ڳ���ʵϰ������
// ��ϸ���о��������������⣬�Լ����˸��ҵ���ʾ��
// �ڴˣ��Ҹ�л���膴ѧ�����ҵ������Ͱ���������ı����У��һ��������ᵽ
// �����ڸ����������ҵİ�����

// �ҵĳ������з������õ�����������ĵ�֮����
// ����̲ġ����ñʼǡ����ϵ�Դ�����Լ������ο����ϵĴ����,
// �Ҷ��Ѿ��ڳ����ע����������ע�������õĳ�����

// �Ҵ�δû��Ϯ�����˵ĳ���Ҳû�е��ñ��˵ĳ���
// �������޸�ʽ�ĳ�Ϯ����ԭ�ⲻ���ĳ�Ϯ��

// �ұ�д������򣬴���û�����Ҫȥ�ƻ���������������ϵͳ��������ת��

// ������

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Graph.h"
char* getFilePath(const char* path) {
	char* ret = (char*)malloc(strlen(path) * 2);
	char* t = ret;
	if (ret) {
		strcpy(ret, path);
		t += strlen(path);
		while (*t != '\\')*t-- = 0;
	}
	return ret;
}

int main(int argc, const char* argv[]) {
	char* path = getFilePath(argv[0]);
	Graph* graph = loadFile(path);
	if (graph) {
		if (argc == 2) {
			switch (*argv[1]) {
			case 'B':BFS(graph); break;
			case 'D':DFS(graph); break;
			case 'S':search(graph); break;
			}
		} else {
			BFS(graph);
			DFS(graph);
			search(graph);
		}
#ifdef _DEBUG_
		system("pause");
#endif
		return 0;
	}
	return 1;
}