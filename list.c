
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct dataNode *makeNode(){
    struct dataNode *temp = malloc(sizeof(struct dataNode));
    temp->next = NULL;
    temp->adj = malloc(sizeof(struct list));
    return temp;
}

int addNode(struct list *l, int val){
    struct dataNode *temp,*n;
    temp = makeNode();
    temp->data = val;
    if(l->head == NULL){
        l->head = temp;
        l->tail = temp;
    }
    else{
        l->tail->next = temp;
        l->tail = temp;
    }
    return 0;
}

int printList(struct list *l){
    struct dataNode *temp = l->head;
    while(temp != NULL){
        printf("%i ,",temp->data);
        temp = temp->next;
    }
    return 0;
}

