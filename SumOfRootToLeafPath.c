/******************************************************************************
Program to find sum of all the pathsums from roo to leaf
Kalpvriksha session : 11-04-2023
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct bnode {
    int data;
    struct bnode * left;
    struct bnode * right;
} node;

node * insert (int value, node *rNode){
    if(rNode==NULL){
        rNode = (node *) malloc(sizeof(node));
        rNode->data=value;
        rNode->left = rNode->right = NULL;
    }
    else if(value < rNode->data){
        rNode->left = insert(value, rNode->left);
    }
    else if(value >= rNode->data){
        rNode->right = insert(value, rNode->right);
    }
    return rNode;
}

void inorder(node* rNode)
{
    if (rNode == NULL)
        return;
    inorder(rNode->left);
    printf("%d ",  rNode->data);
    inorder(rNode->right);
}

void preorder( node *root){
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

int totalSum = 0;
int sumOfRootToLeafPaths(node * rNode, int sum){
    if(rNode==NULL){
        return 0;
    }
    sum = sum + rNode->data;
    if(rNode->left==NULL&&rNode->right==NULL){
        return sum;
    }
    totalSum = sumOfRootToLeafPaths(rNode->left, sum) + sumOfRootToLeafPaths(rNode->right, sum);
    return totalSum;
    
}

int main()
{
    node *root =NULL;
    int choice, value;
    do{
        printf("1. Insert\n");
        printf("2. Sum of all paths\n");
        printf("3. Display inorder\n");
        printf("4. Display preorder\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            printf("Enter value: ");
            scanf("%d", &value);
            root = insert(value, root);
            printf("Inserted!\n\n");
            break;
            
            case 2:
            int sum = sumOfRootToLeafPaths(root,0);
            printf("\nSum of root to leaf paths = %d\n\n", sum);
            break;
            
            case 3:
            inorder(root);
            printf("\n\n");
            break;
            
            case 4:
            preorder(root);
            printf("\n\n");
            break;
            
            case 0:
            printf("Exiting...");
            break;
            
            default:
            printf("Enter valid choice\n");
        }
    }
    while(choice!=0);

    return 0;
}
