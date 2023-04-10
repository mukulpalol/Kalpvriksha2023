/******************************************************************************
Binary Search Tree
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *root = NULL;

struct node *create_node(int data){
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    if (new_node == NULL)
    {
        printf("\nMemory not allocated");
        return NULL;
    }
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
 
    return new_node;
}

void insert(int data){
    struct node *new_node = create_node(data);
    if (new_node != NULL){
        if (root == NULL){
            root = new_node;
            printf("\nNode Inserted\n\n");
            return;
        }
        struct node *temp = root;
        struct node *prev = NULL;
        while (temp != NULL){
            prev = temp;
            if (data > temp->data){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        if (data > prev->data){
            prev->right = new_node;
        }
        else{
            prev->left = new_node;
        }
        printf("\nNode Inserted\n\n");
    }
}

void inorder(struct node *root){
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ",  root->data);
    inorder(root->right);
}

void preorder(struct node *root){
    if (root == NULL)
        return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct node *root){
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

int main()
{
    int choice, data;
    do{
        printf("1. Insert\n");
        printf("2. Inorder\n");
        printf("3. Post Order\n");
        printf("4. Pre Oder\n");
        printf("5. Exit\n");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
            printf("\nEnter Data: ");
            scanf("%d", &data);
            insert(data);
            break;
            
            case 2:
            printf("\nInorder Traversal\n");
            inorder(root);
            printf("\n\n");
            break;
            
            case 3:
            printf("\nPost Order Traversal\n");
            postorder(root);
            printf("\n\n");
            break;
            
            case 4:
            printf("\nPre Order Traversal\n");
            preorder(root);
            printf("\n\n");
            break;
            
            case 5:
            printf("Exiting...");
            break;
            
            default:
            printf("Enter valid choice!");
        }
    }while(choice!=5);

    return 0;
}
