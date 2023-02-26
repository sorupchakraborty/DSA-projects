/*Write a menu driven program to perform following for a BST

o Create node
o Insert node in a BST.
o Delete node in a BST.
o Display function
o Inorder, pre-order, and post-order Traversal*/

#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int key;
    struct node *left;
    struct node *right;
} s;

s *create(int item)
{
    s *temp = (s *)malloc(sizeof(s));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
};

void inorder(s *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d -->", root->key);
        inorder(root->right);
    }
}

void preorder(s *root)
{
    if (root != NULL)
    {
        printf("%d \t", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(s *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d \t", root->key);
    }
}

s *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}


s *deleteNode(struct node *root, int key)
{
  // Return if the tree is empty
  if (root == NULL) return root;

  // Find the node to be deleted
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);

  else {
    // If the node is with only one child or no child
    if (root->left == NULL) {
      struct node *temp = root->right;
      free(root);
      return temp;
    }
    else if (root->right == NULL) {
      struct node *temp = root->left;
      free(root);
      return temp;
    }

    // If the node has two children
    struct node *temp = minValueNode(root->right);

    // Place the inorder successor in position of the node to be deleted
    root->key = temp->key;

    // Delete the inorder successor
    root->right = deleteNode(root->right, temp->key);
  }
  return root;
}

s *insert(s *n, int key)
{
    if (n == NULL)
    {
        return create(key);
    }
    if (key < n->key)
        n->left = insert(n->left, key);
    else if (key > n->key)
        n->right = insert(n->right, key);
    return n;
}

int main()
{
    struct node* root = NULL;
    int ch,x,y,n,key;
    int k=1;
    printf("1.To create a list.\n2.To insert a node.\n3.To delete a node.\n4.To display.\n");
    printf("5.Inorder traversal.\n6.Preorder traversal.\n7.Postorder traversal.\n");
    while(k==1)
    {
        printf("Enter your choice : \n");

        scanf("%d",&ch);
        switch (ch)
        {
            case 1:
                printf("Enter node data : ");
                scanf("%d",&y);
                root = create(y);
                inorder(root);
                break;

            case 2:
                printf("How many numbers : ");
                scanf("%d",&n);
                for(int i=0; i<n; i++)
                {
                    scanf("%d",&x);
                    if(root==NULL)
                    {
                        root = insert(root,x);
                    }
                    else{
                        insert(root,x);
                    }
                }
                inorder(root);
                break;

            case 3:
                printf("Enter data to delete: \n");
                scanf("%d",&key);
                deleteNode(root,key);
                inorder(root);
                break;

            case 4:
                inorder(root);
                break;

            case 5:
                inorder(root);
                break;

            case 6:
                preorder(root);
                break;

            case 7:
                postorder(root);
                break;

            default:
                printf("Invalid input.");
                
        }
        printf("\nPress 1 to run again or any key to exit(0)\n");
        scanf("%d",&k);
    }

}