#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

struct Queue {
    int items[MAX_SIZE];
    int front, rear;
    unsigned int size;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
    q->size = 0;
}

int isEmpty(struct Queue* q) {
    return q->size == 0;
}

int isFull(struct Queue* q) {
    return q->size == MAX_SIZE;
}

void enqueue(struct Queue* q, int value) {
    if (isFull(q)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmpty(q)) {
        q->front = 0;
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->items[q->rear] = value;
    q->size++;
    printf("%d enqueued to the queue\n", value);
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        exit(1);
    }
    int dequeuedItem = q->items[q->front];
    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
    }
    q->size--;
    return dequeuedItem;
}

int main() {
    struct Queue q;
    initQueue(&q);

    enqueue(&q, 1);
    enqueue(&q, 2);
    enqueue(&q, 3);
    enqueue(&q, 4);
    enqueue(&q, 5);

    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));

    enqueue(&q, 6);
    enqueue(&q, 7);

    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));
    printf("%d dequeued from the queue\n", dequeue(&q));

    return 0;
}
