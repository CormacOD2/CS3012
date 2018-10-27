
#include "list.h"
#include <stdio.h>
#include <stdlib.h>

struct list *nodeList;
int size;

//init a DAG
struct list *createDAG(){
    if(nodeList == NULL){
        nodeList = malloc(sizeof(struct list));
    }
    size = 0;
    return nodeList;
}

//add nodes to DAG , arg 1 = node and arg 2 = adjacent to node
//if node not in DAG , will add it to DAG list
//if val not in DAG , will add it to DAG list
//adds val to node's adj list
int insertIntoDAG(int node, int val){
    struct dataNode *t1 = findNode(nodeList, node);
    struct dataNode *t2 = findNode(nodeList, val);
    if(t1 == NULL) {
        addNode(nodeList,node);
        size++;
        t1 = findNode(nodeList,node);
    }
    if(t2 == NULL) {
        addNode(nodeList,val);
        size++;
        t2 = findNode(nodeList, val);
    }
    addNode(t1->adj,t2->data);
    return 0;
}

int getSize(){
    return size;
}