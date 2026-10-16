#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// ================= Standard Traversals =================

void preorder(Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}

// ================= Leaf Nodes =================

int countAndPrintLeaves(Node* root) {
    if (root == NULL) return 0;

    // Check if current node is a leaf (no left and no right child)
    if (root->left == NULL && root->right == NULL) {
        printf("%d ", root->data);
        return 1;
    }

    return countAndPrintLeaves(root->left) + countAndPrintLeaves(root->right);
}

// ================= Non-Leaf Nodes =================

int countAndPrintNonLeaves(Node* root) {
    if (root == NULL) return 0;

    // A node is non-leaf if it has at least one child
    if (root->left != NULL || root->right != NULL) {
        printf("%d ", root->data);
        return 1 + countAndPrintNonLeaves(root->left) + countAndPrintNonLeaves(root->right);
    }

    return 0;
}

// ================= Level of All Nodes =================

// Root is at Level 1 (or 0, depending on convention)
void printNodeLevels(Node* root, int currentLevel) {
    if (root == NULL) return;

    printf("Node %d -> Level %d\n", root->data, currentLevel);
    printNodeLevels(root->left, currentLevel + 1);
    printNodeLevels(root->right, currentLevel + 1);
}

// Helper function to free allocated tree memory
void freeTree(Node* root) {
    if (root == NULL) return;
    freeTree(root->left);
    freeTree(root->right);
    freeTree(root);
}

// ================= Main Function =================

int main() {
    /*
            Constructed Tree:
                   1
                 /   \
                2     3
               / \   / \
              4   5 6   7
    */

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    // 1. Traversals
    printf("Preorder Traversal:  ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal:   ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n\n");

    // 2. Leaf Nodes
    printf("Leaf Nodes: ");
    int leafCount = countAndPrintLeaves(root);
    printf("\nTotal Leaf Nodes: %d\n\n", leafCount);

    // 3. Non-Leaf Nodes
    printf("Non-Leaf Nodes: ");
    int nonLeafCount = countAndPrintNonLeaves(root);
    printf("\nTotal Non-Leaf Nodes: %d\n\n", nonLeafCount);

    // 4. Levels of Nodes
    printf("Levels of all nodes (Root at Level 1):\n");
    printNodeLevels(root, 1);

    // Clean up
    freeTree(root);

    return 0;
}