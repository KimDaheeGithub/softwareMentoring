#include <stdio.h>
#include <stdlib.h>

void main() {
	// 1�� �迭 ����; ��
	int row;

	// ����� �� ������ �Է��Ѵ�.
	printf("�Ҵ��� ���� ũ�⸦ �Է��ϼ���> ");
	scanf_s("%d", &row, sizeof(int));

	// ���������� ���� �� �迭�� 2���迭�̹Ƿ�,
	// 2���迭 ��Ұ� * �� �����ٸ� �ܰ��� 1���迭 ��Ҵ� ** �ΰ��� malloc
	int **arr = (int **)malloc(sizeof(int)*row);

	// ����ڰ� ���ϴ� ���� ������ŭ 2�� �迭�� �����Ҵ�
	for (int i = 0; i < row; i++) {
		// 2�� �迭 �����Ҵ� ������ 0������ 1�����̹Ƿ� row + 1
		arr[i] = (int *)malloc(sizeof(int)*(row + 1));

		// �� ����
		for (int j = 0; j <= i; j++) {
			arr[i][j] = 0;
		}
	}

	// �� ���
	for (int i = 0; i < row; i++) {
		printf("arr[%d]> ", i);
		for (int j = 0; j <= i; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	system("pause");
}