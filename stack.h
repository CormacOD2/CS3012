#ifndef STACK_H
#define STACK_H
    
    typedef struct stackNode{
        int data;
        struct stackNode *next;
    }stack;

    int getSize();
    stack *createStack();
    stack *push(struct stackNode *head, int val);
    stack *pop(struct stackNode *head);
    void printStack(struct stackNode* head);
    
#endif 

