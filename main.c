#include "stack.h"
#include "binaryTree.h"
#include "input.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

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
    graph *DAG = createGraph(6);

    addEdge(DAG,0,1);
    addEdge(DAG,0,3);
    addEdge(DAG,1,2);
    addEdge(DAG,2,5);
    addEdge(DAG,3,4);
    addEdge(DAG,4,5);
    addEdge(DAG,5,6);
    
    graph *reverse=createGraph(6);
    
    addEdge(reverse,1,0);
    addEdge(reverse,3,0);
    addEdge(reverse,2,1);
    addEdge(reverse,5,2);
    addEdge(reverse,4,3);
    addEdge(reverse,5,4);
    addEdge(reverse,6,5);

    
    
    printf("\nDAG : ");
    displayGraph(DAG);
    topologicalSort(DAG);
    lcaDAG(reverse,4,2);
    
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
    }*/
    return (0);
     
}

