#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 5

void insert(char [], int*, int*, char);
char del(char [], int*, int*);
void display(char [], int, int);
bool isFull(int, int);
bool isEmpty(int, int);

int main() {
    char queue[SIZE];
    int front = -1, rear = -1;
    int choice;
    char element;

    for (;;) {
        printf("\nQueue Operations\n");
        printf("=====================");
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (!isFull(front, rear)) {
                    printf("\nEnter an element: ");
                    scanf(" %c", &element);
                    insert(queue, &front, &rear, element);
                } else {
                    printf("\nQueue is Full\n");
                }
                break;
            case 2:
                if (!isEmpty(front, rear)) {
                    element = del(queue, &front, &rear);
                    printf("\nDeleted element is %c\n", element);
                } else {
                    printf("\nQueue is Empty\n");
                }
                break;
            case 3:
                if (!isEmpty(front, rear)) {
                    printf("\nContents of the Queue:\n");
                    display(queue, front, rear);
                } else {
                    printf("\nQueue is Empty\n");
                }
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice\n");
                break;
        }
    }
    return 0;
}

bool isFull(int front, int rear) {
    return ((rear + 1) % SIZE == front);
}

bool isEmpty(int front, int rear) {
    return (front == -1);
}

void insert(char queue[], int *front, int *rear, char value) {
    if (*rear == -1) {
        *front = 0;
    }
    *rear = (*rear + 1) % SIZE;
    queue[*rear] = value;
}

char del(char queue[], int *front, int *rear) {
    char element;
    element = queue[*front];
    if (*front == *rear) {
        *front = -1;
        *rear = -1;
    } else {
        *front = (*front + 1) % SIZE;
    }
    return element;
}

void display(char queue[], int front, int rear) {
    int i;

    if (front <= rear) {
        for (i = front; i <= rear; i++) {
            printf("%c\t", queue[i]);
        }
    } else {
        for (i = front; i < SIZE; i++) {
            printf("%c\t", queue[i]);
        }
        for (i = 0; i <= rear; i++) {
            printf("%c\t", queue[i]);
        }
    }
    printf("\n");
}
