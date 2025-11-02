#include <stdio.h>
int main()
{
    char str[100];
    int i = 0;
    int vowels = 0, consonants = 0;

    printf("Enter a word: ");
    scanf("%[^\n]", str);  

    while (str[i] != '\0')  
    {
        char ch = str[i];

        if (ch >= 'A' && ch <= 'Z')
            ch = ch + ('a' - 'A');

        if (ch >= 'a' && ch <= 'z')
        {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }

        i++;
    }

    printf("\nVowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}

