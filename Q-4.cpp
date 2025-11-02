#include <stdio.h>
int main()
{
    int arr[3][3][3];
    int layer, row, col;
    int totalSum = 0;
    float overallAvg;
    int min, max;

    printf("Enter elements for a 3x3x3 array:\n");
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

    min = max = arr[0][0][0];

    printf("\n-----Layer-wise Results-----\n");

    for (layer = 0; layer < 3; layer++)
    {
        int layerSum = 0;
        printf("\nLayer %d:\n", layer + 1);

        for (row = 0; row < 3; row++)
        {
            for (col = 0; col < 3; col++)
            {
                int val = arr[layer][row][col];
                printf("%4d", val);

                layerSum += val;
                totalSum += val;
                if (val < min)
                    min = val;
                if (val > max)
                    max = val;
            }
            printf("\n");
        }

        float layerAvg = layerSum / 9.0;
        printf("Sum of Layer %d: %d\n", layer + 1, layerSum);
        printf("Average of Layer %d: %.2f\n", layer + 1, layerAvg);
    }

    overallAvg = totalSum / 27.0;

    printf("\n----- Overall Insights -----\n");
    printf("Total Sum of all layers: %d\n", totalSum);
    printf("Overall Average: %.2f\n", overallAvg);
    printf("Minimum Value: %d\n", min);
    printf("Maximum Value: %d\n", max);

    return 0;
}

