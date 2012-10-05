#include <stdio.h>
#include "../src/LinkedList.h"

void MyPrint(void *);

int main()
{
	node *empty = NULL;
	node *head = create((void *)"blarg", sizeof("blarg"));

	printf("Size of empty list (should be 0): %d", size(empty));
	printf("\nSize of new list (should be 1): %d", size(head));

	add(head, (void *)"test", sizeof("test"));
	printf("\nSize of list with on add (should be 2): %d", size(head));


	printf("\nPrinting list (should be blarg, test):");
	printList(head, MyPrint);



	printf("\n");

	return 0;
}

void MyPrint(void *item)
{
	printf("\n%s", (char *)item);
}
