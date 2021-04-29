#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { //큐 구조체
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}Circular_Queue;

void init(Circular_Queue* q) {
	q->front = 0;
	q->rear = 0;
}

void queue_print(Circular_Queue* q) {
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

int is_empty(Circular_Queue* q) {
	return (q->front == q->rear);
}

int is_full(Circular_Queue* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(Circular_Queue* q, element item) {
	if (is_full(q)) {
		fprintf(stderr, "Queue Full\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(Circular_Queue* q) {
	if (is_empty(q)) {
		fprintf(stderr, "Queue Empty\n");
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
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