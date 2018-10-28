#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct stackNode *createStack(){
    struct stackNode *head = malloc(sizeof(struct stackNode));
    head = NULL;
    return head;
}

struct stackNode *push(struct stackNode *head, int val){
    struct stackNode *temp = malloc(sizeof(struct stackNode));
    if(temp == NULL){
        return NULL;
    }
    temp->data = val;
    temp->next = head;
    head = temp;
    return head;
}

struct stackNode *pop(struct stackNode *head){
    if(head == NULL) return NULL;
    struct stackNode *temp = head;
    head = head->next;
    temp->next = NULL;
    free(temp);
    return head;
}

void printStack(struct stackNode* head){
    printf("Stack Print : ");
    while(head!=NULL){
        printf(" %i",head->data);
        head = pop(head);     
    }
}