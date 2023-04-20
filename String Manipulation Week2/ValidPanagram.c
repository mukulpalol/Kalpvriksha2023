/******************************************************************************
C program to check if a string is panagram or not
*******************************************************************************/

#include<stdio.h>
 
int main()
{
    char input[100];
    int i, usedAlphabets[26] = {0}, totalUnique = 0;
     
    printf("Enter a string: ");
    scanf("%[^\n]s", input);
     
    for(i = 0; input[i] != '\0'; i++){
        if('a' <= input[i] && input[i] <= 'z'){
            totalUnique += !usedAlphabets[input[i]-'a'];
            usedAlphabets[input[i]-'a'] = 1;
        }
        else if('A' <= input[i] && input[i] <= 'Z'){
            totalUnique += !usedAlphabets[input[i]-'A'];
            usedAlphabets[input[i]-'A'] = 1;
        }
    }
     
    if(totalUnique == 26)
        printf("The Entered String is a Pangram String.");
    else
        printf("The Entered String is not a Pangram String.");
    return 0;
}