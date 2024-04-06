https://www.cnblogs.com/xiekun/p/14386910.html

根据文章的内容，我们将逐步实现二叉查找树（BST）和红黑树（RBT）的C语言版本。首先，我们从二叉查找树的实现开始。

### 1. 二叉查找树（BST）的实现

```c
#include <stdio.h>
#include <stdlib.h>

// 定义二叉查找树节点结构体
typedef struct BsTreeNode {
    int key;
    struct BsTreeNode *left;
    struct BsTreeNode *right;
} BsTreeNode;

// 创建新节点
BsTreeNode* createNode(int key) {
    BsTreeNode* newNode = (BsTreeNode*)malloc(sizeof(BsTreeNode));
    if (!newNode) {
        return NULL;
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 插入节点
BsTreeNode* insert(BsTreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    // 如果key已存在，不插入
    return root;
}

// 删除节点
void deleteNode(BsTreeNode** root, int key) {
    if (*root == NULL) {
        return;
    }
    if (key < (*root)->key) {
        deleteNode(&((*root)->left), key);
    } else if (key > (*root)->key) {
        deleteNode(&((*root)->right), key);
    } else {
        // 找到要删除的节点
        if ((*root)->left == NULL) {
            BsTreeNode* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            BsTreeNode* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            // 找到右子树的最小节点（后继）
            BsTreeNode* successor = (*root)->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            // 将后继节点的值复制到当前节点
            (*root)->key = successor->key;
            // 删除后继节点
            deleteNode(&((*root)->right), successor->key);
        }
    }
}

// 中序遍历
void inorderTraversal(BsTreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// 主函数
int main() {
    BsTreeNode* root = NULL;
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 4);
    insert(&root, 6);
    insert(&root, 8);

    printf("Inorder traversal of the given tree:\n");
    inorderTraversal(root);
    printf("\n");

    deleteNode(&root, 7);
    printf("Inorder traversal after deleting 7:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
```

这段代码实现了二叉查找树的基本插入、删除和中序遍历操作。接下来，我们将实现红黑树的特性和操作。由于红黑树的实现较为复杂，我将在后续的回复中继续提供代码。如果您需要进一步的帮助，请告诉我。


