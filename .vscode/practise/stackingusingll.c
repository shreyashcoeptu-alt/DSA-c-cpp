#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};


struct Node *topList = NULL;
void push(int val){

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    if(!newNode){
        printf("Heap overflow \n");
        return;
    }

    newNode->data = val;
    newNode->next = topList;
    topList = newNode;
}

int pop(){
    if(!topList){
        printf("Underflow \n");
        return -1;
    }

    struct Node *temp = topList;
    int val = temp->data;
    topList = topList->next;
    free(temp);
    return val;
}
void displayListStack() {
    struct Node* curr = topList;
    while (curr) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main(){
    printf("\n--- Linked List Stack ---\n");
    push(100); push(200); push(300);
    printf("Stack: "); displayListStack();
    printf("Popped: %d\n", pop());
    printf("Stack: "); displayListStack();
    return 0;

}




































