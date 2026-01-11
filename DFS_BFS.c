#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;

// ---------- BFS Queue Functions ----------
void enqueue(int value) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int isEmpty() {
    return front == -1 || front > rear;
}

// ---------- BFS Traversal ----------
void bfs(int start, int vertices) {
    for (int i = 0; i < vertices; i++)
        visited[i] = 0;

    front = rear = -1;
    printf("BFS traversal: ");
    visited[start] = 1;
    enqueue(start);

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] == 1 && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
    printf("\n");
}

// ---------- DFS Traversal ----------
void dfs(int vertex, int vertices) {
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < vertices; i++) {
        if (adj[vertex][i] == 1 && !visited[i]) {
            dfs(i, vertices);
        }
    }
}

// ---------- Main Function ----------
int main() {
    int vertices, edges, src, dest, start, i, choice;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    printf("Enter %d edges (src dest):\n", edges);
    for (i = 0; i < edges; i++) {
        scanf("%d %d", &src, &dest);
        adj[src][dest] = 1;
        adj[dest][src] = 1; // Undirected graph
    }


    printf("1. BFS\n2. DFS\n");
    printf("Choose Traversal:\n");
    scanf("%d", &choice);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    if (choice == 1) {
        bfs(start, vertices);
    } else if (choice == 2) {
        for (i = 0; i < vertices; i++)
            visited[i] = 0;
        printf("DFS traversal: ");
        dfs(start, vertices);
        printf("\n");
    } else {
        printf("Invalid choice.\n");
    }

    return 0;
}
