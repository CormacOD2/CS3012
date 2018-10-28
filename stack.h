#ifndef STACK_H
#define STACK_H

    struct stackNode{
        int data;
        struct stackNode *next;
    };

    
    struct stackNode *createStack();
    struct stackNode *push(struct stackNode *head, int val);
    struct stackNode *pop(struct stackNode *head);
    void printStack(struct stackNode* head);
    
#endif 

