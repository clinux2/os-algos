#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node definition
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Queue definition
typedef struct {
    Node* front;
    Node* rear;
} Queue;

// Function declarations
void initQueue(Queue* q);
bool isEmpty(Queue* q);
void enqueue(Queue* q, int value);
int dequeue(Queue* q);
int peek(Queue* q);
void freeQueue(Queue* q);


#define TIME_LIMIT 1000

bool isin_cycle(int time, int start, int q)
{
	if (time - start < q) return true;
	return false
}

int* rr(int n, int q, int* ats, int* bts)
{
	int time = -1, start = 0;
	int* comp_time = (int*)malloc(sizeof(int) * n);
	
	Queue q;
	initQueue(&q);
	int running_process;
	while (time <= TIME_LIMIT)
	{
		time++;
		
		//If at this time, processes arrive, queue up all
		
		//If is start of time quantum, dequeue
		
		//If is in time quantum, the running process done soon(reach 0), start the next cycle
		
		//If is end of time quantum, so if the process still undone, modify burst time, and queue up it
	}	
}


int main() {
	

	return 0;
}










// Function definitions
void initQueue(Queue* q) {
    q->front = NULL;
    q->rear = NULL;
}

bool isEmpty(Queue* q) {
    return q->front == NULL;
}

void enqueue(Queue* q, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }

    newNode->data = value;
    newNode->next = NULL;

    if (isEmpty(q)) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }

    printf("Enqueued: %d\n", value);
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue Underflow\n");
        return -1;
    }

    Node* temp = q->front;
    int value = temp->data;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return value;
}

int peek(Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return -1;
    }
    return q->front->data;
}

void freeQueue(Queue* q) {
    while (!isEmpty(q)) {
        dequeue(q);
    }
}

