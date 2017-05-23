#include <stdio.h>
#include <stdlib.h>

void addSize(int **input, int size);

void main() {
	// 늘릴 배열 크기
	int size = 3;
	int cnt = 1;

	// int 배열 동적할당 (size * cnt) 크기만큼
	int *input = (int *)malloc(sizeof(int) * size * cnt);

	// 숫자를 입력받음
	// (while 문으로 무한루프를 돌아도 되지만
	// 따로 카운트하는 변수 선언 후 다시 더해주고 하는 과정 생략하기 위해서 for 사용)
	for (int i = 0; ; i++) {
		printf("숫자를 입력하세요> ");
		scanf_s("%d", &input[i], sizeof(int));

		// 만약 -1을 입력받는 경우 숫자 입력은 끝(break)
		if (input[i] == -1) break;

		// 만약 배열을 모두 채우게 되면 배열의 크기를 늘리는 함수 addSize 실행
		if (i + 1 == (size*cnt)) {
			cnt++;
			// 할당시킬 배열인 input 의 주소와 할당할 사이즈를 전달
			addSize(&input, (size*cnt));
		}
	}

	printf("\n<input 배열 결과 값>\n");
	// 지금까지 입력받은 값을 출력(-1은 출력하기 싫었당.)
	for (int i = 0; input[i] != -1; i++) {
		printf("input[%d]> %d\n", i, input[i]);
	}

	system("pause");
}

// 배열 크기를 늘리는 함수
// input 배열을 포인터로 받아온다(이미 malloc으로 인해 포인터가 선언되었으므로 이중포인터로 받아옴)
void addSize(int **input, int size) {
	// 임시 배열 할당(사이즈는 파라메터로 받은 size 만큼)
	int *temp = (int *)malloc(sizeof(int) * size);

	// 배열 값 옮겨담기
	for (int j = 0; j < size; j++) {
		temp[j] = (*input)[j];
	}

	// 이전에 할당 된 input 배열을 제거(?)하고
	free(*input);
	// 새로 크기가 늘어난 배열을 받는다.
	*input = temp;

	// 임시로 할당 된 배열도 삭제해야하는걸까..??
	// 만약 사용자가 임의로 만든 함수(지금의 경우 addSize)에서 선언 된 변수들은
	// 함수가 끝난 후 제거되는?? 걸로 생각하는데 malloc으로 인해 동적할당 받은 변수들도
	// heap 영역에서 사라질까요?? 사실 free(temp) 해봤는데 오류나긴 하는데
	// 요약하자면 함수가 종료되면서 사라지니까 굳이 함수에서 동적할당 된 변수를 free() 시킬 필요가 없다??
}