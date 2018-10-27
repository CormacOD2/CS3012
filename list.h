#ifndef LIST_H
#define LIST_H

    //struct declarations
    struct list{
        struct dataNode *head,*tail;
    };

    struct dataNode{
        int data;
        struct dataNode *next;
        struct list *adj;
    };

    // function declarations
    struct dataNode *makeNode();
    int addNode(struct list *l, int val);
    int printList(struct list *l);
    struct dataNode *findNode(struct list *l, int val);

#endif


