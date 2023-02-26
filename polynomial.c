//2
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
    int co,ex;
    struct Node* next;
}st;

st* creation(st* thead,int c,int e)
{
    st* nn=(st*)malloc(sizeof(st));
    nn->co=c;
    nn->ex=e;
    if(thead==NULL){            // for inserting the first node..
        nn->next=NULL;
        return nn;
    }
    else
    {
         nn->next=thead;
        return nn;
    }
    
}


void display(st* thead)
{
    st* temp=thead;
    if(temp==NULL){
        printf("\nEmpty..");
    }
    else{
        while(temp->next!=NULL){
            printf(" %dx^%d +",temp->co,temp->ex);
            temp=temp->next;
        }
       printf(" %dx^%d ",temp->co,temp->ex);
    }
}

st * init(int n)
{
    int i;
    st *h=NULL,*p;
    for(i=0;i<n;i++)
    {
        p=(st*)malloc(sizeof(st));
        p->next=h;
        p->co=0;
        p->ex=0;
        h=p;
    }
  return(h);
}

st * multiply(st *h1, st *h2,int k1) 
{
    st *h3,*p,*q,*r;
   
    int i,j,k,co,power;
    h3=init(k1);
    
    
    for(p=h1,i=0;p!=NULL;p=p->next,i++)
        for(q=h2,j=0;q!=NULL;q=q->next,j++)
        {
            co=p->co * q->co;
            power=p->ex+q->ex;
            for(r=h3,k=0;k<power;k++)
                r=r->next;
            r->co=r->co+co;
            r->ex=power;
        }
  return(h3);
}




void main()
{
    int a,b,n,n1,i;
    st* p1head=NULL;
   
    // Inputing the first polynomial..

    printf("Enter the no of terms of polynomial 1..");
    scanf("%d",&n);
    printf("\nEnter the polynomial in ascinding order of degree..");
    for(i=0;i<n;i++){
        printf("\nEnter the coficient and exnent of the term..");
        scanf("%d%d",&a,&b);
        p1head=creation(p1head,a,b);
    }
    printf("\nThe polynomial 1 is..");
    display(p1head);
    
    
    st* p2head=NULL;
   
    // Inputing the 2nd polynomial..

    printf("Enter the no of terms of polynomial 2..");
    scanf("%d",&n1);
    printf("\nEnter the polynomia2 in ascinding order of degree..");
    for(i=0;i<n1;i++){
        printf("\nEnter the coficient and exnent of the term..");
        scanf("%d%d",&a,&b);
        p2head=creation(p2head,a,b);
    }
    printf("\nThe polynomial 2 is..");
    display(p2head);
    
    st* p3head=NULL;
    
    p3head=multiply(p1head,p2head,(n+n1)-1);
    
    printf("\nThe polynomial 3 is..");
    display(p3head);
    
}