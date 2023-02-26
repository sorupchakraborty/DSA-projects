#include <stdio.h>
#include <malloc.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} s;

s *createNode(int data)
{
    s *n;
    n = (s *)malloc(sizeof(s));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void preOrder(s *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(s *root)
{
    if (root != NULL)
    {

        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

void inOrder(s *root)
{
    if (root != NULL)
    {

        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main()
{

    s *p = createNode(4);
    s *p1 = createNode(1);
    s *p2 = createNode(6);
    s *p3 = createNode(5);
    s *p4 = createNode(2);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);
    return 0;
}