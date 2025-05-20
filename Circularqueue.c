#include <stdio.h>
#define SIZE 5

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, item, i;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            // Enqueue
            if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
                printf("Queue is Full\n");
            } else {
                printf("Enter the element to enqueue: ");
                scanf("%d", &item);
                if (front == -1) {
                    front = rear = 0;
                } else {
                    rear = (rear + 1) % SIZE;
                }
                queue[rear] = item;
            }
        } else if (choice == 2) {
            // Dequeue
            if (front == -1) {
                printf("Queue is Empty\n");
            } else {
                printf("Dequeued element: %d\n", queue[front]);
                if (front == rear) {
                    front = rear = -1; // Queue becomes empty
                } else {
                    front = (front + 1) % SIZE;
                }
            }
        } else if (choice == 3) {
            // Display
            if (front == -1) {
                printf("Queue is Empty\n");
            } else {
                printf("Queue elements: ");
                i = front;
                while (1) {
                    printf("%d ", queue[i]);
                    if (i == rear)
                        break;
                    i = (i + 1) % SIZE;
                }
                printf("\n");
            }
        } else if (choice == 4) {
            // Exit
            break;
        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}
