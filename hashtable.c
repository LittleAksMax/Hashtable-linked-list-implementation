#include "hashtable.h"
#include <stdio.h>
#include <string.h>

void show_hashtable(person_t **ht, unsigned int length)
{
    printf("START\n");
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%d\t", i);
        if (ht[i] == NULL)
            printf("---\n");
        else
        {
            person_t *temp = ht[i];
            while (temp != NULL)
            {
                printf("%s : %d %c ", temp->name, temp->age, (temp->next != NULL ? '-' : ' ')); 
                temp = temp->next;
            }
            printf("\n");
        }
    }
    printf("END\n");
}

void init_hashtable(person_t **ht, unsigned int length)
{
    int i;
    for (i = 0; i < length; i++)
        ht[i] = NULL;
}

unsigned int hash(const char *name, unsigned int length)
{
    unsigned int hash_value = 0;
    int i;
    for (i = 0; name[i] != '\0'; i++)
    {
        hash_value += name[i];
        hash_value *= name[i];
    }
    return (hash_value % length);
}

person_t *hashtable_search(person_t **ht, const char *name, unsigned int length)
{
    unsigned int index = hash(name, length);
    
    person_t *temp = ht[index];
    while (temp != NULL && strcmp(temp->name, name) != 0)
        temp = temp->next;
    return temp;
}

bool hashtable_insert(person_t **ht, person_t *p, unsigned int length)
{
    if (p == NULL)
        return false;

    unsigned int index = hash(p->name, length);

    p->next = ht[index];
    ht[index] = p;
    return true;
    
}

person_t *hashtable_remove(person_t **ht, const char *name, unsigned int length)
{
    unsigned int index = hash(name, length);
    
    person_t *prev, *temp;
    temp = ht[index];
    prev = NULL;

    while (temp != NULL && strcmp(name, temp->name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("TEMP IS NULL\n");
        return NULL;
    }
    if (prev == NULL)
    {
        printf("CORRECT\n");
        ht[index] = temp->next;
    }
    else
    {
        printf("PREV IS NOT NULL\n");
        prev->next = temp->next;
    }
    return temp;
}
