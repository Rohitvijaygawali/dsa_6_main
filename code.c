#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *cn(int data) {
    struct node *nn = (struct node*)malloc(sizeof(struct node));
    nn->data = data;
    nn->left = NULL;
    nn->right = NULL;
    return nn;
}

struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return cn(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void display(struct node *root) {
    if (root != NULL) {
        display(root->left);
        printf("%d\t", root->data);
        display(root->right);
    }
}

void preorder(struct node *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(struct node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

void postorder(struct node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

void search(struct node *root, int data) {
    if (root == NULL) {
        printf("Data not found\n");
        return;
    }
    if (root->data == data) {
        printf("Data is found\n");
    } else if (data < root->data) {
        search(root->left, data);
    } else {
        search(root->right, data);
    }
}

int count(struct node *root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return count(root->left) + count(root->right);
}

int main() {
    struct node *root = NULL;
    int data, ch;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Insert\n2. Display\n3. Pre-order\n4. In-order\n5. Post-order\n6. Search\n7. Count Leaf Nodes\n8. Exit\n");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                root = insert(root, data);
                printf("Entry successfully\n");
                break;
            case 2:
                printf("Displaying the tree (in-order):\n");
                display(root);
                printf("\n");
                break;
            case 3:
                printf("Pre-order traversal:\n");
                preorder(root);
                printf("\n");
                break;
            case 4:
                printf("In-order traversal:\n");
                inorder(root);
                printf("\n");
                break;
            case 5:
                printf("Post-order traversal:\n");
                postorder(root);
                printf("\n");
                break;
            case 6:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                search(root, data);
                break;
            case 7:
                printf("Leaf node count: %d\n", count(root));
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
