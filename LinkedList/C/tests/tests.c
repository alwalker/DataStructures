#include <stdio.h>
#include "../src/LinkedList.h"

int main()
{
	node *empty = NULL;
	node *head = create((void *)"blarg");

	printf("Size of empty list (should be 0): %d", size(empty));
	printf("\nSize of new list (should be 1): %d", size(head));

	add(head, (void *)"test");

	printf("\nSize of list with on add (should be 2): %d", size(head));
	printList(head);



	printf("\n");

	return 0;
}
