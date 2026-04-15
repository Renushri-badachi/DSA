#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int bookID;
    struct Node *left, *right;
};

// Create node
struct Node* createNode(int id) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->bookID = id;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert function
struct Node* insert(struct Node* root, int id) {
    if (root == NULL)
        return createNode(id);

    if (id < root->bookID)
        root->left = insert(root->left, id);
    else
        root->right = insert(root->right, id);

    return root;
}

// Search function
void search(struct Node* root, int key) {
    if (root == NULL) {
        printf("Book not found\n");
        return;
    }

    if (root->bookID == key) {
        printf("Book found: ID = %d\n", key);
        return;
    }

    if (key < root->bookID)
        search(root->left, key);
    else
        search(root->right, key);
}

// Inorder traversal
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->bookID);
        inorder(root->right);
    }
}

// Main function (Menu driven)
int main() {
    struct Node* root = NULL;
    int choice, id;

    while (1) {
        printf("\n--- LIBRARY MENU ---\n");
        printf("1. Insert Book\n");
        printf("2. Search Book\n");
        printf("3. Display Books (Sorted)\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Book ID: ");
                scanf("%d", &id);
                root = insert(root, id);
                break;

            case 2:
                printf("Enter Book ID to search: ");
                scanf("%d", &id);
                search(root, id);
                break;

            case 3:
                printf("Books in sorted order: ");
                inorder(root);
                printf("\n");
                break;

            case 4:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}
