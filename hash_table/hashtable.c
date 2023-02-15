#include "hashtable.h"

/**
 * @brief Allocates memory and returns a hashtable
 * 
 * @param m The modulo to use for the hash function
 * @return HASHTABLE the hashtable pointer
 */
HASHTABLE hashtable_init(int m)
{
    HASHTABLE hash_table = (HASHTABLE)malloc(sizeof(HashTable));
    hash_table->size = m;
    hash_table->hash = m;
    hash_table->collision = (LIST *)malloc(sizeof(List) * m);
    for(int i = 0; i < hash_table->size; i++) {
        hash_table->collision[i] = (LISTE)NULL;
    }
    return hash_table;
}

/**
 * @brief Frees memory from hashtable
 * 
 * @param table 
 */
void hashtable_free(HASHTABLE table)
{
    for (int i = 0; i < table->size; i++)
    {
        list_free(table->collision[i]);
    }
    free(table);
}

/**
 * @brief Prints every linked list in hashtable
 * 
 * @param table 
 */
void hashtable_print(HASHTABLE table) {
    printf("[\n");
    for(int i = 0; i < table->size; i++) {
        if(table->collision[i] != NULL) {
            printf("\t%d -> ", i);
            list_print(table->collision[i]);
        }
    }
    printf("].\n");
}

/**
 * @brief Encode a word into hash
 * 
 * @param word the word to encode
 * @return unsigned long long the resulting hashed value
 */
unsigned long long encode_word(char * word)
{
    int ascii;
    int len = strlen(word);
    unsigned long long value = 0;
    for (int i = 0, p = len - 1; i < len; i++, p--)
    {
        ascii = (int)word[i];
        value += ascii * pow(128, p);
    }
    return value;
}

/**
 * @brief Returns the index in the hashtable from the hashed word
 * 
 * @param table the hashtable
 * @param k the hash
 * @return int the index inside the hashtable
 */
int hashtable_hash(HASHTABLE table, unsigned long long k)
{
    return (int)(k % table->hash);
}

/**
 * @brief Inserts word into hashtable
 * 
 * @param table the hashtable
 * @param word the word, as a cell struct pointer
 */
void hashtable_insert(HASHTABLE table, CELL word)
{
    unsigned long long ascii = encode_word(word->key);
    int index = hashtable_hash(table, ascii);
    if (table->collision[index] == NULL)
    {
        table->collision[index] = list_init();
    }
    list_insert(table->collision[index], word);
}

/**
 * @brief Search word from hashtable, NULL if not found
 * 
 * @param table the hashtable
 * @param word the word to search for
 * @return CELL the word if found, NULL otherwise
 */
CELL hashtable_search(HASHTABLE table, char *word)
{
    unsigned long long ascii = encode_word(word);
    int index = hashtable_hash(table, ascii);
    if(table->collision[index] != NULL) {
        return list_search(table->collision[index], word);
    }
    return NULL;
}

/**
 * @brief Deletes element from hashtable
 * 
 * @param table the hashtable
 * @param item the element to delete from the hashtable
 */
void hashtable_delete(HASHTABLE table, CELL item) {
    for(int i = 0; i < table->size; i++) {
        list_delete(table->collision[i], item);
    }
}

/**
 * @brief Count every item present inside the hashtable
 * 
 * @param table the hashtable
 * @return int the number of items in all linked list of the hashtable
 */
int hashtable_count(HASHTABLE table) {
    int sum = 0;
    for(int i = 0; i < table->size; i++) {
        sum += list_count(table->collision[i]);
    }
    return sum;
}