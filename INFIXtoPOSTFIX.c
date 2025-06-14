#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
   int top;
   int size;
   char *arr;
};

int stackTop(struct stack* sp) {
    return sp->arr[sp->top];
}

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack* ptr, char val) {
    if (isFull(ptr)) 
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack* ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int precedence(char ch) {
    return (ch == '*' || ch == '/') ? 3 : (ch == '+' || ch == '-') ? 2 : 0;
}

char *InfixtoPostfix(char *infix) {
    struct stack *sp = (struct stack *) malloc(sizeof(struct stack));
    sp->size = 10;  
    sp->top = -1;
    sp->arr = (char *) malloc(sp->size * sizeof(char));
    char *postfix = (char *) malloc((strlen(infix) + 1) * sizeof(char));

    if (!sp || !sp->arr || !postfix) {
        printf("Memory allocation failed!\n");
        return NULL;
    }

    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (!isOperator(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (!isEmpty(sp) && precedence(infix[i]) <= precedence(stackTop(sp))) {
                postfix[j++] = pop(sp);
            }
            push(sp, infix[i++]);
        }
    }

    while (!isEmpty(sp)) {
        postfix[j++] = pop(sp);
    }
    postfix[j] = '\0';

    free(sp->arr);
    free(sp);
    return postfix;
}

int main() {
    char *infix = "x-y/z-k*d";
    char *postfix = InfixtoPostfix(infix);

    if (postfix) {
        printf("Postfix is: %s\n", postfix);
        free(postfix);
    }

    return 0;
}