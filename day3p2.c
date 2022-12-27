#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp;
    char buff[3][255];

    fp = fopen("day3.txt", "r");

    int total = 0;
    int count = 0;
    while (fgets(buff[count % 3], 255, fp) != NULL) {
        if(count++ % 3 != 2){
            continue;
        }

        char duplicate;
        int break_flag = 0;
        for(int i = 0; i < (int)strlen(buff[0]); ++i){
            for(int j = 0; j < (int)strlen(buff[1]); ++j){
                if(buff[0][i] == buff[1][j]){
                    for(int k = 0; k < (int)strlen(buff[2]); ++k){
                        if(buff[0][i] == buff[2][k]){
                            duplicate = buff[0][i];
                            break_flag = 1;
                            break;
                        }
                    }
                    if (break_flag == 1) {
                        break;
                    }
                }
            }
            if (break_flag == 1) {
                break;
            }

        }

        int priority;
        if(duplicate >= 'a'){
            priority = duplicate - 'a' + 1;
        }else{
            priority = duplicate - 'A' + 26 + 1;
        }

        total += priority;

        printf("%s", buff[0]);
        printf("%s", buff[1]);
        printf("%s", buff[2]);
    }

    fclose(fp);

    printf("Answer: %d", total);

    return 0;
}
