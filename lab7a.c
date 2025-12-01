#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *createList(int n,struct node *head){
    if(n<=0){
        printf("Invalid number of nodes.\n");
        return NULL;
    }
    struct node *newnode,*temp;
    int data, i;
    for(i=1;i<=n;i++){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter element %d: ",i);
        scanf("%d",&data);
        newnode->data=data;
        newnode->next=NULL;
        newnode->prev=NULL;
        if(head==NULL)
            head=temp=newnode;
        else{
            temp->next=newnode;
            newnode->prev=temp;
            temp=newnode;
        }
    }
    printf("Doubly linked list created successfully.\n");
    return head;
}

void display(struct node *head) {
    if (head==NULL) {
        printf("List is empty\n");
        return;
    }
    struct node *temp=head;
    while (temp!=NULL) {
        printf("%d <-> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node *insertLeft(struct node *head, int value, int position) {
    if (head==NULL) {
        printf("List is empty\n");
        return head;
    }
    struct node *newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=value;
    if (position==1) {
        newnode->next=head;
        newnode->prev=NULL;
        head->prev=newnode;
        return newnode;
    }
    struct node *temp=head;
    int i=1;
    while (i<position && temp!=NULL) {
        temp=temp->next;
        i++;
    }
    if (temp==NULL) {
        printf("Invalid position\n");
        free(newnode);
        return head;
    }
    newnode->next=temp;
    newnode->prev=temp->prev;
    temp->prev->next=newnode;
    temp->prev=newnode;
    return head;
}

struct node *deleteValue(struct node *head, int value) {
    if (head==NULL) {
        printf("List is empty\n");
        return head;
    }
    struct node *temp=head;
    if (temp->data==value) {
        head=temp->next;
        if (head!=NULL)
            head->prev=NULL;
        free(temp);
        return head;
    }
    while (temp!=NULL && temp->data!=value) {
        temp=temp->next;
    }
    if (temp==NULL) {
        printf("Value not found\n");
        return head;
    }
    temp->prev->next=temp->next;
    if (temp->next!=NULL)  
        temp->next->prev=temp->prev;
    printf("Deleted: %d\n", temp->data);
    free(temp);
    return head;
}

int main() {
    struct node *head=NULL;
    int ch,n,pos,value;
    printf("\n--- Doubly Linked List Menu ---\n");
    printf("1.Create node\n2.Insert to the LEFT of position\n3.Delete by value\n4.Display\n5.Exit\n");
    while (1) {
        printf("\nEnter choice: ");
        scanf("%d", &ch);
        switch(ch){
        case 1:
            printf("Enter number of nodes: ");
            scanf("%d", &n);
            head=createList(n,head);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            printf("Insert to the LEFT of position: ");
            scanf("%d", &pos);
            head=insertLeft(head, value, pos);
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            head=deleteValue(head, value);
            break;
        case 4:
            display(head);
            break;
        case 5:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}