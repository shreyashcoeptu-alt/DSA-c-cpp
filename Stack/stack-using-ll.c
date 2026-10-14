#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x) {
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = x;
    n->next = top;
    top = n;
}

void pop() {
    if (top == NULL) {
         printf("Stack Underflow\n"); 
         return; 
    }

    struct Node *t = top;
    printf("Popped: %d\n", t->data);
    top = top->next;
    free(t);

}

void peek() {
    if (top == NULL){
        printf("Stack is empty\n");
    }
    else{
        printf("Top element: %d\n", top->data);
    }
}

void display() {
    struct Node *t = top;
    if (t == NULL) { 
        printf("Stack is empty\n"); 
        return; 
    }
    while (t != NULL) {
        printf("%d\n", t->data);
        t = t->next; 
    }
}

int main() {
    int ch, x;
    do {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 0.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); 
            scanf("%d", &x);
            push(x); 
            break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
        }
    } while (ch != 0);
    return 0;
}
