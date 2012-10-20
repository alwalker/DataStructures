#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../src/LinkedList.h"

void MyPrint(void *);
int MyCompare(void *, void *);
bool CreateTests(char *);
bool AddTests(char *);
bool RemoveTests(char *);
bool PrintTest(char *);
bool GetTests(char *);
bool IndexOfTests(char *);
void TestPrintItem(void *);

int main()
{
	char *result = (char *)calloc(1024, sizeof(char));
	bool passed = false;

	passed = CreateTests(result);
	if(passed)
	{
		printf("\nCreate Tests Passed!");
	}
	else
	{
		printf("\nCreate Tests Failed: %s\n", result);
		return 1;
	}
	fflush(NULL);

	memset(result, '\0', 1024);	
	passed = AddTests(result);
	if(passed)
	{
		printf("\nAdd Tests Passed!");
	}
	else
	{
		printf("\nAdd Tests Failed: %s\n", result);
		return 1;
	}
	fflush(NULL);

	passed = GetTests(result);
	if(passed)
	{
		printf("\nGet Tests Passed!");
	}
	else
	{
		printf("\nGet Tests Failed: %s\n", result);
		return 1;
	}
	fflush(NULL);

	passed = IndexOfTests(result);
	if(passed)
	{
		printf("\nIndexOf Tests Passed!");
	}
	else
	{
		printf("\nIndexOf Tests Failed: %s\n", result);
		return 1;
	}
	fflush(NULL);

	memset(result, '\0', 1024);
	passed = RemoveTests(result);
	if(passed)
	{
		printf("\nRemove Tests Passed!");
	}
	else
	{
		printf("\nRemove Tests Failed: %s\n", result);
		return 1;
	}
	fflush(NULL);

	memset(result, '\0', 1024);
	passed = PrintTest(result);
	if(passed)
	{
		printf("\nPrint Test Passed!");
	}
	else
	{
		printf("\nPrint Test Failed: %s\n", result);
		return 1;
	}
	fflush(NULL);

	printf("\n");
	return 0;
}

bool CreateTests(char *result)
{
	linkedList *list = create((void *)"blarg", sizeof("blarg"), MyPrint, MyCompare);

	if(list->size != 1)
	{
		strcpy(result, "New list did not have size of 1\0");
		return false;
	}

	if(list->head == NULL)
	{
		strcpy(result, "New list has null head\0");
		return false;		
	}

	if(list->printItem == NULL)
	{
		strcpy(result, "New list does not have printItem function\0");
		return false;
	}

	if(list->compare == NULL)
	{
		strcpy(result, "New list does not have compare function\0");
		return false;
	}

	return true;
}

bool AddTests(char *result)
{
	linkedList *list = create((void *)"Item 1\0", sizeof("Item 1\0"), MyPrint, MyCompare);

	add(list, (void *)"Item 2\0", sizeof("Item 2\0"));
	add(list, (void *)"Item 3\0", sizeof("Item 3\0"));
	add(list, (void *)"Item 4\0", sizeof("Item 4\0"));
	add(list, (void *)"Item 5\0", sizeof("Item 5\0"));

	if(list->size != 5)
	{
		sprintf(result, "List has incorrect size of %d (should be 5)!\0", list->size);
		return false;
	}

	if(strcmp(list->head->next->item, "Item 4\0") != 0)
	{
		sprintf(result, "Incorrect item in #2 position: %s!\0",
			(char *)list->head->next->item);
		return false;
	}

	if(strcmp(list->head->next->next->item, "Item 3\0") != 0)
	{
		strcpy(result, "Incorrect item in #3 position!\0");
		return false;
	}

	if(strcmp(list->head->next->next->next->item, "Item 2\0") != 0)
	{
		strcpy(result, "Incorrect item in #4 position!\0");
		return false;
	}

	if(strcmp(list->head->next->next->next->next->item, "Item 1\0") != 0)
	{
		strcpy(result, "Incorrect item in #5 position!\0");
		return false;
	}

	return true;
}

