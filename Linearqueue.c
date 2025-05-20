#include <stdio.h>
#define SIZE 5

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, item;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) { // Enqueue
            if (rear == SIZE - 1) {
                printf("Queue is full (Overflow)\n");
            } else {
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                if (front == -1) front = 0;
                rear++;
                queue[rear] = item;
                printf("Enqueued %d\n", item);
            }
        } else if (choice == 2) { // Dequeue
            if (front == -1 || front > rear) {
                printf("Queue is empty (Underflow)\n");
            } else {
                printf("Dequeued %d\n", queue[front]);
                front++;
            }
        } else if (choice == 3) { // Display
            if (front == -1 || front > rear) {
                printf("Queue is empty\n");
            } else {
                printf("Queue elements: ");
                for (int i = front; i <= rear; i++) {
                    printf("%d ", queue[i]);
                }
                printf("\n");
            }
        } else if (choice == 4) {
            break;
        } else {
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
