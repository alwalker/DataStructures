#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "../src/LinkedList.h"

void MyPrint(void *);
int MyCompare(void *, void *);
bool CreateTests(char *);
bool AddTests(char *);
bool PrintTest(char *);
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

	memset(result, '\0', 1024);
	passed = PrintTest(result);
	if(passed)
	{
		printf("\nPrint Test Passed!");
	}
	else
	{
		printf("\nPrint Tests Failed: %s\n", result);
		return 1;
	}

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
