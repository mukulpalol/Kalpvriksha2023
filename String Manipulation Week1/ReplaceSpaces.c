/******************************************************************************
C program to replace all spcaes with a special char inputted by user
*******************************************************************************/
#include <stdio.h>  
#include <string.h>  
   
int main(){
    char input[100];
    char specialChar = '@';
    printf("Enter a string: ");
    scanf("%[^\n]s", input);
    printf("Enter special character for replacement: ");
    scanf("\n");
    scanf("%c", &specialChar);
    for(int i = 0; i < strlen(input); i++){
        if(input[i] == ' '){
            input[i] = specialChar;
        }
    }
    printf("String after replacing spaces with %c: \n", specialChar);
    printf("%s", input);
    return 0;
}  