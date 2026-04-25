#include <stdio.h>
#include <limits.h>
#include <string.h>

#define V 10

int min(int a, int b) {
    return (a < b) ? a : b;
}

int bfs(int rGraph[V][V], int s, int t, int parent[], int n) {
    int visited[V];
    memset(visited, 0, sizeof(visited));

    int queue[V];
    int front = 0, rear = 0;

    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while (front < rear) {
        int u = queue[front++];
        int v = 0;

        while (v < n) {
            if (!visited[v] && rGraph[u][v] > 0) {
                queue[rear++] = v;
                parent[v] = u;
                visited[v] = 1;

                if (v == t)
                    return 1;
            }
            v++;
        }
    }
    return 0;
}

int fordFulkerson(int graph[V][V], int s, int t, int n) {
    int rGraph[V][V];
    int parent[V];
    int max_flow = 0;
    int u, v;

    u = 0;
    while (u < n) {
        v = 0;
        while (v < n) {
            rGraph[u][v] = graph[u][v];
            v++;
        }
        u++;
    }

    while (bfs(rGraph, s, t, parent, n)) {
        int path_flow = INT_MAX;

        v = t;
        while (v != s) {
            u = parent[v];
            path_flow = min(path_flow, rGraph[u][v]);
            v = parent[v];
        }

        v = t;
        while (v != s) {
            u = parent[v];
            rGraph[u][v] -= path_flow;
            rGraph[v][u] += path_flow;
            v = parent[v];
        }

        max_flow += path_flow;
    }

    return max_flow;
}

int main() {
    int n, i = 0, j, s, t;
    int graph[V][V];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    if (n > V) {
        printf("Number of vertices should be <= %d\n", V);
        return 0;
    }

    printf("Enter capacity matrix:\n");
    while (i < n) {
        j = 0;
        while (j < n) {
            scanf("%d", &graph[i][j]);
            j++;
        }
        i++;
    }

    printf("Enter source and sink: ");
    scanf("%d %d", &s, &t);

    printf("Maximum flow: %d\n", fordFulkerson(graph, s, t, n));

    return 0;
}
