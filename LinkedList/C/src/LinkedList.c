#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

node *create(void *item, int size)
{
	node *newNode = (node *)calloc(1, sizeof(node));
	void *newItem = (void *)calloc(1, size);

	memcpy(newItem, item, size);

	newNode->next = NULL;
	newNode->item = newItem;

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

void add(node *head, void *item, int size)
{
	if(head != NULL)
	{
		node *curr = head;
		while(curr->next != NULL)
		{
			curr = (node *)curr->next;
		}

		node *newNode = (node *)calloc(1, sizeof(node));
		void *newItem = (void *)calloc(1, size);

		memcpy(newItem, item, size);

		newNode->next = NULL;
		newNode->item = newItem;

		curr->next = newNode;
	}
}

void printList(node *head, void(*itemPrint)(void *))
{
	printf("\nList");

	if(head != NULL)
	{
		node *curr = head;
		do
		{
			itemPrint(curr->item);
			curr = (node *)curr->next;
		}while(curr->next != NULL);

		printf("\n%s", (char *)curr->item);
	}
}
