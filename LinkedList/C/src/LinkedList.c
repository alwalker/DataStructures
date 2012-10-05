#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

linkedList *create(void *item, int size, void(*printItem)(void *), int(*compare)(void *, void *))
{
	void *newItem = (void *)calloc(1, size);
	memcpy(newItem, item, size);

	node *newNode = (node *)calloc(1, sizeof(node));
	newNode->next = NULL;
	newNode->item = newItem;

	linkedList *list = (linkedList *)calloc(1, sizeof(linkedList));
	list->head = newNode;
	list->tail = newNode;
	list->size = 1;
	list->printItem = printItem;
	list->compare = compare;

	return list;
}

void add(linkedList *list, void *item, int size)
{
	if(list != NULL)
	{
		void *newItem = (void *)calloc(1, size);
		memcpy(newItem, item, size);

		node *newNode = (node *)calloc(1, sizeof(node));
		newNode->next = NULL;
		newNode->item = newItem;

		list->tail->next = newNode;
		list->tail = newNode;

		list->size = list->size + 1;
	}
}

void printList(linkedList *list)
{
	if(list != NULL)
	{
		node *curr = list->head;
		do
		{
			list->printItem(curr->item);
			curr = curr->next;
		}while(curr->next != NULL);

		list->printItem(curr->item);
	}
}
