#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct { // 큐를 여러개 만들 때 편리하기 위해 구조체 작성(큐 마다 front와 rear구분해야하니)
	int front;
	int rear;
	element data[MAX_QUEUE_SIZE];
}Queue;

void init(Queue* q) { //큐를 초기화. 선형규에서는 rear와 front를 -1로 초기화
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

int is_full(Queue* q) { //큐가 가득찼는가 체크
	if (q->rear == MAX_QUEUE_SIZE - 1) { // rear의 위치가 큐의 맥스 사이즈와 같은가
		return 1;
	}
	else {
		return 0;
	}
}

int is_empty(Queue* q) { //큐가 비었는가 체크
	if (q->front == q->rear) { //큐의 front와 rear의 위치가 같은가
		return 1;
	}
	else {
		return 0;
	}
}

void enqueue(Queue* q, int item) { //큐의 뒤에 요소 추가
	if (is_full(q)) { // 큐가 가득 찼으면
		fprintf(stderr, "FULL!\n"); //에러
		exit(1); //함수 탈출
	}
	q->data[++(q->rear)] = item; //rear의 값을 1증가시키고 큐 data배열의 rear위치에 item을 추가
}

int dequeue(Queue* q) { //큐의 앞에 있는 요소를 반환 후 삭제
	if (is_empty(q)) { //큐가 비었으면
		fprintf(stderr, "Empty!\n"); //에러
		return -1; //에러 탈출
	}
	int item = q->data[++(q->front)]; //front의 값을 1증가시키고 큐 data배열의 front위치의 값을 item에 넣고 출력
	return item; //item 리턴
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