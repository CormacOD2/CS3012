#ifndef GRAPH_H
#define GRAPH_H

    // Adjacency list node
    typedef struct adjListNode
    {
        int v;     
        struct adjListNode *next; 
    }adjnode;

    // Adjacency list 
    typedef struct list
    {
        int size;          
        adjnode *head;      
    }adjList;

    //A graph is an array of adjacency lists.
    typedef struct directedGraph
    {
        int size;        
        adjList *adjListArr;     
    }graph;

    void displayGraph(graph *graph);
    void addEdge(graph *graph, int src, int dest);
    graph *createGraph(int n);
    adjnode *createNode(int v);
    void topologicalSort(graph *g);
    void recurTop(graph *g,int v, int *visited);

#endif


