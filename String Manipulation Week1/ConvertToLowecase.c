/******************************************************************************
C program to convert string to lowercase
*******************************************************************************/

#include <stdio.h>

int main(){
    char inputString[100];
    int i;

    printf("Enter a string: ");
    scanf("%[^\n]s", inputString);

    for(i=0; inputString[i]!='\0'; i++){
        if(inputString[i]>='A' && inputString[i]<='Z'){
            inputString[i] = inputString[i] + 32;
        }
    }
    
    printf("String in lowercase: %s", inputString);
    return 0;
}