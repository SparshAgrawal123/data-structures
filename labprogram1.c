#include <stdio.h>
#define n 5

int stack[5];
int top = -1;

void push(){

    int x;
    
    if(top == n-1){
        printf("overflow");
    }
    else{
        printf("enter data: ");
        scanf("%d", &x);
        top++;
        stack[top] = x;
        printf("value entered: ");
        for(int i = top; i >= 0; i--){
            printf("%d", stack[i]);

        }
        printf("\n");
    }
}

void pop(){

    int item;
    if(top == -1){
        printf("underflow");
    }
    else{
        item = stack[top];
        top--;
        printf("popped: %d", item);
    }
}

void peek(){

    if(top == -1){
        printf("underflow");
    }
    else{
        printf("%d", stack[top]);
    }
}

int main(){

    int ch;
    while(1){ 
        printf("enter the function to perform: ");
        scanf("%d", &ch);
        switch(ch){
        case 1: push();
                break;
        case 2: pop();
                break;
        case3 : peek();
                break;
        case 4: 
               return 0;
        default:
        printf("enter value in range");
        } 
    }
}