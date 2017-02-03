#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dlist.h"

list_t* list_tail(list_t *p)
{
	if (!p)
		return NULL;
	while (p->_next)
		p = p->_next;
	return p;
}

list_t* list_head(list_t *p)
{
	if (!p)
		return NULL;
	while (p->_prev)
		p = p->_prev;
	return p;
}

list_t* list_pushback(list_t *p, const char *str)
{
	p = list_tail(p);
	list_t *q = (list_t*)malloc(sizeof(*q));
	q->_prev = p;
	q->_next = NULL;
	q->_str = (char*)malloc(sizeof(*str)*strlen(str));
	if (p)
		p->_next = q;
	memset(q->_str, '\0', sizeof(*str)*strlen(str));
	strcpy(q->_str, str);
	return q;
}

char* list_popback(list_t *p)
{
	list_t *q = list_tail(p);
	char *str = NULL;
	
	if (q) {
		str = strdup(q->_str);
		free(q->_str);
		if (q->_prev)
			q->_prev->_next = NULL;
		free(q);
	}
	return str;
}

list_t* list_pushfront(list_t *p, const char *str)
{
	p = list_head(p);
	list_t *q = (list_t*)malloc(sizeof(*q));
	q->_prev = NULL;
	q->_next = p;
	q->_str = (char*)malloc(sizeof(*str)*strlen(str));
	if (p)
		p->_prev = q;
	memset(q->_str, '\0', sizeof(*str)*strlen(str));
	strcpy(q->_str, str);
	return q;
}

char* list_popfront(list_t *p)
{
	list_t *q = list_head(p);
	char *str = NULL;
	
	if (q) {
		str = strdup(q->_str);
		free(q->_str);
		if (q->_next)
			q->_next->_prev = NULL;
		free(q);
	}
	return str;
}

list_t* list_find(list_t *p, const char *str)
{
	p = list_head(p);
	while (p) {
		if (!strcmp(p->_str, str))
			return p;
		p = p->_next;
	}
	return NULL;
}

void list_clear(list_t *p)
{
	p = list_head(p);
	if (!p)
		return;
	while(p) {
		free(p->_str);
		free(p);
		p = p->_next;
	}
}

void list_showfromhead(list_t *p)
{
	p = list_head(p);
	while (p) {
		printf("this: %12p, prev: %12p, next: %12p, val: %s\n", p, p->_prev, p->_next, p->_str);
		p = p->_next;
	}
}

void list_showfromtail(list_t *p)
{
	p = list_tail(p);
	while (p) {
		printf("this: %12p, prev: %12p, next: %12p, val: %s\n", p, p->_prev, p->_next, p->_str);
		p = p->_prev;
	}
}
