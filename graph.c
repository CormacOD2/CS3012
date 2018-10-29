#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "graph.h"
#include "stack.h"

stack *TSortStack;

// function to create nodes for adjlists
adjnode *createListNode(int v)
{
    adjnode *newNode = malloc(sizeof(adjnode));
    newNode->v = v;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with n vertices
graph *createGraph(int n)
{
    int i;
    graph *graph = malloc(sizeof(graph));
    graph->size = n;
    graph->adjListArr = malloc(n * sizeof(adjList));
    for(i = 0; i < n; i++)
    {
        graph->adjListArr[i].head = NULL;
        graph->adjListArr[i].size = 0;
    }
    return graph;
}

// add edge to directed graph, from source to destination on given graph
void addEdge(graph *g, int source, int destination)
{
    adjnode *newNode = createListNode(destination);
    newNode->next = g->adjListArr[source].head;
    g->adjListArr[source].head = newNode;
    g->adjListArr[source].size++;
}

// print adj list of graph
void displayGraph(graph *g)
{
    int i;
    for (i = 0; i < g->size; i++)
    {
        adjnode *adjPtr = g->adjListArr[i].head;
        printf("\n%d: ", i);
        while (adjPtr)
        {
            printf("%d->", adjPtr->v);
            adjPtr = adjPtr->next;
        }
        printf("NULL\n");
    }
}

//recursive call to check all adjacent nodes in topological order
void recurTop(graph *g,int v, int *visited){
    visited[v] = 1;
    adjnode *adjPtr = g->adjListArr[v].head;
    while(adjPtr){
        if(visited[adjPtr->v]==0){
            recurTop(g,adjPtr->v,visited);
        }
        adjPtr = adjPtr->next;
    }
    TSortStack = push(TSortStack,v);
}

//sorts DAG into topological order by use of stack
void topologicalSort(graph *g){
    TSortStack = createStack();
    int visited[g->size];
    int i = 0;
    while(i<g->size){
        visited[i] = 0;
        i++;
    }
    i = 0;
    while(i<g->size){
        if(visited[i]==0){
            recurTop(g,i,visited);
        }
        i++;
    }
    printf("DAG in topological order : ");
    printStack(TSortStack);
}

// given graph, current node, jump array and count will recursive find jumps too
// connected nodes
void countJumps(graph *g, int node, int *jumps, int count){
    int hop = count;
    adjnode *adjPtr = g->adjListArr[node].head;
    while(adjPtr){
        if(count < jumps[adjPtr->v]){
            jumps[adjPtr->v] = count;
            countJumps(g,adjPtr->v,jumps,hop+1);
        }
        adjPtr = adjPtr->next;
    }
}

//will call count nodes on reversed graph and find smallest amount of jumps
// to a connected node for LCA
void lcaDAG(graph *g, int child1, int child2){
 
    int child1Count[g->size];
    int child2Count[g->size];
    int i;
    
    for(i=0;i<g->size;i++){
        child1Count[i] = INT_MAX;
        child2Count[i] = INT_MAX;
    }
    
    countJumps(g,child1,child1Count,1);
    countJumps(g,child2,child2Count,1);

    int lca=INT_MAX;
    int lcaJumps = INT_MAX;
    for(i = 0; i < g->size;i++){
        if((child1Count[i]!= INT_MAX && child2Count[i] != INT_MAX)&&(child1Count[i] + child2Count[i] < lcaJumps)){
            lcaJumps = child1Count[i]+child2Count[i];
            lca = i; 
        }
    }
    
    if(lca == INT_MAX) printf("\n No LCA found between %i and %i !",child1,child2);
    else printf("LCA of %i and %i is : %i",child1,child2,lca);
}
