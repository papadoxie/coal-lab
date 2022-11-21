#pragma once

//?Helper struct for HashMap
/** key-value pair
*/
typedef struct _pair{
    char value[8];
    char key[4];
} Pair;

//?HashMap struct
/** HashMap with a key-value pair and total size
*/
typedef struct _hash_map
{
    Pair **pairs;
    int size;
} HashMap;

//?Functions to operate on HashMap
/** Initialize and return a HashMap
 * @param size size of the HashMap
 * @return Pointer to a new HashMap
*/
HashMap *initMap(int size);

/** Insert a key-value pair into the HashMap
 * @param map pointer to a HashMap
 * @param key key from a key-value pair
 * @param value value from key value pair
*/
void insertPair(HashMap *map, char *key, char *value);

/** Looks for a value against a corresponding key
 * @param map pointer to a HashMap
 * @param key key from a key-value pair
 * @return Value if key matches or NULL if no match found
*/
char *get(HashMap *map, char *key);

//Safely destroy the HashMap
void destroy(HashMap *map);

/** Calculate a hash
 * @param key key from a key-value pair
 * @param size size of the HashMap
 * @return The calculated hash
*/
int Hash(char *key, int size);
