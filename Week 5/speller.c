// Implements a dictionary's functionality
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <strings.h>
#include <string.h>
#include "dictionary.h"

//defined global variables
#define number_for_hash 1000000
#define wordlength LENGTH + 1
#define tablepntr table[hash_key]
#define pointer node *pntr
#define if_pointer_null tablepntr == NULL
#define  if_pntr_not_null pntr != NULL
#define compare_words strcasecmp(word, pntr->word) == 0
#define pntr_linked  pntr = pntr->next
#define first_letter char firstLetter
#define capitalizer toupper(word[0])
#define return_first_letter return ((int) firstLetter) 
#define first_capital ((int) 'A')
#define dic_looker FILE *look_dic
#define dic_open fopen(dictionary, "r")
#define dic_looker_not_null look_dic != NULL
#define scan_dic fscanf(look_dic, "%s", strword) != EOF
#define tempmemo node *tempmem 
#define size_of_mem malloc(sizeof(node))
#define tempmemo_null tempmem == NULL
#define tempmemo_not_null tempmem != NULL
#define wordhasher hash(strword)
#define copier strcpy(tempmem -> word, strword)
#define link_mem_pntr tempmem -> next = tablepntr
#define increment_cntr stringcntr ++
#define close_dic fclose(look_dic)
#define iterate_buckets int i = 0; i < s; i++
#define first_node node *head
#define second_node node *freeme
#define second_not_n freeme != NULL
#define second_n_tempmem node *tmp
#define linked_secondn freeme->next
#define free_secondnmem free(tmp)
#define last_argument i == s - 1 && freeme == NULL
int stringcntr = 0;
unsigned int hash_key = 0;


// Represents a node in a hash table
typedef struct node
{
    char word[wordlength];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int s = number_for_hash;

// Hash table
node *table[s];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    hash_key = hash(word);

    if (if_pointer_null)
    {
        return false;
    }
    else
    {
        pointer = tablepntr;

        while (if_pntr_not_null)
        {
            if (compare_words)
            {
                return true;
            }
            pntr_linked;
        }

    }

    return false;
}

// Hashes word to a number
//got the hash function @https://github.com/rodrigomlpOz/CS50Solutions/blob/master/CS50Psets/pset5/speller/dictionary.c
unsigned int hash(const char *word)
{
    // TODO
    first_letter = capitalizer;

    return_first_letter - first_capital;
}


// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    char strword[wordlength];
    dic_looker = dic_open;
    if (dic_looker_not_null)
    {
        while (scan_dic)
        {
            tempmemo = size_of_mem;
            if (tempmemo_null)
            {
                return false;
            }
        
            if (tempmemo_not_null)
            {
                hash_key = wordhasher;
                copier;
                link_mem_pntr;
                tablepntr = tempmem;
                increment_cntr;
            }
        }
        close_dic;
    }
    else 
    {
        return false;
    }
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return stringcntr;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    //iterate through each of the bucket
    for (iterate_buckets)
    {
        first_node = table[i];
        second_node = head;
        // freeing linked lists
        while (second_not_n)
        {
            second_n_tempmem = freeme;
            freeme = linked_secondn;
            free_secondnmem;
        }
        
        if (last_argument)
        {
            return true;
        }
        
        table[i] = NULL;
    }
    return false;

}
