#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char buff[4];
    char cursor;

    fp = fopen("day6.txt", "r");

    for(size_t i = 0; i < 4; ++i){
        buff[i] = fgetc(fp);
    }

    int count = 4;
    while ((cursor = fgetc(fp)) != EOF) {
        int match_flag = 0;
        for(size_t i = 0; i < 3; ++i){
            for(size_t j = i + 1; j < 4; ++j){
                if (buff[i] == buff[j]) {
                    match_flag = 1;
                    break;
                }
            }
            if (match_flag) {
                break;
            }
        }

        if (!match_flag) {
            break;
        }

        for(size_t i = 0; i < 3; ++i){
            buff[i] = buff[i + 1];
        }
        buff[3] = cursor;
        count++;
        printf("%s %d\n", buff, match_flag);
    }

    fclose(fp);

    printf("%d", count);

    return 0;
}
