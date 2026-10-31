#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};


struct Node *createNew(int data){
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->right = n->left = NULL;
    return n;
}

void preoder(struct Node *root){
    if(!root) return;
    printf("%d", root->data);
    preoder(root->left);
    preoder(root->right);
}
void inoder(struct Node *root){
    if(!root) return;
    preoder(root->left);
    printf("%d", root->data);
    preoder(root->right);
}
void postoder(struct Node *root){
    if(!root) return;
    preoder(root->left);
    preoder(root->right);
    printf("%d", root->data);
}

int printAndCountLeafNode(struct Node *root){
    if(!root) return 0;
    if(!root->left && !root->right){
        printf("%d", root->data);
        return 1;
    }
    return printAndCountLeafNode(root->left) + printAndCountLeafNode(root->right);
    
}

int printAndCountNonLeafNode(struct Node *root){

    if(!root || (!root->left && !root->right)) return 0;
    printf("%d", root->data);
    return 1 + printAndCountNonLeafNode(root->left) + printAndCountNonLeafNode(root->right);
    
}

void printLevels(struct Node *root,int level){
    if(!root) return;
    printf("Node %d -> Level %d \n", root->data, level);
    printLevels(root->left,level + 1);
    printLevels(root->right,level + 1);

}

int main(){
    struct Node *root = createNew(1);
    root->left = createNew(2);
    root->right = createNew(3);
    root->left->left= createNew(4);
    root->left->right= createNew(5);

    printLevels(root, 1);
    
    return 0;
}


