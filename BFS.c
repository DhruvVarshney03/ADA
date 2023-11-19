#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 100

int adj_matrix[MAX_NODES][MAX_NODES];
int visited[MAX_NODES];
int queue[MAX_NODES];
int front = -1, rear = -1;

void bfs(int start_node, int num_nodes) {
    visited[start_node] = 1;
    queue[++rear] = start_node;

    while (front != rear) {
        int curr_node = queue[++front];
        printf("%d ", curr_node);

        for (int i = 0; i < num_nodes; i++) {
            if (adj_matrix[curr_node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                queue[++rear] = i;
            }
        }
    }
}

int main() {
    int num_nodes, start_node;
    printf("Dhruv Varshney\nA2305221157\n");
    printf("Enter the number of nodes: ");
    scanf("%d", &num_nodes);

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &adj_matrix[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &start_node);

    printf("BFS traversal: ");
    bfs(start_node, num_nodes);

    return 0;
}
