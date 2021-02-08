#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

#define TABLE_SIZE 10

person_t *hashtable[TABLE_SIZE];

person_t *create_person(const char *name, unsigned int age)
{
    person_t *p = (person_t *)malloc(sizeof(person_t));
    strcpy(p->name, name);

    p->age = age;
    p->next = NULL;
    return p;
}

int main()
{
    init_hashtable(hashtable, TABLE_SIZE);

    hashtable_insert(hashtable, create_person("LittleAksMax", 15), TABLE_SIZE);
    hashtable_insert(hashtable, create_person("LittleAssSmax", 15), TABLE_SIZE);
    hashtable_insert(hashtable, create_person("David", 15), TABLE_SIZE);

    hashtable_insert(hashtable, create_person("Szilvia", 17), TABLE_SIZE); 
    hashtable_insert(hashtable, create_person("timi", 15), TABLE_SIZE);
    hashtable_insert(hashtable, create_person("micoka", 15), TABLE_SIZE);

    hashtable_remove(hashtable, "micoka", TABLE_SIZE);

    show_hashtable(hashtable, TABLE_SIZE);    

    return 0;
}