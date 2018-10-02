
#include "binaryTree.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char** argv) {
    struct node *root = NULL;
    root = fileInput();
    structure(root,0);
    int bool = 0;
    bool = bstInput();
    
    if(bool == 1){
        root = convertToBST(root);
        structure(root,0);
    }
    lcaInput(root);
    return (0);
}

