
#include "list.h"
#include "binaryTree.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>


// runs through BT confirming it is a BST , True == 1, False == 0
 int isBST(struct node *root, int low, int high) {
        if(root == NULL) {
            return 1;
        }
        if(root->key <= low || root->key >= high) {
            return 0;
        }
        return isBST(root->left, low, root->key) &&
               isBST(root->right, root->key, high);
    }

//testing binaryTree.c functions
void testFunctions(struct node *root){
    struct node *temp = NULL;

    //---------@ TEST : inOrder -----------------
    int inOrderArray[11];
    int cmpArray[11] = {-5,-4,-3,-2,-1,0,1,2,3,4,5};
    int i = 0;
    inOrder(root,inOrderArray,&i);
    int inOrderBool = 0;
    for(int i = 0; i < 11 ; i++){
        if(cmpArray[i] != inOrderArray[i]) inOrderBool = 1;
    }
    if(inOrderBool == 0 && i == 11) printf("Testing : inOrder with BT : Correct\n");
    else printf("Testing : inOrder with BT : Failure\n");
    //---------@ TEST : countNodes -----------------
    if(countNodes(temp) == 0) printf("Testing : countNode with empty BT : Correct\n");
    else printf("Testing : countNode with empty BT : Failure\n");
    if(countNodes(root)==11) printf("Testing : countNode with BT : Correct\n");
    else printf("Testing : countNode with BT : Failure\n");
    //---------@ TEST : checkNodes -----------------
    if(checkNode(root,10) == 0) printf("Testing : checkNode with wrong key : Correct\n");
    if(checkNode(root,1) ==1) printf("Testing : checkNodes with key present in BT : Correct\n");
    //---------@ TEST : ConvertToBST & mergeSort -----------------
    struct node *bst = root;
    bst = convertToBST(root);
    int bool = isBST(bst,INT_MAX,INT_MIN);
    if(bool == 0) printf("Testing : convertToBST and mergeSort : Correct\n");
    else printf("Testing : convertToBST and mergeSort : Failure\n");
    structure(bst,0);
}

int main(int argc, char** argv) {
    
    struct list *nodeList = malloc(sizeof(struct list));
    addNode(nodeList,1);
    addNode(nodeList,2);
    printList(nodeList);
    return 0;
    
    /*
    struct node *root = NULL;
    root = fileInput();
    structure(root,0);
    if(boolTest() == 1){
        testFunctions(root);
    }else{
        int bool = 0;
        bool = bstInput();

        if(bool == 1){
            root = convertToBST(root);
            structure(root,0);
        }
        while(1){
            lcaInput(root);
        }
    }
    return (0);
     */
}

