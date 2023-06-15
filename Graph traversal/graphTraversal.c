#include <stdio.h>
#include "queue.h"
#define MAX_VERTICES 10
typedef struct Graph
{
    int n;
    int adj[MAX_VERTICES][MAX_VERTICES];
} Graph;

void initGraph(Graph *g)
{
    int i, j;
    for (i = 0; i < MAX_VERTICES; i++)
        for (j = 0; j < MAX_VERTICES; j++)
            (g->adj)[i][j] = 0;
}

void printgraph(Graph *g)
{
    int i, j;
    for (i = 0; i < g->n; i++)
    {
        for (j = 0; j < g->n; j++)
        {
            printf("%d ", (g->adj)[i][j]);
        }
        printf("\n");
    }
}

void dfsTraverse(Graph *g, int *visited, int v)
{
    visited[v] = 1;
    int numOfVertices = g->n;
    int i;

    printf("%d ", v);
    for (i = 0; i < numOfVertices; i++)
    {
        if (g->adj[v][i] == 1 && !visited[i])
            dfsTraverse(g, visited, i);
    }
}
void bfsTraverse(Graph *g)
{
    if (g->n <= 0)
        return;
    Queue bfsQueue;
    initQueue(&bfsQueue);
    int visited[MAX_VERTICES] = {0};
    int v;
    int i;
    enQueue(&bfsQueue, 0);
    visited[0] = 1;
    while (!isEmpty(&bfsQueue))
    {
        v = deQueue(&bfsQueue);
        printf("%d ", v);
        for (i = 0; i < MAX_VERTICES; i++)
        {
            if (g->adj[v][i] == 1 && !visited[i])
            {
                visited[i] = 1;
                enQueue(&bfsQueue, i);
            }
        }
    }
}

int main()
{
    int n;
    int e;
    int i;
    int a, b;
    int visited[MAX_VERTICES] = {0};
    Graph graph;
    initGraph(&graph);
    printf("Enter the number of vertices in the graph: \n");
    scanf("%d", &n);
    while (n > MAX_VERTICES)
    {
        printf("Max vertices is %d\n", MAX_VERTICES);
        scanf("%d", &n);
    }
    printf("Enter the number of edges in the graph: \n");
    scanf("%d", &e);
    graph.n = n;
    printf("Enter the edges of the form (a b) which means an edge between vertex a and b\n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d", &a, &b);
        graph.adj[a][b] = 1;
        graph.adj[b][a] = 1;
    }
    printf("\nAdjacency matrix\n");
    printgraph(&graph);
    printf("\nDFS: ");
    dfsTraverse(&graph, visited, 0);
    printf("\nBFS: ");
    bfsTraverse(&graph);
    return 0;
}