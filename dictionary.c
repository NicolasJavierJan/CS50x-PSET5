// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 45;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    for (node *tmp = table[hash(word)]; tmp != NULL; tmp = tmp->next)
    {
        if (strcasecmp(word, tmp->word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    int i = 0;
    i = strlen(word);
    return i - 1;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // TODO
    //define the file pointer variable and open dictionary

    FILE *dictionaries = fopen(dictionary, "r");
    char words[LENGTH + 1];
    int wordcounter = 0;

    if (dictionaries == NULL)
    {
        fclose(dictionaries);
        return false;
    }

    y// read words
    while (fscanf(dictionaries, "%s", words) != EOF)
    {
        node *n = malloc(sizeof(node));
        if (n != NULL)
        {
            strcpy(n->word, words);
            n->next = NULL;
            if (table[hash(words)] == NULL)
            {
                table[hash(words)] = n;
            }
            else
            {
                n->next = table[hash(words)];
                table[hash(words)] = n;
            }
        }
        else
        {
            return false;
        }
    }
    fclose(dictionaries);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    int i = 0;
    int wordcount = 0;
    while (i <= 44)
    {
        for (node *tmp = table[i]; tmp != NULL; tmp = tmp->next)
        {
            wordcount++;
        }
        i++;
    }
    //printf("%i\n", wordcount);
    return wordcount;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    int i = 0;
    while (i <= 44)
    {
        node *tmp;
        for (node *cursor = table[i]; cursor != NULL; cursor = tmp)
        {
            tmp = cursor->next;
            free(cursor);
        }
        i++;
    }
    return true;
}
