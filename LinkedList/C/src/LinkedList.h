typedef struct node
{
	void *item;
	struct node *next;
}node;

typedef struct linkedList
{
	struct node *head;
	struct node *tail;
	int size;
	void(*printItem)(void *);
	int(*compare)(void *, void *);
}linkedList;

linkedList *create(void *, int, void(*)(void *), int(*)(void *, void *));
void add(linkedList *, void *, int);
void printList(linkedList *);
