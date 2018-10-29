#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

//init stack
stack *createStack(){
    stack *head = malloc(sizeof(stack));
    head = NULL;
    return head;
}

// push val onto given stack pointer
stack *push(stack *head, int val){
    stack *temp = malloc(sizeof(stack));
    if(temp == NULL) return NULL;
    temp->data = val;
    temp->next = head;
    head = temp;
    return head;
}

//pop node off top of stack and return it
stack *pop(stack *head){
    if(head == NULL) return NULL;
    head = head->next;
    return head;
}

//simple function to print stack
void printStack(stack* head)
{
    stack *current;
    current = head;
    if(current!= NULL)
    {
        do
        {
            printf(" %d",current->data);
            current = current->next;
        }
        while (current!= NULL);
        printf("\n");
    }
    else
    {
        printf("The Stack is empty\n");
    }
}