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
        struct directedGraph *reverseGraph;
    }graph;

    void displayGraph(graph *graph);
    void addEdge(graph *graph, int src, int dest);
    graph *createGraph(int n);
    adjnode *createNode(int v);
    void topologicalSort(graph *g);
    void recurTop(graph *g,int v, int *visited);
    void lcaDAG(graph *g, int child1, int child2);
    void countJumps(graph *g, int node, int *jumps, int count);
    
#endif


