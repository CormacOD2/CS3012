
#ifndef binarytree_h
#define binarytree_h

    //struct declarations
    struct node{
        int key;
        struct node *left, *right;
    };
    
    //function declarations
    struct node* insert(struct node* n, int k);
    int checkNode(struct node *root, int k);
    struct node *lca(struct node *root, int k1, int k2);
    void structure(struct node *root, int lvl);
    struct node *convertToBST(struct node *root);
    
#endif

