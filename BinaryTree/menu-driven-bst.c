#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node* root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } else if (value > root->data) {
        root->right = insert(root->right, value);
    } else {
        printf("Duplicate value %d ignored (BST does not allow duplicates).\n", value);
    }
    return root;
}


struct Node* findMin(struct Node* node) {
    while (node && node->left != NULL) {
        node = node->left;
    }
    return node;
}

struct Node* deleteNode(struct Node* root, int value) {
    if (root == NULL) {
        printf("Element %d not found in the tree.\n", value);
        return NULL;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    } else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    } else {
       

        // Case 1: No children (leaf node)
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // Case 2: One child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Case 3: Two children
        else {
            // Find inorder successor (smallest in the right subtree)
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

// (c) Search an element
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

// (d) Recursive Traversals
void inorderRecursive(struct Node* root) {
    if (root != NULL) {
        inorderRecursive(root->left);
        printf("%d ", root->data);
        inorderRecursive(root->right);
    }
}

void preorderRecursive(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
}

void postorderRecursive(struct Node* root) {
    if (root != NULL) {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        printf("%d ", root->data);
    }
}

// (d) Non-Recursive (Iterative) Inorder Traversal using a Stack
void inorderNonRecursive(struct Node* root) {
    struct Node* stack[MAX_STACK_SIZE];
    int top = -1;
    struct Node* curr = root;

    while (curr != NULL || top != -1) {
        // Reach the leftmost node of the current subtree
        while (curr != NULL) {
            if (top >= MAX_STACK_SIZE - 1) {
                printf("Stack Overflow!\n");
                return;
            }
            stack[++top] = curr;
            curr = curr->left;
        }

        // Current must be NULL at this point, backtrack from stack
        curr = stack[top--];
        printf("%d ", curr->data);

        // Visit the right subtree
        curr = curr->right;
    }
}

// (e) Display Depth (Height) of tree
int getDepth(struct Node* root) {
    if (root == NULL) {
        return 0;
    }
    int leftDepth = getDepth(root->left);
    int rightDepth = getDepth(root->right);

    return (leftDepth > rightDepth ? leftDepth : rightDepth) + 1;
}

// (f) Display leaf nodes
void displayLeafNodes(struct Node* root) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return;
    }
    displayLeafNodes(root->left);
    displayLeafNodes(root->right);
}

// Main Menu
int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n================ BINARY SEARCH TREE MENU ================\n");
        printf("1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Search an element\n");
        printf("4. Display Tree (Recursive Traversals)\n");
        printf("5. Display Tree (Non-Recursive Inorder Traversal)\n");
        printf("6. Display Depth of Tree\n");
        printf("7. Display Leaf Nodes\n");
        printf("8. Exit\n");
        printf("Enter your choice (1-8): ");
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Exiting...\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &val);
                root = insert(root, val);
                printf("%d inserted successfully.\n", val);
                break;

            case 2:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Enter value to delete: ");
                    scanf("%d", &val);
                    if (search(root, val) != NULL) {
                        root = deleteNode(root, val);
                        printf("%d deleted successfully.\n", val);
                    } else {
                        printf("%d does not exist in the tree.\n", val);
                    }
                }
                break;

            case 3:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Enter value to search: ");
                    scanf("%d", &val);
                    if (search(root, val) != NULL) {
                        printf("Element %d is present in the BST.\n", val);
                    } else {
                        printf("Element %d is NOT present in the BST.\n", val);
                    }
                }
                break;

            case 4:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("\n--- Recursive Traversals ---\n");
                    printf("Inorder   : ");
                    inorderRecursive(root);
                    printf("\nPreorder  : ");
                    preorderRecursive(root);
                    printf("\nPostorder : ");
                    postorderRecursive(root);
                    printf("\n");
                }
                break;

            case 5:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Non-Recursive Inorder: ");
                    inorderNonRecursive(root);
                    printf("\n");
                }
                break;

            case 6:
                printf("Depth (Height) of tree: %d\n", getDepth(root));
                break;

            case 7:
                if (root == NULL) {
                    printf("Tree is empty!\n");
                } else {
                    printf("Leaf Nodes: ");
                    displayLeafNodes(root);
                    printf("\n");
                }
                break;

            case 8:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please choose between 1 and 8.\n");
        }
    }

    return 0;
}