
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

//allocate memory for node
struct dataNode *makeNode(){
    struct dataNode *temp = malloc(sizeof(struct dataNode));
    temp->next = NULL;
    temp->adj = malloc(sizeof(struct list));
    return temp;
}

//add a node to a given list
int addNode(struct list *l, int val){
    struct dataNode *temp;
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

//search list to see if given node is present , return NULL if not
struct dataNode *findNode(struct list *l, int val){
    struct dataNode *temp;
    temp = l->head;
    if(temp == NULL) return NULL;
    while(temp != NULL){
        if(temp->data == val) return temp;
        temp = temp->next;
    }
    return NULL;
}

//simple func to print list
int printList(struct list *l){
    struct dataNode *temp = l->head;
    while(temp != NULL){
        printf("%i ,",temp->data);
        temp = temp->next;
    }
    return 0;
}

