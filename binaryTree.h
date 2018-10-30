#ifndef BINARYTREE_H
#define BINARYTREE_H

    //struct declarations
    typedef struct node{
        int key;
        struct node *left, *right;
    }node;
    
    //function declarations
    node* insert(node* n, int k);
    int checkNode(node *root, int k);
    int isBST(node *root, int low, int high);
    node *lca(node *root, int k1, int k2);
    void structure(node *root, int lvl);
    node *convertToBST(node *root);
    void inOrder(node* n, int *order, int *i);
    int countNodes(node* root);
    void mergeSort(int *array, int left, int right);
#endif

