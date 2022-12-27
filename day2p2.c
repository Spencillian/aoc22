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
            hand = 0;
        }else if (buff[0] == 'B') {
            hand = 1;
        }else {
            hand = 2;
        }

        int game_state;
        if(buff[2] == 'X'){
            game_state = 2;
        }else if (buff[2] == 'Y') {
            game_state = 0;
        }else {
            game_state = 1;
        }

        int response = (hand + game_state) % 3;

        int score = (((game_state + 1) % 3) * 3) + response + 1;

        total += score;
        printf("%s", buff);
    }
    fclose(fp);

    printf("%d", total);

    return 0;
}
