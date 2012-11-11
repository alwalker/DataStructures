#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void add(tree *t, void *item, int size)
{
	if(t->root == NULL)
	{
		void *newItem = (void *)calloc(1, size);
		memcpy(newItem, item, size);

		node *newNode = (void *)calloc(1, sizeof(node));
		newNode->parent = NULL;
		newNode->left = NULL;
		newNode->right = NULL;
		newNode->item = newItem;

		t->root = newNode;
	}
	else
	{
		node *curr = t->root;
		while(curr != NULL)
		{
			if (t->compare(curr->item, item) > 0)
			{
				if (curr->left != NULL)
				{
					curr = curr->left;
				}
				else
				{
					void *newItem = (void *)calloc(1, size);
					memcpy(newItem, item, size);

					node *newNode = (void *)calloc(1, sizeof(node));
					newNode->parent = curr;
					newNode->left = NULL;
					newNode->right = NULL;
					newNode->item = newItem;

					curr->left = newNode;
					return;
				}
			}
			else if (t->compare(curr->item, item) < 0)
			{
				if (curr->right != NULL)
				{
					curr = curr->right;
				}
				else
				{
					void *newItem = (void *)calloc(1, size);
					memcpy(newItem, item, size);

					node *newNode = (void *)calloc(1, sizeof(node));
					newNode->parent = curr;
					newNode->left = NULL;
					newNode->right = NULL;
					newNode->item = newItem;

					curr->right = newNode;
					return;
				}
			}
			else
			{
				return;
			}
		}
	}
}