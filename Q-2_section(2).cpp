#include <stdio.h>
int main() 
{
    int arr[10];
    int i, search, count = 0;
    printf("Enter 10 integers:\n");
    for (i = 0; i < 10; i++) 
	{
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the number to search: ");
    scanf("%d", &search);
    for (i = 0; i < 10; i++) 
	{
        if (arr[i] == search) 
		{
            count++;
        }
    }
    if (count > 0)
        printf("\nThe number %d occurred %d time(s) in the array.\n", search, count);
    else
        printf("\nNumber not found.\n");
    return 0;
}

