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
