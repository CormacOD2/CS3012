#include <stdio.h>
#include <stdlib.h>
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
void addEdge(graph *graph, int source, int destination)
{
    adjnode *newNode = createListNode(destination);
    newNode->next = graph->adjListArr[source].head;
    graph->adjListArr[source].head = newNode;
    graph->adjListArr[source].size++;
}

// print adj list of graph
void displayGraph(graph *graph)
{
    int i;
    for (i = 0; i < graph->size; i++)
    {
        adjnode *adjPtr = graph->adjListArr[i].head;
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


