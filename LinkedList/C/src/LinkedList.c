#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>

node *create(void *item)
{
	node *newNode = (node *)calloc(1, sizeof(node));
	newNode->next = NULL;
	newNode->item = item;

	return newNode;
}

int size(node *head)
{
	int count = head == NULL ? 0:1;

	if(head != NULL)
	{
		node *curr = head;
		while(curr->next != NULL)
		{
			count= count + 1;
			curr = (node *)curr->next;
		}
	}

	return count;
}

void add(node *head, void *item)
{
	if(head != NULL)
	{
		node *curr = head;
		while(curr->next != NULL)
		{
			curr = (node *)curr->next;
		}

		node *newNode = (node *)calloc(1, sizeof(node));
		newNode->next = NULL;
		newNode->item = item;

		curr->next = newNode;
	}
}

void printList(node *head)
{
	printf("\nList");

	if(head != NULL)
	{
		node *curr = head;
		do
		{
			printf("\n%s", (char *)curr->item);
			curr = (node *)curr->next;
		}while(curr->next != NULL);

		printf("\n%s", (char *)curr->item);
	}
}


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