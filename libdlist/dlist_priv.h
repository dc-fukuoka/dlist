#ifndef DLIST_PRIV_H
#define DLIST_PRIV_H

typedef struct list_t {
	char *_str;
	struct list_t *_next;
	struct list_t *_prev;
} list_t;

#endif /* DLIST_PRIV_H */
