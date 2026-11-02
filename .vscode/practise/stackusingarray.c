#include <stdio.h>
#include <stdlib.h>
#define MAX 5


int arrStack[MAX];
int topArr = -1;

void push(int val){
    if(topArr == MAX - 1 ){
        printf("Array overflow!");
        return;
    }

    arrStack[++topArr] = val;
}

int pop(){
    if(topArr == -1){
        printf("Array underflow!");
        return -1;
    }
    return arrStack[topArr--]; 
}

void displayArr(){
    if(topArr == -1){
        printf("Empty \n");
        return;
    }

    for(int i=topArr; i>=0;i--){
        printf("%d", arrStack[i]);
        printf("\n");
    }

    printf("\n");
}

int main(){
    printf("--- Array Stack ---\n");
    push(10); 
    push(20);
    push(30);
    printf("Stack: ");
    displayArr();
    printf("Popped: %d\n", pop());
    printf("Stack: "); 
    displayArr();
}

