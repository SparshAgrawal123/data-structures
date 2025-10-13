#include <stdio.h>
#include<stdlib.h>
# define N 5
int front=-1,rear=-1;
int queue[N];
void enqueue(int x){
    if(rear==N-1){
        printf("queue overflow\n");

    }
    else if(front==-1 && rear==-1){
        front=rear=0;
        queue[rear]=x;
        printf("Element Inserted \n");
    }
    else{
        rear++;
        queue[rear]=x;
        printf("Element Inserted \n");
    }
}

void dequeue(){
        if(front==-1 && rear==-1){
            printf("queue is empty\n");
        }
        else if(front==rear){
            front=rear=-1;
        }
        else{
            printf("deleted element = %d\n",queue[front]);
            front++;
        }
    }

void display(){
        int i;
        for(i=front;i<=rear;i++){
            printf("%d\n",queue[i]);
        }
    }
int main(){
    int ch;
    printf("1.Insert/n2.Delete\n3.Display\n4.Exit\n");
    while(1){
        int x;
        printf("enter choice\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the number you want to Insert : ");
            scanf("%d",&x);
            enqueue(x);
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice .");
        }
    }
    return 0;
}
