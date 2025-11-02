#include <stdio.h>
int main()
{
    int a[3][3], b[3][3], c[3][3] = {0};
    int r1, c1, r2, c2;
    int i, j, k;

    printf("Enter rows and columns of first matrix (max 3x3): ");
    scanf("%d %d", &r1, &c1);

    printf("Enter rows and columns of second matrix (max 3x3): ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2)
    {
        printf("\nError: Matrix multiplication not possible!\n");
        printf("Number of columns in first matrix must equal number of rows in second.\n");
        return 0;
    }

    printf("\nEnter elements of first matrix:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nEnter elements of second matrix:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
        {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &b[i][j]);
        }
    }

    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    printf("\nMatrix 1:\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c1; j++)
            printf("%4d", a[i][j]);
        printf("\n");
    }

    printf("\nMatrix 2:\n");
    for (i = 0; i < r2; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%4d", b[i][j]);
        printf("\n");
    }

    printf("\nResultant Matrix (1 x 2):\n");
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
            printf("%4d", c[i][j]);
        printf("\n");
    }

    return 0;
}
