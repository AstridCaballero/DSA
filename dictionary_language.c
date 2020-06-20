#include <stdio.h>
#include <string.h>

unsigned int hash(const char *word, int n);

int main(void)
{
    int n;
    int index;
    int i;
    // character array
    char lan[15];
    // character array
    char greet[10];
    printf("number of languages: ");
    scanf("%i", &n);
    // array of characters arrays
    char table[n][10];

    // loop the table
    for (i = 0; i < n; i++)
    {
        printf("Input language name: ");
        scanf("%s", lan);
        index = hash(lan, n);
        printf("Input greeting: ");
        scanf("%s", greet);
        strcpy(table[index], greet);
        printf("%s", table[index]);
    }
    return 0;
}

// Hashes word to a number
// Using DJB hash function (Professor Daniel J. Bernstein hash function)
// 23/04/2020 from http://www.partow.net/programming/hashfunctions/index.html#SDBMHashFunction
unsigned int hash(const char *word, int n)
{
    // TODO
    unsigned int hash = 5381;
    unsigned int i = 0;

    // word++ move to the next character in word by adding one to the pointer
    // LENGHT is the max lenght of a word
    for (i = 0; word[i] != '\0' ; word++, i++)
    {
        // loop until the word ends as LENGTH is 45 and the word might be shorter. the word ends when the character is NULL
        // so the value in word (*word) is zero.
        if (*word == 0)
        {
            break;
        }
        else
        {
            hash = ((hash << 5) + hash) + (*word);
        }
    }
    hash = hash % n;
    return hash;
}