#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { // ť�� ������ ���� �� ���ϱ� ���� ����ü �ۼ�(ť ���� front�� rear�����ؾ��ϴ�)
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}Queue;

void init(Queue* q) { //ť�� �ʱ�ȭ. �����Կ����� rear�� front�� -1�� �ʱ�ȭ
	q->rear = -1;
	q->front = -1;
}

void queue_print(Queue* q) {
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

int is_full(Queue* q) { //ť�� ����á�°� üũ
	if (q->rear == MAX_QUEUE_SIZE - 1) { // rear�� ��ġ�� ť�� �ƽ� ������� ������
		return 1;
	}
	else {
		return 0;
	}
}

int is_empty(Queue* q) { //ť�� ����°� üũ
	if (q->front == q->rear) { //ť�� front�� rear�� ��ġ�� ������
		return 1;
	}
	else {
		return 0;
	}
}

void enqueue(Queue* q, int item) { //ť�� �ڿ� ��� �߰�
	if (is_full(q)) { // ť�� ���� á����
		fprintf(stderr, "FULL!\n"); //����
		exit(1); //�Լ� Ż��
	}
	q->data[++(q->rear)] = item; //rear�� ���� 1������Ű�� ť data�迭�� rear��ġ�� item�� �߰�
}

int dequeue(Queue* q) { //ť�� �տ� �ִ� ��Ҹ� ��ȯ �� ����
	if (is_empty(q)) { //ť�� �������
		fprintf(stderr, "Empty!\n"); //����
		return -1; //���� Ż��
	}
	int item = q->data[++(q->front)]; //front�� ���� 1������Ű�� ť data�迭�� front��ġ�� ���� item�� �ְ� ���
	return item; //item ����
}

int main(void) {

	int item;
	Queue q;

	init(&q);

	enqueue(&q, 43);
	queue_print(&q);

	enqueue(&q, 21);
	queue_print(&q);
	
	enqueue(&q, 77);
	queue_print(&q);

	item = dequeue(&q);
	queue_print(&q);

	item = dequeue(&q);
	queue_print(&q);

	item = dequeue(&q);
	queue_print(&q);

	enqueue(&q, 95);
	queue_print(&q);

	enqueue(&q, 24);
	queue_print(&q);

	enqueue(&q, 15);
	queue_print(&q);

	enqueue(&q, 67);
	queue_print(&q);

	return 0;
}