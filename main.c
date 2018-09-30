
#include "binaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    NODE *root = NULL;
    char ch, buffer[32];
    int i=0;
    FILE *f;
    
    if((f = fopen("nodeInput.txt","r"))==NULL){
        printf("File cannot be opened\n");
        exit(255);
    }
    
    while((ch = fgetc(f)) != EOF){
        if(ch == ','){
            int key = atoi(buffer);

            if(root == NULL){
                root = insert(root,key);
            }
            insert(root,key);
            
            bzero(buffer,32);
            i = 0;
        }else if(ch >= '0' && ch <= '9'){
            buffer[i] = ch;
            i++;
        }
    }
    structure(root,0);

    return (0);
}

