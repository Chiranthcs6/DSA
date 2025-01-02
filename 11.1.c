#include <stdio.h>
#include <stdlib.h>

int a[20][20], q[20], visited[20], reach[20];
int n, i, j, f = 0, r = -1, count = 0;

void bfs(int v) {
    int i;
    visited[v] = 1; 
    q[++r] = v;    

    while (f <= r) {
        int current = q[f++];
        for (i = 1; i <= n; i++) {
            if (a[current][i] && !visited[i]) { 
                q[++r] = i;  
                visited[i] = 1;
            }
        }
    }
}

void dfs(int v) {
    int i;
    reach[v] = 1; 
    for (i = 1; i <= n; i++) {
        if (a[v][i] && !reach[i]) {
            count++;
            printf("\n%d -> %d", v, i);
            dfs(i);         }
    }
}

int main() {
    int v, choice;
    printf("\nEnter the number of vertices: ");
    scanf("%d", &n);

  
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
        reach[i] = 0;
    }

    printf("\nEnter graph data in matrix form:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);  
        }
    }

    while (1) {
        printf("\n1. BFS\n2. DFS\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter the starting vertex for BFS: ");
                scanf("%d", &v);

                if (v < 1 || v > n) {
                    printf("\nInvalid starting vertex.");
                } else {
                    bfs(v);
                    printf("\nThe nodes reachable from %d are:\n", v);
                    for (i = 1; i <= n; i++) {
                        if (visited[i])
                            printf("%d ", i);
                    }
                }
                break;

            case 2:
                count = 0; 
                printf("\nPerforming DFS from vertex 1:");
                dfs(1);
                if (count == n - 1)
                    printf("\nGraph is connected.");
                else
                    printf("\nGraph is not connected.");
                break;

            case 3:
                exit(0);

            default:
                printf("\nPlease enter a valid choice.");
        }
    }

    return 0;
}
