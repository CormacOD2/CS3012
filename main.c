#include "stack.h"
#include "binaryTree.h"
#include "graph.h"
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

char *FILE_NAME = "nodeInput.txt";
char *TEST_FILE_NAME = "testNodeInput.txt";
char *DAG_FILE_NAME ="DAGinput.txt";


//testing binaryTree.c functions
void testFunctions(struct node *root){
    node *temp = NULL;

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
    node *bst = root;
    bst = convertToBST(root);
    int bool = isBST(bst,INT_MAX,INT_MIN);
    if(bool == 0) printf("Testing : convertToBST and mergeSort : Correct\n");
    else printf("Testing : convertToBST and mergeSort : Failure\n");
    structure(bst,0);
}

int main(int argc, char** argv) {      
    node *root = NULL;
    graph *DAG = NULL;
    int exitBool = 0;
    
    while(exitBool == 0){
        char temp;
        printf("Please Enter :\n  1 : for default binary tree.\n  2 : for DAG \n  3 : for tests.\n");
        fflush(stdout);
        
        scanf("%s",&temp);
        exitBool = 1;
        
        if(temp == '1'){
            root = fileInput(FILE_NAME);
            structure(root,0);
            int bool = 0;
            bool = bstInput();

            if(bool == 1){
                root = convertToBST(root);
                structure(root,0);
            }
            while(1){
                lcaInput(root);
            }
        }else if(temp == '2'){
            DAG = DAGinput(DAG_FILE_NAME);
            displayGraph(DAG);
            //displayGraph(DAG->reverseGraph);
            while(1){
                lcaDAGInput(DAG);
            }
        }else if(temp == '3'){
            root = fileInput(TEST_FILE_NAME);
            testFunctions(root);
        }
    }
    return (0);
     
}

