#ifndef DLIST_H
#define DLIST_H

#include "dlist_priv.h"

list_t* list_tail(list_t *p);
list_t* list_head(list_t *p);
list_t* list_pushback(list_t *p, const char *str);
char* list_popback(list_t *p);
list_t* list_pushfront(list_t *p, const char *str);
char* list_popfront(list_t *p);
list_t* list_find(list_t *p, const char *str);
void list_clear(list_t *p);
void list_showfromhead(list_t *p);
void list_showfromtail(list_t *p);

#endif /* DLIST_H */
