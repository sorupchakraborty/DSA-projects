/*Write a C program to create a Binary search tree for the given sequence of elements using
linked list representation and display.
Input: 22,20,11,33,13,44,14,55,15
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int key;
    struct node *left, *right;
} s;

s *newNode(int item)
{
    s *temp = (s *)malloc(sizeof(s));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(s *root)
{
    if (root != NULL)
    { //
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}

s *insert(s *node, int key)
{
    if (node == NULL)
        return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int main()
{
    s *root = NULL;
    root = insert(root, 22);
    insert(root, 20);
    insert(root, 11);
    insert(root, 33);
    insert(root, 13);
    insert(root, 44);
    insert(root, 14);
    insert(root, 55);
    insert(root, 15);

    inorder(root);
    return 0;
}