/* 
 * File:   main.c
 * Author: Cormac O'Dwyer
 *
 * Created on 29 September 2018, 18:09
 * 
 * NOTES :  very simple binary tree code with print function 
 *          for debug purpose
 */

#include <stdio.h>
#include <stdlib.h>

//node structure for BT
struct node{
    int key;
    struct node *left, *right;
};

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

struct node *lca(struct node *root, int k1, int k2){
    if(root == NULL) return NULL;
    if(root->key > k1 && root->key > k2) return lca(root->left, k1,k2);
    if(root->key < k1 && root->key < k2) return lca(root->right,k1,k2);
    return root;
}

//some print formating 
void printPadding(char c, int n){
    int i;
    for(i=0;i<n;i++){
        putchar(c);
    }
}

//prints the binary tree for debugging purposes
void structure(struct node *root, int lvl){
    int i;
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

