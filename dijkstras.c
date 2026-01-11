#include <stdio.h> 
#define V 10 
#define INF 99999 
 
void primMST(int graph[V][V], int n) { 
    int parent[V], key[V], mstSet[V]; 
 
    for (int i = 0; i < n; i++) { 
        parent[i] = -1; 
        key[i] = INF; 
        mstSet[i] = 0; 
    } 
 
    key[0] = 0;     // start from vertex 0 
 
    for (int count = 0; count < n - 1; count++) { 
        int min = INF, u = -1; 
        for (int v = 0; v < n; v++) 
            if (!mstSet[v] && key[v] < min) { min = key[v]; u = v; } 
 
        if (u == -1) break; // disconnected remaining vertices 
        mstSet[u] = 1; 
 
        for (int v = 0; v < n; v++) { 
            // edge exists (non-zero), v not in MST, and smaller key 
            if (graph[u][v] != 0 && !mstSet[v] && graph[u][v] < key[v]) { 
                parent[v] = u; 
                key[v] = graph[u][v]; 
            } 
        } 
    } 
 
    int totalCost = 0; 
    for (int i = 1; i < n; i++) { 
        if (parent[i] != -1) { 
            // NOTE: use graph[parent[i]][i] (not graph[i][parent[i]]) 
            printf("Edge %d: (%d, %d) cost: %d\n", i, parent[i] + 1, i + 1, graph[parent[i]][i]); 
            totalCost += graph[parent[i]][i]; 
        } else { 
            printf("Edge %d: (no connection) cost: 0\n", i); 
        } 
    } 
    printf("Total cost of minimum spanning tree: %d\n", totalCost); 
} 
 
int main() { 
    int n; 
    int graph[V][V]; 
 
    printf("Enter the number of vertices: "); 
    if (scanf("%d", &n) != 1 || n <= 0 || n > V) { printf("Invalid vertex count\n"); return 1; } 
 
    printf("Enter the adjacency matrix (0 for no edge):\n"); 
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) 
            scanf("%d", &graph[i][j]); 
 
    // Make matrix symmetric for undirected graph (if user entered only one side) 
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (graph[i][j] == 0 && graph[j][i] != 0) graph[i][j] = graph[j][i]; 
            else if (graph[i][j] != 0 && graph[j][i] == 0) graph[j][i] = graph[i][j]; 
        } 
    } 
 
    primMST(graph, n); 
    return 0; 
} 