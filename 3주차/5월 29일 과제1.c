#include <stdio.h>
#include <stdlib.h>

//������ ����ϴ� �Լ� square
int square(int n, int *nPtr);

int main() {
	/*call by value �� call by reference �� ���� ���ϱ� ����
	�ΰ��� int ������ �����ߴ�.*/
	int n1, n2;
	printf("Enter the number to be calculated by square> ");
	scanf("%d", &n1);

	n2 = n1;

	/*���� ����� �񱳸� ���� �ϳ��� value ��, �ϳ��� �ּҸ� ���� �����ͷ� ���� ����*/
	square(n1, &n2);

	/*�׷��� ���� main �Լ������� call by value�� ���� n1 �� ���� ���� �� �ñ������� n1���� ������ �����Ƿ�
	n1�� �ʱ� ��, call by reference�� ���� n2�� �ּҸ� �޾� n2�� ���� ��ü�� �ٲ�������Ƿ�
	���� ������ ��µȴ�.*/
	printf("\n< In main after square function >\n");
	printf("call by value's n> %d\n", n1);
	printf("call by reference's n> %d\n", n2);

	system("PAUSE");
	return 0;
}

int square(int n, int *nPtr) {
	/*call by value*/
	n = n * n;

	/*call by reference*/
	*nPtr = *nPtr * *nPtr;

	/*square�Լ� �������� ������ ��� ���� �� �� ���� ��� ���� ���� �� ���ð�*/
	printf("< In square function >\n");
	printf("call by value's n> %d\n", n);
	printf("call by reference's n> %d\n", *nPtr);

	return 0;
}