#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *FILE_NAME = "nodeInput.txt";
struct node *root = NULL;
void fileInput(){
    char ch, buffer[1000],temp;
    int i=0;
    FILE *f;
    char *fileName ="";
    int exitBool = 0;
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
        while((ch = fgetc(f)) != EOF){
        if(ch == ',' || ch == ' '|| ch == '\t'){
            int key = atoi(buffer);
            if(root == NULL){
                root = insert(root,key);
            }
                        insert(root,key);
            bzero(buffer,32);
            i = 0;
        }else if(ch == '-' && i == 0){
            buffer[i] = ch;
            i++;
        }else if(ch >= '0' && ch <= '9'){
            buffer[i] = ch;
            i++;
        }else{
            bzero(buffer,32);
        }
    }
}
int main(int argc, char** argv) {
    fileInput();
    structure(root,0);
    return (0);
}

