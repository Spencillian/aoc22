#include <stdio.h>
#include <stdlib.h>

int main(){
    char val = 'A';
    
    int result = (int)(val - 'A' + 1);
    if(val >= 'a'){
        result = val - 'a' + 1;
    }else{
        result = val - 'A' + 26 + 1;
    }
    printf("%c\n", val);
    printf("%d\n", result);

    return 0;
}
