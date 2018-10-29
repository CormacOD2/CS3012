#ifndef BINARYTREE_H
#define BINARYTREE_H

    //struct declarations
    typedef struct node{
        int key;
        struct node *left, *right;
    }node;
    
    //function declarations
    node* insert(struct node* n, int k);
    int checkNode(struct node *root, int k);
    int isBST(struct node *root, int low, int high);
    node *lca(struct node *root, int k1, int k2);
    void structure(struct node *root, int lvl);
    node *convertToBST(struct node *root);
    void inOrder(struct node* n, int *order, int *i);
    int countNodes(struct node* root);
    void mergeSort(int *array, int left, int right);
#endif

