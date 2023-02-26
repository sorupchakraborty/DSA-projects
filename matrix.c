#include <stdio.h>

int main()
{
    int n;
    printf("Enter matrix n X n :\n");
    scanf("%d", &n);
    int a1[n][n];
    int upper = 0, lower = 0, tri = 0;
    printf("Enter matrix eliments:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a1[i][j]);
        }
    }

    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < n; j++)
        {
            printf("\t%d", a1[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < i && a1[i][j] == 0)
            {
                upper = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > i && a1[i][j] == 0)
            {
                lower = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a1[i][i] != 0 && a1[i][i + 1] != 0 && a1[i + 1][i] != 0)
            {
                tri = 1;
            }
        }
    }

    if (lower == 1 && upper == 1)
    {
        printf("Tri Diagonal matrix\n");
    }
    else if (lower == 1 && upper == 0)
    {
        printf("Lower Triangular matrix\n");
    }
    else if (upper == 1 && lower == 0)
    {
        printf("Upper Triangular matrix\n");
    }
    else
    {
        printf("Normal matrix\n");
    }

    return 0;
}
