#include <stdio.h>
#define MAX 5

int stack[MAX], top = -1;

void push(int x) {
    if (top == MAX - 1) printf("Stack Overflow\n");
    else stack[++top] = x;
}

void pop() {
    if (top == -1) printf("Stack Underflow\n");
    else printf("Popped: %d\n", stack[top--]);
}
void peek() {
    if (top == -1) printf("Stack is empty\n");
    else printf("Top element: %d\n", stack[top]);
}

void display() {
    if (top == -1) { 
        printf("Stack is empty\n"); 
        return; 
    }

    for (int i = top; i >= 0; i--) {
    printf("%d\n", stack[i]);
    }
}

int main() {
    int ch, x;
    do {
        printf("\n1.Push 2.Pop 3.Peek 4.Display 0.Exit: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: printf("Enter value: "); scanf("%d", &x); push(x); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;   
        }
    } while (ch != 0);
    return 0;
}
