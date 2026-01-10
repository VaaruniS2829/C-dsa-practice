#include <stdio.h>

int main()
{
    int n, i, j;
    int graph[10][10];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adjacency matrix with 0
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            graph[i][j] = 0;
        }
    }

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nAdjacency Matrix of the graph:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
