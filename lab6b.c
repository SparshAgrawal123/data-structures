#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head=NULL;   
struct Node *front=NULL;  
struct Node *rear=NULL;   

struct Node *createList(int n,struct Node *head){
    if(n<=0){
        printf("Invalid number of nodes.\n");
        return NULL;
    }
    struct Node *newNode,*temp;
    int data, i;
    for(i=1;i<=n;i++){
        newNode=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter element %d: ",i);
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;
        if(head==NULL)
            head=temp=newNode;
        else{
            temp->next=newNode;
            temp=newNode;
        }
    }
    return head;
}

void push(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(head==NULL){
        head=newNode;
        return;
    }
    struct Node *top=head;
    while(top->next!=NULL)
        top=top->next;
    top->next=newNode;
}

void pop(){
    if(head==NULL){
        printf("Stack empty.\n");
        return;
    }
    struct Node *temp=head,*prev=NULL;
    while(temp->next != NULL){
        prev=temp;
        temp=temp->next;
    }
    if(prev==NULL)
        head=NULL;
    else
        prev->next=NULL;
    printf("Popped: %d\n", temp->data);
    free(temp);
}

void enqueue(int data){
    struct Node *newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    if(rear==NULL)
        front=rear=newNode;
    else{
        rear->next=newNode;
        rear=newNode;
    }
}

void dequeue(){
    if(front==NULL){
        printf("Queue empty.\n");
        return;
    }
    struct Node *temp=front;
    printf("Dequeued: %d\n",temp->data);
    front=front->next;
    if(front==NULL)
        rear=NULL;
    free(temp);
}

void displayList(struct Node *temp){
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    int ch,n,data;
    printf("Enter number of elements in stack: ");
    scanf("%d", &n);
    head=createList(n, head);
    printf("\nSTACK MENU\n1.Push\n2.Pop\n3.Display\n4.Exit Stack Menu\n");
    while(1){
        printf("Enter a choice: ");
        scanf("%d", &ch);
        if(ch==1){
            printf("Enter data: ");
            scanf("%d", &data);
            push(data);
        }
        else if(ch==2)
            pop();
        else if(ch==3)
            displayList(head);
        else if(ch==4)
            break;
        else
            printf("Invalid choice");
    }
    printf("\nEnter number of elements in queue: ");
    scanf("%d", &n);
    front=createList(n,front);
    rear=front;
    while(rear && rear->next)
        rear=rear->next;
    printf("\nQUEUE MENU\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit Queue Menu\n");
    while(1){
        printf("Enter a choice: ");
        scanf("%d", &ch);
        if(ch==1){
            printf("Enter data: ");
            scanf("%d", &data);
            enqueue(data);
        }
        else if(ch==2)
            dequeue();
        else if(ch==3)
            displayList(front);
        else if(ch==4)
            return 0;
        else
            printf("Invalid choice");
    }
    return 0;
}