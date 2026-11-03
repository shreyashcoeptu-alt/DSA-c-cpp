#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coeff;
    int exp;
    struct Node *next;
};


struct Node *insertTerm(struct Node *head, int c, int e){
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;

    //if its the first element or if its the largest exp and needs to be at the first
    if(!head || e > head->exp){
        newNode->next = head;
        return newNode;
    }

    struct Node *curr = head;
    struct Node *prev = NULL;


    //travesing to the right place!
    while(curr && curr->exp > e){
        prev = curr;
        curr = curr->next;
    }

    //adding the like terms!!
    if(curr && curr->exp == e){
        curr->coeff += c;   
        free(newNode);
    }else{
        newNode->next = curr;
        prev->next = newNode;
    }

    return head;

}

struct Node *add(struct Node *p1, struct Node *p2){
    struct Node *res = NULL;
    for(struct Node *t = p1; t; t=t->next) return insertTerm(res, t->coeff, t->exp);
    for(struct Node *t = p2; t; t=t->next) return insertTerm(res, t->coeff, t->exp);
    return res;

}

void display(struct Node* head) {
    if (!head) {
        printf("0\n");
        return;
    }
    while (head) {
        printf("%dx^%d", head->coeff, head->exp);
        head = head->next;
        if (head && head->coeff >= 0) printf(" + ");
        else if (head) printf(" ");
    }
    printf("\n");
}

int main() {
    struct Node *p1 = NULL, *p2 = NULL;

    // P1: 5x^2 + 4x^1 + 2x^0
    p1 = insertTerm(p1, 5, 2);
    p1 = insertTerm(p1, 4, 1);
    p1 = insertTerm(p1, 2, 0);

    // P2: 3x^2 + 1x^1 + 4x^0
    p2 = insertTerm(p2, 3, 2);
    p2 = insertTerm(p2, 1, 1);
    p2 = insertTerm(p2, 4, 0);

    printf("P1: "); display(p1);
    printf("P2: "); display(p2);

}