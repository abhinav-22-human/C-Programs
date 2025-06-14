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
        printf("Stack overflow\n");
    else {
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(struct stack *ptr) {
    if (isEmpty(ptr)) {
        printf("Stack underflow\n");
        return 1;
    } else {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int paranthesisMatch(char *exp) {
    struct stack *sp = (struct stack*)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->arr = (char*)malloc(sp->size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') push(sp, '(');
        else if (exp[i] == ')') {
            if (isEmpty(sp)) return 0;
            pop(sp);
        }
    }

    return isEmpty(sp);
}

int main() {
    char *exp = "((8)(*__$$9))";
    if (paranthesisMatch(exp)) 
        printf("The parentheses are matching\n");
    else 
        printf("Parentheses are not matching\n");
    return 0;
}