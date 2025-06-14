#include <stdio.h>
#include <stdlib.h>

struct stack {
    int size;
    int top;
    char *arr;
};

int isEmpty(struct stack *ptr) {
    return ptr->top == -1;
}

int isFull(struct stack *ptr) {
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char val) {
    if (isFull(ptr)) 
        printf("Stack Overflow! Cannot push %c to the stack\n", val);
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack Underflow! Cannot pop from the stack\n");
        return -1;
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char stackTop(struct stack *sp) {
    return sp->arr[sp->top];
}

int match(char a, char b) {
    return (a == '{' && b == '}') || (a == '(' && b == ')') || (a == '[' && b == ']');
}

int parenthesisMatch(char *exp) {
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char *)malloc(sp->size * sizeof(char));
    char popped_ch;

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            push(sp, exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            if (isEmpty(sp)) return 0;
            popped_ch = pop(sp);
            if (!match(popped_ch, exp[i])) return 0;
        }
    }

    return isEmpty(sp);
}

int main() {
    char *exp1 = "[4-6]((8){(9-8)})";
    char *exp2 = "((8){(9-8)})";

    if (parenthesisMatch(exp1))
        printf("The parentheses are balanced\n");
    else
        printf("The parentheses are not balanced\n");

    if (parenthesisMatch(exp2))
        printf("The parentheses are matching\n");
    else
        printf("The parentheses are not matching\n");

    return 0;
}