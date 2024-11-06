// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// Size of hash table
#define N 18000

// Hash table
node *table[N] = {NULL};

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // Makes a copy of the word to all lowercase
    char wordLower[LENGTH + 1];
    for (int i = 0, lenght = strlen(word); i <= lenght; i++)
        wordLower[i] = tolower(word[i]);

    // Goes to the index and search the list for the word
    unsigned int key = hash(word);
    node *ptr = table[key];

    while (ptr != NULL)
    {
        if (strcmp(ptr->word, wordLower) == 0)
            return true;
        ptr = ptr->next;
    }

    return false;
}

// Hashes word to a number according with the first 3 letter of the word
unsigned int hash(const char *word)
{
    unsigned int first, second, third;

    // 26^2 | 26^1 | 26^0
    // A       B       C
    first = (toupper(word[0]) - 'A') * (26 * 26);
    second = (toupper(word[1]) - 'A') * 26;
    third = (toupper(word[2]) - 'A');

    if (strlen(word) == 1)
        return first;
    else if (strlen(word) == 2)
        return first + second;

    return first + second + third;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Opens the dictionary file
    FILE *dicFile = fopen(dictionary, "r");
    if (dicFile == NULL)
    {
        printf("Error while loading dictionary. Try again.\n");
        return false;
    }

    unsigned int key;
    char wordBuffer[LENGTH + 1];
    node *newNode;

    while (fscanf(dicFile, "%s", wordBuffer) != EOF)
    {
        key = hash(wordBuffer);

        // Initialize a new node for the word
        newNode = (node *) malloc(sizeof(node));
        if (newNode == NULL)
            return false;

        strcpy(newNode->word, wordBuffer);
        newNode->next = NULL;

        // If it's empty, points the head to the new node
        if (table[key] == NULL)
        {
            table[key] = newNode;
        }
        // If there's a word already, prepend in the list
        else
        {
            newNode->next = table[key];
            table[key] = newNode;
        }
    }

    fclose(dicFile);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int count = 0;
    node *ptr;

    // Check every index and runs through every list counting the numbers
    for (int i = 0; i < N; i++)
    {
        // If index is occupied, count every word on the list
        if (table[i] != NULL)
        {
            ptr = table[i];
            while (ptr != NULL)
            {
                count++;
                ptr = ptr->next;
            }
        }
    }

    return count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *ptr;
    node *pAux;

    // Check every index and runs through every list freeing the nodes
    for (int i = 0; i < N; i++)
    {
        if (table[i] != NULL)
        {
            ptr = table[i];

            while (ptr != NULL)
            {
                pAux = ptr->next;
                free(ptr);
                ptr = NULL;
                ptr = pAux;
            }
        }
    }

    return true;
}
