#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node* nextNode; 
}Node;


void insertEnd(Node** root, int value){
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        exit(2);
    }
    newNode->value = value;
    newNode->nextNode = NULL;

    Node* current = *root;
    while (current->nextNode != NULL){
        current = current->nextNode; 
    }   
    current->nextNode = newNode;
}

void insertBeginning(Node** root, int value){
    Node* newNode = malloc(sizeof(Node));
    if (newNode == NULL){
        exit(3);
    }
    newNode->value = value;
    newNode->nextNode = *root;
    *root = newNode;
}

void insertNth(Node** root, int value, int n){
    
    if (n == 0){
        insertBeginning(root, value);
    }
    else{
        Node* newNode = malloc(sizeof(Node));
        newNode->value = value;
        if (newNode == NULL){
            exit(4);
        }

        int counter = 0;
        Node* current = *root;

        while(current != NULL){
            if (counter == n-1){
                break;
            }
            counter++;
            current = current->nextNode;
        }
        newNode->nextNode = current->nextNode;
        current->nextNode = newNode;
    }
    
}

void deallocate(Node** root){
    Node* current = *root;
    while (current != NULL){
        Node* aux = current;
        current = current->nextNode;
        free(aux);
    }
}

void deleteNode(Node** root, int n){
    Node* current = *root;
    if (n == 0){
        Node* freeAdress = current;
        *root = current->nextNode;
        free(freeAdress);
    }
    else{
        int counter = 0;
        while(current != NULL){
            if (counter == n-1){
                break;
            }
            current = current->nextNode;
            counter++;
        }
        Node* freeAdress = current->nextNode;
        current->nextNode = current->nextNode->nextNode;
        free(freeAdress);
    }
    
}

int main(){
    
    Node* headNode = malloc(sizeof(Node));
    if (headNode == NULL){
        exit(1);
    }
    headNode->value = 10;
    headNode->nextNode = NULL; 

    insertNth(&headNode, 6, 0);
    insertBeginning(&headNode, 5);
    insertEnd(&headNode, 15);
    insertEnd(&headNode, 20);
    insertEnd(&headNode, 25);
    
    deleteNode(&headNode, 0);

    int counter = 1;
    for (Node* current = headNode; current != NULL; current = current->nextNode){
        printf("Address of Node-%d: %p\n", counter, current);
        printf("Next Node: %p\n", current->nextNode);
        printf("%d\n", current->value);
        counter++;
    }

    deallocate(&headNode);

    return 0;
}