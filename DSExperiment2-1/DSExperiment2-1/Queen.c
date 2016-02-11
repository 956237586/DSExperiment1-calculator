// ����ϵر�֤��

// ���Լ��������������������ӷ�������Ƶ���������й�����
// ��������������У���������ʲô���Ѷ�������ˣ���ô���ҽ��ڳ���ʵϰ������
// ��ϸ���о��������������⣬�Լ����˸��ҵ���ʾ��

// �ڴˣ��Ҹ�л ���膴ѧ�����ҵ������Ͱ���������ı����У��һ��������ᵽ
// �����ڸ����������ҵİ�����

// �ҵĳ������з������õ�����������ĵ�֮����
// ����̲ġ����ñʼǡ����ϵ�Դ�����Լ������ο����ϵĴ����,
// �Ҷ��Ѿ��ڳ����ע����������ע�������õĳ�����

// �Ҵ�δû��Ϯ�����˵ĳ���Ҳû�е��ñ��˵ĳ���
// �������޸�ʽ�ĳ�Ϯ����ԭ�ⲻ���ĳ�Ϯ��

// �ұ�д������򣬴���û�����Ҫȥ�ƻ���������������ϵͳ��������ת��

// ������

/*/
�ļ����ƣ�Queen.c
��Ŀ���ƣ�DSExperiment2
�����ߣ�������
����ʱ�䣺2015.10.21
����޸�ʱ�䣺2015.10.22
���ܣ��˻ʺ�������ļ�
�ļ��еĺ������ƺͼ򵥹���������������
�ļ��ж����ȫ�ֱ����ͼ򵥹���������������
�ļ����õ������������ȫ�ֱ��������������
//*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
//#define _DEBUG_ //����ģʽ�л�
typedef int* Queens;
struct _chessBoard {
	Queens queens;//�ʺ�����
	int size;//��ģ
	int end;//����������־
	int count;//���������
};
typedef struct _chessBoard* CheesBoard;

CheesBoard createCheesBoard(int size);//��ʼ������
Queens createQueens(int n);//��ʼ���ʺ�����
void search(CheesBoard chs);//��ʼ����
int beAttacked(Queens queens, int n);//��n���Ƿ񱻹���
int isSameColumn(Queens queens, int queen1, int queen2);//����Ƿ�ͬ��
int isSameMainDiagonal(Queens queens, int queen1, int queen2);//����Ƿ�ͬ���Խ���
int isSameDiagonal(Queens queens, int queen1, int queen2);//����Ƿ�ͬ���Խ���
void printResult(CheesBoard chs);//��ӡ���

/*
�������ƣ�main
����������������ں���
*/
int main() {
	CheesBoard eightQueen = createCheesBoard(11);
	search(eightQueen);
	system("pause");
	return 0;
}

/*
�������ƣ�search
����������������ʼ����
����ֵ������еĻ�������
�������������(��ѡ)������n
*/
void search(CheesBoard chs) {
	Queens queens = chs->queens;
	int n = chs->size;
	int i = 0;

	while (i < n) {
		if (!beAttacked(queens, i)) {		//�����������
			i++;							//������һ��
		} else {
			while (queens[i] == n - 1) {	//����Ѿ����Թ���������λ��
				if (i != 0) {				//������ǵ�һ�������
					queens[i--] = 0;		//����i��1
				} else {					//�����������
					chs->end = 1; 
					break;
				}
			}
			queens[i]++;					//��ǰ�е�λ������ƶ�һλ
		}
		if (chs->end) break;
		if (i == n) {						//���n�ж��������
			(chs->count)++;					//���������1
			printResult(chs);				//��ӡ��ǰ���
			while (queens[i - 1] == n - 1){	//�����һ�����ƶ�һ��λ��
				queens[--i] = 0;			//����������һ�����
			}
			queens[--i]++;
		}
#ifdef _DEBUG_
		printResult(chs);
		system("pause");
#endif
	}
}

/*
�������ƣ�createChessBoard
����������������ʼ������
����ֵ������еĻ�������ʼ���õ�����
�������������(��ѡ)����ģsize
*/

CheesBoard createCheesBoard(int size) {
	CheesBoard cheesBoard = (CheesBoard)malloc(sizeof(struct _chessBoard));
	cheesBoard->end = 0;
	cheesBoard->count = 0;
	cheesBoard->size = size;
	cheesBoard->queens = createQueens(size);
	return cheesBoard;
}

/*
�������ƣ�createQueens
����������������������ʼ������
����ֵ������еĻ����������õ�����
�������������(��ѡ)���ʺ�����n
*/

Queens createQueens(int n) {
	int i;
	Queens queens = (Queens)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++) queens[i] = 0;
	return queens;
}

/*
�������ƣ�beAttacked
���������������жϵ�n���Ƿ񱻹���
����ֵ������еĻ������������������1����֮����0
�������������(��ѡ)�����̱����Լ�Ҫ�жϵĻʺ�λ��
*/

int beAttacked(Queens queens, int n) {
	int i = 0;
	int ret = 0;
	for (i = 0; i < n; i++) {
		if (isSameColumn(queens, i, n) || isSameMainDiagonal(queens, i, n)
			|| isSameDiagonal(queens, i, n)) {
			ret = 1;
			break;
		}
	}
	return ret;
}

/*
�������ƣ�isSameColumn
������������������Ƿ�ͬ��
����ֵ������еĻ�����ͬ�з���1�����򷵻�0
�������������(��ѡ)���ʺ������Լ�Ҫ�жϵ������ʺ�
*/

int isSameColumn(Queens queens, int queen1, int queen2) {
	return queens[queen1] == queens[queen2];
}

/*
�������ƣ�isSameMainDiagonal
������������������Ƿ�ͬ���Խ���
����ֵ������еĻ�����ͬ���Խ��߷���1�����򷵻�0
�������������(��ѡ)���ʺ������Լ�Ҫ�жϵ������ʺ�
*/

int isSameMainDiagonal(Queens queens, int queen1, int queen2) {
	return queen2 - queen1 == queens[queen2] - queens[queen1];
}

/*
�������ƣ�isSameDiagonal
������������������Ƿ�ͬ���Խ���
����ֵ������еĻ�����ͬ���Խ��߷���1�����򷵻�0
�������������(��ѡ)���ʺ������Լ�Ҫ�жϵ������ʺ�
*/
int isSameDiagonal(Queens queens, int queen1, int queen2) {
	return queen1 + queens[queen1] == queen2 + queens[queen2];
}

//��ӡ��ǰ���̽��
void printResult(CheesBoard chs) {
	int i = 0;
	int j = 0;
	system("cls");
	printf("\n-----------------\n");
	for (i = 0; i < chs->size; i++) {
		for (j = 0; j < chs->size; j++) {
			if (chs->queens[i] == j)printf(" *");
			else printf(" -");
		}
		printf("\n");
	}
	printf("-----------------\n");
	printf(" count = %d\n", chs->count);
#ifdef _DEBUG_
	Sleep(30);
#else
	Sleep(100);
#endif
}
