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
    root = insert(root,5);
    insert(root,3);
    insert(root,2);
    insert(root,6);
    structure(root,0);
    return (0);
}

