/*
Prerna Mehta's Question:
Given a string of round, curly, and square opening and closing brackets, return whether the brackets are balanced (well-formed).
*/

#include <stdio.h>
#include <stdlib.h>

char stack[100];
int top =-1;

void push(char c){
    stack[++top]=c;
}
void pop(){
    top--;
}

int main()
{
    char bracketSequence[100];
    scanf("%[^\n]%*c",bracketSequence);
    for(int i=0;bracketSequence[i]!='\0';i++){
        char bracket=bracketSequence[i];
        if(bracket=='('||bracket=='['||bracket=='{')
        push(bracket);
        else{
            if(bracket==')'&&stack[top]!='('){
            printf("Invalid bracket sequence!");
            return 0;}
            if(bracket==']'&&stack[top]!='['){
            printf("Invalid bracket sequence!");
            return 0;}
            if(bracket=='}'&&stack[top]!='{'){
            printf("Invalid bracket sequence!");
            return 0;}
            pop();
        }
    }
    if(top==-1)
    printf("Valid bracket sequence!");
    else
    printf("Invalid bracket sequence!");
    return 0;
}