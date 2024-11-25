#include <stdio.h>
#include <limits.h>

#define V 9

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (sptSet[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], sptSet[V], prev[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
        prev[i] = -1;
    }
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    printf("Dijkstra Algorithm - Shortest distances and paths from source vertex %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d \t %d \t Path: ", i, dist[i]);
        int path[V], pathIndex = 0;
        for (int j = i; j != -1; j = prev[j]) {
            path[pathIndex++] = j;
        }
        for (int j = pathIndex - 1; j >= 0; j--) {
            printf("%d ", path[j]);
        }
        printf("\n");
    }
}

void bellmanFord(int graph[V][V], int src) {
    int dist[V], prev[V];
    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    dist[src] = 0;

    for (int i = 1; i < V; i++) {
        for (int u = 0; u < V; u++) {
            for (int v = 0; v < V; v++) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    prev[v] = u;
                }
            }
        }
    }

    printf("\nBellman-Ford Algorithm - Shortest distances and paths from source vertex %d:\n", src);
    for (int i = 0; i < V; i++) {
        printf("%d \t %d \t Path: ", i, dist[i]);
        int path[V], pathIndex = 0;
        for (int j = i; j != -1; j = prev[j]) {
            path[pathIndex++] = j;
        }
        for (int j = pathIndex - 1; j >= 0; j--) {
            printf("%d ", path[j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0, 0, 0, 8, 0},
        {4, 0, 8, 0, 0, 0, 0, 0, 0},
        {0, 8, 0, 7, 0, 4, 0, 0, 0},
        {0, 0, 7, 0, 9, 14, 0, 0, 0},
        {0, 0, 0, 9, 0, 10, 0, 0, 0},
        {0, 0, 4, 14, 10, 0, 2, 0, 0},
        {0, 0, 0, 0, 0, 2, 0, 1, 6},
        {8, 0, 0, 0, 0, 0, 1, 0, 7},
        {0, 0, 0, 0, 0, 0, 6, 7, 0}
    };

    int source;
    printf("Enter the source vertex (0 to 8): ");
    scanf("%d", &source);

    printf("\nDijkstra's Algorithm Results:\n");
    dijkstra(graph, source);

    printf("\nBellman-Ford Algorithm Results:\n");
    bellmanFord(graph, source);

    return 0;
}
