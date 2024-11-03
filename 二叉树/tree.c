#include <stdio.h>
#include <stdlib.h>

struct btree{
    int val;
    struct btree *left;
    struct btree *right;
};

struct qnode{
    void *ptr;
    struct qnode *next;
};

struct queue{
    int len;
    struct qnode *node;
};

void init(struct btree **node, int height){
    if(height == 0) return;

    *node = (struct btree*) malloc(sizeof(struct btree));
    (*node) -> val = height;
    (*node) -> left = NULL;
    (*node) -> right = NULL;

    init(&((*node) -> left), height - 1);
    init(&((*node) -> right), height - 1);
}

/* 简易队列实现 */
void push(struct queue *queue, void *ptr){
    struct qnode *node = queue -> node;
    if(node == NULL){
        node = (struct qnode*) malloc(sizeof(struct qnode));
        node -> ptr = ptr;
        node -> next = NULL;
        queue -> node = node;
    }else{
        while(node -> next != NULL){
            node = node -> next;
        }

        node -> next = (struct qnode*) malloc(sizeof(struct qnode));
        node -> next -> ptr= ptr;
        node -> next -> next = NULL;
    }

    queue -> len += 1;
}

void* pop(struct queue *queue){
    struct qnode *node = queue -> node;
    
    if(node == NULL){
        return NULL;
    }

    void *ptr = node -> ptr;
    queue -> node = node -> next;
    free(node);
    queue -> len -= 1;

    return ptr;
}

/* 前序遍历/深度优先遍历 */
void printTreeD(struct btree *root){
    if(root == NULL) return;

    printf("val = %d\n", root -> val);
    printTree(root -> left);
    printTree(root -> right);
}

/* 层次遍历/广度优先遍历 */
void printTreeB(struct btree *root){
    struct queue queue;
    struct btree *node;

    queue.len = 0;
    queue.node = NULL;
    push(&queue, root);

    while(queue.len != 0){
        node = (struct btree*) pop(&queue);
        if(node -> left != NULL) push(&queue, node -> left);
        if(node -> right != NULL) push(&queue, node -> right);
        printf("val = %d\n", node -> val);
    }
}

int main(void){
    struct btree *root;
    
    init(&root, 8);
    printTree(root);
    printf("----------------\n");
    printTreeL(root);
}