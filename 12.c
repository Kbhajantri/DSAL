#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int create(int);
void linear_prob(int[], int, int);
void display(int[]);

int main() {
    int hashTable[MAX], num, key, ans = 1;

    printf("Collision handling by linear probing:\n");

    for (int i = 0; i < MAX; i++) {
        hashTable[i] = -1;
    }

    do {
        printf("\nEnter the data: ");
        scanf("%d", &num);
        key = create(num);
        linear_prob(hashTable, key, num);

        printf("\nDo you wish to continue? (1/0) ");
        scanf("%d", &ans);
    } while (ans);

    display(hashTable);

    return 0;
}

int create(int num) {
    int key = num % MAX;
    return key;
}

void linear_prob(int hashTable[MAX], int key, int num) {
    int i = key, flag = 0;

    if (hashTable[key] == -1) {
        hashTable[key] = num;
    } else {
        printf("\nCollision Detected...!!!\n");

        // Linear probing
        while (i < MAX && !flag) {
            if (hashTable[i] == -1) {
                hashTable[i] = num;
                flag = 1;
            }
            i++;
        }

        i = 0;
        while (i < key && !flag) {
            if (hashTable[i] == -1) {
                hashTable[i] = num;
                flag = 1;
            }
            i++;
        }

        if (!flag) {
            printf("\nHash table is full\n");
            display(hashTable);
            exit(1);
        }
    }
}

void display(int hashTable[MAX]) {
    int choice;

    printf("\n1. Display ALL\n2. Filtered Display\n");
    scanf("%d", &choice);

    printf("\nThe hash table is:\n");

    if (choice == 1) {
        for (int i = 0; i < MAX; i++) {
            printf("\n%d %d", i, hashTable[i]);
        }
    } else {
        for (int i = 0; i < MAX; i++) {
            if (hashTable[i] != -1) {
                printf("\n%d %d", i, hashTable[i]);
            }
        }
    }
}
