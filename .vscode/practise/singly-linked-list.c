#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *createNode(int val){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next= NULL;
    return newNode;
}

struct Node *insertBeginning(struct Node *head, int val){
    struct Node *temp = createNode(val);
    temp->next = head;
    return temp;
}
struct Node *insertEnd(struct Node *head, int val){
    struct Node *node = createNode(val);
    if(!head) return node;

    struct Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = node;
    return head;

}

struct Node *insertIndex(struct Node *head, int val, int index){
    struct Node *newNode = createNode(val);
    struct Node *temp = head;
    for(int i = 0; i<index-1; i++){
        temp = temp->next;
    }
    newNode->next = temp->next->next;
    temp->next = newNode;

    return head;
}


struct Node *deleteBeginning(struct Node *head){
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

struct Node *deleteEnd(struct Node *head){
  
    if (!head) return NULL;
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    struct Node *temp = head;
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;

}

struct Node *deleteIndex(struct Node *head, int index){

    struct Node *temp = head;
    for(int i = 0; i<index-1; i++){
        temp = temp->next;
    }

    free(temp->next);
    temp->next = temp->next->next;
    return head;

}

void display(struct Node *head){
    struct Node *temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf(" NULL \n");
}

struct Node *reverse(struct Node *head){
    struct Node *prev = NULL;
    struct Node *curr = head;
    struct Node *nxt = NULL;

    while(curr){
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;

    }
    return prev;
}

int main(){

    struct Node *head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);
    display(head);

    head = insertBeginning(head,50);
    display(head);
    head = reverse(head);
    display(head);
    return 0;
}