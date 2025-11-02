#include <stdio.h>
#include <math.h>
// Function to find determinant (for Singular / Non-Singular check)
int findDeterminant(int a[5][5], int n)
{
    int det = 0;
    int subMatrix[5][5];
    if (n == 1)
        return a[0][0];
    else if (n == 2)
        return (a[0][0] * a[1][1] - a[0][1] * a[1][0]);
    else
    {
        for (int x = 0; x < n; x++)
        {
            int subi = 0;
            for (int i = 1; i < n; i++)
            {
                int subj = 0;
                for (int j = 0; j < n; j++)
                {
                    if (j == x)
                        continue;
                    subMatrix[subi][subj] = a[i][j];
                    subj++;
                }
                subi++;
            }
            det = det + (pow(-1, x) * a[0][x] * findDeterminant(subMatrix, n - 1));
        }
    }
    return det;
}

int main()
{
    int rows, cols;
    int matrix[5][5];
    int i, j;

    printf("Enter number of rows (up to 5): ");
    scanf("%d", &rows);
    printf("Enter number of columns (up to 5): ");
    scanf("%d", &cols);

    printf("\nEnter elements of the matrix:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("element[%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("\nThe matrix is:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%4d", matrix[i][j]);
        }
        printf("\n");
    }

    int isSquare = 0, isZero = 1, isDiagonal = 1, isIdentity = 1, isScalar = 1;
    int isUpper = 1, isLower = 1, isSymmetric = 1, isSkewSym = 1;
    int isRow = 0, isColumn = 0;

    if (rows == cols)
        isSquare = 1;
    if (rows == 1)
        isRow = 1;
    if (cols == 1)
        isColumn = 1;

    int firstDiagonal = matrix[0][0];

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
                isZero = 0;

            if (i != j && matrix[i][j] != 0)
                isDiagonal = 0;

            if (i == j && matrix[i][j] != 1)
                isIdentity = 0;
            if (i != j && matrix[i][j] != 0)
                isIdentity = 0;

            if (i == j && matrix[i][j] != firstDiagonal)
                isScalar = 0;
            if (i != j && matrix[i][j] != 0)
                isScalar = 0;

            if (i > j && matrix[i][j] != 0)
                isUpper = 0;

            if (i < j && matrix[i][j] != 0)
                isLower = 0;

            if (isSquare)
            {
                if (matrix[i][j] != matrix[j][i])
                    isSymmetric = 0;
                if (matrix[i][j] != -matrix[j][i])
                    isSkewSym = 0;
            }
        }
    }

    printf("\n--- Matrix Type(s) ---\n");

    if (isSquare)
        printf("Square Matrix\n");
    else
        printf("Rectangular Matrix\n");

    if (isZero)
        printf("Zero (Null) Matrix\n");
    if (isRow)
        printf("Row Matrix\n");
    if (isColumn)
        printf("Column Matrix\n");
    if (isDiagonal)
        printf("Diagonal Matrix\n");
    if (isScalar)
        printf("Scalar Matrix\n");
    if (isIdentity)
        printf("Identity Matrix\n");
    if (isUpper)
        printf("Upper Triangular Matrix\n");
    if (isLower)
        printf("Lower Triangular Matrix\n");
    if (isSymmetric && isSquare)
        printf("Symmetric Matrix\n");
    if (isSkewSym && isSquare)
        printf("Skew-Symmetric Matrix\n");

    if (isSquare)
    {
        int det = findDeterminant(matrix, rows);
        if (det == 0)
            printf("Singular Matrix\n");
        else
            printf("Non-Singular Matrix\n");
    }

    char choice;
    printf("\nDo you want to compare with another matrix? (y/n): ");
    scanf(" %c", &choice);

    if (choice == 'y' || choice == 'Y')
    {
        int matrix2[5][5];
        printf("\nEnter elements of the second matrix:\n");
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                printf("element2[%d][%d]: ", i, j);
                scanf("%d", &matrix2[i][j]);
            }
        }

        int isEqual = 1;
        for (i = 0; i < rows; i++)
        {
            for (j = 0; j < cols; j++)
            {
                if (matrix[i][j] != matrix2[i][j])
                    isEqual = 0;
            }
        }

        if (isEqual)
            printf("\nBoth matrices are Equal Matrices.\n");
        else
            printf("\nMatrices are Not Equal.\n");
    }

    return 0;
}

