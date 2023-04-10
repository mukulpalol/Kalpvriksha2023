/*
Mukul Palol's Question:
Design a stack that returns the minimum element in constant time

Conditions:
• Time complexity should be O(1)
• The minimum element should be updated if a new element pushed in the stack is smaller than it
• The minimum element should be updated to a new minimum element if it is popped from the stack
Example in the image
*/

#include <stdio.h>
#include <stdlib.h>

int mainStack[100];
int secondaryStack[100];
int mainTop =-1;
int secondaryTop =-1;

void mainPush(int data){
    mainStack[++mainTop]=data;
}

void secondaryPush(int data){
    if(secondaryTop==-1)
    secondaryStack[++secondaryTop]=data;
    else{
        if(secondaryStack[secondaryTop]>=data)
        secondaryStack[++secondaryTop]=data;
    }
}

int Pop(){
    if(mainStack[mainTop]==secondaryStack[secondaryTop])
    secondaryTop--;
    int data =mainStack[mainTop--];
    return data;
}

int main()
{
    int choice, data;
    do{
        printf("1.Push\n2.Pop\n3.Display minimum element\n4.Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter integer: ");
            scanf("%d",&data);
            mainPush(data);
            secondaryPush(data);
            break;
            case 2:
            printf("Element Popped: %d\n",Pop());
            break;
            case 3:
            printf("Minimum element in stack: %d\n",secondaryStack[secondaryTop]);
            break;
            case 4: 
            printf("Exiting!");
            break;
            default:
            printf("Enter valid choice!\n");
        }
    }while(choice!=4);
    return 0;
}