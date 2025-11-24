#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node *createList(int n,struct Node *head){
    struct Node *newNode, *temp;
    int data, i;
    if(n<=0){
        printf("Invalid number of nodes.\n");
        return;
    }
    for(i=1;i<=n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));  
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data=data;
        newNode->next=NULL;
        if(head==NULL)
            head=temp=newNode;
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    printf("\nLinked list created successfully\n");
    return head;
}

struct Node* sortList(struct Node *head) {
    struct Node *i, *j;
    int tempData;
    for(i=head;i!=NULL;i=i->next) {
        for(j=i->next;j!=NULL;j=j->next) {
            if(i->data>j->data) {
                tempData=i->data;
                i->data=j->data;
                j->data=tempData;
            }
        }
    }
    return head;
}

struct Node* reverseList(struct Node *head) {
    struct Node *temp=head;
    struct Node *prev=NULL;
    struct Node *curr;
    while (temp!=NULL) {
        curr=temp->next;
        temp->next=prev;
        prev=temp;
        temp=curr;
    }
    return prev;
}

struct Node *concatenationList(struct Node *head1, struct Node *head2){
    struct Node *temp1=head1;
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    while(temp1->next!=NULL){
        temp1=temp1->next;
    }
    temp1->next=head2;
    return head1;
}

void displayList(struct Node *head) {
    struct Node *temp=head;
    while (temp!=NULL) {
        printf("%d\t", temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main() {
    int n,n1,n2;
    struct Node *head1=NULL;
    struct Node *head2=NULL;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    head=createList(n,head);
    head=reverseList(head);
    displayList(head);
    head=reverseList(head);     
    printf("\nReverse List:\n");
    displayList(head);
    printf("\nSorted List:\n");
    head=sortList(head);        
    displayList(head);
    printf("Enter the number of nodes for list 1: ");
    scanf("%d", &n1);
    head1=createList(n1,head1);
    printf("Enter the number of nodes for list 2: ");
    scanf("%d", &n2);
    head2=createList(n2,head2);
    head1=concatenationList(head1,head2);
    printf("Concatenation of list 1 and list 2: ");
    displayList(head1);
    return 0;
}