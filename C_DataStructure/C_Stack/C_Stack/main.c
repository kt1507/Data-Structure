#include <stdio.h>

#define SIZE 5

char stack[SIZE];	// ������ ���� �迭
int top = -1;	// �� ���� ���Ҹ� ��Ÿ�� top����, �⺻���� -1

int isFull() { // ������ ��ȭ �������� �˻��ϴ� �Լ�
	if (top >= SIZE - 1) {	//top�� �ִ� ũ��� ���ų� Ŭ ���(SIZE - 1�� ������ �迭�� 0�� index���� �����ϱ� ����)
		printf("Error : Stack is Full.\n");
		return 1; // return true
	}
	return 0; // return false
}

int isEmpty() { // ������ ���� �������� �˻��ϴ� �Լ�
	if (top == -1) { // top�� -1�� ��� stack�� �� ����
		printf("Error : Stack is empty\n");
		return 1; // return true
	}
	return 0; // return false
}

void push(data) { // ���ÿ� ���Ҹ� �����ϴ� �Լ�
	if (!isFull()) { // ������ ��ȭ �������� üũ
		top++; // top�� 1����
		stack[top] = data; // �ش� ������ data ����
	}
}

char pop() { // ���ÿ� ���Ҹ� �����ϴ� �Լ�. ��ȯ���� Stack �迭 �ڷ����� �°� ����
	if (!isEmpty()) { // ������ ����ִ��� üũ
		char temp = stack[top]; // top ���Ҹ� �ӽ� ���� temp�� ����
		top--; // top ���� 1����
		return temp; // temp ��ȯ
	}
}

char peek() { // ������ �� ���� ���Ҹ� ��ȯ�ϴ� �Լ�
	if (!isEmpty()) { // ������ ����ִ��� üũ
		return stack[top]; // ������ �� �� �� ��ȯ
	}
}

void printStack() { // ������ ��� ���Ҹ� ����ϴ� �Լ�
	if (!isEmpty()) { // ������ ����ִ��� üũ
		for (int i = 0; i <= top; i++) {
			printf("%c ", stack[i]);
		}
		printf("\n");
	}
}

int main() {
	printf("printStack()\n"); // ���� ��ü ���
	printStack(); // ���� ��������̹Ƿ� ���� �߻�

	printf("\npush('A')\n"); // A ����
	push('A');
	printf("push('B')\n"); // B ����
	push('B');
	printf("push('C')\n"); // C ����
	push('C');

	printf("\nprintStack()\n"); // ���� ��ü ���
	printStack();

	printf("\npop()\n");
	pop(); // ���� �ϳ� ����

	printf("\npush('D')\n"); // D ����
	push('D');
	printf("push('E')\n"); // E ����
	push('E');
	printf("push('F')\n"); // F ����
	push('F');
	printf("push('G')\n"); // G ����
	push('G');

	printf("\nprintStack()\n"); // ���� ��ü ���
	printStack();

	printf("\npop()\n");
	pop(); // ���� �ϳ� ����
	printf("pop()\n");
	pop(); // ���� �ϳ� ����

	printf("\nprintStack()\n"); // ���� ��ü ���
	printStack();

	return 0;
}