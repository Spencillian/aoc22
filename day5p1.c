#include <endian.h>
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

//
//[M]                     [N] [Z]
//[F]             [R] [Z] [C] [C]
//[C]     [V]     [L] [N] [G] [V]
//[W]     [L]     [T] [H] [V] [F] [H]
//[T]     [T] [W] [F] [B] [P] [J] [L]
//[D] [L] [H] [J] [C] [G] [S] [R] [M]
//[L] [B] [C] [P] [S] [D] [M] [Q] [P]
//[B] [N] [J] [S] [Z] [W] [F] [W] [R]
// 1   2   3   4   5   6   7   8   9

int main(){
    FILE *fp;
    char buff[255];

    fp = fopen("day5.txt", "r");

    stack stacks[9] = {
        init_stack("BLDTWCFM"),
        init_stack("NBL"),
        init_stack("JCHTLV"),
        init_stack("SPJW"),
        init_stack("ZSCFTLR"),
        init_stack("WDGBHNZ"),
        init_stack("FMSPVGCN"),
        init_stack("WQRJFVCZ"),
        init_stack("RPMLH"),
    };

    size_t moves[3];
    while (fgets(buff, 255, fp) != NULL) {
        if (buff[0] != 'm') {
            continue;
        }

        size_t count = 0;
        for(size_t i = 0; i < strlen(buff); ++i){
            if (buff[i] >= '0' && buff[i] <= '9') {
                char num[255] = {'\0'};
                for(size_t j = 0; j < strlen(buff); ++j, ++i){
                    if (buff[i] == ' ') {
                        break;
                    }
                    num[j] = buff[i];
                }
                moves[count++] = atoi(num);
                if(buff[i] == '\0'){
                    break;
                }
            }
        }

        for(size_t i = 0; i < moves[0]; ++i){
            push(&stacks[moves[2] - 1], pop(&stacks[moves[1] - 1]));
        }

        printf("%s:%lu %lu %lu\n", buff, moves[0], moves[1], moves[2]);
    }

    fclose(fp);

    char result[255];
    for(size_t i = 0; i < 9; ++i){
        result[i] = pop(&stacks[i]);
    }

    printf("%s\n", result);

    return 0;
}
