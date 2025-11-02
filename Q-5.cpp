#include <stdio.h>
int main()
{
    int arr[3][3][3];
    int layer, row, col;

    printf("Enter elements for a 3x3x3 matrix:\n");

    for (layer = 0; layer < 3; layer++)
    {
        printf("\n--- Layer %d ---\n", layer + 1);
        for (row = 0; row < 3; row++)
        {
            for (col = 0; col < 3; col++)
            {
                printf("Element[%d][%d][%d]: ", layer, row, col);
                scanf("%d", &arr[layer][row][col]);
            }
        }
    }

    printf("\n----- Displaying All Layers -----\n");
    for (layer = 0; layer < 3; layer++)
    {
        printf("\nLayer %d:\n", layer + 1);
        for (row = 0; row < 3; row++)
        {
            for (col = 0; col < 3; col++)
                printf("%4d", arr[layer][row][col]);
            printf("\n");
        }
    }

    printf("\n----- Layer Similarity Report -----\n");

    for (int l1 = 0; l1 < 3; l1++)
    {
        for (int l2 = l1 + 1; l2 < 3; l2++)
        {
            int identical = 1; 

            for (row = 0; row < 3 && identical; row++)
            {
                for (col = 0; col < 3; col++)
                {
                    if (arr[l1][row][col] != arr[l2][row][col])
                    {
                        identical = 0;
                        break;
                    }
                }
            }

            if (identical)
                printf("Layer %d and Layer %d are IDENTICAL.\n", l1 + 1, l2 + 1);
            else
                printf("Layer %d and Layer %d are DISTINCT.\n", l1 + 1, l2 + 1);
        }
    }
    return 0;
}

