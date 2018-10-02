#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *FILE_NAME = "nodeInput.txt";
struct node *root = NULL;


struct node *fileInput(){
    char ch, buffer[100],temp;
    int i=0;
    FILE *f;
    char *fileName ="";
    int exitBool = 0;
    
    //allows user to select either standard build input or test input
    while(exitBool == 0){
        printf("Enter '1' for default binary tree, or '2' to run test input\n");
        fflush(stdout);
        scanf("%s",&temp);
        if(temp == '1'){
            fileName = FILE_NAME;
            exitBool = 1;
        }else if(temp <= '2'){
            fileName = "testNodeInput.txt";
            exitBool = 1;
        }
    }
    
    if((f = fopen(fileName,"r"))==NULL){
        printf("Error : File cannot be opened\n");
        exit(255);
    }
    //taking in ints from text file, allow nums to be separated by spaces,commas
    //or tabs. any typos will be discarded(chars,symbols,ect) but not crash.
    //allows for negative nums.
    int typoBool = 0;
    
    while((ch = fgetc(f)) != EOF){
        if(ch == ',' || ch == ' '|| ch == '\t'){
            typoBool = 0;
            int key = atoi(buffer);
            if(root == NULL){
                root = insert(root,key);
            }
            insert(root,key);
            bzero(buffer,32);
            i = 0;
        }else if(ch == '-' && i == 0){
            buffer[i] = ch;
            typoBool = 0;
            i++;
        }else if((ch >= '0' && ch <= '9') && typoBool == 0){
            buffer[i] = ch;
            typoBool = 0;
            i++;
        }else{
            bzero(buffer,32);
            typoBool = 1;
        }
    }
    return root;
}

//takes console input for LCA , only accepts ints , anything else will prompt
//the user to enter a correct integer
void lcaInput(){
    int num,k1,k2;
    int exit = 1;
    char term;
    //exit when both inputs are ints and also located in the BT, keep prompting
    //user if input is incorrect or key on in BT
    while(exit != 3){
        printf("\nFinding Lowest Common Ancestor, please enter key %i : \n",exit);
        if(scanf("%d%c", &num, &term) != 2 || term != '\n'){
            printf("Incorrect input , please try again !\n");
        } else {
            if(checkNode(root,num) == 0){
                printf("Sorry that key is not in the BT , please try again !\n");
            }else{
                if(exit == 1) k1 = num;
                else k2 = num;
                exit++;
            }
        }
        
    }
    struct node *temp = lca(root,k1,k2);
    if(temp == NULL){
        printf("\nThere is no Common Ancestor between %i and %i",k1,k2);
    }
    printf("\nThe Lowest Common Ancestor of %i and %i is : %i\n", k1,k2,temp->key);
}


