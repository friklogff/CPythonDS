https://www.cnblogs.com/xiekun/p/14386910.html

�������µ����ݣ����ǽ���ʵ�ֶ����������BST���ͺ������RBT����C���԰汾�����ȣ����ǴӶ����������ʵ�ֿ�ʼ��

### 1. �����������BST����ʵ��

```c
#include <stdio.h>
#include <stdlib.h>

// �������������ڵ�ṹ��
typedef struct BsTreeNode {
    int key;
    struct BsTreeNode *left;
    struct BsTreeNode *right;
} BsTreeNode;

// �����½ڵ�
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

// ����ڵ�
BsTreeNode* insert(BsTreeNode* root, int key) {
    if (root == NULL) {
        return createNode(key);
    } else if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    // ���key�Ѵ��ڣ�������
    return root;
}

// ɾ���ڵ�
void deleteNode(BsTreeNode** root, int key) {
    if (*root == NULL) {
        return;
    }
    if (key < (*root)->key) {
        deleteNode(&((*root)->left), key);
    } else if (key > (*root)->key) {
        deleteNode(&((*root)->right), key);
    } else {
        // �ҵ�Ҫɾ���Ľڵ�
        if ((*root)->left == NULL) {
            BsTreeNode* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            BsTreeNode* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            // �ҵ�����������С�ڵ㣨��̣�
            BsTreeNode* successor = (*root)->right;
            while (successor->left != NULL) {
                successor = successor->left;
            }
            // ����̽ڵ��ֵ���Ƶ���ǰ�ڵ�
            (*root)->key = successor->key;
            // ɾ����̽ڵ�
            deleteNode(&((*root)->right), successor->key);
        }
    }
}

// �������
void inorderTraversal(BsTreeNode* root) {
    if (root) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

// ������
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

��δ���ʵ���˶���������Ļ������롢ɾ����������������������������ǽ�ʵ�ֺ���������ԺͲ��������ں������ʵ�ֽ�Ϊ���ӣ��ҽ��ں����Ļظ��м����ṩ���롣�������Ҫ��һ���İ�����������ҡ�


