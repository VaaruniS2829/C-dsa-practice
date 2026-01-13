#include <stdio.h>

int a[20][20], visited[20], n;

/* DFS function */
void DFS(int v)
{
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for(i = 1; i <= n; i++)
    {
        if(a[v][i] == 1 && visited[i] == 0)
        {
            DFS(i);
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 1; i <= n; i++)
    {
        for(j = 1; j <= n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    for(i = 1; i <= n; i++)
        visited[i] = 0;

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    DFS(start);

    return 0;
}
