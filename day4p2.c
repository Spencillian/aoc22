#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp;
    char buff[255];

    fp = fopen("day4.txt", "r");

    int total = 0;
    while (fgets(buff, 255, fp) != NULL) {
        int vals[4];
        char temp[255];
        int count_char = 0;
        int count_int = 0;
        for(int i = 0; i < (int)strlen(buff); ++i){
            if (buff[i] >= '0' && buff[i] <= '9') {
                temp[count_char++] = buff[i];
            }else{
                temp[count_char] = '\0';
                count_char = 0;

                vals[count_int++] = atoi(temp);
            }
        }

        if (vals[0] <= vals[2] && vals[1] >= vals[3]) {
            total++;
            continue;
        }

        if (vals[2] <= vals[0] && vals[3] >= vals[1]) {
            total++;
            continue;
        }

        printf("%s", buff);
    }

    fclose(fp);

    printf("%d", total);

    return 0;
}
