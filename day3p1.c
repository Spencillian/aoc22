#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *fp;
    char buff[255];

    fp = fopen("day3.txt", "r");

    int total = 0;
    while (fgets(buff, 255, fp) != NULL) {
        char duplicate;
        int length = (int)strlen(buff);
        for(int i = 0; i < length / 2; ++i){
            for(int j = length / 2; j < length; ++j){
                if(buff[i] == buff[j]){
                    duplicate = buff[i];
                    break;
                }
            }
        }

        int priority;
        if(duplicate >= 'a'){
            priority = duplicate - 'a' + 1;
        }else{
            priority = duplicate - 'A' + 26 + 1;
        }

        total += priority;

        printf("%s", buff);
    }

    fclose(fp);

    printf("Answer: %d", total);

    return 0;
}
