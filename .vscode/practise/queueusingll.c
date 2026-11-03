#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *next;
};

struct Queue{
    struct Node *front;
    struct Node *rear;
};

struct Queue *createfirst(){
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Node));

    q->front = NULL;
    q->rear = NULL;
    return q;
}

void enqueue(struct Qeueu *q, int val){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

}

void dequeue(){

}

void display(){

}

int main(){

    struct Node *top = NULL;
    return 0;
}