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

void init(Circular_Queue* q) { //큐를 초기화
	q->front = 0;
	q->rear = 0;
}

void queue_print(Circular_Queue* q) { //큐 프린트 하는 함수
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

int is_empty(Circular_Queue* q) { //큐가 비었는가 체크
	return (q->front == q->rear); //front와 rear의 위치 값이 같으면 큐는 비었음
}

int is_full(Circular_Queue* q) { //큐가 가득 찼는가 체크
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front); //rear의 위치 값에 1을 더한 값이 front와 같으면 큐는 가득 참(원형큐이기 때문에 rear의 값이 계속 커지므로 큐의 사이즈 값으로 나눈 나머지와 비교)
}

void enqueue(Circular_Queue* q, element item) { //요소 추가
	if (is_full(q)) { //큐가 가득 찼으면
		fprintf(stderr, "Queue Full\n"); //에러 출력
		return;
	}
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE; //현재 rear의 위치 값에 다음 rear의 위치 값으로 변경
	q->data[q->rear] = item; //큐 데이터 배열의 rear위치에 item을 입력
}

element dequeue(Circular_Queue* q) { //요소 제거
	if (is_empty(q)) { //큐가 비었으면
		fprintf(stderr, "Queue Empty\n"); //에러 출력
		exit(1);
	}
	q->front = (q->front + 1) % MAX_QUEUE_SIZE; //현재 front 위치 값에 다음 front 위치 값으로 변경
	return q->data[q->front]; //큐 데이터 배열의 front위치의 값을 반환
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