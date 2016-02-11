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
�ļ����ƣ�calculator.c
��Ŀ���ƣ�DSExperiment1
�����ߣ�������
����ʱ�䣺201.9.12
����޸�ʱ�䣺2015.9.17
���ܣ��������������ļ�
�ļ��еĺ������ƺͼ򵥹���������������
�ļ��ж����ȫ�ֱ����ͼ򵥹���������������
�ļ����õ������������ȫ�ֱ��������������
�������ļ���������ϵ��calculator.h
//*/


#include "calculator.h"

/*/
�������ƣ�calculator
����������������������ں���
����ֵ������еĻ������ɹ�����1��ʧ�ܷ���-1
���������������(��ѡ)Ҫ����ı��ʽ�ַ���������NULL��Ҫ���û�����
//*/
int calculator(char * string) {
	char* s = NULL;
	char* p = NULL;
	Stack* numbers = createStack(MAXSIZE);
	Stack* operators = createStack(MAXSIZE);
	double t;
	
	if (numbers == NULL	|| operators == NULL) {
		errorWarning("��ʼ������");
		return -1;
	}

	if (string == NULL) {
		p = s = (char*)malloc(MAXSIZE);
		if (s == NULL) {
			errorWarning("��ʼ������");
			return -1;
		}
		printf("\n��������ʽ��");
		scanf("%[^\n]%*c", s);
	} else {
		s = string;
	}

	printf("\n������ı��ʽ��:\n%s\n", s);
	s = preTreat(&s);
	//printf("preTreated\n%s\n", s);

	if (string == NULL)free(p);
	
	if (!check(s)) {
		errorWarning("�������");
		return -1;
	}

	p = s;
	while (*p != '#') {
		if (isOperator(*p)) {//����������
			if (*p == ')') {
				while (decode(seek(operators)) != '(')
					merge(numbers, operators);
				pop(operators, NULL);
				//printf("pop operator (\n");
			} else {
				if (*p != '(')
					while (canCalculate(*p, operators))//����ɼ���
						merge(numbers, operators);
				push(operators, encode(*p));
				//printf("push operator %c\n\n", *p);
			}
			p++;
		} else if (isNumber(*p)) {//�����������
			t = parseNum(&p);
			push(numbers, t);
		}
	}
	while (!isEmpty(operators))
		merge(numbers, operators);
	pop(numbers, &t);

	if (t - (int)t == 0)printf("\n����� %d\n", (int)t);
	else printf("\n����� %.5lf\n", t);

	//system("pause");
	return 1;
}


/*/
�������ƣ�check
������������������Ϸ��Լ��
��������֮ǰ��Ԥ�������������Ǿ���Ԥ����ı��ʽ�ַ���
����ֵ������еĻ�����������������1�����򷵻�0
���������������Ҫ�����ַ���
//*/
int check(char* s) {
	char* p = s;
	int t = 0;//�����ж�

	//��鿪ͷ��һλ�Ƿ�Ϊ�����
	if ((*p != '(' && isOperator(*p))||
		*p == '.')
		return 0;

	//�ս�����
	while (*p != 0 && *p != '#')p++;
	if (*p == 0 || *(p + 1) != 0)return 0;
	//ѭ���˳�������ֻ������������0����#
	//����������´����·�����*p����0����
	//������������Ͳ��ᱻִ�У����õ���ָ��Ƿ�����

	//����β�Ƿ�Ϊ�����
	p--;
	if (*p != ')' && isOperator(*p)||
		*p == '.')
		return 0;
	p = s;

	//����ƥ����
	while (*p != 0) {
		if (*p == '(')t++;
		else if (*p == ')') {
			if (--t < 0)	return 0;
		}
		p++;
	}
	if (t != 0)return 0;;
	p = s;

	//���źϷ��Լ�� )(
	while (*p != 0) {
		if (*p == ')' && *(p + 1) == '(')
			return 0;
		p++;
	}
	p = s;

	//�������������Ƿ�û������
	//��ִ�е���˵���϶����ս��
	//���ҿ�ͷ�ͽ�β���ǺϷ��ģ�û�����������
	while (*p != '#') {
		if (isOperator(*p) && *p != '('
			&& *p != ')') {
			if (!isNumber(*(p - 1))
				&& *(p - 1) != ')')
				return 0;
			if (!isNumber(*(p + 1))
				&& *(p + 1) != '(')
				return 0;
		}
		p++;
	}

	return 1;
}

/*/
�������ƣ�preTreat
�����������������ʽ�ַ���Ԥ����������Ч�ַ�������ظ���С����
��������֮ǰ��Ԥ���������д����ս��0���ַ���
����ֵ������еĻ������ɹ�����1��ʧ�ܷ���0
��������������������ս��0���ַ�����˫��ָ��
//*/
char* preTreat(char** s) {
	char* ps = *s;
	char* t1 = (char*)malloc(MAXSIZE);
	char* t2 = (char*)malloc(MAXSIZE);
	char* pt1 = t1;
	char* pt2 = t2;

	while (*ps != 0) {
		if ((isOperator(*ps) || isNumber(*ps)
			|| *ps == '.' || *ps == '#')) {
			*pt1++ = *ps;
		}
		ps++;
	}
	*pt1 = 0;
	pt1 = t1;

	while (*pt1 != 0) {
		if (*pt1 == '.' && *(pt1 + 1) == '.')pt1++;
		else *pt2++ = *pt1++;
	}
	*pt2 = 0;
	free(t1);
	*s = t2;
	return t2;
}