bool GetTests(char *result)
{
	char *head, *tail, *middle;
	linkedList *list = create((void *)"Item 1\0", sizeof("Item 1\0"), MyPrint, MyCompare);

	add(list, (void *)"Item 2\0", sizeof("Item 2\0"));
	add(list, (void *)"Item 3\0", sizeof("Item 3\0"));
	add(list, (void *)"Item 4\0", sizeof("Item 4\0"));
	add(list, (void *)"Item 5\0", sizeof("Item 5\0"));

	head = (char *)get(list, 0);
	middle = (char *)get(list, 2);
	tail = (char *)get(list, 4);

	if(strcmp(head, "Item 5\0") != 0)
	{			
		sprintf(result, "Incorrect head returned: %s", head);
		return false;
	}
	if(strcmp(middle, "Item 3\0") != 0)
	{
		sprintf(result, "Incorrect middle returned: %s", middle);
		return false;
	}
	if(strcmp(tail, "Item 1\0") != 0)
	{
		sprintf(result, "Incorrect tail return: %s", tail);
		return false;
	}

	return true;
}

bool IndexOfTests(char *result)
{
	linkedList *list = create((void *)"Item 1\0", sizeof("Item 1\0"), MyPrint, MyCompare);

	add(list, (void *)"Item 2\0", sizeof("Item 2\0"));
	add(list, (void *)"Item 3\0", sizeof("Item 3\0"));
	add(list, (void *)"Item 4\0", sizeof("Item 4\0"));
	add(list, (void *)"Item 5\0", sizeof("Item 5\0"));

	int index = indexOf(list, (void *)"Item 1\0");
	int badIndex = indexOf(list, (void *)"BANANAS\0");

	if(index != 4)
	{			
		sprintf(result, "Incorrect index returned: %d", index);
		return false;
	}

	if(badIndex != -1)
	{			
		sprintf(result, "Found non existing item!", badIndex);
		return false;
	}

	return true;
}

