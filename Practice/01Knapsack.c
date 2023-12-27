#include <stdio.h>

#define MAX_ITEMS 100

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapSack(int cap, int weight[], int price[], int n, int selected[]) {
    if (n == 0 || cap == 0)
        return 0;

    if (weight[n - 1] > cap)
        return knapSack(cap, weight, price, n - 1, selected);

    int include = price[n - 1] + knapSack(cap - weight[n - 1], weight, price, n - 1, selected);
    int exclude = knapSack(cap, weight, price, n - 1, selected);

    if (include > exclude) {
        selected[n - 1] = 1;
        return include;
    } else {
        selected[n - 1] = 0;
        return exclude;
    }
}

void printSelectedItems(int selected[], int weight[], int price[], int n) {
    printf("Selected items:\n");
    for (int i = 0; i < n; i++) {
        if (selected[i] == 1) {
            printf("Item %d - Weight: %d, Value: %d\n", i + 1, weight[i], price[i]);
        }
    }
}

int main() {
    int n;
    printf("Name:Ananta Walli");
    printf("\nEnrollment Number:A2305221322");
    printf("\nEnter the number of items: ");
    scanf("%d", &n);

    int weight[MAX_ITEMS];
    int price[MAX_ITEMS];

    printf("Enter the weight and value of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &weight[i], &price[i]);
    }

    int cap;
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &cap);

    int selected[MAX_ITEMS] = {0};
    int maxVal = knapSack(cap, weight, price, n, selected);

    printf("Maximum value: %d\n", maxVal);
    printSelectedItems(selected, weight, price, n);

    return 0;
}
