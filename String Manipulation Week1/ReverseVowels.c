/******************************************************************************
C program to reverse the order of vowels in a string
*******************************************************************************/

#include<stdio.h>

int main(){
    char input[100], subArray[100];
    printf("Enter a string:\n");
    scanf("%[^\n]s", input);
    int i, count=0, countArray[101];
    for(i=0; input[i]!='\0'; i++){
       if(input[i]=='a' || input[i]=='e' || input[i]=='i' || input[i]=='o' || input[i]=='u' || 
          input[i]=='A' || input[i]=='E' || input[i]=='I' || input[i]=='O' || input[i]=='U'){
           countArray[count]=i;
           subArray[count]=input[i];
           count++;
       }            
    }
    int end=count-1;
    for(i=0; i<count-1; i++)
    {
        input[countArray[i]]=subArray[end];
        end--;
    }
    printf("%s",input);
    return 0;
}