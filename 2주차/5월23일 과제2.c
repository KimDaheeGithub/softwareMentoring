#include <stdio.h>
#include <stdlib.h>

void addSize(int **input, int size);

void main() {
	// �ø� �迭 ũ��
	int size = 3;
	int cnt = 1;

	// int �迭 �����Ҵ� (size * cnt) ũ�⸸ŭ
	int *input = (int *)malloc(sizeof(int) * size * cnt);

	// ���ڸ� �Է¹���
	// (while ������ ���ѷ����� ���Ƶ� ������
	// ���� ī��Ʈ�ϴ� ���� ���� �� �ٽ� �����ְ� �ϴ� ���� �����ϱ� ���ؼ� for ���)
	for (int i = 0; ; i++) {
		printf("���ڸ� �Է��ϼ���> ");
		scanf_s("%d", &input[i], sizeof(int));

		// ���� -1�� �Է¹޴� ��� ���� �Է��� ��(break)
		if (input[i] == -1) break;

		// ���� �迭�� ��� ä��� �Ǹ� �迭�� ũ�⸦ �ø��� �Լ� addSize ����
		if (i + 1 == (size*cnt)) {
			cnt++;
			// �Ҵ��ų �迭�� input �� �ּҿ� �Ҵ��� ����� ����
			addSize(&input, (size*cnt));
		}
	}

	printf("\n<input �迭 ��� ��>\n");
	// ���ݱ��� �Է¹��� ���� ���(-1�� ����ϱ� �Ⱦ���.)
	for (int i = 0; input[i] != -1; i++) {
		printf("input[%d]> %d\n", i, input[i]);
	}

	system("pause");
}

// �迭 ũ�⸦ �ø��� �Լ�
// input �迭�� �����ͷ� �޾ƿ´�(�̹� malloc���� ���� �����Ͱ� ����Ǿ����Ƿ� ���������ͷ� �޾ƿ�)
void addSize(int **input, int size) {
	// �ӽ� �迭 �Ҵ�(������� �Ķ���ͷ� ���� size ��ŭ)
	int *temp = (int *)malloc(sizeof(int) * size);

	// �迭 �� �Űܴ��
	for (int j = 0; j < size; j++) {
		temp[j] = (*input)[j];
	}

	// ������ �Ҵ� �� input �迭�� ����(?)�ϰ�
	free(*input);
	// ���� ũ�Ⱑ �þ �迭�� �޴´�.
	*input = temp;

	// �ӽ÷� �Ҵ� �� �迭�� �����ؾ��ϴ°ɱ�..??
	// ���� ����ڰ� ���Ƿ� ���� �Լ�(������ ��� addSize)���� ���� �� ��������
	// �Լ��� ���� �� ���ŵǴ�?? �ɷ� �����ϴµ� malloc���� ���� �����Ҵ� ���� �����鵵
	// heap �������� ��������?? ��� free(temp) �غôµ� �������� �ϴµ�
	// ������ڸ� �Լ��� ����Ǹ鼭 ������ϱ� ���� �Լ����� �����Ҵ� �� ������ free() ��ų �ʿ䰡 ����??
}