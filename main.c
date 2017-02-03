#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int i;
	list_t *p = NULL;

	if (argc == 1) {
		fprintf(stderr, "usage: %s <arbitrary strings>\n", argv[0]);
		return -1;
	}
	for (i=1; i<argc; i++) {
		p = list_pushback(p, argv[i]);
	}
	list_showfromhead(p);
	list_clear(p);

	return 0;
}