bool RemoveTests(char *result)
{
	linkedList *list = create((void *)"Item 1\0", sizeof("Item 1\0"), MyPrint, MyCompare);
	linkedList *singleList = create((void *)"Item 1\0", sizeof("Item 1\0"), MyPrint, MyCompare);
	linkedList *middleList = create((void *)"Item 1\0", sizeof("Item 1\0"), MyPrint, MyCompare);
	linkedList *tailList = create((void *)"Item 1\0", sizeof("Item 1\0"), MyPrint, MyCompare);

	add(list, (void *)"Item 2\0", sizeof("Item 2\0"));
	add(list, (void *)"Item 3\0", sizeof("Item 3\0"));
	add(list, (void *)"Item 4\0", sizeof("Item 4\0"));
	add(list, (void *)"Item 5\0", sizeof("Item 5\0"));
	add(middleList, (void *)"Item 2\0", sizeof("Item 2\0"));
	add(middleList, (void *)"Item 3\0", sizeof("Item 3\0"));
	add(middleList, (void *)"Item 4\0", sizeof("Item 4\0"));
	add(middleList, (void *)"Item 5\0", sizeof("Item 5\0"));
	add(tailList, (void *)"Item 2\0", sizeof("Item 2\0"));
	add(tailList, (void *)"Item 3\0", sizeof("Item 3\0"));
	add(tailList, (void *)"Item 4\0", sizeof("Item 4\0"));
	add(tailList, (void *)"Item 5\0", sizeof("Item 5\0"));

	removeItem(list, (void *)"Item 5\0");
	if(list->size != 4)
	{
		sprintf(result, "List has incorrect size of %d (should be 4)!(head remove)\0", list->size);
		return false;
	}
	if(strcmp(list->head->item, "Item 4\0") != 0)
	{
		sprintf(result, "Incorrect item in #1 position(head remove): %s!\0",
			(char *)list->head->next->item);
		return false;
	}
	if(strcmp(list->head->next->item, "Item 3\0") != 0)
	{
		sprintf(result, "Incorrect item in #2 position(head remove): %s!\0",
			(char *)list->head->next->item);
		return false;
	}
	if(strcmp(list->head->next->next->item, "Item 2\0") != 0)
	{
		strcpy(result, "Incorrect item in #3 position(head remove)!\0");
		return false;
	}
	if(strcmp(list->head->next->next->next->item, "Item 1\0") != 0)
	{
		strcpy(result, "Incorrect item in #4 position(head remove)!\0");
		return false;
	}

	removeItem(singleList, (void *)"Item 1\0");
	if(singleList->size != 0)
	{
		sprintf(
			result,
			"List has incorrect size of %d (should be 4)!(single item test)\0",
			list->size);
		return false;
	}
	if(singleList->head != NULL)
	{
		sprintf(
			result,
			"List has incorrect head (should be null)!(single item test)\0");
		return false;
	}

	removeItem(middleList, (void *)"Item 3\0");
	if(middleList->size != 4)
	{
		sprintf(
			result,
			"List has incorrect size of %d (should be 4)!(middle list)\0",
			middleList->size);
		return false;
	}
	if(strcmp(middleList->head->item, "Item 5\0") != 0)
	{
		sprintf(result, "Incorrect item in #1 position(middle list): %s!\0",
			(char *)middleList->head->next->item);
		return false;
	}
	if(strcmp(middleList->head->next->item, "Item 4\0") != 0)
	{
		sprintf(result, "Incorrect item in #2 position(middle list): %s!\0",
			(char *)middleList->head->next->item);
		return false;
	}
	if(strcmp(middleList->head->next->next->item, "Item 2\0") != 0)
	{
		sprintf(
			result,
			"Incorrect item in #3 position: %s(middle list)!\0",
			(char *)middleList->head->next->next->item);
		return false;
	}
	if(strcmp(middleList->head->next->next->next->item, "Item 1\0") != 0)
	{
		strcpy(result, "Incorrect item in #4 position(middle list)!\0");
		return false;
	}

	removeItem(tailList, (void *)"Item 1\0");
	if(tailList->size != 4)
	{
		sprintf(
			result,
			"List has incorrect size of %d (should be 4)!(tail remove)\0",
			tailList->size);
		return false;
	}
	if(strcmp(tailList->head->item, "Item 5\0") != 0)
	{
		sprintf(result, "Incorrect item in #1 position(tail remove): %s!\0",
			(char *)tailList->head->next->item);
		return false;
	}
	if(strcmp(tailList->head->next->item, "Item 4\0") != 0)
	{
		sprintf(result, "Incorrect item in #2 position(tail remove): %s!\0",
			(char *)tailList->head->next->item);
		return false;
	}
	if(strcmp(tailList->head->next->next->item, "Item 3\0") != 0)
	{
		strcpy(result, "Incorrect item in #3 position(tail remove)!\0");
		return false;
	}
	if(strcmp(tailList->head->next->next->next->item, "Item 2\0") != 0)
	{
		strcpy(result, "Incorrect item in #4 position(tail remove)!\0");
		return false;
	}

	return true;
}

char *testPrintout;
bool PrintTest(char *result)
{
	testPrintout = (char *)calloc(2048, sizeof(char));

	linkedList *list = create((void *)"Item 1\0", sizeof("Item 1\0"), TestPrintItem, MyCompare);
	add(list, (void *)"Item 2\0", sizeof("Item 2\0"));
	add(list, (void *)"Item 3\0", sizeof("Item 3\0"));
	add(list, (void *)"Item 4\0", sizeof("Item 4\0"));
	add(list, (void *)"Item 5\0", sizeof("Item 5\0"));

	printList(list);

	if(strcmp(testPrintout, "Item 5Item 4Item 3Item 2Item 1") != 0)
	{
		sprintf(result,
			"Incorrect items passed to print:\n\t%s\nShould have been:\n\tItem 1Item 2Item 3Item 4Item 5",
			testPrintout);
		return false;
	}

	return true;
}
void TestPrintItem(void *item)
{
	strcat(testPrintout, (char *)item);
}




void MyPrint(void *item)
{
	printf("\n%s", (char *)item);
}

int MyCompare(void *left, void *right)
{
	return strcmp((char *)left, (char *)right);
}
