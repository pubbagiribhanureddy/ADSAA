#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int ORDER;
int MAX_KEYS;
int MIN_KEYS;

typedef struct BTreeNode {
    int *keys;
    struct BTreeNode** children;
    int numKeys;
    bool isLeaf;
} BTreeNode;

BTreeNode* createNode(bool isLeaf) {
    BTreeNode* node = (BTreeNode*)malloc(sizeof(BTreeNode));
    node->isLeaf = isLeaf;
    node->numKeys = 0;
    node->keys = (int*)malloc((ORDER - 1) * sizeof(int));
    node->children = (BTreeNode**)malloc(ORDER * sizeof(BTreeNode*));
    for (int i = 0; i < ORDER; i++)
        node->children[i] = NULL;
    return node;
}

bool search(BTreeNode* root, int key) {
    int i = 0;
    while (i < root->numKeys && key > root->keys[i])
        i++;
    if (i < root->numKeys && key == root->keys[i])
        return true;
    if (root->isLeaf)
        return false;
    return search(root->children[i], key);
}

void splitChild(BTreeNode* parent, int i, BTreeNode* fullChild) {
    BTreeNode* newChild = createNode(fullChild->isLeaf);
    newChild->numKeys = MIN_KEYS;

    for (int j = 0; j < MIN_KEYS; j++)
        newChild->keys[j] = fullChild->keys[j + MIN_KEYS + 1];

    if (!fullChild->isLeaf) {
        for (int j = 0; j <= MIN_KEYS; j++)
            newChild->children[j] = fullChild->children[j + MIN_KEYS + 1];
    }

    for (int j = parent->numKeys; j >= i + 1; j--)
        parent->children[j + 1] = parent->children[j];

    parent->children[i + 1] = newChild;

    for (int j = parent->numKeys - 1; j >= i; j--)
        parent->keys[j + 1] = parent->keys[j];

    parent->keys[i] = fullChild->keys[MIN_KEYS];
    parent->numKeys++;

    fullChild->numKeys = MIN_KEYS;
}

void insertNonFull(BTreeNode* node, int key) {
    int i = node->numKeys - 1;
    if (node->isLeaf) {
        while (i >= 0 && key < node->keys[i]) {
            node->keys[i + 1] = node->keys[i];
            i--;
        }
        node->keys[i + 1] = key;
        node->numKeys++;
    } else {
        while (i >= 0 && key < node->keys[i])
            i--;
        i++;
        if (node->children[i]->numKeys == MAX_KEYS) {
            splitChild(node, i, node->children[i]);
            if (key > node->keys[i])
                i++;
        }
        insertNonFull(node->children[i], key);
    }
}

BTreeNode* insert(BTreeNode* root, int key) {
    if (root->numKeys == MAX_KEYS) {
        BTreeNode* newRoot = createNode(false);
        newRoot->children[0] = root;
        splitChild(newRoot, 0, root);
        insertNonFull(newRoot, key);
        return newRoot;
    } else {
        insertNonFull(root, key);
        return root;
    }
}

void inorderTraversal(BTreeNode* root) {
    if (root != NULL) {
        int i;
        for (i = 0; i < root->numKeys; i++) {
            inorderTraversal(root->children[i]);
            printf("%d ", root->keys[i]);
        }
        inorderTraversal(root->children[i]);
    }
}

int main() {
    printf("Enter the order of the B-Tree: ");
    scanf("%d", &ORDER);
    MAX_KEYS = ORDER - 1;
    MIN_KEYS = (ORDER / 2) - 1;

    int n;
    printf("Enter the number of elements to insert: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    BTreeNode* root = createNode(true);
    for (int i = 0; i < n; i++) {
        root = insert(root, arr[i]);
    }

    printf("\nInorder traversal of B-Tree:\n");
    inorderTraversal(root);
    printf("\n");

    int key;
    printf("\nEnter a key to search: ");
    scanf("%d", &key);
    printf(search(root, key) ? "Key found!\n" : "Key not found.\n");

    return 0;
}