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

int main(){
    stack s = init_stack("HELLO");
    stack t = init_stack("HELLO");

    printf("%s\n", s.arr);

    push(&s, '!');
    printf("%s\n", s.arr);
    printf("%s\n", t.arr);

    push(&s, '6');
    printf("%s\n", s.arr);

    return 0;
}
