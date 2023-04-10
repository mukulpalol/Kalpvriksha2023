/******************************************************************************
C program to trim leading white space characters from a string
*******************************************************************************/

#include <stdio.h>

void trimLeading(char * str){
    int index, i, j;
    index = 0;
    while(str[index] == ' ' || str[index] == '\t' || str[index] == '\n'){
        index++;
    }
    if(index != 0){
        i = 0;
        while(str[i + index] != '\0'){
            str[i] = str[i + index];
            i++;
        }
        str[i] = '\0';
    }
}

int main(){
    char str[100];
    printf("Enter a string: ");
    scanf("%[^\n]s", str);
    printf("\nString before trimming leading whitespace: \n%s", str);
    trimLeading(str);
    printf("\n\nString after trimming leading whitespace: \n%s", str);
    return 0;
}