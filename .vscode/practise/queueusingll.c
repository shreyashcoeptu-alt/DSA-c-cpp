#include <stdio.h>
#include <stdlib.h>

// Definition of a node
struct Node {
    int data;
    struct Node* next;
};

// Queue wrapper storing pointers to both ends
struct Queue {
    struct Node* front;
    struct Node* rear;
};

// Function to initialize an empty queue
struct Queue* createQueue() {
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

// Enqueue: Add an element to the rear of the queue (O(1))
void enqueue(struct Queue* q, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Heap Overflow! Cannot allocate memory.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty, both front and rear point to new node
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
        printf("Enqueued %d\n", value);
        return;
    }

    // Add new node to the end and shift rear
    q->rear->next = newNode;
    q->rear = newNode;
    printf("Enqueued %d\n", value);
}

// Dequeue: Remove an element from the front of the queue (O(1))
int dequeue(struct Queue* q) {
    // Underflow condition: queue is empty
    if (q->front == NULL) {
        printf("Queue Underflow! The queue is empty.\n");
        return -1;
    }

    struct Node* temp = q->front;
    int dequeuedVal = temp->data;

    // Advance front pointer
    q->front = q->front->next;

    // If front becomes NULL, queue is now empty, so reset rear to NULL
    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
    return dequeuedVal;
}

// Peek / Front: View the front element without removing it (O(1))
int peek(struct Queue* q) {
    if (q->front == NULL) {
        printf("Queue is empty.\n");
        return -1;
    }
    return q->front->data;
}

// Check if queue is empty (O(1))
int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

// Display all elements from front to rear
void display(struct Queue* q) {
    if (isEmpty(q)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* curr = q->front;
    printf("Queue (Front -> Rear): ");
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Queue* q = createQueue();

    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    display(q);

    printf("Front element is: %d\n", peek(q));

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    display(q);

    enqueue(q, 40);
    display(q);

    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q));
    printf("Dequeued: %d\n", dequeue(q)); // Attempt on empty queue

    free(q);
    return 0;
}