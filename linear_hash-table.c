#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int hashtable[MAX] = {0};
int size = 0;

void insert(int key) {
    if (size == MAX) {
        printf("Table is full\n");
        return;
    }
    
    int index = key % MAX;
    while (hashtable[index] != 0) {
        index = (index + 1) % MAX;
    }
    
    hashtable[index] = key;
    size++;
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < MAX; i++) {
        printf("%d: %d\n", i, hashtable[i]);
    }
}

int main() {
    int choice, key;

    while (1) {
        printf("\n--- Hash Table Interface ---\n");
        printf("1. Insert Key\n");
        printf("2. Display Hash Table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                display();
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
}