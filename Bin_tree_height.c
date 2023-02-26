//3
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
}s;
s * create(){
    s * n = (s *) malloc(sizeof(s));
    scanf("%d",&n->data);
    n->left=NULL;
    n->right=NULL;
    return n;
}
int height(s * n){
    if(n!=NULL)
    return 0;
    else{
        int lh=height(n->left);
        int rh=height(n->right);
        if(lh>rh)
        return(lh+1);
        else
        return(rh+1);
    }
}
int main()
{
    s * root=create();
    int h= height(root);
    printf("Height of the tree:%d",h);
    return 0;
}