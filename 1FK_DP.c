#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    int i, j;
    int **dp = (int **)malloc((n+1) * sizeof(int *));
    for(i=0; i<=n; i++) {
        dp[i] = (int *)malloc((W+1) * sizeof(int));
    }

    for(i=0; i<=n; i++) {
        for(j=0; j<=W; j++) {
            if(i==0 || j==0) {
                dp[i][j] = 0;
            }
            else if(wt[i-1] <= j) {
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            }
            else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    int result = dp[n][W];

    for(i=0; i<=n; i++) {
        free(dp[i]);
    }
    free(dp);

    return result;
}

int main() {
    int n, W;
    printf("Dhruv Varshney\nA2305221157\n");
    printf("Enter the number of items: ");
    scanf("%d", &n);

    int *wt = (int *)malloc(n * sizeof(int));
    int *val = (int *)malloc(n * sizeof(int));
    printf("Enter the weight and profit of each item:\n");
    for(int i=0; i<n; i++) {
        scanf("%d %d", &wt[i], &val[i]);
    }

    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);

    int max_val = knapsack(W, wt, val, n);
    printf("The maximum value that can be obtained is: %d\n", max_val);

    free(wt);
    free(val);

    return 0;
}
