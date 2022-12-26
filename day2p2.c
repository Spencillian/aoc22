#include <stdio.h>
#include <stdlib.h>

int main(){
    FILE *fp;
    char buff[255];

    fp = fopen("day2.txt", "r");

    int total = 0;
    while (fgets(buff, 255, fp)){
        int hand;
        if(buff[0] == 'A'){
            hand = 1;
        }else if (buff[0] == 'B') {
            hand = 2;
        }else {
            hand = 3;
        }

        int response;
        if(buff[2] == 'X'){
            response = 1;
        }else if (buff[2] == 'Y') {
            response = 2;
        }else {
            response = 3;
        }

        int game_results = (hand - response + 2) % 3;

        int score;
        if (game_results == 2) {
            score = 3 + response;
        }else if (game_results == 0) {
            score = response;
        }else {
            score = 6 + response;
        }

        total += score;
        printf("%s", buff);
    }
    fclose(fp);

    printf("%d", total);

    return 0;
}
