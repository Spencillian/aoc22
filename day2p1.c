#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char buff[255];

    fp = fopen("day2.txt", "r");

    while (fgets(buff, 255, fp)){
        printf("%s", buff);
    }

    fclose(fp);

    return 0;
}
