/******************************************************************************
C program to check if string is palindrome or not
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main(){
    char input[100];
    int i, len;
    int flag = 0;
    printf("Enter a string: ");
    scanf("%[^\n]%*c", input);
    len = strlen(input);
    for (i = 0; i < len; i++){
        if (input[i] != input[len - 1 - i]){
            flag = 1;
            break;
        }
    }
    if (flag == 1){
        printf("%s is not a palindrome\n", input);
    } 
    else{
        printf("%s is a palindrome\n", input);
    }
    return 0;
}