/*/
�������ƣ�calcu
��������������Ĭ�ϴ�����ں���NULL���������û��ֶ�������ʽ
��������֮ǰ��Ԥ����������
����ֵ������еĻ������ɹ�����1��ʧ�ܷ���-1
//*/
int calcu() {
	return calculator(NULL);
}


/*/
�������ƣ�errorWarning
�����������������󾯸�
��������֮ǰ��Ԥ����������
����ֵ������еĻ�������
������������������󾯸����
//*/
void errorWarning(char* warning) {
	printf("%s\n\n", warning);
	//system("pause");
}


/*/
�������ƣ�isOperator
���������������ж��ַ��Ƿ�Ϊ�Ϸ�������
��������֮ǰ��Ԥ����������
����ֵ������еĻ������Ƿ���1�����Ƿ���0
���������������Ҫ�жϵ��ַ�c
//*/
int isOperator(char c) {
	return c == '+' || c == '-' || c == '*'
		|| c == '/' || c == '(' || c == ')';
}


/*/
�������ƣ�isNumber
���������������ж��ַ��Ƿ�Ϊ����
��������֮ǰ��Ԥ����������
����ֵ������еĻ������Ƿ���1�����Ƿ���0
���������������Ҫ�жϵ��ַ�c
//*/
int isNumber(char c) {
	return c >= '0' && c <= '9';
}

/*/
�������ƣ�encode
�����������������������룬������ջ
��������֮ǰ��Ԥ���������ַ�c���뾭���Ϸ��Լ��
����ֵ������еĻ�����������
���������������Ҫ������ַ�c
//*/
double encode(char c) {
	double t;
	switch (c) {
	case '+':t = 0; break;
	case '-':t = 1; break;
	case '*':t = 2; break;
	case '/':t = 3; break;
	case '(':t = 4; break;
	case ')':t = 5; break;
	}
	return t;
}


/*/
�������ƣ�decode
�����������������������룬�����ջ��Ƚ�
��������֮ǰ��Ԥ���������ַ�c�����Ǿ��������ֵ
����ֵ������еĻ�����������
���������������Ҫ������ַ�c
//*/
char decode(double d) {
	char c;
	switch ((int)d) {
	case 0:c = '+'; break;
	case 1:c = '-'; break;
	case 2:c = '*'; break;
	case 3:c = '/'; break;
	case 4:c = '('; break;
	case 5:c = ')'; break;
	}
	return c;
}


/*/
�������ƣ�priority
���������������ж��������ȼ�
��������֮ǰ��Ԥ���������ַ�c�����Ǿ����Ϸ��Լ��
����ֵ������еĻ��������ȼ�
���������������Ҫ�жϵ������c
//*/
int priority(char c) {
	int t;
	switch (c) {
	case '(':t = 0; break;
	case '+':
	case '-':t = 1; break;
	case '*':
	case '/':t = 2; break;
	}
	return t;
}

/*/
�������ƣ�merge
������������������һ������
��������֮ǰ��Ԥ�����������Խ���һ�κϷ�����
����ֵ������еĻ�������
���������������������ջ�Ͳ�����ջ
//*/
void merge(Stack* numbers, Stack* operators) {
	double num1, num2, t;
	//printf("\n");
	pop(operators, &t);
	//printf("pop operator %c\n\n", decode(t));
	pop(numbers, &num2);//����Ҫע�⣬��pop��������num2
	pop(numbers, &num1);//���д���˼����ͳ����ͻ����
	t = calculate(decode(t), num1, num2);
	push(numbers, t);
}

/*/
�������ƣ�calculate
������������������һ��ʵ������
��������֮ǰ��Ԥ������������������Ϸ����
����ֵ������еĻ�����������
���������������2���������Ͳ�����
//*/
double calculate(char operate, double num1, double num2) {
	double t;
	switch (operate) {
	case '+':t = num1 + num2; break;
	case '-':t = num1 - num2; break;
	case '*':t = num1 * num2; break;
	case '/':
		if (num2 != 0)t = num1 / num2;
		else errorWarning("��������Ϊ0");
		break;
	}
	return t;
}


/*/
�������ƣ�parseNum
�����������������ַ�������һ��������
��������֮ǰ��Ԥ���������ַ�������Ԥ����ͺϷ��Լ��
����ֵ������еĻ������������
���������������Ҫʶ����ַ���˫��ָ��
//*/
double parseNum(char** s) {
	double t = 0;
	sscanf(*s, "%lf", &t);
	//��������ж��С���㣬��Ϊ�û�������ǶԵ�
	//ֻ��һ���������С����������ֲ����Զ�����
	while (isNumber(**s) || **s == '.')(*s)++;
	return t;
}

/*/
�������ƣ�canCalculate
���������������뵱ǰջ��Ԫ�رȽ����ȼ�
��������֮ǰ��Ԥ��������c�ǺϷ������
����ֵ������еĻ������ɽ��кϷ����㷵��1�����򷵻�0
���������������Ҫ��ջ��������������ջ
//*/
int canCalculate(char c, Stack* operators) {
	return !isEmpty(operators) &&
		priority(c) <= priority(decode(seek(operators)));
}