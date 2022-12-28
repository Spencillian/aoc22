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
    return s->arr[s->top--];
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

    stack stacks[] = {
        init_stack("MFCWTDLB"),
        init_stack("LBN"),
        init_stack("VLTHCJ"),
        init_stack("WJPS"),
        init_stack("RLTFCSZ"),
        init_stack("ZNHBGDW"),
        init_stack("NCGVPSMF"),
        init_stack("ZCVFJRQW"),
        init_stack("HLMPR"),
    };

    while (fgets(buff, 255, fp) != NULL) {
        if (buff[0] != 'm') {
            continue;
        }
        printf("%s", buff);
    }

    fclose(fp);

    return 0;
}
