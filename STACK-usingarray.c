#include<stdio.h>
#include<stdlib.h>
int main(){
    //struct stack;
    //s.size=80;
    //s.top=-1;
    //s.arr=(int*)malloc(s.size*sizeof(int));
    struct stack*s;
    s->size=80;
    s->top=-1;
    s->arr=(int*)malloc(s->size*sizeof(int));
    return 0;

}
struct stack {
    int size;
    int top;
    int *arr;
};
void isEmpty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
}
void isFull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
}