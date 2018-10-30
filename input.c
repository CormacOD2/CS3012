#include "binaryTree.h"
#include "input.h"
#include "graph.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node *root = NULL;

node *fileInput(char *file){
    char ch, buffer[100];
    int i=0;
    FILE *f;

    if((f = fopen(file,"r"))==NULL){
        printf("Error : File cannot be opened\n");
        exit(255);
    }
    //taking in ints from text file, allow nums to be separated by spaces,commas
    //or tabs. any typos will be discarded(chars,symbols,ect) but not crash.
    //allows for negative nums.
    int typoBool = 0;
    
    while((ch = fgetc(f)) != EOF){
        if(ch == ',' || ch == ' '|| ch == '\t' || ch == '\n'){
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
            i=0;
            typoBool = 1;
        }
    }
    return root;
}

//takes console input for LCA , only accepts ints , anything else will prompt
//the user to enter a correct integer
void lcaInput(struct node *n){
    root = n;
    int num,k1,k2;
    int exit = 1;
    char term;
    //exit when both inputs are ints and also located in the BT, keep prompting
    //user if input is incorrect or key on in BT
    while(exit != 3){
        printf("\nFinding Lowest Common Ancestor, please enter key %i : \n",exit);
        fflush(stdout);
 
        if(scanf("%d%c", &num, &term) != 2 || term != '\n'){
            printf("Incorrect input , please try again !\n");
        } else {
            if(checkNode(n,num) == 0){
                printf("Sorry that key is not in the BT , please try again !\n");
            }else{
                if(exit == 1) k1 = num;
                else k2 = num;
                exit++;
            }
        }
    }
    struct node *temp = lca(n,k1,k2);
    if(temp == NULL){
        printf("\nThere is no Common Ancestor between %i and %i",k1,k2);
    }
    printf("\nThe Lowest Common Ancestor of %i and %i is : %i\n", k1,k2,temp->key);
}

// a 'boolean' function to check if user wants to convert their BT
// return 0 == False, 1 == True;
int bstInput(){
    int exitBool = 0;
    int conversionBool = 0;
    char temp;
    
    while(exitBool == 0){
        printf("\nWould you like to convert your BT into a BST ? Enter '1' yes "
                "or '2' for no.\n");
        fflush(stdout);
        scanf("%s",&temp);
        if((strcmp(&temp, "1")) == 0){
            conversionBool = 1;
            exitBool = 1;
        }else if((strcmp(&temp, "2")) == 0){
            exitBool = 1;
        }
    }
    return conversionBool;
}

graph *DAGinput(char *file){

    char ch, buffer[100];
    char temp[32];
    FILE *f;
    
    if((f = fopen(file,"r"))==NULL){
        printf("Error : File cannot be opened\n");
        exit(255);
    }

    // getting first line of file where graph size is
    int dagSize;
    if(fgets(temp, 32, f) != NULL) dagSize = atoi(temp);
    if(temp == NULL || dagSize == 0){
        printf("Error in DAG file input , please try again.");
        return NULL;
    }
    
    graph *dag = createGraph(dagSize);
    graph *reverseDag = createGraph(dagSize);
    
    int exitBool = 0;   
    int node = -1;
    int adj = -1;
    int typoBool = 0;
    int i=0;
 
    // getting two ints per line , ignores whitespace, commas and tabs
    // if not in correct format will stop and exit error
    while((ch = fgetc(f)) != EOF || exitBool == 1){
        if(ch == ',' || ch == ' '|| ch == '\t'){
            typoBool = 0;
            
            if(node == -1){
                node = atoi(buffer);
            }else if(node != -1 && adj == -1){
                adj = atoi(buffer);
                // add edge to graph , and reverse it for reverse graph
                // reset node & adj for next input
                addEdge(dag,node,adj);
                addEdge(reverseDag,adj,node);
                node = -1;
                adj = -1;
            }else{
                printf("Error in DAG file input , please try again.");
                exitBool == 1;
            }
            
            bzero(buffer,32);
            i = 0;
        }else if((ch >= '0' && ch <= '9') && typoBool == 0){
            buffer[i] = ch;
            typoBool = 0;
            i++;
        }else{
            bzero(buffer,32);
            i=0;
            typoBool = 1;
        }
    }
    dag->reverseGraph = reverseDag;
    return dag;
 
}
