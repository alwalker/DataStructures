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
		newNode->next = list->head;
		newNode->item = newItem;

		list->head = newNode;

		list->size = list->size + 1;
	}
}

void removeItem(linkedList *list, void *item)
{
	if(list != NULL)
	{
		node *prev = NULL, *next = NULL;
		node *curr = list->head;

		do
		{
			next = curr->next;

			if(list->compare(curr->item, item) == 0)
			{
				free(curr->item);
				free(curr);

				if(prev == NULL)
				{
					if(next != NULL)
					{
						list->head = next;
					}
					else
					{
						list->head = NULL;
					}
				}
				else
				{
					prev->next = next;
				}

				list->size = list->size - 1;
			}

			prev = curr;
			curr = next;
		}while(next != NULL);
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
