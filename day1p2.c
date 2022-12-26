#include <stdio.h>
#include <stdlib.h>

int* sort(int arr[], const int len){
    for(int i = 1; i < len; ++i){
        for(int j = i; j < len; ++j){
            if(arr[j] < arr[i - 1]){
                int temp = arr[i - 1];
                arr[i - 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;
}

int main(){
    FILE *fp;
    char buff[255];

    fp = fopen("day1.txt", "r");

    int max[3] = {0, 0, 0};
    int sum = 0;
    while (fgets(buff, 255, fp) != NULL) {
        if (buff[0] == '\n') {
            if (sum > max[0]) {
                max[0] = sum;
                sort(max, 3);
            }
            sum = 0;
            continue;
        }
        printf("%s", buff);
        sum += atoi(buff);
    }

    fclose(fp);

    printf("Answer: %d\n", max[0] + max[1] + max[2]);

    return 0;
}
