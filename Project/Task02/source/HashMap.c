#include "../include/HashMap.h"
#include <stdlib.h>
#include <string.h>

HashMap *initMap(int size)
{
    HashMap *newMap = malloc(sizeof(HashMap));
    newMap->size = size;
    newMap->numElements = 0;
    newMap->pairs = malloc(newMap->size * sizeof(Pair *));
    memset(newMap->pairs, 0, size * sizeof(Pair *));
    return newMap;
}

void insertPair(HashMap *map, char *key, char *value)
{

    if(map->numElements == map->size){
        return;
    }

    Pair *pair = malloc(sizeof(Pair));

    strncpy(pair->key, key, 50);
    strncpy(pair->value, value, 16);

    int index = Hash(key, map->size);

    while (!(map->pairs[index] == NULL))
    {
        index++;
        index %= map->size;
    }

    map->pairs[index] = pair;
    map->numElements++;
}

char *get(HashMap *map, const char *key)
{
    int index = Hash(key, map->size);
    int i = 0;

    while (!(map->pairs[index] == NULL))
    {
        if (strcmp(map->pairs[index]->key, key) == 0)
        {
            return map->pairs[index]->value;
        }
        index++;
        i++;
        index %= map->size;

        if (i == map->size)
        {
            break;
        }
    }
    return NULL;
}

void destroy(HashMap *map)
{
    for (int i = 0; i < map->size; i++)
    {
        free(map->pairs[i]);
        map->pairs[i] = NULL;
    }
    free(map->pairs);
    map->pairs = NULL;
}

int Hash(const char *key, int size)
{
    int hash = 0;
    for (int i = 0; i < strlen(key); i++){
        hash += key[i];
    }
    return (hash % size);
}