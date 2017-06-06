#include <stdio.h>
#include <stdlib.h>

void main() {
	// 1차 배열 개수; 행
	int row;

	// 출력할 행 개수를 입력한다.
	printf("할당할 행의 크기를 입력하세요> ");
	scanf_s("%d", &row, sizeof(int));

	// 최종적으로 생성 될 배열은 2차배열이므로,
	// 2차배열 요소가 * 을 가진다면 외곽의 1차배열 요소는 ** 두개로 malloc
	int **arr = (int **)malloc(sizeof(int)*row);

	// 사용자가 원하는 행의 개수만큼 2차 배열을 동적할당
	for (int i = 0; i < row; i++) {
		// 2차 배열 동적할당 개수는 0번부터 1개씩이므로 row + 1
		arr[i] = (int *)malloc(sizeof(int)*(row + 1));

		// 값 대입
		for (int j = 0; j <= i; j++) {
			arr[i][j] = 0;
		}
	}

	// 값 출력
	for (int i = 0; i < row; i++) {
		printf("arr[%d]> ", i);
		for (int j = 0; j <= i; j++) {
			printf("%d", arr[i][j]);
		}
		printf("\n");
	}

	system("pause");
}