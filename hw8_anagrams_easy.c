/*
Yash Waghmare
This programs identifies anagrams from a file and prints them and stores them in a different file.
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_anagram(char word[], char anagram[]);

int main()
{
    char word[50];
    char anagram[50];
    char word_cpy[1000];
    char anagram_cpy[1000];
    int correct = 0;
    printf("This program loads the dictionary easy.txt and will print all the anagrams in there to a word you give.\n");
    printf("Enter the word: ");
    scanf("%s", word);

    FILE *txt_file = fopen("easy.txt", "r");
    FILE *anagram_file = fopen("easi.txt", "w+");

    printf("Anagrams found: \n");
    while (!feof(txt_file))
    {
        fscanf(txt_file, "%s", anagram);
        strcpy(word_cpy, word);
        strcpy(anagram_cpy, anagram);
        int compare1 = strcmp(word_cpy, anagram_cpy);
        if (compare1 != 0)
        {
            int result = check_anagram(word_cpy, anagram_cpy);
            if (result == 1)
            {
                printf("%s\n", anagram);
                correct++;
                fprintf(anagram_file, "%s\n", anagram);
            }
        }
    }
    if (correct == 0)
    {
        printf("No anagrams were found\n");
    }
    printf("Please use our service again!");
}

int check_anagram(char word[], char anagram[])
{
    int string = strlen(word);
    char temp;
    for (int i = 0; i < string - 1; i++)
    {
        for (int j = i + 1; j < string; j++)
        {
            if (word[i] > word[j])
            {
                temp = word[i];
                word[i] = word[j];
                word[j] = temp;
            }
            if (anagram[i] > anagram[j])
            {
                temp = anagram[i];
                anagram[i] = anagram[j];
                anagram[j] = temp;
            }
        }
    }
    int result = strcmp(anagram, word);
    if (result == 0)
    {
        return 1;
    }
    else if (result == 1)
    {
        return 2;
    }
}