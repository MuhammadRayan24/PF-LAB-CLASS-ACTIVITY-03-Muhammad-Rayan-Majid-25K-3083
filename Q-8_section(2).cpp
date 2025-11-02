#include <stdio.h>
int main() {
    char str[100];
    printf("Enter any text :\n");
    scanf("%[^A-Za-z]", str);
    printf("\nThe non-alphabetic characters are:\n%s\n", str);
    return 0;
}

