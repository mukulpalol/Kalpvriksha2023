/*
Kushal Rawat Question:
-> Find the middle element of a singly Linked list and print it's data. 
CONDITIONS: 
* Iterate list only once. (Only one loop can be used) 
* You don't know the Length of the linked list. 
* For odd number of elements - show one middle element
*For even number of elements - show both middle elements

Like there are 6 elements, so you have to show the 3rd and 4th both elements data.
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void insert(){
    struct node *dataNode,*traverseNode;
    int item;
    dataNode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&item);
    dataNode->data=item;
    if(head==NULL)
    {
        dataNode->next=NULL;
        head=dataNode;
        printf("Node inserted!\n");
    }
    else
    {
        traverseNode=head;
        while (traverseNode->next!=NULL)
        {
            traverseNode=traverseNode->next;
        }
        traverseNode->next=dataNode;
        dataNode->next=NULL;
        printf("Node inserted!\n");
    }
}

void display(){
    struct node *traverseNode;
    traverseNode=head;
    if(traverseNode==NULL)
    {
        printf("List empty!\n");
    }
    else
    {
        printf("List elements!\n");
        while (traverseNode!=NULL)
        {
            printf("%d\t",traverseNode->data);
            traverseNode=traverseNode->next;
        }
        printf("\n");
    }
}

void displayMidElement(){
    int index=1;
    struct node *middleNode, *traverseNode;
    middleNode=head;
    traverseNode=head;
    if(head==NULL){
        printf("List empty!\nNo middle element!\n");
    }
    else{
        while(traverseNode->next!=NULL){
            if(index==1){}
            if(index%2==0){
                traverseNode=traverseNode->next;
                middleNode=middleNode->next;
            }
            else{
                traverseNode=traverseNode->next;
            }
            index++;
        }
        if(index%2==0){
            printf("Middle elements are: %d, %d\n",middleNode->data,middleNode->next->data);
        }
        else{
            printf("Middle element is: %d\n",middleNode->data);
        }
    }
}

int main()
{
    int choice;
    do{
        printf("1. Insert in Linked List\n2. Display Linked List\n3. Display middle element of Linked List\n4. Exit\nEnter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: insert(); break;
            case 2: display(); break;
            case 3: displayMidElement(); break;
            case 4: printf("Exiting..."); break;
            default: printf("Enter a valid choice!");
        }
    }while(choice!=4);
    return 0;
}
