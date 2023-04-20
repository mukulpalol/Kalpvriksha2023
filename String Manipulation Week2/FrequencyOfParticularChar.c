/******************************************************************************
C program to find the frequency of a particular character
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int main()
{
    char input[100], ch;
    int count = 0, i;
    
    printf("Enter a string: ");
    scanf("%[^\n]%*c", input);

    printf("Enter a character to find frequency: ");
    scanf("%c", &ch);

    for (i = 0; input[i] != '\0'; ++i){
        if (ch == input[i])
            ++count;
    }

    printf("Frequency of %c = %d", ch, count);
    return 0;
}