#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { //ť ����ü
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}Circular_Queue;

void init(Circular_Queue* q) { //ť�� �ʱ�ȭ
	q->front = 0;
	q->rear = 0;
}

void queue_print(Circular_Queue* q) { //ť ����Ʈ �ϴ� �Լ�
	int i;
	for (i = 0; i < MAX_QUEUE_SIZE; i++) {
		if (i <= q->front || i > q->rear) {
			printf("   | ");
		}
		else {
			printf("%d | ", q->data[i]);
		}
	}
	printf("\n");
}

int is_empty(Circular_Queue* q) { //ť�� ����°� üũ
	return (q->front == q->rear); //front�� rear�� ��ġ ���� ������ ť�� �����
}

int is_full(Circular_Queue* q) { //ť�� ���� á�°� üũ
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //rear�� ��ġ ���� 1�� ���� ���� front�� ������ ť�� ���� ��(����ť�̱� ������ rear�� ���� ��� Ŀ���Ƿ� ť�� ������ ������ ���� �������� ��)
}

void enqueue(Circular_Queue* q, element item) { //��� �߰�
	if (is_full(q)) { //ť�� ���� á����
		fprintf(stderr, "Queue Full\n"); //���� ���
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //���� rear�� ��ġ ���� ���� rear�� ��ġ ������ ����
	q->data[q->rear] = item; //ť ������ �迭�� rear��ġ�� item�� �Է�
}

element dequeue(Circular_Queue* q) { //��� ����
	if (is_empty(q)) { //ť�� �������
		fprintf(stderr, "Queue Empty\n"); //���� ���
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //���� front ��ġ ���� ���� front ��ġ ������ ����
	return q->data[q->front]; //ť ������ �迭�� front��ġ�� ���� ��ȯ
}

int main(void) {

	int item;
	Circular_Queue q;

	init(&q);

	do {
		scanf("%d", &item);
		if (item == -1) {
			break;
		}
		enqueue(&q, item);
	} while (1);

	while (!is_empty(&q)) {
		item = dequeue(&q);
		printf("%d ", item);
	}
	printf("\n");

	return 0;
}