#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int items[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return (q->rear == -1 && q->front == -1);
}

int isFull(struct Queue* q) {
    return q->rear == MAX_SIZE - 1;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = q->rear = 0;
    } else {
        q->rear++;
    }
    q->items[q->rear] = value;
    printf("%d enqueued to the queue\n", value);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    int dequeuedItem = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return dequeuedItem;
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));

    return 0;
}
