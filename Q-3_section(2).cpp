#include <stdio.h>
int main()
{
    int pass[10], fail[10];    
    int passCount = 0, failCount = 0;
    float passSum = 0, failSum = 0;
    int marks;
    int i = 0;

    printf("Enter quiz marks for up to 10 students (-1 to stop):\n");

    while (i < 10)
    {
        printf("Student %d marks: ", i + 1);
        scanf("%d", &marks);

        if (marks == -1)
            break;

        if (marks >= 5 && marks <= 10)
        {
            pass[passCount] = marks;
            passSum += marks;
            passCount++;
        }
        else if (marks >= 0 && marks < 5)
        {
            fail[failCount] = marks;
            failSum += marks;
            failCount++;
        }
        else
        {
            printf("Invalid input! Marks must be between 0 and 10 or -1 to exit.\n");
            continue;
        }

        i++;
    }

    printf("\n----- Results -----\n");

    printf("\nPass Students Marks (5-10):\n");
    if (passCount == 0)
        printf("No pass students.\n");
    else
    {
        for (i = 0; i < passCount; i++)
            printf("%d ", pass[i]);
        printf("\nAverage Pass Marks: %.2f\n", passSum / passCount);
    }

    printf("\nFail Students Marks (0-4):\n");
    if (failCount == 0)
        printf("No fail students.\n");
    else
    {
        for (i = 0; i < failCount; i++)
            printf("%d ", fail[i]);
        printf("\nAverage Fail Marks: %.2f\n", failSum / failCount);
    }

    return 0;
}

