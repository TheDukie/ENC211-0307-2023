#include <stdio.h>
#include <stdlib.h>

typedef int stack_data;
struct stack_rec {
    stack_data data;
    struct stack_rec *next;
};
struct stack_rec *top = NULL;

void stack_init() {
    top = NULL;
}

void stack_clear() {
    while (!stack_empty())
        stack_pop();
}

int stack_empty() {
    return top == NULL;
}

void stack_push(stack_data d) {
    struct stack_rec *temp;
    temp = (struct stack_rec *)malloc(sizeof(struct stack_rec));
    temp->data = d;
    temp->next = top;
    top = temp;
}

stack_data stack_pop() {
    stack_data d = 0;
    struct stack_rec *temp;
    if (top != NULL) {
        d = top->data;
        temp = top;
        top = top->next;
        free(temp);
    }
    return d;
}

void stack_dup() {
    if (!stack_empty()) {
        stack_data top_data = stack_pop();
        stack_push(top_data);
        stack_push(top_data);
    }
}

int stack_count() {
    int count = 0;
    struct stack_rec *current = top;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

void stack_add() {
    if (stack_count() >= 2) {
        stack_data a = stack_pop();
        stack_data b = stack_pop();
        stack_push(a + b);
    }
}

int main() {
    stack_init();
    stack_push(10);
    stack_push(20);
    stack_add();
    printf("Result: %d\n", stack_pop());
    stack_clear();
    return 0;
}
make
