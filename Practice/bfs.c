#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100


struct Queue {
    int items[MAX_VERTICES];
    int front;
    int rear;
};


void initializeQueue(struct Queue *q) {
    q->front = -1;
    q->rear = -1;
}


int isEmpty(struct Queue *q) {
    return q->front == -1;
}


void enqueue(struct Queue *q, int value) {
    if (q->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
    } else {
        if (q->front == -1) {
            q->front = 0;
        }
        q->rear++;
        q->items[q->rear] = value;
    }
}


int dequeue(struct Queue *q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = q->rear = -1;
        }
    }
    return item;
}


void BFS(int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES], int vertices, int startVertex) {
    int visited[MAX_VERTICES] = {0};
    struct Queue q;
    initializeQueue(&q);

    visited[startVertex] = 1;
    printf("Breadth-First Search starting from vertex %d: ", startVertex);
    printf("%d ", startVertex);
    enqueue(&q, startVertex);

    while (!isEmpty(&q)) {
        int currentVertex = dequeue(&q);

        for (int i = 0; i < vertices; i++) {
            if (adjacencyMatrix[currentVertex][i] && !visited[i]) {
                visited[i] = 1;
                printf("%d ", i);
                enqueue(&q, i);
            }
        }
    }
}

int main() {
    int vertices, startVertex;
    printf("Ananta Walli, A2305221322");
    printf("\nEnter the number of vertices: ");
    scanf("%d", &vertices);

    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];

    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adjacencyMatrix[i][j]);
        }
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    BFS(adjacencyMatrix, vertices, startVertex);

    return 0;
}
