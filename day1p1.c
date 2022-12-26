#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char buff[255];

    fp = fopen("day1.txt", "r");

    int max = 0;
    int sum = 0;
    while (fgets(buff, 255, fp) != NULL) {
        if (buff[0] == '\n') {
            if (sum > max) {
                max = sum;
            }
            sum = 0;
            continue;
        }
        printf("%s", buff);
        sum += atoi(buff);
    }

    fclose(fp);

    printf("Answer: %d", max);

    return 0;
}
