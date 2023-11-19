#include <stdio.h>
#include <stdbool.h>

#define MAX_NODES 100

int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];

void dfs(int node, int num_nodes) {
    visited[node] = true;
    printf("%d ", node);

    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, num_nodes);
        }
    }
}

int main() {
    int num_nodes;
    printf("Enter the number of nodes in the graph: ");
    scanf("%d", &num_nodes);

    printf("Enter the adjacency matrix of the graph:\n");
    for (int i = 0; i < num_nodes; i++) {
        for (int j = 0; j < num_nodes; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    int start_node;
    printf("Enter the starting node for DFS: ");
    scanf("%d", &start_node);

    printf("DFS traversal starting from node %d: ", start_node);
    dfs(start_node, num_nodes);

    return 0;
}
