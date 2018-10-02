/*
 * NOTES :  very simple binary tree code with print function 
 *          for debug purpose
 */
#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>

//------------------ Binary Tree Functions ----------------------------------

//utility function for creating a new node
struct node *createNode(int k){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = k;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//recursive function that traverses the node to insert at correct location
struct node* insert(struct node* n, int k){
    if(n == NULL) return createNode(k);
    if(k < n->key){
        n->left = insert(n->left,k);
    } else if(k > n->key){
        n->right = insert(n->right,k);
    }
    return n;
}

//check if given key is present in the BT, 1 == true , 0 == false
int checkNode(struct node *root, int k){
    if(root == NULL) return 0;
    if(root->key > k) return checkNode(root->left,k);
    if(root->key < k) return checkNode(root->right,k);
    return 1;
}

//Simple recursive function to count the amount of nodes in the BT
int countNodes(struct node* root) 
{ 
    if (root == NULL) return 0; 
    return countNodes (root->left) + countNodes (root->right) + 1; 
} 

//------------------ Binary Search tree Conversion --------------------------

//Stores inOrder traversal of the Tree in an array
void inOrder(struct node* n, int *order, int *i) 
{ 
    if (n == NULL) return; 
    inOrder(n->left, order, i); 
    order[*i] = n->key; 
    (*i)++;
    inOrder(n->right, order, i); 
} 

//standard merge sort function *DISCLAIMER* copied from my second year
//assignment
void merge(int *array, int left, int mid, int right) 
{ 
    int i, j, k; 
    int partitionL = mid - left + 1; 
    int partitionR =  right - mid; 

    int L[partitionL], R[partitionR]; 
  
    for (i = 0; i < partitionL; i++){
        L[i] = array[left + i]; 
    } 
    for (j = 0; j < partitionR; j++){ 
        R[j] = array[mid + left + j]; 
    }
    while (i < partitionL && j < partitionR) 
    { 
        if (L[i] <= R[j]) 
        { 
            array[k] = L[i]; 
            i++; 
        } 
        else
        { 
            array[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
    while (i < partitionL) 
    { 
        array[k] = L[i]; 
        i++; 
        k++; 
    } 
    while (j < partitionR) 
    { 
        array[k] = R[j]; 
        j++; 
        k++; 
    } 
} 
  

void mergeSort(int *array, int left, int right) 
{ 
    if (left < right) 
    { 
        int mid = left+(right-left)/2; 
        mergeSort(array, left, mid); 
        mergeSort(array, mid+1, right); 
        merge(array, left, mid, right); 
    } 
}

//recursively construct new BST from sorted array and returns the root pointer
struct node *arrayToBST(int *array, int start, int end) 
{ 
    if (start > end) return NULL; 
    int mid = (start + end)/2; 
    struct node *root = createNode(array[mid]); 
    root->left =  arrayToBST(array, start, mid-1); 
    root->right = arrayToBST(array, mid+1, end); 
    return root; 
}


struct node *convertToBST(struct node *root){
    int n = countNodes(root);
    int array[n];
    int i = 0;
    inOrder(root, array, &i);
    mergeSort(array,0,n-1);
    root = arrayToBST(array,0,n-1);
    return root;
}

//------------------ LCA Assignment -----------------------------------------

//simple recursive function to find LCA
struct node *lca(struct node *root, int k1, int k2){
    if(root == NULL) return NULL;
    if(root->key > k1 && root->key > k2) return lca(root->left, k1,k2);
    if(root->key < k1 && root->key < k2) return lca(root->right,k1,k2);
    return root;
}

//------------------ Print Functions ---------------------------------------
//some print formating 
void printPadding(char c, int n){
    int i;
    for(i=0;i<n;i++){
        putchar(c);
    }
}

//prints the binary tree for debugging purposes
void structure(struct node *root, int lvl){
    if(root == NULL){
        printPadding('\t',lvl);
        puts("~");
    }else{
        structure(root->right,lvl+1);
        printPadding('\t',lvl);
        printf("%d\n", root->key);
        structure(root->left,lvl+1);
    }
}




