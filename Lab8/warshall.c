#include <stdio.h>
#define MAX 100

void WarshallTransitiveClosure(int graph[MAX][MAX], int v)
{
    int i, j, k;

    for (k = 0; k < v; k++)
    {
        for (i = 0; i < v; i++)
        {
            for (j = 0; j < v; j++)
            {
                if (graph[i][j] || (graph[i][k] && graph[k][j]))
                    graph[i][j] = 1;
            }
        }
    }
}
int main(void)
{
    int i, j, v; // v - number of vertices
    int graph[MAX][MAX];

    printf("Warshall's Transitive Closure\n");
    printf("Enter the number of vertices : ");
    scanf("%d", &v);

    printf("Enter the adjacency matrix :\n");
    for (i = 0; i < v; i++)
        for (j = 0; j < v; j++)
            scanf("%d", &graph[i][j]);

    WarshallTransitiveClosure(graph, v);

    printf("\nThe transitive closure for the given graph is :\n");
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            printf("%d\t", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
