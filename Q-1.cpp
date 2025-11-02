#include<stdio.h>
int main ()
{
	int matrix[3][3] , cofactor[3][3], adjoint[3][3] , inverse[3][3], determinant=0;
	printf("\n Enter elements for 3x3 matrix: ");
	for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			printf("\n Element [%d][%d] : ", i , j);
			scanf("%d",&matrix[i][j]);
		}
	}
	printf("\n Original Matrix:\n");
		for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			printf("%d\t",matrix[i][j]);
			
		}
		printf("\n");
	}
	// transpose
	printf("\n Transpose of Matrix:\n");
		for (int i=0; i<3; i++)
	{
		for (int j=0; j<3; j++)
		{
			printf("%d\t",matrix[j][i]);
		}
		printf("\n");
	}
	   // Determinant
	  
    for (int i = 0; i < 3; i++) 
	{
         determinant += matrix[0][i] *
                       (matrix[1][(i + 1) % 3] * matrix[2][(i + 2) % 3] -
                        matrix[1][(i + 2) % 3] * matrix[2][(i + 1) % 3]);
    }

    printf("\nDeterminant of Matrix: %d\n", determinant);
    if (determinant == 0) 
	{
        printf("\nDeterminant is zero.\n");
    }
     // Cofactor Matrix
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++) 
		{
            cofactor[i][j] = ((matrix[(j + 1) % 3][(i + 1) % 3] * matrix[(j + 2) % 3][(i + 2) % 3]) -
                              (matrix[(j + 1) % 3][(i + 2) % 3] * matrix[(j + 2) % 3][(i + 1) % 3]));
        }
    }
    printf("\nCofactor Matrix:\n");
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++)
	    {
            printf("%d\t", cofactor[i][j]);
        }
        printf("\n");
    }
     // Adjoint 
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++)
		 {
            adjoint[i][j] = cofactor[j][i];
        }
    }
    printf("\nAdjoint Matrix:\n");
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++) 
		{
            printf("%d\t", adjoint[i][j]);
        }
        printf("\n");
    }
     // Inverse 
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++) 
		{
	     inverse[i][j] = adjoint[i][j] / determinant;
        }
    }
    printf("\nInverse Matrix:\n");
    for (int i = 0; i < 3; i++) 
	{
        for (int j = 0; j < 3; j++) 
		{
            printf("%d\t", inverse[i][j]);
        }
        printf("\n");
    }
	return 0;
}

