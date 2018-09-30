
#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
    struct node *root = NULL;
    
    root = insert(root,7);
    insert(root,3);
    insert(root,2);
    insert(root,6);
    insert(root,4);
    struct node *l = lca(root,6,2);
    structure(root,0);
    int isThere = checkNode(root,1);
    
    printf(" %i The LCA of %i and %i is : %i\n", isThere,6,2,l->key);
    return (0);
}

