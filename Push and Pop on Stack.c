#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Stack {
    int items[MAX_SIZE];
    int top;
};

void initStack(struct Stack* stack) {
    stack->top = -1;
}

int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

void push(struct Stack* stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->top++;
    stack->items[stack->top] = value;
    printf("Pushed %d onto the stack.\n", value);
}

int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        exit(1);
    }
    int poppedItem = stack->items[stack->top];
    stack->top--;
    return poppedItem;
}

int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Popped %d from the stack.\n", pop(&stack));
    printf("Popped %d from the stack.\n", pop(&stack));
    printf("Popped %d from the stack.\n", pop(&stack));

    return 0;
}
