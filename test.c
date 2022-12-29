#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    size_t top;
    char arr[255];
} stack;

stack init_stack(char array[]){
    stack s = {
        .top = strlen(array),
    };
    strcpy(s.arr, array);
    return s;
}

void push(stack *s, char label){
    s->arr[s->top++] = label;
}

char pop(stack *s){
    return s->arr[--s->top];
}

int main(){
    stack stacks[2] = {
        init_stack("HELLO"),
        init_stack("WORLD"),
    };

    printf("%s\n", stacks[0].arr);

    push(&stacks[0], '!');
    printf("%s\n", stacks[0].arr);
    printf("%s\n", stacks[1].arr);

    push(&stacks[0], '6');
    printf("%s\n", stacks[0].arr);


    printf("%c\n", pop(&stacks[0]));
    printf("%c\n", pop(&stacks[0]));
    printf("%c\n", pop(&stacks[0]));

    return 0;
}
