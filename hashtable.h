#include "../utils.h"

#define MAX_NAME 20

typedef struct person 
{
    char name[MAX_NAME];
    unsigned int age;
    struct person *next;
} person_t;

void show_hashtable(person_t **, unsigned int);

unsigned int hash(const char *, unsigned int);
void init_hashtable(person_t **, unsigned int);

person_t *hashtable_search(person_t **, const char *, unsigned int);
bool hashtable_insert(person_t **, person_t *, unsigned int);
person_t *hashtable_remove(person_t **, const char *, unsigned int);
