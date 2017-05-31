#include <stdio.h>
#include <stdlib.h>

//제곱을 계산하는 함수 square
int square(int n, int *nPtr);

int main() {
	/*call by value 와 call by reference 의 값을 비교하기 위해
	두가지 int 변수를 선언했다.*/
	int n1, n2;
	printf("Enter the number to be calculated by square> ");
	scanf("%d", &n1);

	n2 = n1;

	/*제곱 계산의 비교를 위해 하나는 value 로, 하나는 주소를 보내 포인터로 받을 예정*/
	square(n1, &n2);

	/*그러나 정작 main 함수에서는 call by value로 보낸 n1 은 값만 받을 뿐 궁극적으로 n1에는 영향이 없으므로
	n1은 초기 값, call by reference로 보낸 n2는 주소를 받아 n2의 내용 자체를 바꿔버렸으므로
	제곱 값으로 출력된다.*/
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

	/*square함수 내에서는 제곱을 계산 했을 때 두 변수 모두 제곱 값이 잘 나올것*/
	printf("< In square function >\n");
	printf("call by value's n> %d\n", n);
	printf("call by reference's n> %d\n", *nPtr);

	return 0;
}