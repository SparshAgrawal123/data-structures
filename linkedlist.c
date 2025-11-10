#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void createList (int n){
    struct Node *newNode, *temp;
    int data, i;
    if (n<=0){
        printf("Invalid number of nodes\n");
        return;
    }
    for(i=1;i<=n;i++){
        newNode = (struct Node *)malloc(sizeof(struct Node));
        if(newNode == NULL){
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;
        if(head == NULL){
            head = newNode;
        } else {
            temp->next = newNode;
        }
        temp = newNode;
    }
    printf("\nLinked list created successfully\n");
}

void insertAtBeginning(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
    printf("Node inserted at the beginning\n");
}

void insertAtEnd(int data){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp;
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
    } else {
        temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Node inserted at the end\n");
}

void insertAtPosition(int data, int position){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    int i;
    if (position <= 0){
        printf("Invalid position\n");
        free(newNode);
        return;
    }
    if (position == 1){
        insertAtBeginning(data);
        return;
    }
    newNode->data = data;
    for(i=1; i<position-1 && temp!=NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position out of range.\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d\n", position);
    }
}

void displayList(){
    struct Node *temp = head;
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    printf("\nLinked List: ");
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int ch, n, data, position;
    printf("Singly Linked List Operations Menu:\n");
        printf("1. Create List\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Position\n5. Display List\n6. Exit\n");
    while(1){
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch){
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                createList(n);
                break;
            case 2:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 5:
                displayList();
                break;
            case 6:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}