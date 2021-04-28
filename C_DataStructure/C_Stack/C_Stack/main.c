#include <stdio.h>

#define SIZE 5

char stack[SIZE];	// 스택을 위한 배열
int top = -1;	// 맨 위의 원소를 나타낼 top변수, 기본값은 -1

int isFull() { // 스택이 포화 상태인지 검사하는 함수
	if (top >= SIZE - 1) {	//top이 최대 크기와 같거나 클 경우(SIZE - 1인 이유는 배열이 0번 index부터 시작하기 때문)
		printf("Error : Stack is Full.\n");
		return 1; // return true
	}
	return 0; // return false
}

int isEmpty() { // 스택이 공백 상태인지 검사하는 함수
	if (top == -1) { // top이 -1인 경우 stack은 빈 상태
		printf("Error : Stack is empty\n");
		return 1; // return true
	}
	return 0; // return false
}

void push(data) { // 스택에 원소를 삽입하는 함수
	if (!isFull()) { // 스택이 포화 상태인지 체크
		top++; // top을 1증가
		stack[top] = data; // 해당 공간에 data 삽입
	}
}

char pop() { // 스택에 원소를 제거하는 함수. 반환형은 Stack 배열 자료형에 맞게 수정
	if (!isEmpty()) { // 스택이 비어있는지 체크
		char temp = stack[top]; // top 원소를 임시 변수 temp에 저장
		top--; // top 변수 1감소
		return temp; // temp 반환
	}
}

char peek() { // 스택의 맨 위의 원소를 반환하는 함수
	if (!isEmpty()) { // 스택이 비어있는지 체크
		return stack[top]; // 스택의 맨 위 값 반환
	}
}

void printStack() { // 스택의 모든 원소를 출력하는 함수
	if (!isEmpty()) { // 스택이 비어있는지 체크
		for (int i = 0; i <= top; i++) {
			printf("%c ", stack[i]);
		}
		printf("\n");
	}
}

int main() {
	printf("printStack()\n"); // 스택 전체 출력
	printStack(); // 스택 공백상태이므로 에러 발생

	printf("\npush('A')\n"); // A 삽입
	push('A');
	printf("push('B')\n"); // B 삽입
	push('B');
	printf("push('C')\n"); // C 삽입
	push('C');

	printf("\nprintStack()\n"); // 스택 전체 출력
	printStack();

	printf("\npop()\n");
	pop(); // 원소 하나 제거

	printf("\npush('D')\n"); // D 삽입
	push('D');
	printf("push('E')\n"); // E 삽입
	push('E');
	printf("push('F')\n"); // F 삽입
	push('F');
	printf("push('G')\n"); // G 삽입
	push('G');

	printf("\nprintStack()\n"); // 스택 전체 출력
	printStack();

	printf("\npop()\n");
	pop(); // 원소 하나 제거
	printf("pop()\n");
	pop(); // 원소 하나 제거

	printf("\nprintStack()\n"); // 스택 전체 출력
	printStack();

	return 0;
}