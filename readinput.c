#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char buff[255];

    fp = fopen("input.txt", "r");

    while (fgets(buff, 255, fp) != NULL) {
        printf("%s", buff);
    }

    fclose(fp);

    return 0;
}
