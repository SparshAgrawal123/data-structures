#include <stdio.h>
#include <ctype.h>

#define n 5
int queue[5];
int front = -1;
int rear = -1;

void enque(int x){

    if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = x;
    }
    else if((rear+1)%n == front){
        printf("queue overflow\n");
    }
    else{
        rear = (rear+1)%n;
        queue[rear] = x;
    }
}

void deque(){

    if(front == -1 && rear == -1){
        printf("queue underflow\n");
    }
    else if(front == rear){
        printf("deque = %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("deque = %d\n", queue[front]);
        front = (front+1)%n;
    }
}
void display(){

    for(int i = front; ; (i = (i+1)%n)){
        printf("%d\t", queue[i]);
        if(i == rear)
        break;
    }
    printf("\n");
}

int main(){

    int ch;
    printf("1.enque\n2.deque\n3.display\n");

     while(1){
        int x;
        printf("enter choice: ");
        scanf("%d", &ch);

        switch(ch){

            case 1: printf("enter number to insert: ");
                    scanf("%d", &x);
                    enque(x);
                    break;
            case 2: deque();
                    break;
            case 3: display();
                    break;
            case 4: return 0;
            default: printf("invalid choice");

        }
     }
     return 0;
}