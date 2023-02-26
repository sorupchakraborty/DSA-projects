#include <stdio.h>
typedef struct poly
{
    int co;
    int ex;
}p;


int main()
{
    int term1,term2,term3;
    int k;

    printf("Enter Number of terms in First Poly:\n");
    scanf("%d",&term1);
    p p1[term1];
    printf("Enter Terms of First Polynomial:\n");
   
    for(int i=0;i<term1;i++)
    {
        printf("Enter Coeffient of term (%d)\n",i+1);
        scanf("%d",&p1[i].co);
        printf("Enter exponent of term (%d)\n",i+1);
        scanf("%d",&p1[i].ex);
    }


    printf("Enter Number of terms in 2nd Polynomial:\n");
    scanf("%d",&term2);
    p p2[term2];
    printf("Enter Terms of 2nd Poly:\n");
   
    for(int i=0;i<term2;i++)
    {
        printf("Enter Coeffient of term (%d)\n",i+1);
        scanf("%d",&p2[i].co);
        printf("Enter exponent of term (%d)\n",i+1);
        scanf("%d",&p2[i].ex);
    }

	p p3[term2+term1];
	
	int p,q,r;
    p=q=r=0;
    while(p<term1 && q<term2)
    {
        if(p1[p].ex==p2[q].ex)
        {
            p3[r].co=p1[p].co+p2[q].co;
            p3[r].ex=p1[p].ex;
            p++;
            q++;
            r++;
        }
        else if(p1[p].ex>p2[q].ex)
        {
            p3[r].co=p1[p].co;
            p3[r].ex=p1[p].ex;
            p++;
            r++;
        }
        else
        {
            p3[r].co=p2[p].co;
            p3[r].ex=p2[p].ex;
            q++;
            r++;
        }
    }
    
    while(p<term1)
	{
		p3[r].co=p1[p].co;
		p3[r].ex=p1[p].ex;
		p++;
		r++;
	}

	while(q<term2)
	{
	    p3[r].co=p2[q].co;
		p3[r].ex=p2[q].ex;
		q++;
		r++;
	}
	
	printf("\nAfter the addition of polynomial:\n");
    
	for(k=0;k<r-1;k++)
	{
	    printf("%d(x^%d)+",p3[k].co,p3[k].ex);
	}
	printf("%d(x^%d)",p3[r-1].co,p3[r-1].ex);

    return 0;
}